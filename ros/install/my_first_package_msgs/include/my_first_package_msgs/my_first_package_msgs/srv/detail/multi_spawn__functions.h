// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from my_first_package_msgs:srv/MultiSpawn.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "my_first_package_msgs/srv/multi_spawn.h"


#ifndef MY_FIRST_PACKAGE_MSGS__SRV__DETAIL__MULTI_SPAWN__FUNCTIONS_H_
#define MY_FIRST_PACKAGE_MSGS__SRV__DETAIL__MULTI_SPAWN__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/action_type_support_struct.h"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_runtime_c/service_type_support_struct.h"
#include "rosidl_runtime_c/type_description/type_description__struct.h"
#include "rosidl_runtime_c/type_description/type_source__struct.h"
#include "rosidl_runtime_c/type_hash.h"
#include "rosidl_runtime_c/visibility_control.h"
#include "my_first_package_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "my_first_package_msgs/srv/detail/multi_spawn__struct.h"

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_my_first_package_msgs
const rosidl_type_hash_t *
my_first_package_msgs__srv__MultiSpawn__get_type_hash(
  const rosidl_service_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_my_first_package_msgs
const rosidl_runtime_c__type_description__TypeDescription *
my_first_package_msgs__srv__MultiSpawn__get_type_description(
  const rosidl_service_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_my_first_package_msgs
const rosidl_runtime_c__type_description__TypeSource *
my_first_package_msgs__srv__MultiSpawn__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_my_first_package_msgs
const rosidl_runtime_c__type_description__TypeSource__Sequence *
my_first_package_msgs__srv__MultiSpawn__get_type_description_sources(
  const rosidl_service_type_support_t * type_support);

/// Initialize srv/MultiSpawn message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * my_first_package_msgs__srv__MultiSpawn_Request
 * )) before or use
 * my_first_package_msgs__srv__MultiSpawn_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_my_first_package_msgs
bool
my_first_package_msgs__srv__MultiSpawn_Request__init(my_first_package_msgs__srv__MultiSpawn_Request * msg);

/// Finalize srv/MultiSpawn message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_first_package_msgs
void
my_first_package_msgs__srv__MultiSpawn_Request__fini(my_first_package_msgs__srv__MultiSpawn_Request * msg);

/// Create srv/MultiSpawn message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * my_first_package_msgs__srv__MultiSpawn_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_my_first_package_msgs
my_first_package_msgs__srv__MultiSpawn_Request *
my_first_package_msgs__srv__MultiSpawn_Request__create(void);

/// Destroy srv/MultiSpawn message.
/**
 * It calls
 * my_first_package_msgs__srv__MultiSpawn_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_first_package_msgs
void
my_first_package_msgs__srv__MultiSpawn_Request__destroy(my_first_package_msgs__srv__MultiSpawn_Request * msg);

/// Check for srv/MultiSpawn message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_first_package_msgs
bool
my_first_package_msgs__srv__MultiSpawn_Request__are_equal(const my_first_package_msgs__srv__MultiSpawn_Request * lhs, const my_first_package_msgs__srv__MultiSpawn_Request * rhs);

/// Copy a srv/MultiSpawn message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_first_package_msgs
bool
my_first_package_msgs__srv__MultiSpawn_Request__copy(
  const my_first_package_msgs__srv__MultiSpawn_Request * input,
  my_first_package_msgs__srv__MultiSpawn_Request * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_my_first_package_msgs
const rosidl_type_hash_t *
my_first_package_msgs__srv__MultiSpawn_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_my_first_package_msgs
const rosidl_runtime_c__type_description__TypeDescription *
my_first_package_msgs__srv__MultiSpawn_Request__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_my_first_package_msgs
const rosidl_runtime_c__type_description__TypeSource *
my_first_package_msgs__srv__MultiSpawn_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_my_first_package_msgs
const rosidl_runtime_c__type_description__TypeSource__Sequence *
my_first_package_msgs__srv__MultiSpawn_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of srv/MultiSpawn messages.
/**
 * It allocates the memory for the number of elements and calls
 * my_first_package_msgs__srv__MultiSpawn_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_first_package_msgs
bool
my_first_package_msgs__srv__MultiSpawn_Request__Sequence__init(my_first_package_msgs__srv__MultiSpawn_Request__Sequence * array, size_t size);

/// Finalize array of srv/MultiSpawn messages.
/**
 * It calls
 * my_first_package_msgs__srv__MultiSpawn_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_first_package_msgs
void
my_first_package_msgs__srv__MultiSpawn_Request__Sequence__fini(my_first_package_msgs__srv__MultiSpawn_Request__Sequence * array);

/// Create array of srv/MultiSpawn messages.
/**
 * It allocates the memory for the array and calls
 * my_first_package_msgs__srv__MultiSpawn_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_my_first_package_msgs
my_first_package_msgs__srv__MultiSpawn_Request__Sequence *
my_first_package_msgs__srv__MultiSpawn_Request__Sequence__create(size_t size);

/// Destroy array of srv/MultiSpawn messages.
/**
 * It calls
 * my_first_package_msgs__srv__MultiSpawn_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_first_package_msgs
void
my_first_package_msgs__srv__MultiSpawn_Request__Sequence__destroy(my_first_package_msgs__srv__MultiSpawn_Request__Sequence * array);

/// Check for srv/MultiSpawn message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_first_package_msgs
bool
my_first_package_msgs__srv__MultiSpawn_Request__Sequence__are_equal(const my_first_package_msgs__srv__MultiSpawn_Request__Sequence * lhs, const my_first_package_msgs__srv__MultiSpawn_Request__Sequence * rhs);

/// Copy an array of srv/MultiSpawn messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_first_package_msgs
bool
my_first_package_msgs__srv__MultiSpawn_Request__Sequence__copy(
  const my_first_package_msgs__srv__MultiSpawn_Request__Sequence * input,
  my_first_package_msgs__srv__MultiSpawn_Request__Sequence * output);

/// Initialize srv/MultiSpawn message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * my_first_package_msgs__srv__MultiSpawn_Response
 * )) before or use
 * my_first_package_msgs__srv__MultiSpawn_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_my_first_package_msgs
bool
my_first_package_msgs__srv__MultiSpawn_Response__init(my_first_package_msgs__srv__MultiSpawn_Response * msg);

/// Finalize srv/MultiSpawn message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_first_package_msgs
void
my_first_package_msgs__srv__MultiSpawn_Response__fini(my_first_package_msgs__srv__MultiSpawn_Response * msg);

/// Create srv/MultiSpawn message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * my_first_package_msgs__srv__MultiSpawn_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_my_first_package_msgs
my_first_package_msgs__srv__MultiSpawn_Response *
my_first_package_msgs__srv__MultiSpawn_Response__create(void);

/// Destroy srv/MultiSpawn message.
/**
 * It calls
 * my_first_package_msgs__srv__MultiSpawn_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_first_package_msgs
void
my_first_package_msgs__srv__MultiSpawn_Response__destroy(my_first_package_msgs__srv__MultiSpawn_Response * msg);

/// Check for srv/MultiSpawn message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_first_package_msgs
bool
my_first_package_msgs__srv__MultiSpawn_Response__are_equal(const my_first_package_msgs__srv__MultiSpawn_Response * lhs, const my_first_package_msgs__srv__MultiSpawn_Response * rhs);

/// Copy a srv/MultiSpawn message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_first_package_msgs
bool
my_first_package_msgs__srv__MultiSpawn_Response__copy(
  const my_first_package_msgs__srv__MultiSpawn_Response * input,
  my_first_package_msgs__srv__MultiSpawn_Response * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_my_first_package_msgs
const rosidl_type_hash_t *
my_first_package_msgs__srv__MultiSpawn_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_my_first_package_msgs
const rosidl_runtime_c__type_description__TypeDescription *
my_first_package_msgs__srv__MultiSpawn_Response__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_my_first_package_msgs
const rosidl_runtime_c__type_description__TypeSource *
my_first_package_msgs__srv__MultiSpawn_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_my_first_package_msgs
const rosidl_runtime_c__type_description__TypeSource__Sequence *
my_first_package_msgs__srv__MultiSpawn_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of srv/MultiSpawn messages.
/**
 * It allocates the memory for the number of elements and calls
 * my_first_package_msgs__srv__MultiSpawn_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_first_package_msgs
bool
my_first_package_msgs__srv__MultiSpawn_Response__Sequence__init(my_first_package_msgs__srv__MultiSpawn_Response__Sequence * array, size_t size);

/// Finalize array of srv/MultiSpawn messages.
/**
 * It calls
 * my_first_package_msgs__srv__MultiSpawn_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_first_package_msgs
void
my_first_package_msgs__srv__MultiSpawn_Response__Sequence__fini(my_first_package_msgs__srv__MultiSpawn_Response__Sequence * array);

/// Create array of srv/MultiSpawn messages.
/**
 * It allocates the memory for the array and calls
 * my_first_package_msgs__srv__MultiSpawn_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_my_first_package_msgs
my_first_package_msgs__srv__MultiSpawn_Response__Sequence *
my_first_package_msgs__srv__MultiSpawn_Response__Sequence__create(size_t size);

/// Destroy array of srv/MultiSpawn messages.
/**
 * It calls
 * my_first_package_msgs__srv__MultiSpawn_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_first_package_msgs
void
my_first_package_msgs__srv__MultiSpawn_Response__Sequence__destroy(my_first_package_msgs__srv__MultiSpawn_Response__Sequence * array);

/// Check for srv/MultiSpawn message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_first_package_msgs
bool
my_first_package_msgs__srv__MultiSpawn_Response__Sequence__are_equal(const my_first_package_msgs__srv__MultiSpawn_Response__Sequence * lhs, const my_first_package_msgs__srv__MultiSpawn_Response__Sequence * rhs);

/// Copy an array of srv/MultiSpawn messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_first_package_msgs
bool
my_first_package_msgs__srv__MultiSpawn_Response__Sequence__copy(
  const my_first_package_msgs__srv__MultiSpawn_Response__Sequence * input,
  my_first_package_msgs__srv__MultiSpawn_Response__Sequence * output);

/// Initialize srv/MultiSpawn message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * my_first_package_msgs__srv__MultiSpawn_Event
 * )) before or use
 * my_first_package_msgs__srv__MultiSpawn_Event__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_my_first_package_msgs
bool
my_first_package_msgs__srv__MultiSpawn_Event__init(my_first_package_msgs__srv__MultiSpawn_Event * msg);

/// Finalize srv/MultiSpawn message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_first_package_msgs
void
my_first_package_msgs__srv__MultiSpawn_Event__fini(my_first_package_msgs__srv__MultiSpawn_Event * msg);

/// Create srv/MultiSpawn message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * my_first_package_msgs__srv__MultiSpawn_Event__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_my_first_package_msgs
my_first_package_msgs__srv__MultiSpawn_Event *
my_first_package_msgs__srv__MultiSpawn_Event__create(void);

/// Destroy srv/MultiSpawn message.
/**
 * It calls
 * my_first_package_msgs__srv__MultiSpawn_Event__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_first_package_msgs
void
my_first_package_msgs__srv__MultiSpawn_Event__destroy(my_first_package_msgs__srv__MultiSpawn_Event * msg);

/// Check for srv/MultiSpawn message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_first_package_msgs
bool
my_first_package_msgs__srv__MultiSpawn_Event__are_equal(const my_first_package_msgs__srv__MultiSpawn_Event * lhs, const my_first_package_msgs__srv__MultiSpawn_Event * rhs);

/// Copy a srv/MultiSpawn message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_first_package_msgs
bool
my_first_package_msgs__srv__MultiSpawn_Event__copy(
  const my_first_package_msgs__srv__MultiSpawn_Event * input,
  my_first_package_msgs__srv__MultiSpawn_Event * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_my_first_package_msgs
const rosidl_type_hash_t *
my_first_package_msgs__srv__MultiSpawn_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_my_first_package_msgs
const rosidl_runtime_c__type_description__TypeDescription *
my_first_package_msgs__srv__MultiSpawn_Event__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_my_first_package_msgs
const rosidl_runtime_c__type_description__TypeSource *
my_first_package_msgs__srv__MultiSpawn_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_my_first_package_msgs
const rosidl_runtime_c__type_description__TypeSource__Sequence *
my_first_package_msgs__srv__MultiSpawn_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of srv/MultiSpawn messages.
/**
 * It allocates the memory for the number of elements and calls
 * my_first_package_msgs__srv__MultiSpawn_Event__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_first_package_msgs
bool
my_first_package_msgs__srv__MultiSpawn_Event__Sequence__init(my_first_package_msgs__srv__MultiSpawn_Event__Sequence * array, size_t size);

/// Finalize array of srv/MultiSpawn messages.
/**
 * It calls
 * my_first_package_msgs__srv__MultiSpawn_Event__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_first_package_msgs
void
my_first_package_msgs__srv__MultiSpawn_Event__Sequence__fini(my_first_package_msgs__srv__MultiSpawn_Event__Sequence * array);

/// Create array of srv/MultiSpawn messages.
/**
 * It allocates the memory for the array and calls
 * my_first_package_msgs__srv__MultiSpawn_Event__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_my_first_package_msgs
my_first_package_msgs__srv__MultiSpawn_Event__Sequence *
my_first_package_msgs__srv__MultiSpawn_Event__Sequence__create(size_t size);

/// Destroy array of srv/MultiSpawn messages.
/**
 * It calls
 * my_first_package_msgs__srv__MultiSpawn_Event__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_first_package_msgs
void
my_first_package_msgs__srv__MultiSpawn_Event__Sequence__destroy(my_first_package_msgs__srv__MultiSpawn_Event__Sequence * array);

/// Check for srv/MultiSpawn message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_first_package_msgs
bool
my_first_package_msgs__srv__MultiSpawn_Event__Sequence__are_equal(const my_first_package_msgs__srv__MultiSpawn_Event__Sequence * lhs, const my_first_package_msgs__srv__MultiSpawn_Event__Sequence * rhs);

/// Copy an array of srv/MultiSpawn messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_first_package_msgs
bool
my_first_package_msgs__srv__MultiSpawn_Event__Sequence__copy(
  const my_first_package_msgs__srv__MultiSpawn_Event__Sequence * input,
  my_first_package_msgs__srv__MultiSpawn_Event__Sequence * output);
#ifdef __cplusplus
}
#endif

#endif  // MY_FIRST_PACKAGE_MSGS__SRV__DETAIL__MULTI_SPAWN__FUNCTIONS_H_
