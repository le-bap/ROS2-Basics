#!/usr/bin/env python3
import rclpy
from rclpy.node import Node

from example_interfaces.srv import AddTwoInts

def main(args=None):
    rclpy.init(args=args)
    # criando um objeto Node chamado add_two_ints_no_oop
    node = Node("add_two_ints_no_oop") 
    # criando o cliente
    client =  node.create_client(AddTwoInts, "add_two_ints")

    # enquanto o servidor nao responde
    while not client.wait_for_service(1.0):
        node.get_logger().warn("Waiting for Server Add Two Ints")

    # criando um objeto de request
    request =  AddTwoInts.Request()
    request.a = 3
    request.b = 8

    # manda o request de forma assicrona para a variavel future q recebera a resposta
    future = client.call_async(request)
    # deixa o no rodando ate ter a resposta
    rclpy.spin_until_future_complete(node, future)

    try:  # recebe a resposta do service e print a resposta
        response = future.result()
        node.get_logger().info(str(request.a) + " + " + str(request.b) + " = " + str(response.sum))
        
    except Exception as e:
        node.get_logger().error("Service call failed %r" % (e,))
    rclpy.shutdown()


if __name__ == "__main__":
    main()


