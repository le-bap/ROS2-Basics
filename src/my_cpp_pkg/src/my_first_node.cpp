#include "rclcpp/rclcpp.hpp"

class MyNode: public rclcpp::Node // cria a classe MyNode que herda a classe Node no rclcpp
{
public:
    MyNode(): Node("cpp_test") // invoca o construtor da classe Node e o nomeia o nó de cpp_test
    {
        RCLCPP_INFO(this->get_logger(), "Hello cpp Node!");
        timer = this->create_wall_timer(std::chrono::seconds(1), 
            std::bind(&MyNode::timerCallback, this)); // cria timer de 1 segundo que chama a função timerCallback
    }

private:

    void timerCallback()
    {
        counter++;
        RCLCPP_INFO(this->get_logger(), "Hello %d", counter);
    }

    rclcpp::TimerBase::SharedPtr timer; // declara um timer do ros2 para shared pointer chamado timer
    int counter = 0;
};

int main(int argc, char **argv){
    
    rclcpp::init(argc, argv); // inicializa a comunicação do ros
    auto node = std::make_shared<MyNode>(); // cria um shared pointer pra o nó MyNode
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}   
