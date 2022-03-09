// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from exomy_msgs:msg/Screen.idl
// generated code does not contain a copyright notice
#include "exomy_msgs/msg/detail/screen__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `state`
#include "rosidl_runtime_c/string_functions.h"

bool
exomy_msgs__msg__Screen__init(exomy_msgs__msg__Screen * msg)
{
  if (!msg) {
    return false;
  }
  // state
  if (!rosidl_runtime_c__String__init(&msg->state)) {
    exomy_msgs__msg__Screen__fini(msg);
    return false;
  }
  return true;
}

void
exomy_msgs__msg__Screen__fini(exomy_msgs__msg__Screen * msg)
{
  if (!msg) {
    return;
  }
  // state
  rosidl_runtime_c__String__fini(&msg->state);
}

exomy_msgs__msg__Screen *
exomy_msgs__msg__Screen__create()
{
  exomy_msgs__msg__Screen * msg = (exomy_msgs__msg__Screen *)malloc(sizeof(exomy_msgs__msg__Screen));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(exomy_msgs__msg__Screen));
  bool success = exomy_msgs__msg__Screen__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
exomy_msgs__msg__Screen__destroy(exomy_msgs__msg__Screen * msg)
{
  if (msg) {
    exomy_msgs__msg__Screen__fini(msg);
  }
  free(msg);
}


bool
exomy_msgs__msg__Screen__Sequence__init(exomy_msgs__msg__Screen__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  exomy_msgs__msg__Screen * data = NULL;
  if (size) {
    data = (exomy_msgs__msg__Screen *)calloc(size, sizeof(exomy_msgs__msg__Screen));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = exomy_msgs__msg__Screen__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        exomy_msgs__msg__Screen__fini(&data[i - 1]);
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
exomy_msgs__msg__Screen__Sequence__fini(exomy_msgs__msg__Screen__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      exomy_msgs__msg__Screen__fini(&array->data[i]);
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

exomy_msgs__msg__Screen__Sequence *
exomy_msgs__msg__Screen__Sequence__create(size_t size)
{
  exomy_msgs__msg__Screen__Sequence * array = (exomy_msgs__msg__Screen__Sequence *)malloc(sizeof(exomy_msgs__msg__Screen__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = exomy_msgs__msg__Screen__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
exomy_msgs__msg__Screen__Sequence__destroy(exomy_msgs__msg__Screen__Sequence * array)
{
  if (array) {
    exomy_msgs__msg__Screen__Sequence__fini(array);
  }
  free(array);
}
