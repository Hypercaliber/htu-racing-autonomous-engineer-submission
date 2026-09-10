// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_interfaces:msg/BoundingBox.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_interfaces/msg/bounding_box.h"


#ifndef CUSTOM_INTERFACES__MSG__DETAIL__BOUNDING_BOX__STRUCT_H_
#define CUSTOM_INTERFACES__MSG__DETAIL__BOUNDING_BOX__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/BoundingBox in the package custom_interfaces.
typedef struct custom_interfaces__msg__BoundingBox
{
  uint8_t class_id;
  float confidence;
  float x1;
  float y1;
  float x2;
  float y2;
} custom_interfaces__msg__BoundingBox;

// Struct for a sequence of custom_interfaces__msg__BoundingBox.
typedef struct custom_interfaces__msg__BoundingBox__Sequence
{
  custom_interfaces__msg__BoundingBox * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interfaces__msg__BoundingBox__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__BOUNDING_BOX__STRUCT_H_
