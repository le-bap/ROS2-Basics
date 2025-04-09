#include "rclcpp/rclcpp.hpp"
#include "my_robot_interfaces/msg/led_panel_state.hpp"
#include "my_robot_interfaces/srv/set_led.hpp"
#include <array>

using std::placeholders::_1;
using std::placeholders::_2;
class LedPanelNode : public rclcpp::Node
{
public:
    LedPanelNode() : Node("led_panel_node")
    {
        led_state = {0, 0, 0};
        publisher = this->create_publisher<my_robot_interfaces::msg::LedPanelState>("led_panel_state", 10);
        timer = this->create_wall_timer(std::chrono::milliseconds(3000),
                                        std::bind(&LedPanelNode::publish_led_status, this));
        server = this->create_service<my_robot_interfaces::srv::SetLed>(
            "set_led", std::bind(&LedPanelNode::set_led_callback, this, _1, _2));
        RCLCPP_INFO(this->get_logger(), "LED Panel Node has been started");
    }

private:
    void publish_led_status()
    {
        my_robot_interfaces::msg::LedPanelState msg;
        msg.led_status = led_state;
        publisher->publish(msg);
    }

    void set_led_callback(my_robot_interfaces::srv::SetLed::Request::SharedPtr request,
                          my_robot_interfaces::srv::SetLed::Response::SharedPtr response)
    {
        int64_t led_number = request->led_number;
        int16_t state = request->state;
        
        if (led_number > 2 || led_number < 0)
        {
            response->led_on = false;
            RCLCPP_INFO(this->get_logger(), "Numero do LED invalido");
            return;
        }
        else if (state != 0 && state != 1)
        {
            response->led_on = false;
            RCLCPP_INFO(this->get_logger(), "Numero do estado deve ser 0 ou 1");
            return;
        }

        led_state.at(led_number) = state;
        response->led_on = true;
        publish_led_status();
    }

    rclcpp::Publisher<my_robot_interfaces::msg::LedPanelState>::SharedPtr publisher;
    rclcpp::TimerBase::SharedPtr timer;
    rclcpp::Service<my_robot_interfaces::srv::SetLed>::SharedPtr server;
    
    std::vector<int64_t> led_state;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<LedPanelNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}