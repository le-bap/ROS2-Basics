#include "rclcpp/rclcpp.hpp"
#include "my_robot_interfaces/srv/set_led.hpp"
    
class BatteryNode : public rclcpp::Node 
{
public:
    BatteryNode() : Node("battery_node") 
    {   
        RCLCPP_INFO(this->get_logger(), "Battery Node has been started");
        battery_life = 6;
        thread = std::thread(std::bind(&BatteryNode::simulateBatteryLife, this));
        client = this->create_client<my_robot_interfaces::srv::SetLed>("set_led");
        while(!client->wait_for_service(std::chrono::seconds(2)))
        {
            RCLCPP_WARN(this->get_logger(),  "Waiting for the server to be up...");
        }
    }

    
private:

    void simulateBatteryLife()
    {
        while(battery_life != 0)
        {
            battery_life -= 1;
            RCLCPP_INFO(this->get_logger(), "battery life: %d", battery_life);
            callSetLedService();
            sleep(4);
        }
    }


    void callSetLedService()
    {
        if (battery_life == 3)
        {
            auto request = std::make_shared<my_robot_interfaces::srv::SetLed::Request>();
            request->led_number = 0;
            request->state = 1;
            auto future = client->async_send_request(request);
            try{
                auto response = future.get();
                RCLCPP_INFO(this->get_logger(), "LED Panel acendeu outro LED", response->led_on);
            }
            catch(const std::exception &e){
                RCLCPP_ERROR(this->get_logger(),  "Service call failed");
            }
        }
        
        else if (battery_life == 0)
        {
            auto request = std::make_shared<my_robot_interfaces::srv::SetLed::Request>();
            request->led_number = 1;
            request->state = 1;
            auto future = client->async_send_request(request);

            // processando a resposta
            try{
                auto response = future.get();
                RCLCPP_INFO(this->get_logger(), "LED Panel acendeu outro LED", response->led_on);
            }
            catch(const std::exception &e){
                RCLCPP_ERROR(this->get_logger(),  "Service call failed");
            }

            RCLCPP_INFO(this->get_logger(), "Bateria descarregada... carregando");
            sleep(2);
            
            // apagar led 0
            request->led_number = 1;
            request->state = 0;
            future = client->async_send_request(request);
            sleep(1);
            // apagar led 1
            request->led_number = 0;
            request->state = 0;
            future = client->async_send_request(request);

            RCLCPP_INFO(this->get_logger(), "Bateria carregada!");
            battery_life = 6;
        }

    }
    
    void BatteryCharging()
    {
        

    }
    std::thread thread;
    int battery_life;

    rclcpp::Client<my_robot_interfaces::srv::SetLed>::SharedPtr client;
};
int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<BatteryNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}