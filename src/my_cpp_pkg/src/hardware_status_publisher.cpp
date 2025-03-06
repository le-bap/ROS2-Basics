#include "rclcpp/rclcpp.hpp"
#include "my_robot_interfaces/msg/hardware_status.hpp"

using namespace std::chrono_literals;

class HardwareStatusPublisherNode : public rclcpp::Node
{
public:
    HardwareStatusPublisherNode() : Node("hardware_status_publisher")
    {
        publisher_ = this->create_publisher<my_robot_interfaces::msg::HardwareStatus>( 
            "hardware_status", 10);
        timer_ = this->create_wall_timer(
            1s, 
            std::bind(&HardwareStatusPublisherNode::publishHardwareStatus, this));
        RCLCPP_INFO(this->get_logger(), "Hw status publisher has been started");
    }

private:
    void publishHardwareStatus()
    {
        auto msg = my_robot_interfaces::msg::HardwareStatus();
		msg.temperature = 52.3;
		msg.are_motors_ready = false;
		msg.debug_message = "Motors are too hot";
		publisher_->publish(msg);
    }

    rclcpp::Publisher<my_robot_interfaces::msg::HardwareStatus>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<HardwareStatusPublisherNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}