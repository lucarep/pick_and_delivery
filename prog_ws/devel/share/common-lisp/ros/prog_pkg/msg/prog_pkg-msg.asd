
(cl:in-package :asdf)

(defsystem "prog_pkg-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "Deliver" :depends-on ("_package_Deliver"))
    (:file "_package_Deliver" :depends-on ("_package"))
    (:file "Goal" :depends-on ("_package_Goal"))
    (:file "_package_Goal" :depends-on ("_package"))
    (:file "Picker" :depends-on ("_package_Picker"))
    (:file "_package_Picker" :depends-on ("_package"))
  ))