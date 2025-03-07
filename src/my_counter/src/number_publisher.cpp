#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int64.hpp"
    
class NumberPublisherNode : public rclcpp::Node 
{
public:
    NumberPublisherNode() : Node("number_publisher") {
        publisher = this->create_publisher<std_msgs::msg::Int64>("number", 10);
        timer = this->create_wall_timer(std::chrono::milliseconds(1000),
                                        std::bind(&NumberPublisherNode::PublishNumber, this));

        RCLCPP_INFO(this->get_logger(), "Number Publisher Node has started");
    }
    
private:
    // declarando publisher dos numeros
    rclcpp::Publisher<std_msgs::msg::Int64>::SharedPtr publisher;

    // criando um timer para publicar a msg
    rclcpp::TimerBase::SharedPtr timer;
    
    void PublishNumber(){
        auto msg = std_msgs::msg::Int64();
        msg.data = num;
        publisher->publish(msg);
    }

    int num = 2;
};
    
int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<NumberPublisherNode>(); 
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}