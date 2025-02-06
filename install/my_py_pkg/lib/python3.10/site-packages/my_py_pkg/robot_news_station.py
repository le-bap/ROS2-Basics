#!/usr/bin/env python3
import rclpy
from rclpy.node import Node

from example_interfaces.msg import String # importando o tipo de msg String
    # lembrar de adicionar a dependencia de example_interface no package.xml
    
class RobotNewsStationNode(Node): 
    def __init__(self):
        super().__init__("robot_news_station")

        self.robot_name = "C3PO"
        # criando um publisher chamado robot_news do tipo String
        self.publisher = self.create_publisher(String, "robot_news", 10)
        # criando timer para publicar no topico
        self.timer = self.create_timer(1, self.publish_news)
        # publica msg que o nó foi iniciado
        self.get_logger().info("Robot News Station has been started")

    def publish_news(self): # função que publicará msg no topico
        msg = String() # cria mensagem do tipo String
        msg.data = "Hello, this is " + self.robot_name + " from the robot news station" # informação que a msg contem
        self.publisher.publish(msg) # publica a msg no topico robot_news
    
    
def main(args=None):
    rclpy.init(args=args)
    node = RobotNewsStationNode()
    rclpy.spin(node)
    rclpy.shutdown()
    
    
if __name__ == "__main__":
    main()