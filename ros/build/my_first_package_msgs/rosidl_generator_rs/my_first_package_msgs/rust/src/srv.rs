#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};




// Corresponds to my_first_package_msgs__srv__MultiSpawn_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MultiSpawn_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub num: i64,

}



impl Default for MultiSpawn_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::MultiSpawn_Request::default())
  }
}

impl rosidl_runtime_rs::Message for MultiSpawn_Request {
  type RmwMsg = super::srv::rmw::MultiSpawn_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        num: msg.num,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      num: msg.num,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      num: msg.num,
    }
  }
}


// Corresponds to my_first_package_msgs__srv__MultiSpawn_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MultiSpawn_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub x: Vec<f64>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub y: Vec<f64>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub theta: Vec<f64>,

}



impl Default for MultiSpawn_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::MultiSpawn_Response::default())
  }
}

impl rosidl_runtime_rs::Message for MultiSpawn_Response {
  type RmwMsg = super::srv::rmw::MultiSpawn_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        x: msg.x.as_slice().into(),
        y: msg.y.as_slice().into(),
        theta: msg.theta.as_slice().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        x: msg.x.as_slice().into(),
        y: msg.y.as_slice().into(),
        theta: msg.theta.as_slice().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      x: msg.x.into(),
      y: msg.y.into(),
      theta: msg.theta.into(),
    }
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


