// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from my_robot_interfaces:srv/ComputeRectangleArea.idl
// generated code does not contain a copyright notice
#include "my_robot_interfaces/srv/detail/compute_rectangle_area__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
my_robot_interfaces__srv__ComputeRectangleArea_Request__init(my_robot_interfaces__srv__ComputeRectangleArea_Request * msg)
{
  if (!msg) {
    return false;
  }
  // length
  // widht
  return true;
}

void
my_robot_interfaces__srv__ComputeRectangleArea_Request__fini(my_robot_interfaces__srv__ComputeRectangleArea_Request * msg)
{
  if (!msg) {
    return;
  }
  // length
  // widht
}

bool
my_robot_interfaces__srv__ComputeRectangleArea_Request__are_equal(const my_robot_interfaces__srv__ComputeRectangleArea_Request * lhs, const my_robot_interfaces__srv__ComputeRectangleArea_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // length
  if (lhs->length != rhs->length) {
    return false;
  }
  // widht
  if (lhs->widht != rhs->widht) {
    return false;
  }
  return true;
}

bool
my_robot_interfaces__srv__ComputeRectangleArea_Request__copy(
  const my_robot_interfaces__srv__ComputeRectangleArea_Request * input,
  my_robot_interfaces__srv__ComputeRectangleArea_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // length
  output->length = input->length;
  // widht
  output->widht = input->widht;
  return true;
}

my_robot_interfaces__srv__ComputeRectangleArea_Request *
my_robot_interfaces__srv__ComputeRectangleArea_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_robot_interfaces__srv__ComputeRectangleArea_Request * msg = (my_robot_interfaces__srv__ComputeRectangleArea_Request *)allocator.allocate(sizeof(my_robot_interfaces__srv__ComputeRectangleArea_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(my_robot_interfaces__srv__ComputeRectangleArea_Request));
  bool success = my_robot_interfaces__srv__ComputeRectangleArea_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
my_robot_interfaces__srv__ComputeRectangleArea_Request__destroy(my_robot_interfaces__srv__ComputeRectangleArea_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    my_robot_interfaces__srv__ComputeRectangleArea_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
my_robot_interfaces__srv__ComputeRectangleArea_Request__Sequence__init(my_robot_interfaces__srv__ComputeRectangleArea_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_robot_interfaces__srv__ComputeRectangleArea_Request * data = NULL;

  if (size) {
    data = (my_robot_interfaces__srv__ComputeRectangleArea_Request *)allocator.zero_allocate(size, sizeof(my_robot_interfaces__srv__ComputeRectangleArea_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = my_robot_interfaces__srv__ComputeRectangleArea_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        my_robot_interfaces__srv__ComputeRectangleArea_Request__fini(&data[i - 1]);
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
my_robot_interfaces__srv__ComputeRectangleArea_Request__Sequence__fini(my_robot_interfaces__srv__ComputeRectangleArea_Request__Sequence * array)
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
      my_robot_interfaces__srv__ComputeRectangleArea_Request__fini(&array->data[i]);
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

my_robot_interfaces__srv__ComputeRectangleArea_Request__Sequence *
my_robot_interfaces__srv__ComputeRectangleArea_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_robot_interfaces__srv__ComputeRectangleArea_Request__Sequence * array = (my_robot_interfaces__srv__ComputeRectangleArea_Request__Sequence *)allocator.allocate(sizeof(my_robot_interfaces__srv__ComputeRectangleArea_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = my_robot_interfaces__srv__ComputeRectangleArea_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
my_robot_interfaces__srv__ComputeRectangleArea_Request__Sequence__destroy(my_robot_interfaces__srv__ComputeRectangleArea_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    my_robot_interfaces__srv__ComputeRectangleArea_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
my_robot_interfaces__srv__ComputeRectangleArea_Request__Sequence__are_equal(const my_robot_interfaces__srv__ComputeRectangleArea_Request__Sequence * lhs, const my_robot_interfaces__srv__ComputeRectangleArea_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!my_robot_interfaces__srv__ComputeRectangleArea_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
my_robot_interfaces__srv__ComputeRectangleArea_Request__Sequence__copy(
  const my_robot_interfaces__srv__ComputeRectangleArea_Request__Sequence * input,
  my_robot_interfaces__srv__ComputeRectangleArea_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(my_robot_interfaces__srv__ComputeRectangleArea_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    my_robot_interfaces__srv__ComputeRectangleArea_Request * data =
      (my_robot_interfaces__srv__ComputeRectangleArea_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!my_robot_interfaces__srv__ComputeRectangleArea_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          my_robot_interfaces__srv__ComputeRectangleArea_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!my_robot_interfaces__srv__ComputeRectangleArea_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
my_robot_interfaces__srv__ComputeRectangleArea_Response__init(my_robot_interfaces__srv__ComputeRectangleArea_Response * msg)
{
  if (!msg) {
    return false;
  }
  // area
  return true;
}

void
my_robot_interfaces__srv__ComputeRectangleArea_Response__fini(my_robot_interfaces__srv__ComputeRectangleArea_Response * msg)
{
  if (!msg) {
    return;
  }
  // area
}

bool
my_robot_interfaces__srv__ComputeRectangleArea_Response__are_equal(const my_robot_interfaces__srv__ComputeRectangleArea_Response * lhs, const my_robot_interfaces__srv__ComputeRectangleArea_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // area
  if (lhs->area != rhs->area) {
    return false;
  }
  return true;
}

bool
my_robot_interfaces__srv__ComputeRectangleArea_Response__copy(
  const my_robot_interfaces__srv__ComputeRectangleArea_Response * input,
  my_robot_interfaces__srv__ComputeRectangleArea_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // area
  output->area = input->area;
  return true;
}

my_robot_interfaces__srv__ComputeRectangleArea_Response *
my_robot_interfaces__srv__ComputeRectangleArea_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_robot_interfaces__srv__ComputeRectangleArea_Response * msg = (my_robot_interfaces__srv__ComputeRectangleArea_Response *)allocator.allocate(sizeof(my_robot_interfaces__srv__ComputeRectangleArea_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(my_robot_interfaces__srv__ComputeRectangleArea_Response));
  bool success = my_robot_interfaces__srv__ComputeRectangleArea_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
my_robot_interfaces__srv__ComputeRectangleArea_Response__destroy(my_robot_interfaces__srv__ComputeRectangleArea_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    my_robot_interfaces__srv__ComputeRectangleArea_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
my_robot_interfaces__srv__ComputeRectangleArea_Response__Sequence__init(my_robot_interfaces__srv__ComputeRectangleArea_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_robot_interfaces__srv__ComputeRectangleArea_Response * data = NULL;

  if (size) {
    data = (my_robot_interfaces__srv__ComputeRectangleArea_Response *)allocator.zero_allocate(size, sizeof(my_robot_interfaces__srv__ComputeRectangleArea_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = my_robot_interfaces__srv__ComputeRectangleArea_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        my_robot_interfaces__srv__ComputeRectangleArea_Response__fini(&data[i - 1]);
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
my_robot_interfaces__srv__ComputeRectangleArea_Response__Sequence__fini(my_robot_interfaces__srv__ComputeRectangleArea_Response__Sequence * array)
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
      my_robot_interfaces__srv__ComputeRectangleArea_Response__fini(&array->data[i]);
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

my_robot_interfaces__srv__ComputeRectangleArea_Response__Sequence *
my_robot_interfaces__srv__ComputeRectangleArea_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_robot_interfaces__srv__ComputeRectangleArea_Response__Sequence * array = (my_robot_interfaces__srv__ComputeRectangleArea_Response__Sequence *)allocator.allocate(sizeof(my_robot_interfaces__srv__ComputeRectangleArea_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = my_robot_interfaces__srv__ComputeRectangleArea_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
my_robot_interfaces__srv__ComputeRectangleArea_Response__Sequence__destroy(my_robot_interfaces__srv__ComputeRectangleArea_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    my_robot_interfaces__srv__ComputeRectangleArea_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
my_robot_interfaces__srv__ComputeRectangleArea_Response__Sequence__are_equal(const my_robot_interfaces__srv__ComputeRectangleArea_Response__Sequence * lhs, const my_robot_interfaces__srv__ComputeRectangleArea_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!my_robot_interfaces__srv__ComputeRectangleArea_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
my_robot_interfaces__srv__ComputeRectangleArea_Response__Sequence__copy(
  const my_robot_interfaces__srv__ComputeRectangleArea_Response__Sequence * input,
  my_robot_interfaces__srv__ComputeRectangleArea_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(my_robot_interfaces__srv__ComputeRectangleArea_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    my_robot_interfaces__srv__ComputeRectangleArea_Response * data =
      (my_robot_interfaces__srv__ComputeRectangleArea_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!my_robot_interfaces__srv__ComputeRectangleArea_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          my_robot_interfaces__srv__ComputeRectangleArea_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!my_robot_interfaces__srv__ComputeRectangleArea_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
