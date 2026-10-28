#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to my_first_package_msgs__msg__CmdAndPoseVel

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::CmdAndPoseVel::default())
  }
}

impl rosidl_runtime_rs::Message for CmdAndPoseVel {
  type RmwMsg = super::msg::rmw::CmdAndPoseVel;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        cmd_vel_linear: msg.cmd_vel_linear,
        cmd_vel_angular: msg.cmd_vel_angular,
        pose_x: msg.pose_x,
        pose_y: msg.pose_y,
        linear_vel: msg.linear_vel,
        angular_vel: msg.angular_vel,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      cmd_vel_linear: msg.cmd_vel_linear,
      cmd_vel_angular: msg.cmd_vel_angular,
      pose_x: msg.pose_x,
      pose_y: msg.pose_y,
      linear_vel: msg.linear_vel,
      angular_vel: msg.angular_vel,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      cmd_vel_linear: msg.cmd_vel_linear,
      cmd_vel_angular: msg.cmd_vel_angular,
      pose_x: msg.pose_x,
      pose_y: msg.pose_y,
      linear_vel: msg.linear_vel,
      angular_vel: msg.angular_vel,
    }
  }
}


