// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from exomy_sim_msgs:msg/JointCommand.idl
// generated code does not contain a copyright notice
#include "exomy_sim_msgs/msg/detail/joint_command__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `name`
// Member `mode`
#include "rosidl_runtime_c/string_functions.h"

bool
exomy_sim_msgs__msg__JointCommand__init(exomy_sim_msgs__msg__JointCommand * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    exomy_sim_msgs__msg__JointCommand__fini(msg);
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__init(&msg->name)) {
    exomy_sim_msgs__msg__JointCommand__fini(msg);
    return false;
  }
  // mode
  if (!rosidl_runtime_c__String__init(&msg->mode)) {
    exomy_sim_msgs__msg__JointCommand__fini(msg);
    return false;
  }
  // value
  return true;
}

void
exomy_sim_msgs__msg__JointCommand__fini(exomy_sim_msgs__msg__JointCommand * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // name
  rosidl_runtime_c__String__fini(&msg->name);
  // mode
  rosidl_runtime_c__String__fini(&msg->mode);
  // value
}

exomy_sim_msgs__msg__JointCommand *
exomy_sim_msgs__msg__JointCommand__create()
{
  exomy_sim_msgs__msg__JointCommand * msg = (exomy_sim_msgs__msg__JointCommand *)malloc(sizeof(exomy_sim_msgs__msg__JointCommand));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(exomy_sim_msgs__msg__JointCommand));
  bool success = exomy_sim_msgs__msg__JointCommand__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
exomy_sim_msgs__msg__JointCommand__destroy(exomy_sim_msgs__msg__JointCommand * msg)
{
  if (msg) {
    exomy_sim_msgs__msg__JointCommand__fini(msg);
  }
  free(msg);
}


bool
exomy_sim_msgs__msg__JointCommand__Sequence__init(exomy_sim_msgs__msg__JointCommand__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  exomy_sim_msgs__msg__JointCommand * data = NULL;
  if (size) {
    data = (exomy_sim_msgs__msg__JointCommand *)calloc(size, sizeof(exomy_sim_msgs__msg__JointCommand));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = exomy_sim_msgs__msg__JointCommand__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        exomy_sim_msgs__msg__JointCommand__fini(&data[i - 1]);
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
exomy_sim_msgs__msg__JointCommand__Sequence__fini(exomy_sim_msgs__msg__JointCommand__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      exomy_sim_msgs__msg__JointCommand__fini(&array->data[i]);
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

exomy_sim_msgs__msg__JointCommand__Sequence *
exomy_sim_msgs__msg__JointCommand__Sequence__create(size_t size)
{
  exomy_sim_msgs__msg__JointCommand__Sequence * array = (exomy_sim_msgs__msg__JointCommand__Sequence *)malloc(sizeof(exomy_sim_msgs__msg__JointCommand__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = exomy_sim_msgs__msg__JointCommand__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
exomy_sim_msgs__msg__JointCommand__Sequence__destroy(exomy_sim_msgs__msg__JointCommand__Sequence * array)
{
  if (array) {
    exomy_sim_msgs__msg__JointCommand__Sequence__fini(array);
  }
  free(array);
}
