# generated from
# rosidl_cmake/cmake/template/rosidl_cmake_export_typesupport_targets.cmake.in

set(_exported_typesupport_targets
  "__rosidl_typesupport_introspection_c:exomy_sim_msgs__rosidl_typesupport_introspection_c;__rosidl_typesupport_introspection_cpp:exomy_sim_msgs__rosidl_typesupport_introspection_cpp")

# populate exomy_sim_msgs_TARGETS_<suffix>
if(NOT _exported_typesupport_targets STREQUAL "")
  # loop over typesupport targets
  foreach(_tuple ${_exported_typesupport_targets})
    string(REPLACE ":" ";" _tuple "${_tuple}")
    list(GET _tuple 0 _suffix)
    list(GET _tuple 1 _target)

    set(_target "exomy_sim_msgs::${_target}")
    if(NOT TARGET "${_target}")
      # the exported target must exist
      message(WARNING "Package 'exomy_sim_msgs' exports the typesupport target '${_target}' which doesn't exist")
    else()
      list(APPEND exomy_sim_msgs_TARGETS${_suffix} "${_target}")
    endif()
  endforeach()
endif()
