cmake_minimum_required(VERSION 3.8)
project(battery_manager)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(my_robot_interfaces REQUIRED)

add_executable(led_panel src/LED_panel.cpp)
ament_target_dependencies(led_panel rclcpp my_robot_interfaces)

add_executable(battery_node src/battery.cpp)
ament_target_dependencies(battery_node rclcpp my_robot_interfaces)

install(TARGETS
  led_panel
  battery_node
  DESTINATION lib/${PROJECT_NAME}
)



ament_package()
