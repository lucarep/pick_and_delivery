; Auto-generated. Do not edit!


(cl:in-package prog_pkg-msg)


;//! \htmlinclude Arrived.msg.html

(cl:defclass <Arrived> (roslisp-msg-protocol:ros-message)
  ((reached_goal
    :reader reached_goal
    :initarg :reached_goal
    :type cl:integer
    :initform 0))
)

(cl:defclass Arrived (<Arrived>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Arrived>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Arrived)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name prog_pkg-msg:<Arrived> is deprecated: use prog_pkg-msg:Arrived instead.")))

(cl:ensure-generic-function 'reached_goal-val :lambda-list '(m))
(cl:defmethod reached_goal-val ((m <Arrived>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader prog_pkg-msg:reached_goal-val is deprecated.  Use prog_pkg-msg:reached_goal instead.")
  (reached_goal m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Arrived>) ostream)
  "Serializes a message object of type '<Arrived>"
  (cl:let* ((signed (cl:slot-value msg 'reached_goal)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 18446744073709551616) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Arrived>) istream)
  "Deserializes a message object of type '<Arrived>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'reached_goal) (cl:if (cl:< unsigned 9223372036854775808) unsigned (cl:- unsigned 18446744073709551616))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Arrived>)))
  "Returns string type for a message object of type '<Arrived>"
  "prog_pkg/Arrived")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Arrived)))
  "Returns string type for a message object of type 'Arrived"
  "prog_pkg/Arrived")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Arrived>)))
  "Returns md5sum for a message object of type '<Arrived>"
  "e06eb18f4448ce87af267960da61e43d")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Arrived)))
  "Returns md5sum for a message object of type 'Arrived"
  "e06eb18f4448ce87af267960da61e43d")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Arrived>)))
  "Returns full string definition for message of type '<Arrived>"
  (cl:format cl:nil "int64 reached_goal~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Arrived)))
  "Returns full string definition for message of type 'Arrived"
  (cl:format cl:nil "int64 reached_goal~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Arrived>))
  (cl:+ 0
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Arrived>))
  "Converts a ROS message object to a list"
  (cl:list 'Arrived
    (cl:cons ':reached_goal (reached_goal msg))
))
