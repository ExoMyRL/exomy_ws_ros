// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from exomy_msgs:msg/RoverCommand.idl
// generated code does not contain a copyright notice
#include "exomy_msgs/msg/detail/rover_command__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


bool
exomy_msgs__msg__RoverCommand__init(exomy_msgs__msg__RoverCommand * msg)
{
  if (!msg) {
    return false;
  }
  // connected
  // motors_enabled
  // locomotion_mode
  // vel
  // steering
  return true;
}

void
exomy_msgs__msg__RoverCommand__fini(exomy_msgs__msg__RoverCommand * msg)
{
  if (!msg) {
    return;
  }
  // connected
  // motors_enabled
  // locomotion_mode
  // vel
  // steering
}

exomy_msgs__msg__RoverCommand *
exomy_msgs__msg__RoverCommand__create()
{
  exomy_msgs__msg__RoverCommand * msg = (exomy_msgs__msg__RoverCommand *)malloc(sizeof(exomy_msgs__msg__RoverCommand));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(exomy_msgs__msg__RoverCommand));
  bool success = exomy_msgs__msg__RoverCommand__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
exomy_msgs__msg__RoverCommand__destroy(exomy_msgs__msg__RoverCommand * msg)
{
  if (msg) {
    exomy_msgs__msg__RoverCommand__fini(msg);
  }
  free(msg);
}


bool
exomy_msgs__msg__RoverCommand__Sequence__init(exomy_msgs__msg__RoverCommand__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  exomy_msgs__msg__RoverCommand * data = NULL;
  if (size) {
    data = (exomy_msgs__msg__RoverCommand *)calloc(size, sizeof(exomy_msgs__msg__RoverCommand));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = exomy_msgs__msg__RoverCommand__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        exomy_msgs__msg__RoverCommand__fini(&data[i - 1]);
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
exomy_msgs__msg__RoverCommand__Sequence__fini(exomy_msgs__msg__RoverCommand__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      exomy_msgs__msg__RoverCommand__fini(&array->data[i]);
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

exomy_msgs__msg__RoverCommand__Sequence *
exomy_msgs__msg__RoverCommand__Sequence__create(size_t size)
{
  exomy_msgs__msg__RoverCommand__Sequence * array = (exomy_msgs__msg__RoverCommand__Sequence *)malloc(sizeof(exomy_msgs__msg__RoverCommand__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = exomy_msgs__msg__RoverCommand__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
exomy_msgs__msg__RoverCommand__Sequence__destroy(exomy_msgs__msg__RoverCommand__Sequence * array)
{
  if (array) {
    exomy_msgs__msg__RoverCommand__Sequence__fini(array);
  }
  free(array);
}
