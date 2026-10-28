# generated from rosidl_cmake/cmake/rosidl_cmake_aggregate_target-extras.cmake.in

# Create a convenience aggregate target my_first_package_msgs::my_first_package_msgs
# that links all generated interface targets, so downstream packages can use
# a single modern CMake target name instead of ${my_first_package_msgs_TARGETS}.
if(my_first_package_msgs_TARGETS AND NOT TARGET my_first_package_msgs::my_first_package_msgs)
  add_library(my_first_package_msgs::my_first_package_msgs INTERFACE IMPORTED)
  set_target_properties(my_first_package_msgs::my_first_package_msgs PROPERTIES
    INTERFACE_LINK_LIBRARIES "${my_first_package_msgs_TARGETS}")
endif()
