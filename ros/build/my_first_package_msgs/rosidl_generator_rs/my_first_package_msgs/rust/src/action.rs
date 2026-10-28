
#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to my_first_package_msgs__action__DistTurtle_Goal

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct DistTurtle_Goal {

    // This member is not documented.
    #[allow(missing_docs)]
    pub linear_x: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub angular_z: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub dist: f32,

}



impl Default for DistTurtle_Goal {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::DistTurtle_Goal::default())
  }
}

impl rosidl_runtime_rs::Message for DistTurtle_Goal {
  type RmwMsg = super::action::rmw::DistTurtle_Goal;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        linear_x: msg.linear_x,
        angular_z: msg.angular_z,
        dist: msg.dist,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      linear_x: msg.linear_x,
      angular_z: msg.angular_z,
      dist: msg.dist,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      linear_x: msg.linear_x,
      angular_z: msg.angular_z,
      dist: msg.dist,
    }
  }
}


// Corresponds to my_first_package_msgs__action__DistTurtle_Result

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct DistTurtle_Result {

    // This member is not documented.
    #[allow(missing_docs)]
    pub pos_x: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub pos_y: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub pos_theta: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub result_dist: f32,

}



impl Default for DistTurtle_Result {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::DistTurtle_Result::default())
  }
}

impl rosidl_runtime_rs::Message for DistTurtle_Result {
  type RmwMsg = super::action::rmw::DistTurtle_Result;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        pos_x: msg.pos_x,
        pos_y: msg.pos_y,
        pos_theta: msg.pos_theta,
        result_dist: msg.result_dist,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      pos_x: msg.pos_x,
      pos_y: msg.pos_y,
      pos_theta: msg.pos_theta,
      result_dist: msg.result_dist,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      pos_x: msg.pos_x,
      pos_y: msg.pos_y,
      pos_theta: msg.pos_theta,
      result_dist: msg.result_dist,
    }
  }
}


// Corresponds to my_first_package_msgs__action__DistTurtle_Feedback

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct DistTurtle_Feedback {

    // This member is not documented.
    #[allow(missing_docs)]
    pub remained_dist: f32,

}



impl Default for DistTurtle_Feedback {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::DistTurtle_Feedback::default())
  }
}

impl rosidl_runtime_rs::Message for DistTurtle_Feedback {
  type RmwMsg = super::action::rmw::DistTurtle_Feedback;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        remained_dist: msg.remained_dist,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      remained_dist: msg.remained_dist,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      remained_dist: msg.remained_dist,
    }
  }
}


// Corresponds to my_first_package_msgs__action__DistTurtle_FeedbackMessage

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct DistTurtle_FeedbackMessage {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub feedback: super::action::DistTurtle_Feedback,

}



impl Default for DistTurtle_FeedbackMessage {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::DistTurtle_FeedbackMessage::default())
  }
}

impl rosidl_runtime_rs::Message for DistTurtle_FeedbackMessage {
  type RmwMsg = super::action::rmw::DistTurtle_FeedbackMessage;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Owned(msg.goal_id)).into_owned(),
        feedback: super::action::DistTurtle_Feedback::into_rmw_message(std::borrow::Cow::Owned(msg.feedback)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal_id)).into_owned(),
        feedback: super::action::DistTurtle_Feedback::into_rmw_message(std::borrow::Cow::Borrowed(&msg.feedback)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      goal_id: unique_identifier_msgs::msg::UUID::from_rmw_message(msg.goal_id),
      feedback: super::action::DistTurtle_Feedback::from_rmw_message(msg.feedback),
    }
  }
}






// Corresponds to my_first_package_msgs__action__DistTurtle_SendGoal_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct DistTurtle_SendGoal_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub goal: super::action::DistTurtle_Goal,

}



impl Default for DistTurtle_SendGoal_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::DistTurtle_SendGoal_Request::default())
  }
}

impl rosidl_runtime_rs::Message for DistTurtle_SendGoal_Request {
  type RmwMsg = super::action::rmw::DistTurtle_SendGoal_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Owned(msg.goal_id)).into_owned(),
        goal: super::action::DistTurtle_Goal::into_rmw_message(std::borrow::Cow::Owned(msg.goal)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal_id)).into_owned(),
        goal: super::action::DistTurtle_Goal::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      goal_id: unique_identifier_msgs::msg::UUID::from_rmw_message(msg.goal_id),
      goal: super::action::DistTurtle_Goal::from_rmw_message(msg.goal),
    }
  }
}


// Corresponds to my_first_package_msgs__action__DistTurtle_SendGoal_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct DistTurtle_SendGoal_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub accepted: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub stamp: builtin_interfaces::msg::Time,

}



impl Default for DistTurtle_SendGoal_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::DistTurtle_SendGoal_Response::default())
  }
}

impl rosidl_runtime_rs::Message for DistTurtle_SendGoal_Response {
  type RmwMsg = super::action::rmw::DistTurtle_SendGoal_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        accepted: msg.accepted,
        stamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Owned(msg.stamp)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      accepted: msg.accepted,
        stamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Borrowed(&msg.stamp)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      accepted: msg.accepted,
      stamp: builtin_interfaces::msg::Time::from_rmw_message(msg.stamp),
    }
  }
}


// Corresponds to my_first_package_msgs__action__DistTurtle_GetResult_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct DistTurtle_GetResult_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::UUID,

}



impl Default for DistTurtle_GetResult_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::DistTurtle_GetResult_Request::default())
  }
}

impl rosidl_runtime_rs::Message for DistTurtle_GetResult_Request {
  type RmwMsg = super::action::rmw::DistTurtle_GetResult_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Owned(msg.goal_id)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal_id)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      goal_id: unique_identifier_msgs::msg::UUID::from_rmw_message(msg.goal_id),
    }
  }
}


// Corresponds to my_first_package_msgs__action__DistTurtle_GetResult_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct DistTurtle_GetResult_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub status: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub result: super::action::DistTurtle_Result,

}



impl Default for DistTurtle_GetResult_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::DistTurtle_GetResult_Response::default())
  }
}

impl rosidl_runtime_rs::Message for DistTurtle_GetResult_Response {
  type RmwMsg = super::action::rmw::DistTurtle_GetResult_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        status: msg.status,
        result: super::action::DistTurtle_Result::into_rmw_message(std::borrow::Cow::Owned(msg.result)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      status: msg.status,
        result: super::action::DistTurtle_Result::into_rmw_message(std::borrow::Cow::Borrowed(&msg.result)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      status: msg.status,
      result: super::action::DistTurtle_Result::from_rmw_message(msg.result),
    }
  }
}






#[link(name = "my_first_package_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__my_first_package_msgs__action__DistTurtle_SendGoal() -> *const std::ffi::c_void;
}

// Corresponds to my_first_package_msgs__action__DistTurtle_SendGoal
#[allow(missing_docs, non_camel_case_types)]
pub struct DistTurtle_SendGoal;

impl rosidl_runtime_rs::Service for DistTurtle_SendGoal {
    type Request = DistTurtle_SendGoal_Request;
    type Response = DistTurtle_SendGoal_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__my_first_package_msgs__action__DistTurtle_SendGoal() }
    }
}




#[link(name = "my_first_package_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__my_first_package_msgs__action__DistTurtle_GetResult() -> *const std::ffi::c_void;
}

// Corresponds to my_first_package_msgs__action__DistTurtle_GetResult
#[allow(missing_docs, non_camel_case_types)]
pub struct DistTurtle_GetResult;

impl rosidl_runtime_rs::Service for DistTurtle_GetResult {
    type Request = DistTurtle_GetResult_Request;
    type Response = DistTurtle_GetResult_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__my_first_package_msgs__action__DistTurtle_GetResult() }
    }
}






#[link(name = "my_first_package_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_action_type_support_handle__my_first_package_msgs__action__DistTurtle() -> *const std::ffi::c_void;
}

// Corresponds to my_first_package_msgs__action__DistTurtle
#[allow(missing_docs, non_camel_case_types)]
pub struct DistTurtle;

impl rosidl_runtime_rs::Action for DistTurtle {
  // --- Associated types for client library users ---
  /// The goal message defined in the action definition.
  type Goal = DistTurtle_Goal;

  /// The result message defined in the action definition.
  type Result = DistTurtle_Result;

  /// The feedback message defined in the action definition.
  type Feedback = DistTurtle_Feedback;

  // --- Associated types for client library implementation ---
  /// The feedback message with generic fields which wraps the feedback message.
  type FeedbackMessage = super::action::DistTurtle_FeedbackMessage;

  /// The send_goal service using a wrapped version of the goal message as a request.
  type SendGoalService = super::action::DistTurtle_SendGoal;

  /// The generic service to cancel a goal.
  type CancelGoalService = action_msgs::srv::rmw::CancelGoal;

  /// The get_result service using a wrapped version of the result message as a response.
  type GetResultService = super::action::DistTurtle_GetResult;

  // --- Methods for client library implementation ---
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_action_type_support_handle__my_first_package_msgs__action__DistTurtle() }
  }

  fn create_goal_request(
    goal_id: &[u8; 16],
    goal: super::action::rmw::DistTurtle_Goal,
  ) -> super::action::rmw::DistTurtle_SendGoal_Request {
   super::action::rmw::DistTurtle_SendGoal_Request {
      goal_id: unique_identifier_msgs::msg::rmw::UUID { uuid: *goal_id },
      goal,
    }
  }

  fn split_goal_request(
    request: super::action::rmw::DistTurtle_SendGoal_Request,
  ) -> (
    [u8; 16],
   super::action::rmw::DistTurtle_Goal,
  ) {
    (request.goal_id.uuid, request.goal)
  }

  fn create_goal_response(
    accepted: bool,
    stamp: (i32, u32),
  ) -> super::action::rmw::DistTurtle_SendGoal_Response {
   super::action::rmw::DistTurtle_SendGoal_Response {
      accepted,
      stamp: builtin_interfaces::msg::rmw::Time {
        sec: stamp.0,
        nanosec: stamp.1,
      },
    }
  }

  fn get_goal_response_accepted(
    response: &super::action::rmw::DistTurtle_SendGoal_Response,
  ) -> bool {
    response.accepted
  }

  fn get_goal_response_stamp(
    response: &super::action::rmw::DistTurtle_SendGoal_Response,
  ) -> (i32, u32) {
    (response.stamp.sec, response.stamp.nanosec)
  }

  fn create_feedback_message(
    goal_id: &[u8; 16],
    feedback: super::action::rmw::DistTurtle_Feedback,
  ) -> super::action::rmw::DistTurtle_FeedbackMessage {
    let mut message = super::action::rmw::DistTurtle_FeedbackMessage::default();
    message.goal_id.uuid = *goal_id;
    message.feedback = feedback;
    message
  }

  fn split_feedback_message(
    feedback: super::action::rmw::DistTurtle_FeedbackMessage,
  ) -> (
    [u8; 16],
   super::action::rmw::DistTurtle_Feedback,
  ) {
    (feedback.goal_id.uuid, feedback.feedback)
  }

  fn create_result_request(
    goal_id: &[u8; 16],
  ) -> super::action::rmw::DistTurtle_GetResult_Request {
   super::action::rmw::DistTurtle_GetResult_Request {
      goal_id: unique_identifier_msgs::msg::rmw::UUID { uuid: *goal_id },
    }
  }

  fn get_result_request_uuid(
    request: &super::action::rmw::DistTurtle_GetResult_Request,
  ) -> &[u8; 16] {
    &request.goal_id.uuid
  }

  fn create_result_response(
    status: i8,
    result: super::action::rmw::DistTurtle_Result,
  ) -> super::action::rmw::DistTurtle_GetResult_Response {
   super::action::rmw::DistTurtle_GetResult_Response {
      status,
      result,
    }
  }

  fn split_result_response(
    response: super::action::rmw::DistTurtle_GetResult_Response
  ) -> (
    i8,
   super::action::rmw::DistTurtle_Result,
  ) {
    (response.status, response.result)
  }
}


