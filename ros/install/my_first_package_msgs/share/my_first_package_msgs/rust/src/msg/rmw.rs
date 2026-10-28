#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "my_first_package_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__my_first_package_msgs__msg__CmdAndPoseVel() -> *const std::ffi::c_void;
}

#[link(name = "my_first_package_msgs__rosidl_generator_c")]
extern "C" {
    fn my_first_package_msgs__msg__CmdAndPoseVel__init(msg: *mut CmdAndPoseVel) -> bool;
    fn my_first_package_msgs__msg__CmdAndPoseVel__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<CmdAndPoseVel>, size: usize) -> bool;
    fn my_first_package_msgs__msg__CmdAndPoseVel__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<CmdAndPoseVel>);
    fn my_first_package_msgs__msg__CmdAndPoseVel__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<CmdAndPoseVel>, out_seq: *mut rosidl_runtime_rs::Sequence<CmdAndPoseVel>) -> bool;
}

// Corresponds to my_first_package_msgs__msg__CmdAndPoseVel
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct CmdAndPoseVel {

    // This member is not documented.
    #[allow(missing_docs)]
    pub cmd_vel_linear: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub cmd_vel_angular: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub pose_x: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub pose_y: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub linear_vel: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub angular_vel: f32,

}



impl Default for CmdAndPoseVel {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !my_first_package_msgs__msg__CmdAndPoseVel__init(&mut msg as *mut _) {
        panic!("Call to my_first_package_msgs__msg__CmdAndPoseVel__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for CmdAndPoseVel {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { my_first_package_msgs__msg__CmdAndPoseVel__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { my_first_package_msgs__msg__CmdAndPoseVel__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { my_first_package_msgs__msg__CmdAndPoseVel__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for CmdAndPoseVel {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for CmdAndPoseVel where Self: Sized {
  const TYPE_NAME: &'static str = "my_first_package_msgs/msg/CmdAndPoseVel";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__my_first_package_msgs__msg__CmdAndPoseVel() }
  }
}


