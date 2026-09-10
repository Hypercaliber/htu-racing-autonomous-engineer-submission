// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_interfaces:msg/BoundingBox.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_interfaces/msg/bounding_box.hpp"


#ifndef CUSTOM_INTERFACES__MSG__DETAIL__BOUNDING_BOX__BUILDER_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__BOUNDING_BOX__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_interfaces/msg/detail/bounding_box__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_interfaces
{

namespace msg
{

namespace builder
{

class Init_BoundingBox_y2
{
public:
  explicit Init_BoundingBox_y2(::custom_interfaces::msg::BoundingBox & msg)
  : msg_(msg)
  {}
  ::custom_interfaces::msg::BoundingBox y2(::custom_interfaces::msg::BoundingBox::_y2_type arg)
  {
    msg_.y2 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::msg::BoundingBox msg_;
};

class Init_BoundingBox_x2
{
public:
  explicit Init_BoundingBox_x2(::custom_interfaces::msg::BoundingBox & msg)
  : msg_(msg)
  {}
  Init_BoundingBox_y2 x2(::custom_interfaces::msg::BoundingBox::_x2_type arg)
  {
    msg_.x2 = std::move(arg);
    return Init_BoundingBox_y2(msg_);
  }

private:
  ::custom_interfaces::msg::BoundingBox msg_;
};

class Init_BoundingBox_y1
{
public:
  explicit Init_BoundingBox_y1(::custom_interfaces::msg::BoundingBox & msg)
  : msg_(msg)
  {}
  Init_BoundingBox_x2 y1(::custom_interfaces::msg::BoundingBox::_y1_type arg)
  {
    msg_.y1 = std::move(arg);
    return Init_BoundingBox_x2(msg_);
  }

private:
  ::custom_interfaces::msg::BoundingBox msg_;
};

class Init_BoundingBox_x1
{
public:
  explicit Init_BoundingBox_x1(::custom_interfaces::msg::BoundingBox & msg)
  : msg_(msg)
  {}
  Init_BoundingBox_y1 x1(::custom_interfaces::msg::BoundingBox::_x1_type arg)
  {
    msg_.x1 = std::move(arg);
    return Init_BoundingBox_y1(msg_);
  }

private:
  ::custom_interfaces::msg::BoundingBox msg_;
};

class Init_BoundingBox_confidence
{
public:
  explicit Init_BoundingBox_confidence(::custom_interfaces::msg::BoundingBox & msg)
  : msg_(msg)
  {}
  Init_BoundingBox_x1 confidence(::custom_interfaces::msg::BoundingBox::_confidence_type arg)
  {
    msg_.confidence = std::move(arg);
    return Init_BoundingBox_x1(msg_);
  }

private:
  ::custom_interfaces::msg::BoundingBox msg_;
};

class Init_BoundingBox_class_id
{
public:
  Init_BoundingBox_class_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_BoundingBox_confidence class_id(::custom_interfaces::msg::BoundingBox::_class_id_type arg)
  {
    msg_.class_id = std::move(arg);
    return Init_BoundingBox_confidence(msg_);
  }

private:
  ::custom_interfaces::msg::BoundingBox msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::msg::BoundingBox>()
{
  return custom_interfaces::msg::builder::Init_BoundingBox_class_id();
}

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__BOUNDING_BOX__BUILDER_HPP_
