#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int64.hpp"
#include "example_interfaces/srv/set_bool.hpp"

using std::placeholders::_1;
using std::placeholders::_2;

class NumberCounterNode : public rclcpp::Node
{
public:
    NumberCounterNode() : Node("number_counter")
    {
        subscriber = this->create_subscription<std_msgs::msg::Int64>("number", 10,
                                                                     std::bind(&NumberCounterNode::AddNumber, this, std::placeholders::_1));

        publisher = this->create_publisher<std_msgs::msg::Int64>("number_count", 10);

        server = this->create_service<example_interfaces::srv::SetBool>("reset_counter",
                                                                        std::bind(&NumberCounterNode::RecetNumber, this, _1, _2));

        RCLCPP_INFO(this->get_logger(), "Number Counter Node has been started");
    }

private:
    // para somar os valores recebidos
    int counter;

    // publisher que publicará a soma
    rclcpp::Publisher<std_msgs::msg::Int64>::SharedPtr publisher;

    // subscriber que receberá os números
    rclcpp::Subscription<std_msgs::msg::Int64>::SharedPtr subscriber;

    // serviço que irá recetar a contagem
    rclcpp::Service<example_interfaces::srv::SetBool>::SharedPtr server;

    // função para receber os valores do topico "number" e publicar
    // soma no topico "number_count"
    void AddNumber(std_msgs::msg::Int64::SharedPtr msg)
    {   
        counter += msg->data;
        auto newMsg = std_msgs::msg::Int64();
        newMsg.data = counter;
        publisher->publish(newMsg);
        
    }

    void RecetNumber(example_interfaces::srv::SetBool::Request::SharedPtr request,
                             example_interfaces::srv::SetBool::Response::SharedPtr response)
    {
        if (request->data == true)
        {
            counter = 0;
            response->success = true;
            response->message = "Counter has been reset";
        }
        else
        {
            response->success = false;
            response->message = "Counter has not been reset";
        }
    }
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<NumberCounterNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}