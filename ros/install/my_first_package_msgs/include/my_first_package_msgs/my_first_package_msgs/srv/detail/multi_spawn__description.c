// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from my_first_package_msgs:srv/MultiSpawn.idl
// generated code does not contain a copyright notice

#include "my_first_package_msgs/srv/detail/multi_spawn__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_my_first_package_msgs
const rosidl_type_hash_t *
my_first_package_msgs__srv__MultiSpawn__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x69, 0xcb, 0x12, 0xb4, 0xf3, 0x6f, 0xad, 0xf0,
      0x81, 0x2f, 0xd2, 0xa4, 0x0e, 0xbe, 0x0f, 0x57,
      0x3e, 0x9e, 0xb9, 0x9b, 0x66, 0xa6, 0xfc, 0xd9,
      0x09, 0x72, 0xa1, 0x80, 0xda, 0xdc, 0x02, 0xbc,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_my_first_package_msgs
const rosidl_type_hash_t *
my_first_package_msgs__srv__MultiSpawn_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x45, 0x46, 0x1a, 0x3b, 0xc0, 0x79, 0x1c, 0xa6,
      0x0c, 0xc7, 0xda, 0x34, 0xb2, 0x58, 0xb0, 0x17,
      0x4a, 0xb6, 0xcf, 0x2f, 0x6a, 0xb8, 0x0f, 0x42,
      0x50, 0xc7, 0xb9, 0x6f, 0xd8, 0xaa, 0x34, 0x9c,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_my_first_package_msgs
const rosidl_type_hash_t *
my_first_package_msgs__srv__MultiSpawn_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x55, 0x26, 0x21, 0x64, 0x16, 0xde, 0xb9, 0x75,
      0xe7, 0x8a, 0x41, 0x7b, 0x05, 0x3c, 0x69, 0xdc,
      0x79, 0xce, 0x77, 0xb9, 0x30, 0xcf, 0xa3, 0xa3,
      0x87, 0xf6, 0x91, 0x6b, 0x24, 0xb4, 0x19, 0x7b,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_my_first_package_msgs
const rosidl_type_hash_t *
my_first_package_msgs__srv__MultiSpawn_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x0b, 0x28, 0x23, 0x3b, 0x15, 0x68, 0x69, 0xf0,
      0xa8, 0xe2, 0x67, 0x7b, 0x6b, 0xd5, 0x48, 0x6c,
      0x5c, 0x01, 0xe2, 0x9c, 0x02, 0xb8, 0xae, 0xa0,
      0xae, 0xe9, 0xca, 0xb0, 0x8b, 0x35, 0x78, 0xa8,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "service_msgs/msg/detail/service_event_info__functions.h"
#include "builtin_interfaces/msg/detail/time__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t service_msgs__msg__ServiceEventInfo__EXPECTED_HASH = {1, {
    0x41, 0xbc, 0xbb, 0xe0, 0x7a, 0x75, 0xc9, 0xb5,
    0x2b, 0xc9, 0x6b, 0xfd, 0x5c, 0x24, 0xd7, 0xf0,
    0xfc, 0x0a, 0x08, 0xc0, 0xcb, 0x79, 0x21, 0xb3,
    0x37, 0x3c, 0x57, 0x32, 0x34, 0x5a, 0x6f, 0x45,
  }};
#endif

static char my_first_package_msgs__srv__MultiSpawn__TYPE_NAME[] = "my_first_package_msgs/srv/MultiSpawn";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char my_first_package_msgs__srv__MultiSpawn_Event__TYPE_NAME[] = "my_first_package_msgs/srv/MultiSpawn_Event";
static char my_first_package_msgs__srv__MultiSpawn_Request__TYPE_NAME[] = "my_first_package_msgs/srv/MultiSpawn_Request";
static char my_first_package_msgs__srv__MultiSpawn_Response__TYPE_NAME[] = "my_first_package_msgs/srv/MultiSpawn_Response";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";

// Define type names, field names, and default values
static char my_first_package_msgs__srv__MultiSpawn__FIELD_NAME__request_message[] = "request_message";
static char my_first_package_msgs__srv__MultiSpawn__FIELD_NAME__response_message[] = "response_message";
static char my_first_package_msgs__srv__MultiSpawn__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field my_first_package_msgs__srv__MultiSpawn__FIELDS[] = {
  {
    {my_first_package_msgs__srv__MultiSpawn__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {my_first_package_msgs__srv__MultiSpawn_Request__TYPE_NAME, 44, 44},
    },
    {NULL, 0, 0},
  },
  {
    {my_first_package_msgs__srv__MultiSpawn__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {my_first_package_msgs__srv__MultiSpawn_Response__TYPE_NAME, 45, 45},
    },
    {NULL, 0, 0},
  },
  {
    {my_first_package_msgs__srv__MultiSpawn__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {my_first_package_msgs__srv__MultiSpawn_Event__TYPE_NAME, 42, 42},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription my_first_package_msgs__srv__MultiSpawn__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {my_first_package_msgs__srv__MultiSpawn_Event__TYPE_NAME, 42, 42},
    {NULL, 0, 0},
  },
  {
    {my_first_package_msgs__srv__MultiSpawn_Request__TYPE_NAME, 44, 44},
    {NULL, 0, 0},
  },
  {
    {my_first_package_msgs__srv__MultiSpawn_Response__TYPE_NAME, 45, 45},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
my_first_package_msgs__srv__MultiSpawn__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {my_first_package_msgs__srv__MultiSpawn__TYPE_NAME, 36, 36},
      {my_first_package_msgs__srv__MultiSpawn__FIELDS, 3, 3},
    },
    {my_first_package_msgs__srv__MultiSpawn__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = my_first_package_msgs__srv__MultiSpawn_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = my_first_package_msgs__srv__MultiSpawn_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = my_first_package_msgs__srv__MultiSpawn_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char my_first_package_msgs__srv__MultiSpawn_Request__FIELD_NAME__num[] = "num";

static rosidl_runtime_c__type_description__Field my_first_package_msgs__srv__MultiSpawn_Request__FIELDS[] = {
  {
    {my_first_package_msgs__srv__MultiSpawn_Request__FIELD_NAME__num, 3, 3},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT64,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
my_first_package_msgs__srv__MultiSpawn_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {my_first_package_msgs__srv__MultiSpawn_Request__TYPE_NAME, 44, 44},
      {my_first_package_msgs__srv__MultiSpawn_Request__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char my_first_package_msgs__srv__MultiSpawn_Response__FIELD_NAME__x[] = "x";
static char my_first_package_msgs__srv__MultiSpawn_Response__FIELD_NAME__y[] = "y";
static char my_first_package_msgs__srv__MultiSpawn_Response__FIELD_NAME__theta[] = "theta";

static rosidl_runtime_c__type_description__Field my_first_package_msgs__srv__MultiSpawn_Response__FIELDS[] = {
  {
    {my_first_package_msgs__srv__MultiSpawn_Response__FIELD_NAME__x, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_UNBOUNDED_SEQUENCE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {my_first_package_msgs__srv__MultiSpawn_Response__FIELD_NAME__y, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_UNBOUNDED_SEQUENCE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {my_first_package_msgs__srv__MultiSpawn_Response__FIELD_NAME__theta, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_UNBOUNDED_SEQUENCE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
my_first_package_msgs__srv__MultiSpawn_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {my_first_package_msgs__srv__MultiSpawn_Response__TYPE_NAME, 45, 45},
      {my_first_package_msgs__srv__MultiSpawn_Response__FIELDS, 3, 3},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char my_first_package_msgs__srv__MultiSpawn_Event__FIELD_NAME__info[] = "info";
static char my_first_package_msgs__srv__MultiSpawn_Event__FIELD_NAME__request[] = "request";
static char my_first_package_msgs__srv__MultiSpawn_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field my_first_package_msgs__srv__MultiSpawn_Event__FIELDS[] = {
  {
    {my_first_package_msgs__srv__MultiSpawn_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {my_first_package_msgs__srv__MultiSpawn_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {my_first_package_msgs__srv__MultiSpawn_Request__TYPE_NAME, 44, 44},
    },
    {NULL, 0, 0},
  },
  {
    {my_first_package_msgs__srv__MultiSpawn_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {my_first_package_msgs__srv__MultiSpawn_Response__TYPE_NAME, 45, 45},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription my_first_package_msgs__srv__MultiSpawn_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {my_first_package_msgs__srv__MultiSpawn_Request__TYPE_NAME, 44, 44},
    {NULL, 0, 0},
  },
  {
    {my_first_package_msgs__srv__MultiSpawn_Response__TYPE_NAME, 45, 45},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
my_first_package_msgs__srv__MultiSpawn_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {my_first_package_msgs__srv__MultiSpawn_Event__TYPE_NAME, 42, 42},
      {my_first_package_msgs__srv__MultiSpawn_Event__FIELDS, 3, 3},
    },
    {my_first_package_msgs__srv__MultiSpawn_Event__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = my_first_package_msgs__srv__MultiSpawn_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = my_first_package_msgs__srv__MultiSpawn_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "int64 num\n"
  "---\n"
  "float64[] x\n"
  "float64[] y\n"
  "float64[] theta";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
my_first_package_msgs__srv__MultiSpawn__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {my_first_package_msgs__srv__MultiSpawn__TYPE_NAME, 36, 36},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 53, 53},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
my_first_package_msgs__srv__MultiSpawn_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {my_first_package_msgs__srv__MultiSpawn_Request__TYPE_NAME, 44, 44},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
my_first_package_msgs__srv__MultiSpawn_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {my_first_package_msgs__srv__MultiSpawn_Response__TYPE_NAME, 45, 45},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
my_first_package_msgs__srv__MultiSpawn_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {my_first_package_msgs__srv__MultiSpawn_Event__TYPE_NAME, 42, 42},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
my_first_package_msgs__srv__MultiSpawn__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *my_first_package_msgs__srv__MultiSpawn__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *my_first_package_msgs__srv__MultiSpawn_Event__get_individual_type_description_source(NULL);
    sources[3] = *my_first_package_msgs__srv__MultiSpawn_Request__get_individual_type_description_source(NULL);
    sources[4] = *my_first_package_msgs__srv__MultiSpawn_Response__get_individual_type_description_source(NULL);
    sources[5] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
my_first_package_msgs__srv__MultiSpawn_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *my_first_package_msgs__srv__MultiSpawn_Request__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
my_first_package_msgs__srv__MultiSpawn_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *my_first_package_msgs__srv__MultiSpawn_Response__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
my_first_package_msgs__srv__MultiSpawn_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *my_first_package_msgs__srv__MultiSpawn_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *my_first_package_msgs__srv__MultiSpawn_Request__get_individual_type_description_source(NULL);
    sources[3] = *my_first_package_msgs__srv__MultiSpawn_Response__get_individual_type_description_source(NULL);
    sources[4] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
