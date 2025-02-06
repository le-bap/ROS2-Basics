#!/usr/bin/env python3
import rclpy
from rclpy.node import Node

# classe MyNode que herda a classe Node do ros
class MyNode(Node):
    
    def __init__(self): # construtor da classe
        super().__init__("py_test")  # invoca o contrutor do Node e nomeia o nó de py_test
        self.counter = 0 # cria um contador
        self.get_logger().info("Hello ROS2 em python")
        self.create_timer(0.5, self.timer_callback) #chama a função timer_callback a cada 0.5 segundo

    def timer_callback(self):
        self.counter += 1
        self.get_logger().info("Hello " + str(self.counter))


def main(args=None):
    rclpy.init(args=args) # precisa estar em qualquer nó pois inicaliza a comunicação do ROS2 
    node = MyNode() # cria o objeto MyNode  
    rclpy.spin(node) # faz com que o programa continue rodando e so pare com crtl c
    rclpy.shutdown() # finaliza a comunicação

if __name__ == "__main__":
    main()
