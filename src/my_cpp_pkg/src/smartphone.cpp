#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/string.hpp"

class SmartphoneNode : public rclcpp::Node
{
public:
    SmartphoneNode() : Node("smartphone")
    {
        // criando subscriber "robot_news" (o placeholders::_1 eh pq a funcao callbackRobotNews recebe 1 parametro)
        subscriber = this->create_subscription<example_interfaces::msg::String>("robot_news", 10,
                                                                                std::bind(&SmartphoneNode::callbackRobotNews, this, std::placeholders::_1));
        RCLCPP_INFO(this->get_logger(), "Smartphone has been started.");
    }

private:
    // função callback q mostrará a mensagem
    void callbackRobotNews(const example_interfaces::msg::String::SharedPtr msg)
    {
        RCLCPP_INFO(this->get_logger(), "%s", msg->data.c_str());
    }
    // declarando subscriber do tipo String chamado subscriber
    rclcpp::Subscription<example_interfaces::msg::String>::SharedPtr subscriber;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<SmartphoneNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}