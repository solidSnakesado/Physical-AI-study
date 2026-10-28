// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from my_first_package_msgs:srv/MultiSpawn.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "my_first_package_msgs/srv/detail/multi_spawn__rosidl_typesupport_introspection_c.h"
#include "my_first_package_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "my_first_package_msgs/srv/detail/multi_spawn__functions.h"
#include "my_first_package_msgs/srv/detail/multi_spawn__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void my_first_package_msgs__srv__MultiSpawn_Request__rosidl_typesupport_introspection_c__MultiSpawn_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  my_first_package_msgs__srv__MultiSpawn_Request__init(message_memory);
}

void my_first_package_msgs__srv__MultiSpawn_Request__rosidl_typesupport_introspection_c__MultiSpawn_Request_fini_function(void * message_memory)
{
  my_first_package_msgs__srv__MultiSpawn_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember my_first_package_msgs__srv__MultiSpawn_Request__rosidl_typesupport_introspection_c__MultiSpawn_Request_message_member_array[1] = {
  {
    "num",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(my_first_package_msgs__srv__MultiSpawn_Request, num),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers my_first_package_msgs__srv__MultiSpawn_Request__rosidl_typesupport_introspection_c__MultiSpawn_Request_message_members = {
  "my_first_package_msgs__srv",  // message namespace
  "MultiSpawn_Request",  // message name
  1,  // number of fields
  sizeof(my_first_package_msgs__srv__MultiSpawn_Request),
  false,  // has_any_key_member_
  my_first_package_msgs__srv__MultiSpawn_Request__rosidl_typesupport_introspection_c__MultiSpawn_Request_message_member_array,  // message members
  my_first_package_msgs__srv__MultiSpawn_Request__rosidl_typesupport_introspection_c__MultiSpawn_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  my_first_package_msgs__srv__MultiSpawn_Request__rosidl_typesupport_introspection_c__MultiSpawn_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t my_first_package_msgs__srv__MultiSpawn_Request__rosidl_typesupport_introspection_c__MultiSpawn_Request_message_type_support_handle = {
  0,
  &my_first_package_msgs__srv__MultiSpawn_Request__rosidl_typesupport_introspection_c__MultiSpawn_Request_message_members,
  get_message_typesupport_handle_function,
  &my_first_package_msgs__srv__MultiSpawn_Request__get_type_hash,
  &my_first_package_msgs__srv__MultiSpawn_Request__get_type_description,
  &my_first_package_msgs__srv__MultiSpawn_Request__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_my_first_package_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, my_first_package_msgs, srv, MultiSpawn_Request)() {
  if (!my_first_package_msgs__srv__MultiSpawn_Request__rosidl_typesupport_introspection_c__MultiSpawn_Request_message_type_support_handle.typesupport_identifier) {
    my_first_package_msgs__srv__MultiSpawn_Request__rosidl_typesupport_introspection_c__MultiSpawn_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &my_first_package_msgs__srv__MultiSpawn_Request__rosidl_typesupport_introspection_c__MultiSpawn_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "my_first_package_msgs/srv/detail/multi_spawn__rosidl_typesupport_introspection_c.h"
// already included above
// #include "my_first_package_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "my_first_package_msgs/srv/detail/multi_spawn__functions.h"
// already included above
// #include "my_first_package_msgs/srv/detail/multi_spawn__struct.h"


// Include directives for member types
// Member `x`
// Member `y`
// Member `theta`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void my_first_package_msgs__srv__MultiSpawn_Response__rosidl_typesupport_introspection_c__MultiSpawn_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  my_first_package_msgs__srv__MultiSpawn_Response__init(message_memory);
}

void my_first_package_msgs__srv__MultiSpawn_Response__rosidl_typesupport_introspection_c__MultiSpawn_Response_fini_function(void * message_memory)
{
  my_first_package_msgs__srv__MultiSpawn_Response__fini(message_memory);
}

size_t my_first_package_msgs__srv__MultiSpawn_Response__rosidl_typesupport_introspection_c__size_function__MultiSpawn_Response__x(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * my_first_package_msgs__srv__MultiSpawn_Response__rosidl_typesupport_introspection_c__get_const_function__MultiSpawn_Response__x(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * my_first_package_msgs__srv__MultiSpawn_Response__rosidl_typesupport_introspection_c__get_function__MultiSpawn_Response__x(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void my_first_package_msgs__srv__MultiSpawn_Response__rosidl_typesupport_introspection_c__fetch_function__MultiSpawn_Response__x(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    my_first_package_msgs__srv__MultiSpawn_Response__rosidl_typesupport_introspection_c__get_const_function__MultiSpawn_Response__x(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void my_first_package_msgs__srv__MultiSpawn_Response__rosidl_typesupport_introspection_c__assign_function__MultiSpawn_Response__x(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    my_first_package_msgs__srv__MultiSpawn_Response__rosidl_typesupport_introspection_c__get_function__MultiSpawn_Response__x(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool my_first_package_msgs__srv__MultiSpawn_Response__rosidl_typesupport_introspection_c__resize_function__MultiSpawn_Response__x(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

size_t my_first_package_msgs__srv__MultiSpawn_Response__rosidl_typesupport_introspection_c__size_function__MultiSpawn_Response__y(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * my_first_package_msgs__srv__MultiSpawn_Response__rosidl_typesupport_introspection_c__get_const_function__MultiSpawn_Response__y(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * my_first_package_msgs__srv__MultiSpawn_Response__rosidl_typesupport_introspection_c__get_function__MultiSpawn_Response__y(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void my_first_package_msgs__srv__MultiSpawn_Response__rosidl_typesupport_introspection_c__fetch_function__MultiSpawn_Response__y(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    my_first_package_msgs__srv__MultiSpawn_Response__rosidl_typesupport_introspection_c__get_const_function__MultiSpawn_Response__y(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void my_first_package_msgs__srv__MultiSpawn_Response__rosidl_typesupport_introspection_c__assign_function__MultiSpawn_Response__y(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    my_first_package_msgs__srv__MultiSpawn_Response__rosidl_typesupport_introspection_c__get_function__MultiSpawn_Response__y(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool my_first_package_msgs__srv__MultiSpawn_Response__rosidl_typesupport_introspection_c__resize_function__MultiSpawn_Response__y(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

size_t my_first_package_msgs__srv__MultiSpawn_Response__rosidl_typesupport_introspection_c__size_function__MultiSpawn_Response__theta(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * my_first_package_msgs__srv__MultiSpawn_Response__rosidl_typesupport_introspection_c__get_const_function__MultiSpawn_Response__theta(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * my_first_package_msgs__srv__MultiSpawn_Response__rosidl_typesupport_introspection_c__get_function__MultiSpawn_Response__theta(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void my_first_package_msgs__srv__MultiSpawn_Response__rosidl_typesupport_introspection_c__fetch_function__MultiSpawn_Response__theta(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    my_first_package_msgs__srv__MultiSpawn_Response__rosidl_typesupport_introspection_c__get_const_function__MultiSpawn_Response__theta(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void my_first_package_msgs__srv__MultiSpawn_Response__rosidl_typesupport_introspection_c__assign_function__MultiSpawn_Response__theta(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    my_first_package_msgs__srv__MultiSpawn_Response__rosidl_typesupport_introspection_c__get_function__MultiSpawn_Response__theta(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool my_first_package_msgs__srv__MultiSpawn_Response__rosidl_typesupport_introspection_c__resize_function__MultiSpawn_Response__theta(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember my_first_package_msgs__srv__MultiSpawn_Response__rosidl_typesupport_introspection_c__MultiSpawn_Response_message_member_array[3] = {
  {
    "x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(my_first_package_msgs__srv__MultiSpawn_Response, x),  // bytes offset in struct
    NULL,  // default value
    my_first_package_msgs__srv__MultiSpawn_Response__rosidl_typesupport_introspection_c__size_function__MultiSpawn_Response__x,  // size() function pointer
    my_first_package_msgs__srv__MultiSpawn_Response__rosidl_typesupport_introspection_c__get_const_function__MultiSpawn_Response__x,  // get_const(index) function pointer
    my_first_package_msgs__srv__MultiSpawn_Response__rosidl_typesupport_introspection_c__get_function__MultiSpawn_Response__x,  // get(index) function pointer
    my_first_package_msgs__srv__MultiSpawn_Response__rosidl_typesupport_introspection_c__fetch_function__MultiSpawn_Response__x,  // fetch(index, &value) function pointer
    my_first_package_msgs__srv__MultiSpawn_Response__rosidl_typesupport_introspection_c__assign_function__MultiSpawn_Response__x,  // assign(index, value) function pointer
    my_first_package_msgs__srv__MultiSpawn_Response__rosidl_typesupport_introspection_c__resize_function__MultiSpawn_Response__x  // resize(index) function pointer
  },
  {
    "y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(my_first_package_msgs__srv__MultiSpawn_Response, y),  // bytes offset in struct
    NULL,  // default value
    my_first_package_msgs__srv__MultiSpawn_Response__rosidl_typesupport_introspection_c__size_function__MultiSpawn_Response__y,  // size() function pointer
    my_first_package_msgs__srv__MultiSpawn_Response__rosidl_typesupport_introspection_c__get_const_function__MultiSpawn_Response__y,  // get_const(index) function pointer
    my_first_package_msgs__srv__MultiSpawn_Response__rosidl_typesupport_introspection_c__get_function__MultiSpawn_Response__y,  // get(index) function pointer
    my_first_package_msgs__srv__MultiSpawn_Response__rosidl_typesupport_introspection_c__fetch_function__MultiSpawn_Response__y,  // fetch(index, &value) function pointer
    my_first_package_msgs__srv__MultiSpawn_Response__rosidl_typesupport_introspection_c__assign_function__MultiSpawn_Response__y,  // assign(index, value) function pointer
    my_first_package_msgs__srv__MultiSpawn_Response__rosidl_typesupport_introspection_c__resize_function__MultiSpawn_Response__y  // resize(index) function pointer
  },
  {
    "theta",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(my_first_package_msgs__srv__MultiSpawn_Response, theta),  // bytes offset in struct
    NULL,  // default value
    my_first_package_msgs__srv__MultiSpawn_Response__rosidl_typesupport_introspection_c__size_function__MultiSpawn_Response__theta,  // size() function pointer
    my_first_package_msgs__srv__MultiSpawn_Response__rosidl_typesupport_introspection_c__get_const_function__MultiSpawn_Response__theta,  // get_const(index) function pointer
    my_first_package_msgs__srv__MultiSpawn_Response__rosidl_typesupport_introspection_c__get_function__MultiSpawn_Response__theta,  // get(index) function pointer
    my_first_package_msgs__srv__MultiSpawn_Response__rosidl_typesupport_introspection_c__fetch_function__MultiSpawn_Response__theta,  // fetch(index, &value) function pointer
    my_first_package_msgs__srv__MultiSpawn_Response__rosidl_typesupport_introspection_c__assign_function__MultiSpawn_Response__theta,  // assign(index, value) function pointer
    my_first_package_msgs__srv__MultiSpawn_Response__rosidl_typesupport_introspection_c__resize_function__MultiSpawn_Response__theta  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers my_first_package_msgs__srv__MultiSpawn_Response__rosidl_typesupport_introspection_c__MultiSpawn_Response_message_members = {
  "my_first_package_msgs__srv",  // message namespace
  "MultiSpawn_Response",  // message name
  3,  // number of fields
  sizeof(my_first_package_msgs__srv__MultiSpawn_Response),
  false,  // has_any_key_member_
  my_first_package_msgs__srv__MultiSpawn_Response__rosidl_typesupport_introspection_c__MultiSpawn_Response_message_member_array,  // message members
  my_first_package_msgs__srv__MultiSpawn_Response__rosidl_typesupport_introspection_c__MultiSpawn_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  my_first_package_msgs__srv__MultiSpawn_Response__rosidl_typesupport_introspection_c__MultiSpawn_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t my_first_package_msgs__srv__MultiSpawn_Response__rosidl_typesupport_introspection_c__MultiSpawn_Response_message_type_support_handle = {
  0,
  &my_first_package_msgs__srv__MultiSpawn_Response__rosidl_typesupport_introspection_c__MultiSpawn_Response_message_members,
  get_message_typesupport_handle_function,
  &my_first_package_msgs__srv__MultiSpawn_Response__get_type_hash,
  &my_first_package_msgs__srv__MultiSpawn_Response__get_type_description,
  &my_first_package_msgs__srv__MultiSpawn_Response__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_my_first_package_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, my_first_package_msgs, srv, MultiSpawn_Response)() {
  if (!my_first_package_msgs__srv__MultiSpawn_Response__rosidl_typesupport_introspection_c__MultiSpawn_Response_message_type_support_handle.typesupport_identifier) {
    my_first_package_msgs__srv__MultiSpawn_Response__rosidl_typesupport_introspection_c__MultiSpawn_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &my_first_package_msgs__srv__MultiSpawn_Response__rosidl_typesupport_introspection_c__MultiSpawn_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "my_first_package_msgs/srv/detail/multi_spawn__rosidl_typesupport_introspection_c.h"
// already included above
// #include "my_first_package_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "my_first_package_msgs/srv/detail/multi_spawn__functions.h"
// already included above
// #include "my_first_package_msgs/srv/detail/multi_spawn__struct.h"


// Include directives for member types
// Member `info`
#include "service_msgs/msg/service_event_info.h"
// Member `info`
#include "service_msgs/msg/detail/service_event_info__rosidl_typesupport_introspection_c.h"
// Member `request`
// Member `response`
#include "my_first_package_msgs/srv/multi_spawn.h"
// Member `request`
// Member `response`
// already included above
// #include "my_first_package_msgs/srv/detail/multi_spawn__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void my_first_package_msgs__srv__MultiSpawn_Event__rosidl_typesupport_introspection_c__MultiSpawn_Event_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  my_first_package_msgs__srv__MultiSpawn_Event__init(message_memory);
}

void my_first_package_msgs__srv__MultiSpawn_Event__rosidl_typesupport_introspection_c__MultiSpawn_Event_fini_function(void * message_memory)
{
  my_first_package_msgs__srv__MultiSpawn_Event__fini(message_memory);
}

size_t my_first_package_msgs__srv__MultiSpawn_Event__rosidl_typesupport_introspection_c__size_function__MultiSpawn_Event__request(
  const void * untyped_member)
{
  const my_first_package_msgs__srv__MultiSpawn_Request__Sequence * member =
    (const my_first_package_msgs__srv__MultiSpawn_Request__Sequence *)(untyped_member);
  return member->size;
}

const void * my_first_package_msgs__srv__MultiSpawn_Event__rosidl_typesupport_introspection_c__get_const_function__MultiSpawn_Event__request(
  const void * untyped_member, size_t index)
{
  const my_first_package_msgs__srv__MultiSpawn_Request__Sequence * member =
    (const my_first_package_msgs__srv__MultiSpawn_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void * my_first_package_msgs__srv__MultiSpawn_Event__rosidl_typesupport_introspection_c__get_function__MultiSpawn_Event__request(
  void * untyped_member, size_t index)
{
  my_first_package_msgs__srv__MultiSpawn_Request__Sequence * member =
    (my_first_package_msgs__srv__MultiSpawn_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void my_first_package_msgs__srv__MultiSpawn_Event__rosidl_typesupport_introspection_c__fetch_function__MultiSpawn_Event__request(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const my_first_package_msgs__srv__MultiSpawn_Request * item =
    ((const my_first_package_msgs__srv__MultiSpawn_Request *)
    my_first_package_msgs__srv__MultiSpawn_Event__rosidl_typesupport_introspection_c__get_const_function__MultiSpawn_Event__request(untyped_member, index));
  my_first_package_msgs__srv__MultiSpawn_Request * value =
    (my_first_package_msgs__srv__MultiSpawn_Request *)(untyped_value);
  *value = *item;
}

void my_first_package_msgs__srv__MultiSpawn_Event__rosidl_typesupport_introspection_c__assign_function__MultiSpawn_Event__request(
  void * untyped_member, size_t index, const void * untyped_value)
{
  my_first_package_msgs__srv__MultiSpawn_Request * item =
    ((my_first_package_msgs__srv__MultiSpawn_Request *)
    my_first_package_msgs__srv__MultiSpawn_Event__rosidl_typesupport_introspection_c__get_function__MultiSpawn_Event__request(untyped_member, index));
  const my_first_package_msgs__srv__MultiSpawn_Request * value =
    (const my_first_package_msgs__srv__MultiSpawn_Request *)(untyped_value);
  *item = *value;
}

bool my_first_package_msgs__srv__MultiSpawn_Event__rosidl_typesupport_introspection_c__resize_function__MultiSpawn_Event__request(
  void * untyped_member, size_t size)
{
  my_first_package_msgs__srv__MultiSpawn_Request__Sequence * member =
    (my_first_package_msgs__srv__MultiSpawn_Request__Sequence *)(untyped_member);
  my_first_package_msgs__srv__MultiSpawn_Request__Sequence__fini(member);
  return my_first_package_msgs__srv__MultiSpawn_Request__Sequence__init(member, size);
}

size_t my_first_package_msgs__srv__MultiSpawn_Event__rosidl_typesupport_introspection_c__size_function__MultiSpawn_Event__response(
  const void * untyped_member)
{
  const my_first_package_msgs__srv__MultiSpawn_Response__Sequence * member =
    (const my_first_package_msgs__srv__MultiSpawn_Response__Sequence *)(untyped_member);
  return member->size;
}

const void * my_first_package_msgs__srv__MultiSpawn_Event__rosidl_typesupport_introspection_c__get_const_function__MultiSpawn_Event__response(
  const void * untyped_member, size_t index)
{
  const my_first_package_msgs__srv__MultiSpawn_Response__Sequence * member =
    (const my_first_package_msgs__srv__MultiSpawn_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void * my_first_package_msgs__srv__MultiSpawn_Event__rosidl_typesupport_introspection_c__get_function__MultiSpawn_Event__response(
  void * untyped_member, size_t index)
{
  my_first_package_msgs__srv__MultiSpawn_Response__Sequence * member =
    (my_first_package_msgs__srv__MultiSpawn_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void my_first_package_msgs__srv__MultiSpawn_Event__rosidl_typesupport_introspection_c__fetch_function__MultiSpawn_Event__response(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const my_first_package_msgs__srv__MultiSpawn_Response * item =
    ((const my_first_package_msgs__srv__MultiSpawn_Response *)
    my_first_package_msgs__srv__MultiSpawn_Event__rosidl_typesupport_introspection_c__get_const_function__MultiSpawn_Event__response(untyped_member, index));
  my_first_package_msgs__srv__MultiSpawn_Response * value =
    (my_first_package_msgs__srv__MultiSpawn_Response *)(untyped_value);
  *value = *item;
}

void my_first_package_msgs__srv__MultiSpawn_Event__rosidl_typesupport_introspection_c__assign_function__MultiSpawn_Event__response(
  void * untyped_member, size_t index, const void * untyped_value)
{
  my_first_package_msgs__srv__MultiSpawn_Response * item =
    ((my_first_package_msgs__srv__MultiSpawn_Response *)
    my_first_package_msgs__srv__MultiSpawn_Event__rosidl_typesupport_introspection_c__get_function__MultiSpawn_Event__response(untyped_member, index));
  const my_first_package_msgs__srv__MultiSpawn_Response * value =
    (const my_first_package_msgs__srv__MultiSpawn_Response *)(untyped_value);
  *item = *value;
}

bool my_first_package_msgs__srv__MultiSpawn_Event__rosidl_typesupport_introspection_c__resize_function__MultiSpawn_Event__response(
  void * untyped_member, size_t size)
{
  my_first_package_msgs__srv__MultiSpawn_Response__Sequence * member =
    (my_first_package_msgs__srv__MultiSpawn_Response__Sequence *)(untyped_member);
  my_first_package_msgs__srv__MultiSpawn_Response__Sequence__fini(member);
  return my_first_package_msgs__srv__MultiSpawn_Response__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember my_first_package_msgs__srv__MultiSpawn_Event__rosidl_typesupport_introspection_c__MultiSpawn_Event_message_member_array[3] = {
  {
    "info",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(my_first_package_msgs__srv__MultiSpawn_Event, info),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "request",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(my_first_package_msgs__srv__MultiSpawn_Event, request),  // bytes offset in struct
    NULL,  // default value
    my_first_package_msgs__srv__MultiSpawn_Event__rosidl_typesupport_introspection_c__size_function__MultiSpawn_Event__request,  // size() function pointer
    my_first_package_msgs__srv__MultiSpawn_Event__rosidl_typesupport_introspection_c__get_const_function__MultiSpawn_Event__request,  // get_const(index) function pointer
    my_first_package_msgs__srv__MultiSpawn_Event__rosidl_typesupport_introspection_c__get_function__MultiSpawn_Event__request,  // get(index) function pointer
    my_first_package_msgs__srv__MultiSpawn_Event__rosidl_typesupport_introspection_c__fetch_function__MultiSpawn_Event__request,  // fetch(index, &value) function pointer
    my_first_package_msgs__srv__MultiSpawn_Event__rosidl_typesupport_introspection_c__assign_function__MultiSpawn_Event__request,  // assign(index, value) function pointer
    my_first_package_msgs__srv__MultiSpawn_Event__rosidl_typesupport_introspection_c__resize_function__MultiSpawn_Event__request  // resize(index) function pointer
  },
  {
    "response",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(my_first_package_msgs__srv__MultiSpawn_Event, response),  // bytes offset in struct
    NULL,  // default value
    my_first_package_msgs__srv__MultiSpawn_Event__rosidl_typesupport_introspection_c__size_function__MultiSpawn_Event__response,  // size() function pointer
    my_first_package_msgs__srv__MultiSpawn_Event__rosidl_typesupport_introspection_c__get_const_function__MultiSpawn_Event__response,  // get_const(index) function pointer
    my_first_package_msgs__srv__MultiSpawn_Event__rosidl_typesupport_introspection_c__get_function__MultiSpawn_Event__response,  // get(index) function pointer
    my_first_package_msgs__srv__MultiSpawn_Event__rosidl_typesupport_introspection_c__fetch_function__MultiSpawn_Event__response,  // fetch(index, &value) function pointer
    my_first_package_msgs__srv__MultiSpawn_Event__rosidl_typesupport_introspection_c__assign_function__MultiSpawn_Event__response,  // assign(index, value) function pointer
    my_first_package_msgs__srv__MultiSpawn_Event__rosidl_typesupport_introspection_c__resize_function__MultiSpawn_Event__response  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers my_first_package_msgs__srv__MultiSpawn_Event__rosidl_typesupport_introspection_c__MultiSpawn_Event_message_members = {
  "my_first_package_msgs__srv",  // message namespace
  "MultiSpawn_Event",  // message name
  3,  // number of fields
  sizeof(my_first_package_msgs__srv__MultiSpawn_Event),
  false,  // has_any_key_member_
  my_first_package_msgs__srv__MultiSpawn_Event__rosidl_typesupport_introspection_c__MultiSpawn_Event_message_member_array,  // message members
  my_first_package_msgs__srv__MultiSpawn_Event__rosidl_typesupport_introspection_c__MultiSpawn_Event_init_function,  // function to initialize message memory (memory has to be allocated)
  my_first_package_msgs__srv__MultiSpawn_Event__rosidl_typesupport_introspection_c__MultiSpawn_Event_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t my_first_package_msgs__srv__MultiSpawn_Event__rosidl_typesupport_introspection_c__MultiSpawn_Event_message_type_support_handle = {
  0,
  &my_first_package_msgs__srv__MultiSpawn_Event__rosidl_typesupport_introspection_c__MultiSpawn_Event_message_members,
  get_message_typesupport_handle_function,
  &my_first_package_msgs__srv__MultiSpawn_Event__get_type_hash,
  &my_first_package_msgs__srv__MultiSpawn_Event__get_type_description,
  &my_first_package_msgs__srv__MultiSpawn_Event__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_my_first_package_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, my_first_package_msgs, srv, MultiSpawn_Event)() {
  my_first_package_msgs__srv__MultiSpawn_Event__rosidl_typesupport_introspection_c__MultiSpawn_Event_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, service_msgs, msg, ServiceEventInfo)();
  my_first_package_msgs__srv__MultiSpawn_Event__rosidl_typesupport_introspection_c__MultiSpawn_Event_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, my_first_package_msgs, srv, MultiSpawn_Request)();
  my_first_package_msgs__srv__MultiSpawn_Event__rosidl_typesupport_introspection_c__MultiSpawn_Event_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, my_first_package_msgs, srv, MultiSpawn_Response)();
  if (!my_first_package_msgs__srv__MultiSpawn_Event__rosidl_typesupport_introspection_c__MultiSpawn_Event_message_type_support_handle.typesupport_identifier) {
    my_first_package_msgs__srv__MultiSpawn_Event__rosidl_typesupport_introspection_c__MultiSpawn_Event_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &my_first_package_msgs__srv__MultiSpawn_Event__rosidl_typesupport_introspection_c__MultiSpawn_Event_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "my_first_package_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "my_first_package_msgs/srv/detail/multi_spawn__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers my_first_package_msgs__srv__detail__multi_spawn__rosidl_typesupport_introspection_c__MultiSpawn_service_members = {
  "my_first_package_msgs__srv",  // service namespace
  "MultiSpawn",  // service name
  // the following fields are initialized below on first access
  NULL,  // request message
  // my_first_package_msgs__srv__detail__multi_spawn__rosidl_typesupport_introspection_c__MultiSpawn_Request_message_type_support_handle,
  NULL,  // response message
  // my_first_package_msgs__srv__detail__multi_spawn__rosidl_typesupport_introspection_c__MultiSpawn_Response_message_type_support_handle
  NULL  // event_message
  // my_first_package_msgs__srv__detail__multi_spawn__rosidl_typesupport_introspection_c__MultiSpawn_Response_message_type_support_handle
};


static rosidl_service_type_support_t my_first_package_msgs__srv__detail__multi_spawn__rosidl_typesupport_introspection_c__MultiSpawn_service_type_support_handle = {
  0,
  &my_first_package_msgs__srv__detail__multi_spawn__rosidl_typesupport_introspection_c__MultiSpawn_service_members,
  get_service_typesupport_handle_function,
  &my_first_package_msgs__srv__MultiSpawn_Request__rosidl_typesupport_introspection_c__MultiSpawn_Request_message_type_support_handle,
  &my_first_package_msgs__srv__MultiSpawn_Response__rosidl_typesupport_introspection_c__MultiSpawn_Response_message_type_support_handle,
  &my_first_package_msgs__srv__MultiSpawn_Event__rosidl_typesupport_introspection_c__MultiSpawn_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    my_first_package_msgs,
    srv,
    MultiSpawn
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    my_first_package_msgs,
    srv,
    MultiSpawn
  ),
  &my_first_package_msgs__srv__MultiSpawn__get_type_hash,
  &my_first_package_msgs__srv__MultiSpawn__get_type_description,
  &my_first_package_msgs__srv__MultiSpawn__get_type_description_sources,
};

// Forward declaration of message type support functions for service members
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, my_first_package_msgs, srv, MultiSpawn_Request)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, my_first_package_msgs, srv, MultiSpawn_Response)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, my_first_package_msgs, srv, MultiSpawn_Event)(void);

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_my_first_package_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, my_first_package_msgs, srv, MultiSpawn)(void) {
  if (!my_first_package_msgs__srv__detail__multi_spawn__rosidl_typesupport_introspection_c__MultiSpawn_service_type_support_handle.typesupport_identifier) {
    my_first_package_msgs__srv__detail__multi_spawn__rosidl_typesupport_introspection_c__MultiSpawn_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)my_first_package_msgs__srv__detail__multi_spawn__rosidl_typesupport_introspection_c__MultiSpawn_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, my_first_package_msgs, srv, MultiSpawn_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, my_first_package_msgs, srv, MultiSpawn_Response)()->data;
  }
  if (!service_members->event_members_) {
    service_members->event_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, my_first_package_msgs, srv, MultiSpawn_Event)()->data;
  }

  return &my_first_package_msgs__srv__detail__multi_spawn__rosidl_typesupport_introspection_c__MultiSpawn_service_type_support_handle;
}
