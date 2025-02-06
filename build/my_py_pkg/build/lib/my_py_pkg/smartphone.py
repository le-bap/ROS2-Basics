#!/usr/bin/env python3i
import rclpy
from rclpy.node import Node

from example_interfaces.msg import String # importando o tipo String para receber msg do topico 
    #  (mesmo tipo do publisher)

class SmartphoneNode(Node): 
    def __init__(self):
        super().__init__("smartphone")
        # criando subcriber do topico "robot_news" que manda mensagens do tipo String e chama a função 
        # callback para ver a msg
        self.subscriber = self.create_subscription(String, "robot_news", self.callback_robot_news, 10)
        self.get_logger().info("Smartphone has been started.")
    
    # função que recebe a mensagem enviada e imprime no terminal
    def callback_robot_news(self, msg):
        self.get_logger().info(msg.data)


def main(args=None):
    rclpy.init(args=args)
    node = SmartphoneNode() 
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
	main()