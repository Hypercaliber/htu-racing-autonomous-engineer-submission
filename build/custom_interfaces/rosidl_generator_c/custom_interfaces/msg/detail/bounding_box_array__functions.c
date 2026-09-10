// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from custom_interfaces:msg/BoundingBoxArray.idl
// generated code does not contain a copyright notice
#include "custom_interfaces/msg/detail/bounding_box_array__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `boxes`
#include "custom_interfaces/msg/detail/bounding_box__functions.h"

bool
custom_interfaces__msg__BoundingBoxArray__init(custom_interfaces__msg__BoundingBoxArray * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    custom_interfaces__msg__BoundingBoxArray__fini(msg);
    return false;
  }
  // boxes
  if (!custom_interfaces__msg__BoundingBox__Sequence__init(&msg->boxes, 0)) {
    custom_interfaces__msg__BoundingBoxArray__fini(msg);
    return false;
  }
  return true;
}

void
custom_interfaces__msg__BoundingBoxArray__fini(custom_interfaces__msg__BoundingBoxArray * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // boxes
  custom_interfaces__msg__BoundingBox__Sequence__fini(&msg->boxes);
}

bool
custom_interfaces__msg__BoundingBoxArray__are_equal(const custom_interfaces__msg__BoundingBoxArray * lhs, const custom_interfaces__msg__BoundingBoxArray * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // boxes
  if (!custom_interfaces__msg__BoundingBox__Sequence__are_equal(
      &(lhs->boxes), &(rhs->boxes)))
  {
    return false;
  }
  return true;
}

bool
custom_interfaces__msg__BoundingBoxArray__copy(
  const custom_interfaces__msg__BoundingBoxArray * input,
  custom_interfaces__msg__BoundingBoxArray * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // boxes
  if (!custom_interfaces__msg__BoundingBox__Sequence__copy(
      &(input->boxes), &(output->boxes)))
  {
    return false;
  }
  return true;
}

custom_interfaces__msg__BoundingBoxArray *
custom_interfaces__msg__BoundingBoxArray__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_interfaces__msg__BoundingBoxArray * msg = (custom_interfaces__msg__BoundingBoxArray *)allocator.allocate(sizeof(custom_interfaces__msg__BoundingBoxArray), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(custom_interfaces__msg__BoundingBoxArray));
  bool success = custom_interfaces__msg__BoundingBoxArray__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
custom_interfaces__msg__BoundingBoxArray__destroy(custom_interfaces__msg__BoundingBoxArray * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    custom_interfaces__msg__BoundingBoxArray__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
custom_interfaces__msg__BoundingBoxArray__Sequence__init(custom_interfaces__msg__BoundingBoxArray__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_interfaces__msg__BoundingBoxArray * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(custom_interfaces__msg__BoundingBoxArray)) {
      return false;
    }
    data = (custom_interfaces__msg__BoundingBoxArray *)allocator.zero_allocate(size, sizeof(custom_interfaces__msg__BoundingBoxArray), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = custom_interfaces__msg__BoundingBoxArray__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        custom_interfaces__msg__BoundingBoxArray__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
custom_interfaces__msg__BoundingBoxArray__Sequence__fini(custom_interfaces__msg__BoundingBoxArray__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      custom_interfaces__msg__BoundingBoxArray__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

custom_interfaces__msg__BoundingBoxArray__Sequence *
custom_interfaces__msg__BoundingBoxArray__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_interfaces__msg__BoundingBoxArray__Sequence * array = (custom_interfaces__msg__BoundingBoxArray__Sequence *)allocator.allocate(sizeof(custom_interfaces__msg__BoundingBoxArray__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = custom_interfaces__msg__BoundingBoxArray__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
custom_interfaces__msg__BoundingBoxArray__Sequence__destroy(custom_interfaces__msg__BoundingBoxArray__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    custom_interfaces__msg__BoundingBoxArray__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
custom_interfaces__msg__BoundingBoxArray__Sequence__are_equal(const custom_interfaces__msg__BoundingBoxArray__Sequence * lhs, const custom_interfaces__msg__BoundingBoxArray__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!custom_interfaces__msg__BoundingBoxArray__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
custom_interfaces__msg__BoundingBoxArray__Sequence__copy(
  const custom_interfaces__msg__BoundingBoxArray__Sequence * input,
  custom_interfaces__msg__BoundingBoxArray__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(custom_interfaces__msg__BoundingBoxArray)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(custom_interfaces__msg__BoundingBoxArray);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    custom_interfaces__msg__BoundingBoxArray * data =
      (custom_interfaces__msg__BoundingBoxArray *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!custom_interfaces__msg__BoundingBoxArray__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          custom_interfaces__msg__BoundingBoxArray__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!custom_interfaces__msg__BoundingBoxArray__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
