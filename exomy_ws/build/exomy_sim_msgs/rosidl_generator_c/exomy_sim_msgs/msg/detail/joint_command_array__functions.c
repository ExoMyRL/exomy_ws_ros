// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from exomy_sim_msgs:msg/JointCommandArray.idl
// generated code does not contain a copyright notice
#include "exomy_sim_msgs/msg/detail/joint_command_array__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `joint_command_array`
#include "exomy_sim_msgs/msg/detail/joint_command__functions.h"

bool
exomy_sim_msgs__msg__JointCommandArray__init(exomy_sim_msgs__msg__JointCommandArray * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    exomy_sim_msgs__msg__JointCommandArray__fini(msg);
    return false;
  }
  // joint_command_array
  if (!exomy_sim_msgs__msg__JointCommand__Sequence__init(&msg->joint_command_array, 0)) {
    exomy_sim_msgs__msg__JointCommandArray__fini(msg);
    return false;
  }
  return true;
}

void
exomy_sim_msgs__msg__JointCommandArray__fini(exomy_sim_msgs__msg__JointCommandArray * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // joint_command_array
  exomy_sim_msgs__msg__JointCommand__Sequence__fini(&msg->joint_command_array);
}

exomy_sim_msgs__msg__JointCommandArray *
exomy_sim_msgs__msg__JointCommandArray__create()
{
  exomy_sim_msgs__msg__JointCommandArray * msg = (exomy_sim_msgs__msg__JointCommandArray *)malloc(sizeof(exomy_sim_msgs__msg__JointCommandArray));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(exomy_sim_msgs__msg__JointCommandArray));
  bool success = exomy_sim_msgs__msg__JointCommandArray__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
exomy_sim_msgs__msg__JointCommandArray__destroy(exomy_sim_msgs__msg__JointCommandArray * msg)
{
  if (msg) {
    exomy_sim_msgs__msg__JointCommandArray__fini(msg);
  }
  free(msg);
}


bool
exomy_sim_msgs__msg__JointCommandArray__Sequence__init(exomy_sim_msgs__msg__JointCommandArray__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  exomy_sim_msgs__msg__JointCommandArray * data = NULL;
  if (size) {
    data = (exomy_sim_msgs__msg__JointCommandArray *)calloc(size, sizeof(exomy_sim_msgs__msg__JointCommandArray));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = exomy_sim_msgs__msg__JointCommandArray__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        exomy_sim_msgs__msg__JointCommandArray__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
exomy_sim_msgs__msg__JointCommandArray__Sequence__fini(exomy_sim_msgs__msg__JointCommandArray__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      exomy_sim_msgs__msg__JointCommandArray__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

exomy_sim_msgs__msg__JointCommandArray__Sequence *
exomy_sim_msgs__msg__JointCommandArray__Sequence__create(size_t size)
{
  exomy_sim_msgs__msg__JointCommandArray__Sequence * array = (exomy_sim_msgs__msg__JointCommandArray__Sequence *)malloc(sizeof(exomy_sim_msgs__msg__JointCommandArray__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = exomy_sim_msgs__msg__JointCommandArray__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
exomy_sim_msgs__msg__JointCommandArray__Sequence__destroy(exomy_sim_msgs__msg__JointCommandArray__Sequence * array)
{
  if (array) {
    exomy_sim_msgs__msg__JointCommandArray__Sequence__fini(array);
  }
  free(array);
}
