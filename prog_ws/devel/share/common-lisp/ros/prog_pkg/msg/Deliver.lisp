; Auto-generated. Do not edit!


(cl:in-package prog_pkg-msg)


;//! \htmlinclude Deliver.msg.html

(cl:defclass <Deliver> (roslisp-msg-protocol:ros-message)
  ((x
    :reader x
    :initarg :x
    :type cl:float
    :initform 0.0)
   (y
    :reader y
    :initarg :y
    :type cl:float
    :initform 0.0)
   (theta
    :reader theta
    :initarg :theta
    :type cl:float
    :initform 0.0))
)

(cl:defclass Deliver (<Deliver>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Deliver>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Deliver)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name prog_pkg-msg:<Deliver> is deprecated: use prog_pkg-msg:Deliver instead.")))

(cl:ensure-generic-function 'x-val :lambda-list '(m))
(cl:defmethod x-val ((m <Deliver>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader prog_pkg-msg:x-val is deprecated.  Use prog_pkg-msg:x instead.")
  (x m))

(cl:ensure-generic-function 'y-val :lambda-list '(m))
(cl:defmethod y-val ((m <Deliver>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader prog_pkg-msg:y-val is deprecated.  Use prog_pkg-msg:y instead.")
  (y m))

(cl:ensure-generic-function 'theta-val :lambda-list '(m))
(cl:defmethod theta-val ((m <Deliver>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader prog_pkg-msg:theta-val is deprecated.  Use prog_pkg-msg:theta instead.")
  (theta m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Deliver>) ostream)
  "Serializes a message object of type '<Deliver>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'x))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'y))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'theta))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Deliver>) istream)
  "Deserializes a message object of type '<Deliver>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'x) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'y) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'theta) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Deliver>)))
  "Returns string type for a message object of type '<Deliver>"
  "prog_pkg/Deliver")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Deliver)))
  "Returns string type for a message object of type 'Deliver"
  "prog_pkg/Deliver")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Deliver>)))
  "Returns md5sum for a message object of type '<Deliver>"
  "a130bc60ee6513855dc62ea83fcc5b20")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Deliver)))
  "Returns md5sum for a message object of type 'Deliver"
  "a130bc60ee6513855dc62ea83fcc5b20")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Deliver>)))
  "Returns full string definition for message of type '<Deliver>"
  (cl:format cl:nil "float32 x~%float32 y~%float32 theta~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Deliver)))
  "Returns full string definition for message of type 'Deliver"
  (cl:format cl:nil "float32 x~%float32 y~%float32 theta~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Deliver>))
  (cl:+ 0
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Deliver>))
  "Converts a ROS message object to a list"
  (cl:list 'Deliver
    (cl:cons ':x (x msg))
    (cl:cons ':y (y msg))
    (cl:cons ':theta (theta msg))
))
