#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/srv/add_two_ints.hpp"
    
class AddTwoIntsClientNode : public rclcpp::Node 
{
public:
    AddTwoIntsClientNode() : Node("add_two_ints_client") 
    {   
        // passando para thread a função
        thread1 = std::thread(std::bind(&AddTwoIntsClientNode::callAddTwoIntsService, this, 1, 4));
        thread2 = std::thread(std::bind(&AddTwoIntsClientNode::callAddTwoIntsService, this, 5, 10));

        // ou
        threads.push_back(std::thread(std::bind(&AddTwoIntsClientNode::callAddTwoIntsService, this, 1, 4)));
        threads.push_back(std::thread(std::bind(&AddTwoIntsClientNode::callAddTwoIntsService, this, 5, 10)));
    }

    // função para chamar o serviço
    void callAddTwoIntsService(int a, int b)
    {
        // criando um client
        auto client = this->create_client<example_interfaces::srv::AddTwoInts>("add_two_ints");
        // mandando uma mensagem enquanto o server nao responde
        while(!client->wait_for_service(std::chrono::seconds(1)))
        {
            RCLCPP_WARN(this->get_logger(),  "Waiting for the server to be up...");
        }

        // criando request e passando os numeros
        auto request = std::make_shared<example_interfaces::srv::AddTwoInts::Request>();
        request->a = a;
        request->b = b;

        // resposta recebida do server
        auto future = client->async_send_request(request);

        // processando a resposta
        try{
            auto response = future.get();
            RCLCPP_INFO(this->get_logger(), "%ld + %ld = %ld", request->a, request->b, response->sum);
        }
        catch(const std::exception &e){
            RCLCPP_ERROR(this->get_logger(),  "Service call failed");
        }
    }
    
private:
    // criando uma thread para rodar a função pois se ela for chamada direto pelo construtor
    // o nó não executará o spin
    std::thread thread1;
    std::thread thread2;
    std::vector<std::thread> threads;
};
    
int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<AddTwoIntsClientNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}