#!/usr/bin/env python3
import rclpy
from rclpy.node import Node

from example_interfaces.srv import AddTwoInts
from functools import partial # usado para passar mais paramentros para future.add_done_callback

class AddTwoInstClientNode(Node):
    def __init__(self):
        super().__init__("add_two_ints_client")
        self.call_add_two_ints_server(6, 7)

    # funcao q criara o cliente 
    def call_add_two_ints_server(self, a, b):
        # criando o cliente
        client =  self.create_client(AddTwoInts, "add_two_ints")

        # enquanto o servidor nao responde
        while not client.wait_for_service(1.0):
            self.get_logger().warn("Waiting for Server Add Two Ints")
        
        # criando um objeto de request
        request =  AddTwoInts.Request()
        request.a = a
        request.b = b

        # manda o request de forma assicrona para a variavel future q recebera a resposta
        future = client.call_async(request)
        # calllback para o future
        future.add_done_callback(partial(self.callback_call_add_two_ints, a=a,b=b))
    
    # função que processará a resposta
    def callback_call_add_two_ints(self,future, a, b):
        try:  # recebe a resposta do service e print a resposta
            response = future.result()
            self.get_logger().info(str(a) + " + " + str(b) + " = " + str(response.sum))
            
        except Exception as e:
            self.get_logger().error("Service call failed %r" % (e,))


def main(args=None):
    rclpy.init(args=args)
    node = AddTwoInstClientNode() 
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()