cmake_minimum_required(VERSION 3.5)
project(ROS_kurs)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(catkin REQUIRED COMPONENTS geometry_msgs roscpp std_msgs)

catkin_package(INCLUDE_DIRS CATKIN_DEPENDS geometry_msgs roscpp std_msgs)

include_directories(${catkin_INCLUDE_DIRS})

add_executable(speed_profile src/speed_profile.cpp)
add_dependencies(speed_profile ${catkin_EXPORTED_TARGETS})
target_link_libraries(speed_profile ${catkin_LIBRARIES})
install(TARGETS speed_profile
        RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

add_executable(lateral_control src/lateral_control.cpp)
add_dependencies(lateral_control ${catkin_EXPORTED_TARGETS})
target_link_libraries(lateral_control ${catkin_LIBRARIES})
install(TARGETS lateral_control
        RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})


install(
  DIRECTORY launch
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
  FILES_MATCHING
  PATTERN "*.launch")
