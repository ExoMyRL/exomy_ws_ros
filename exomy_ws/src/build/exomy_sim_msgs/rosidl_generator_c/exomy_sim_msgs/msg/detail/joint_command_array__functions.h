// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from exomy_sim_msgs:msg/JointCommandArray.idl
// generated code does not contain a copyright notice

#ifndef EXOMY_SIM_MSGS__MSG__DETAIL__JOINT_COMMAND_ARRAY__FUNCTIONS_H_
#define EXOMY_SIM_MSGS__MSG__DETAIL__JOINT_COMMAND_ARRAY__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "exomy_sim_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "exomy_sim_msgs/msg/detail/joint_command_array__struct.h"

/// Initialize msg/JointCommandArray message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * exomy_sim_msgs__msg__JointCommandArray
 * )) before or use
 * exomy_sim_msgs__msg__JointCommandArray__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_exomy_sim_msgs
bool
exomy_sim_msgs__msg__JointCommandArray__init(exomy_sim_msgs__msg__JointCommandArray * msg);

/// Finalize msg/JointCommandArray message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_exomy_sim_msgs
void
exomy_sim_msgs__msg__JointCommandArray__fini(exomy_sim_msgs__msg__JointCommandArray * msg);

/// Create msg/JointCommandArray message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * exomy_sim_msgs__msg__JointCommandArray__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_exomy_sim_msgs
exomy_sim_msgs__msg__JointCommandArray *
exomy_sim_msgs__msg__JointCommandArray__create();

/// Destroy msg/JointCommandArray message.
/**
 * It calls
 * exomy_sim_msgs__msg__JointCommandArray__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_exomy_sim_msgs
void
exomy_sim_msgs__msg__JointCommandArray__destroy(exomy_sim_msgs__msg__JointCommandArray * msg);


/// Initialize array of msg/JointCommandArray messages.
/**
 * It allocates the memory for the number of elements and calls
 * exomy_sim_msgs__msg__JointCommandArray__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_exomy_sim_msgs
bool
exomy_sim_msgs__msg__JointCommandArray__Sequence__init(exomy_sim_msgs__msg__JointCommandArray__Sequence * array, size_t size);

/// Finalize array of msg/JointCommandArray messages.
/**
 * It calls
 * exomy_sim_msgs__msg__JointCommandArray__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_exomy_sim_msgs
void
exomy_sim_msgs__msg__JointCommandArray__Sequence__fini(exomy_sim_msgs__msg__JointCommandArray__Sequence * array);

/// Create array of msg/JointCommandArray messages.
/**
 * It allocates the memory for the array and calls
 * exomy_sim_msgs__msg__JointCommandArray__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_exomy_sim_msgs
exomy_sim_msgs__msg__JointCommandArray__Sequence *
exomy_sim_msgs__msg__JointCommandArray__Sequence__create(size_t size);

/// Destroy array of msg/JointCommandArray messages.
/**
 * It calls
 * exomy_sim_msgs__msg__JointCommandArray__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_exomy_sim_msgs
void
exomy_sim_msgs__msg__JointCommandArray__Sequence__destroy(exomy_sim_msgs__msg__JointCommandArray__Sequence * array);

#ifdef __cplusplus
}
#endif

#endif  // EXOMY_SIM_MSGS__MSG__DETAIL__JOINT_COMMAND_ARRAY__FUNCTIONS_H_
