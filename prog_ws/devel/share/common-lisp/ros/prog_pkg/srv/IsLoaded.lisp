; Auto-generated. Do not edit!


(cl:in-package prog_pkg-srv)


;//! \htmlinclude IsLoaded-request.msg.html

(cl:defclass <IsLoaded-request> (roslisp-msg-protocol:ros-message)
  ()
)

(cl:defclass IsLoaded-request (<IsLoaded-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <IsLoaded-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'IsLoaded-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name prog_pkg-srv:<IsLoaded-request> is deprecated: use prog_pkg-srv:IsLoaded-request instead.")))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <IsLoaded-request>) ostream)
  "Serializes a message object of type '<IsLoaded-request>"
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <IsLoaded-request>) istream)
  "Deserializes a message object of type '<IsLoaded-request>"
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<IsLoaded-request>)))
  "Returns string type for a service object of type '<IsLoaded-request>"
  "prog_pkg/IsLoadedRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'IsLoaded-request)))
  "Returns string type for a service object of type 'IsLoaded-request"
  "prog_pkg/IsLoadedRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<IsLoaded-request>)))
  "Returns md5sum for a message object of type '<IsLoaded-request>"
  "9b05623554ab950ed237d43d45f0b4dd")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'IsLoaded-request)))
  "Returns md5sum for a message object of type 'IsLoaded-request"
  "9b05623554ab950ed237d43d45f0b4dd")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<IsLoaded-request>)))
  "Returns full string definition for message of type '<IsLoaded-request>"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'IsLoaded-request)))
  "Returns full string definition for message of type 'IsLoaded-request"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <IsLoaded-request>))
  (cl:+ 0
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <IsLoaded-request>))
  "Converts a ROS message object to a list"
  (cl:list 'IsLoaded-request
))
;//! \htmlinclude IsLoaded-response.msg.html

(cl:defclass <IsLoaded-response> (roslisp-msg-protocol:ros-message)
  ((result
    :reader result
    :initarg :result
    :type cl:integer
    :initform 0))
)

(cl:defclass IsLoaded-response (<IsLoaded-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <IsLoaded-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'IsLoaded-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name prog_pkg-srv:<IsLoaded-response> is deprecated: use prog_pkg-srv:IsLoaded-response instead.")))

(cl:ensure-generic-function 'result-val :lambda-list '(m))
(cl:defmethod result-val ((m <IsLoaded-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader prog_pkg-srv:result-val is deprecated.  Use prog_pkg-srv:result instead.")
  (result m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <IsLoaded-response>) ostream)
  "Serializes a message object of type '<IsLoaded-response>"
  (cl:let* ((signed (cl:slot-value msg 'result)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 18446744073709551616) signed)))
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
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <IsLoaded-response>) istream)
  "Deserializes a message object of type '<IsLoaded-response>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'result) (cl:if (cl:< unsigned 9223372036854775808) unsigned (cl:- unsigned 18446744073709551616))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<IsLoaded-response>)))
  "Returns string type for a service object of type '<IsLoaded-response>"
  "prog_pkg/IsLoadedResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'IsLoaded-response)))
  "Returns string type for a service object of type 'IsLoaded-response"
  "prog_pkg/IsLoadedResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<IsLoaded-response>)))
  "Returns md5sum for a message object of type '<IsLoaded-response>"
  "9b05623554ab950ed237d43d45f0b4dd")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'IsLoaded-response)))
  "Returns md5sum for a message object of type 'IsLoaded-response"
  "9b05623554ab950ed237d43d45f0b4dd")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<IsLoaded-response>)))
  "Returns full string definition for message of type '<IsLoaded-response>"
  (cl:format cl:nil "int64 result~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'IsLoaded-response)))
  "Returns full string definition for message of type 'IsLoaded-response"
  (cl:format cl:nil "int64 result~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <IsLoaded-response>))
  (cl:+ 0
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <IsLoaded-response>))
  "Converts a ROS message object to a list"
  (cl:list 'IsLoaded-response
    (cl:cons ':result (result msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'IsLoaded)))
  'IsLoaded-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'IsLoaded)))
  'IsLoaded-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'IsLoaded)))
  "Returns string type for a service object of type '<IsLoaded>"
  "prog_pkg/IsLoaded")