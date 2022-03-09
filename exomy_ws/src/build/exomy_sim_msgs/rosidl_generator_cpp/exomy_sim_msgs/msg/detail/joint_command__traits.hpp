// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from exomy_sim_msgs:msg/JointCommand.idl
// generated code does not contain a copyright notice

#ifndef EXOMY_SIM_MSGS__MSG__DETAIL__JOINT_COMMAND__TRAITS_HPP_
#define EXOMY_SIM_MSGS__MSG__DETAIL__JOINT_COMMAND__TRAITS_HPP_

#include "exomy_sim_msgs/msg/detail/joint_command__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<exomy_sim_msgs::msg::JointCommand>()
{
  return "exomy_sim_msgs::msg::JointCommand";
}

template<>
inline const char * name<exomy_sim_msgs::msg::JointCommand>()
{
  return "exomy_sim_msgs/msg/JointCommand";
}

template<>
struct has_fixed_size<exomy_sim_msgs::msg::JointCommand>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<exomy_sim_msgs::msg::JointCommand>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<exomy_sim_msgs::msg::JointCommand>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // EXOMY_SIM_MSGS__MSG__DETAIL__JOINT_COMMAND__TRAITS_HPP_
