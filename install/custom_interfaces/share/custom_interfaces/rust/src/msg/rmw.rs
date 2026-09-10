#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "custom_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__custom_interfaces__msg__BoundingBox() -> *const std::ffi::c_void;
}

#[link(name = "custom_interfaces__rosidl_generator_c")]
extern "C" {
    fn custom_interfaces__msg__BoundingBox__init(msg: *mut BoundingBox) -> bool;
    fn custom_interfaces__msg__BoundingBox__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<BoundingBox>, size: usize) -> bool;
    fn custom_interfaces__msg__BoundingBox__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<BoundingBox>);
    fn custom_interfaces__msg__BoundingBox__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<BoundingBox>, out_seq: *mut rosidl_runtime_rs::Sequence<BoundingBox>) -> bool;
}

// Corresponds to custom_interfaces__msg__BoundingBox
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
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
    unsafe {
      let mut msg = std::mem::zeroed();
      if !custom_interfaces__msg__BoundingBox__init(&mut msg as *mut _) {
        panic!("Call to custom_interfaces__msg__BoundingBox__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for BoundingBox {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { custom_interfaces__msg__BoundingBox__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { custom_interfaces__msg__BoundingBox__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { custom_interfaces__msg__BoundingBox__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for BoundingBox {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for BoundingBox where Self: Sized {
  const TYPE_NAME: &'static str = "custom_interfaces/msg/BoundingBox";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__custom_interfaces__msg__BoundingBox() }
  }
}


#[link(name = "custom_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__custom_interfaces__msg__BoundingBoxArray() -> *const std::ffi::c_void;
}

#[link(name = "custom_interfaces__rosidl_generator_c")]
extern "C" {
    fn custom_interfaces__msg__BoundingBoxArray__init(msg: *mut BoundingBoxArray) -> bool;
    fn custom_interfaces__msg__BoundingBoxArray__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<BoundingBoxArray>, size: usize) -> bool;
    fn custom_interfaces__msg__BoundingBoxArray__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<BoundingBoxArray>);
    fn custom_interfaces__msg__BoundingBoxArray__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<BoundingBoxArray>, out_seq: *mut rosidl_runtime_rs::Sequence<BoundingBoxArray>) -> bool;
}

// Corresponds to custom_interfaces__msg__BoundingBoxArray
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct BoundingBoxArray {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::rmw::Header,


    // This member is not documented.
    #[allow(missing_docs)]
    pub boxes: rosidl_runtime_rs::Sequence<super::super::msg::rmw::BoundingBox>,

}



impl Default for BoundingBoxArray {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !custom_interfaces__msg__BoundingBoxArray__init(&mut msg as *mut _) {
        panic!("Call to custom_interfaces__msg__BoundingBoxArray__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for BoundingBoxArray {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { custom_interfaces__msg__BoundingBoxArray__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { custom_interfaces__msg__BoundingBoxArray__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { custom_interfaces__msg__BoundingBoxArray__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for BoundingBoxArray {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for BoundingBoxArray where Self: Sized {
  const TYPE_NAME: &'static str = "custom_interfaces/msg/BoundingBoxArray";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__custom_interfaces__msg__BoundingBoxArray() }
  }
}


