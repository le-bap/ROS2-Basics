#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/srv/add_two_ints.hpp"

    
int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<rclcpp::Node>("add_two_ints_client_no_oop"); 

    // criando um client
    auto client = node->create_client<example_interfaces::srv::AddTwoInts>("add_two_ints");
    // mandando uma mensagem enquanto o server nao responde
    while(!client->wait_for_service(std::chrono::seconds(1))){
        RCLCPP_WARN(node->get_logger(),  "Waiting for the server to be up...");
    }

    // criando request e passando os numeros
    auto request = std::make_shared<example_interfaces::srv::AddTwoInts::Request>();
    request->a = 3;
    request->b = 8;

    // resposta recebida do server
    auto future = client->async_send_request(request);

    // printando o resultado da interação client/server
    if (rclcpp::spin_until_future_complete(node, future) == rclcpp::FutureReturnCode::SUCCESS)
    {
        RCLCPP_INFO(node->get_logger(), "%ld + %ld = %d", request->a, request->b, (int)future.get()->sum);
    }
    else
    {
        RCLCPP_ERROR(node->get_logger(), "Error while calling service");
    }
    

    rclcpp::shutdown();
    return 0;
}