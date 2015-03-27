; Auto-generated. Do not edit!


(cl:in-package odometry4-msg)


;//! \htmlinclude MyOdometry4.msg.html

(cl:defclass <MyOdometry4> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (Rt_pulse
    :reader Rt_pulse
    :initarg :Rt_pulse
    :type cl:float
    :initform 0.0)
   (Lt_pulse
    :reader Lt_pulse
    :initarg :Lt_pulse
    :type cl:float
    :initform 0.0))
)

(cl:defclass MyOdometry4 (<MyOdometry4>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <MyOdometry4>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'MyOdometry4)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name odometry4-msg:<MyOdometry4> is deprecated: use odometry4-msg:MyOdometry4 instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <MyOdometry4>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader odometry4-msg:header-val is deprecated.  Use odometry4-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'Rt_pulse-val :lambda-list '(m))
(cl:defmethod Rt_pulse-val ((m <MyOdometry4>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader odometry4-msg:Rt_pulse-val is deprecated.  Use odometry4-msg:Rt_pulse instead.")
  (Rt_pulse m))

(cl:ensure-generic-function 'Lt_pulse-val :lambda-list '(m))
(cl:defmethod Lt_pulse-val ((m <MyOdometry4>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader odometry4-msg:Lt_pulse-val is deprecated.  Use odometry4-msg:Lt_pulse instead.")
  (Lt_pulse m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <MyOdometry4>) ostream)
  "Serializes a message object of type '<MyOdometry4>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'Rt_pulse))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'Lt_pulse))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <MyOdometry4>) istream)
  "Deserializes a message object of type '<MyOdometry4>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'Rt_pulse) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'Lt_pulse) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<MyOdometry4>)))
  "Returns string type for a message object of type '<MyOdometry4>"
  "odometry4/MyOdometry4")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'MyOdometry4)))
  "Returns string type for a message object of type 'MyOdometry4"
  "odometry4/MyOdometry4")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<MyOdometry4>)))
  "Returns md5sum for a message object of type '<MyOdometry4>"
  "207d0e59e086a2e869b58bd38f957849")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'MyOdometry4)))
  "Returns md5sum for a message object of type 'MyOdometry4"
  "207d0e59e086a2e869b58bd38f957849")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<MyOdometry4>)))
  "Returns full string definition for message of type '<MyOdometry4>"
  (cl:format cl:nil "Header header~%float64 Rt_pulse~%float64 Lt_pulse~%~% ~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'MyOdometry4)))
  "Returns full string definition for message of type 'MyOdometry4"
  (cl:format cl:nil "Header header~%float64 Rt_pulse~%float64 Lt_pulse~%~% ~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <MyOdometry4>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     8
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <MyOdometry4>))
  "Converts a ROS message object to a list"
  (cl:list 'MyOdometry4
    (cl:cons ':header (header msg))
    (cl:cons ':Rt_pulse (Rt_pulse msg))
    (cl:cons ':Lt_pulse (Lt_pulse msg))
))
