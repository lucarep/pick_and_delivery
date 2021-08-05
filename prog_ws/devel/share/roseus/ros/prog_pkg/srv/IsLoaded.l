;; Auto-generated. Do not edit!


(when (boundp 'prog_pkg::IsLoaded)
  (if (not (find-package "PROG_PKG"))
    (make-package "PROG_PKG"))
  (shadow 'IsLoaded (find-package "PROG_PKG")))
(unless (find-package "PROG_PKG::ISLOADED")
  (make-package "PROG_PKG::ISLOADED"))
(unless (find-package "PROG_PKG::ISLOADEDREQUEST")
  (make-package "PROG_PKG::ISLOADEDREQUEST"))
(unless (find-package "PROG_PKG::ISLOADEDRESPONSE")
  (make-package "PROG_PKG::ISLOADEDRESPONSE"))

(in-package "ROS")





(defclass prog_pkg::IsLoadedRequest
  :super ros::object
  :slots ())

(defmethod prog_pkg::IsLoadedRequest
  (:init
   (&key
    )
   (send-super :init)
   self)
  (:serialization-length
   ()
   (+
    0
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;;
   self)
  )

(defclass prog_pkg::IsLoadedResponse
  :super ros::object
  :slots (_result ))

(defmethod prog_pkg::IsLoadedResponse
  (:init
   (&key
    ((:result __result) 0)
    )
   (send-super :init)
   (setq _result (round __result))
   self)
  (:result
   (&optional __result)
   (if __result (setq _result __result)) _result)
  (:serialization-length
   ()
   (+
    ;; int32 _result
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _result
       (write-long _result s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _result
     (setq _result (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(defclass prog_pkg::IsLoaded
  :super ros::object
  :slots ())

(setf (get prog_pkg::IsLoaded :md5sum-) "034a8e20d6a306665e3a5b340fab3f09")
(setf (get prog_pkg::IsLoaded :datatype-) "prog_pkg/IsLoaded")
(setf (get prog_pkg::IsLoaded :request) prog_pkg::IsLoadedRequest)
(setf (get prog_pkg::IsLoaded :response) prog_pkg::IsLoadedResponse)

(defmethod prog_pkg::IsLoadedRequest
  (:response () (instance prog_pkg::IsLoadedResponse :init)))

(setf (get prog_pkg::IsLoadedRequest :md5sum-) "034a8e20d6a306665e3a5b340fab3f09")
(setf (get prog_pkg::IsLoadedRequest :datatype-) "prog_pkg/IsLoadedRequest")
(setf (get prog_pkg::IsLoadedRequest :definition-)
      "---
int32 result
")

(setf (get prog_pkg::IsLoadedResponse :md5sum-) "034a8e20d6a306665e3a5b340fab3f09")
(setf (get prog_pkg::IsLoadedResponse :datatype-) "prog_pkg/IsLoadedResponse")
(setf (get prog_pkg::IsLoadedResponse :definition-)
      "---
int32 result
")



(provide :prog_pkg/IsLoaded "034a8e20d6a306665e3a5b340fab3f09")


