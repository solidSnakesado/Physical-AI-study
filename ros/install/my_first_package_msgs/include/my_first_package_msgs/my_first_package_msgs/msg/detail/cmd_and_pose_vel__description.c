// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from my_first_package_msgs:msg/CmdAndPoseVel.idl
// generated code does not contain a copyright notice

#include "my_first_package_msgs/msg/detail/cmd_and_pose_vel__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_my_first_package_msgs
const rosidl_type_hash_t *
my_first_package_msgs__msg__CmdAndPoseVel__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x2f, 0x7b, 0x56, 0xcf, 0xf9, 0x89, 0x16, 0x70,
      0x8f, 0x7d, 0x50, 0xc7, 0x27, 0x95, 0x59, 0x02,
      0xef, 0xa9, 0x61, 0x68, 0x80, 0x2e, 0xc0, 0x84,
      0x49, 0x4a, 0xc8, 0x8d, 0x77, 0x81, 0x2f, 0xb4,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char my_first_package_msgs__msg__CmdAndPoseVel__TYPE_NAME[] = "my_first_package_msgs/msg/CmdAndPoseVel";

// Define type names, field names, and default values
static char my_first_package_msgs__msg__CmdAndPoseVel__FIELD_NAME__cmd_vel_linear[] = "cmd_vel_linear";
static char my_first_package_msgs__msg__CmdAndPoseVel__FIELD_NAME__cmd_vel_angular[] = "cmd_vel_angular";
static char my_first_package_msgs__msg__CmdAndPoseVel__FIELD_NAME__pose_x[] = "pose_x";
static char my_first_package_msgs__msg__CmdAndPoseVel__FIELD_NAME__pose_y[] = "pose_y";
static char my_first_package_msgs__msg__CmdAndPoseVel__FIELD_NAME__linear_vel[] = "linear_vel";
static char my_first_package_msgs__msg__CmdAndPoseVel__FIELD_NAME__angular_vel[] = "angular_vel";

static rosidl_runtime_c__type_description__Field my_first_package_msgs__msg__CmdAndPoseVel__FIELDS[] = {
  {
    {my_first_package_msgs__msg__CmdAndPoseVel__FIELD_NAME__cmd_vel_linear, 14, 14},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {my_first_package_msgs__msg__CmdAndPoseVel__FIELD_NAME__cmd_vel_angular, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {my_first_package_msgs__msg__CmdAndPoseVel__FIELD_NAME__pose_x, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {my_first_package_msgs__msg__CmdAndPoseVel__FIELD_NAME__pose_y, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {my_first_package_msgs__msg__CmdAndPoseVel__FIELD_NAME__linear_vel, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {my_first_package_msgs__msg__CmdAndPoseVel__FIELD_NAME__angular_vel, 11, 11},
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
my_first_package_msgs__msg__CmdAndPoseVel__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {my_first_package_msgs__msg__CmdAndPoseVel__TYPE_NAME, 39, 39},
      {my_first_package_msgs__msg__CmdAndPoseVel__FIELDS, 6, 6},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "float32 cmd_vel_linear\n"
  "float32 cmd_vel_angular\n"
  "\n"
  "float32 pose_x\n"
  "float32 pose_y\n"
  "float32 linear_vel\n"
  "float32 angular_vel";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
my_first_package_msgs__msg__CmdAndPoseVel__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {my_first_package_msgs__msg__CmdAndPoseVel__TYPE_NAME, 39, 39},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 116, 116},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
my_first_package_msgs__msg__CmdAndPoseVel__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *my_first_package_msgs__msg__CmdAndPoseVel__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
