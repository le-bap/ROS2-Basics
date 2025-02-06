#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/string.hpp"

class RobotNewsStationNode : public rclcpp::Node
{
public:
    RobotNewsStationNode() : Node("robot_news_station")
    {
        // inicializando publisher do tipo String para o topico robot_news
        publisher_ = this->create_publisher<example_interfaces::msg::String>("robot_news", 10);
        // inicalizando timer q publicara a msg a cada 0.5 seg a partir da função publishNews() 
        timer = this->create_wall_timer(std::chrono::milliseconds(500),
                                        std::bind(&RobotNewsStationNode::publishNews, this));
        
        RCLCPP_INFO(this->get_logger(), "Robot News Station has been started.");
    }

private:

    void publishNews()
    {
        // declarando a mensagem do tipo String
        auto msg = example_interfaces::msg::String();
        // definindo o conteudo da mensagem
        msg.data = std::string("Hi, this is ") + robot_name + std::string(" from the robot news station");
        // publicando no topico
        publisher_->publish(msg);
    }

    // declarando o ponteiro para o publisher chamado pubisher_ do tipo String
    rclcpp::Publisher<example_interfaces::msg::String>::SharedPtr publisher_;

    std::string robot_name = "R2D2";
    
    // criando um timer para publicar a msg
    rclcpp::TimerBase::SharedPtr timer;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<RobotNewsStationNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}