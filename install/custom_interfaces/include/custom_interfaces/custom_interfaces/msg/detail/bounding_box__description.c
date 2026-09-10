// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from custom_interfaces:msg/BoundingBox.idl
// generated code does not contain a copyright notice

#include "custom_interfaces/msg/detail/bounding_box__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_custom_interfaces
const rosidl_type_hash_t *
custom_interfaces__msg__BoundingBox__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x4c, 0x10, 0xdf, 0xa0, 0xf9, 0x78, 0x08, 0x3b,
      0x35, 0x0d, 0x67, 0xee, 0xc7, 0x68, 0x59, 0x6b,
      0x6b, 0xb7, 0x17, 0xed, 0x62, 0x63, 0xef, 0x5e,
      0x3b, 0xfa, 0x8e, 0x99, 0xba, 0xed, 0xa3, 0xff,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char custom_interfaces__msg__BoundingBox__TYPE_NAME[] = "custom_interfaces/msg/BoundingBox";

// Define type names, field names, and default values
static char custom_interfaces__msg__BoundingBox__FIELD_NAME__class_id[] = "class_id";
static char custom_interfaces__msg__BoundingBox__FIELD_NAME__confidence[] = "confidence";
static char custom_interfaces__msg__BoundingBox__FIELD_NAME__x1[] = "x1";
static char custom_interfaces__msg__BoundingBox__FIELD_NAME__y1[] = "y1";
static char custom_interfaces__msg__BoundingBox__FIELD_NAME__x2[] = "x2";
static char custom_interfaces__msg__BoundingBox__FIELD_NAME__y2[] = "y2";

static rosidl_runtime_c__type_description__Field custom_interfaces__msg__BoundingBox__FIELDS[] = {
  {
    {custom_interfaces__msg__BoundingBox__FIELD_NAME__class_id, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {custom_interfaces__msg__BoundingBox__FIELD_NAME__confidence, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {custom_interfaces__msg__BoundingBox__FIELD_NAME__x1, 2, 2},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {custom_interfaces__msg__BoundingBox__FIELD_NAME__y1, 2, 2},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {custom_interfaces__msg__BoundingBox__FIELD_NAME__x2, 2, 2},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {custom_interfaces__msg__BoundingBox__FIELD_NAME__y2, 2, 2},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
custom_interfaces__msg__BoundingBox__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {custom_interfaces__msg__BoundingBox__TYPE_NAME, 33, 33},
      {custom_interfaces__msg__BoundingBox__FIELDS, 6, 6},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "uint8 class_id\n"
  "float32 confidence\n"
  "\n"
  "float32 x1\n"
  "float32 y1\n"
  "float32 x2\n"
  "float32 y2";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
custom_interfaces__msg__BoundingBox__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {custom_interfaces__msg__BoundingBox__TYPE_NAME, 33, 33},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 78, 78},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
custom_interfaces__msg__BoundingBox__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *custom_interfaces__msg__BoundingBox__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
