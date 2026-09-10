// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_interfaces:msg/BoundingBoxArray.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_interfaces/msg/bounding_box_array.hpp"


#ifndef CUSTOM_INTERFACES__MSG__DETAIL__BOUNDING_BOX_ARRAY__BUILDER_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__BOUNDING_BOX_ARRAY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_interfaces/msg/detail/bounding_box_array__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_interfaces
{

namespace msg
{

namespace builder
{

class Init_BoundingBoxArray_boxes
{
public:
  explicit Init_BoundingBoxArray_boxes(::custom_interfaces::msg::BoundingBoxArray & msg)
  : msg_(msg)
  {}
  ::custom_interfaces::msg::BoundingBoxArray boxes(::custom_interfaces::msg::BoundingBoxArray::_boxes_type arg)
  {
    msg_.boxes = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::msg::BoundingBoxArray msg_;
};

class Init_BoundingBoxArray_header
{
public:
  Init_BoundingBoxArray_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_BoundingBoxArray_boxes header(::custom_interfaces::msg::BoundingBoxArray::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_BoundingBoxArray_boxes(msg_);
  }

private:
  ::custom_interfaces::msg::BoundingBoxArray msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::msg::BoundingBoxArray>()
{
  return custom_interfaces::msg::builder::Init_BoundingBoxArray_header();
}

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__BOUNDING_BOX_ARRAY__BUILDER_HPP_
