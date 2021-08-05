;; Auto-generated. Do not edit!


(when (boundp 'prog_pkg::Arrived)
  (if (not (find-package "PROG_PKG"))
    (make-package "PROG_PKG"))
  (shadow 'Arrived (find-package "PROG_PKG")))
(unless (find-package "PROG_PKG::ARRIVED")
  (make-package "PROG_PKG::ARRIVED"))

(in-package "ROS")
;;//! \htmlinclude Arrived.msg.html


(defclass prog_pkg::Arrived
  :super ros::object
  :slots (_reached_goal ))

(defmethod prog_pkg::Arrived
  (:init
   (&key
    ((:reached_goal __reached_goal) 0)
    )
   (send-super :init)
   (setq _reached_goal (round __reached_goal))
   self)
  (:reached_goal
   (&optional __reached_goal)
   (if __reached_goal (setq _reached_goal __reached_goal)) _reached_goal)
  (:serialization-length
   ()
   (+
    ;; int64 _reached_goal
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int64 _reached_goal
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _reached_goal (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _reached_goal) (= (length (_reached_goal . bv)) 2)) ;; bignum
              (write-long (ash (elt (_reached_goal . bv) 0) 0) s)
              (write-long (ash (elt (_reached_goal . bv) 1) -1) s))
             ((and (class _reached_goal) (= (length (_reached_goal . bv)) 1)) ;; big1
              (write-long (elt (_reached_goal . bv) 0) s)
              (write-long (if (>= _reached_goal 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _reached_goal s)(write-long (if (>= _reached_goal 0) 0 #xffffffff) s)))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int64 _reached_goal
#+(or :alpha :irix6 :x86_64)
      (setf _reached_goal (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _reached_goal (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;;
   self)
  )

(setf (get prog_pkg::Arrived :md5sum-) "e06eb18f4448ce87af267960da61e43d")
(setf (get prog_pkg::Arrived :datatype-) "prog_pkg/Arrived")
(setf (get prog_pkg::Arrived :definition-)
      "int64 reached_goal
")



(provide :prog_pkg/Arrived "e06eb18f4448ce87af267960da61e43d")


