#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to custom_interfaces__msg__BoundingBox

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct BoundingBox {

    // This member is not documented.
    #[allow(missing_docs)]
    pub class_id: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub confidence: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub x1: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub y1: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub x2: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub y2: f32,

}



impl Default for BoundingBox {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::BoundingBox::default())
  }
}

impl rosidl_runtime_rs::Message for BoundingBox {
  type RmwMsg = super::msg::rmw::BoundingBox;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        class_id: msg.class_id,
        confidence: msg.confidence,
        x1: msg.x1,
        y1: msg.y1,
        x2: msg.x2,
        y2: msg.y2,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      class_id: msg.class_id,
      confidence: msg.confidence,
      x1: msg.x1,
      y1: msg.y1,
      x2: msg.x2,
      y2: msg.y2,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      class_id: msg.class_id,
      confidence: msg.confidence,
      x1: msg.x1,
      y1: msg.y1,
      x2: msg.x2,
      y2: msg.y2,
    }
  }
}


// Corresponds to custom_interfaces__msg__BoundingBoxArray

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct BoundingBoxArray {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::Header,


    // This member is not documented.
    #[allow(missing_docs)]
    pub boxes: Vec<super::msg::BoundingBox>,

}



impl Default for BoundingBoxArray {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::BoundingBoxArray::default())
  }
}

impl rosidl_runtime_rs::Message for BoundingBoxArray {
  type RmwMsg = super::msg::rmw::BoundingBoxArray;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        boxes: msg.boxes
          .into_iter()
          .map(|elem| super::msg::BoundingBox::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
        boxes: msg.boxes
          .iter()
          .map(|elem| super::msg::BoundingBox::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      boxes: msg.boxes
          .into_iter()
          .map(super::msg::BoundingBox::from_rmw_message)
          .collect(),
    }
  }
}


