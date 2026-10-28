#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



#[link(name = "my_first_package_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__my_first_package_msgs__srv__MultiSpawn_Request() -> *const std::ffi::c_void;
}

#[link(name = "my_first_package_msgs__rosidl_generator_c")]
extern "C" {
    fn my_first_package_msgs__srv__MultiSpawn_Request__init(msg: *mut MultiSpawn_Request) -> bool;
    fn my_first_package_msgs__srv__MultiSpawn_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<MultiSpawn_Request>, size: usize) -> bool;
    fn my_first_package_msgs__srv__MultiSpawn_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<MultiSpawn_Request>);
    fn my_first_package_msgs__srv__MultiSpawn_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<MultiSpawn_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<MultiSpawn_Request>) -> bool;
}

// Corresponds to my_first_package_msgs__srv__MultiSpawn_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MultiSpawn_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub num: i64,

}



impl Default for MultiSpawn_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !my_first_package_msgs__srv__MultiSpawn_Request__init(&mut msg as *mut _) {
        panic!("Call to my_first_package_msgs__srv__MultiSpawn_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for MultiSpawn_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { my_first_package_msgs__srv__MultiSpawn_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { my_first_package_msgs__srv__MultiSpawn_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { my_first_package_msgs__srv__MultiSpawn_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for MultiSpawn_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for MultiSpawn_Request where Self: Sized {
  const TYPE_NAME: &'static str = "my_first_package_msgs/srv/MultiSpawn_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__my_first_package_msgs__srv__MultiSpawn_Request() }
  }
}


#[link(name = "my_first_package_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__my_first_package_msgs__srv__MultiSpawn_Response() -> *const std::ffi::c_void;
}

#[link(name = "my_first_package_msgs__rosidl_generator_c")]
extern "C" {
    fn my_first_package_msgs__srv__MultiSpawn_Response__init(msg: *mut MultiSpawn_Response) -> bool;
    fn my_first_package_msgs__srv__MultiSpawn_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<MultiSpawn_Response>, size: usize) -> bool;
    fn my_first_package_msgs__srv__MultiSpawn_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<MultiSpawn_Response>);
    fn my_first_package_msgs__srv__MultiSpawn_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<MultiSpawn_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<MultiSpawn_Response>) -> bool;
}

// Corresponds to my_first_package_msgs__srv__MultiSpawn_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MultiSpawn_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub x: rosidl_runtime_rs::Sequence<f64>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub y: rosidl_runtime_rs::Sequence<f64>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub theta: rosidl_runtime_rs::Sequence<f64>,

}



impl Default for MultiSpawn_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !my_first_package_msgs__srv__MultiSpawn_Response__init(&mut msg as *mut _) {
        panic!("Call to my_first_package_msgs__srv__MultiSpawn_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for MultiSpawn_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { my_first_package_msgs__srv__MultiSpawn_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { my_first_package_msgs__srv__MultiSpawn_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { my_first_package_msgs__srv__MultiSpawn_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for MultiSpawn_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for MultiSpawn_Response where Self: Sized {
  const TYPE_NAME: &'static str = "my_first_package_msgs/srv/MultiSpawn_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__my_first_package_msgs__srv__MultiSpawn_Response() }
  }
}






#[link(name = "my_first_package_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__my_first_package_msgs__srv__MultiSpawn() -> *const std::ffi::c_void;
}

// Corresponds to my_first_package_msgs__srv__MultiSpawn
#[allow(missing_docs, non_camel_case_types)]
pub struct MultiSpawn;

impl rosidl_runtime_rs::Service for MultiSpawn {
    type Request = MultiSpawn_Request;
    type Response = MultiSpawn_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__my_first_package_msgs__srv__MultiSpawn() }
    }
}


