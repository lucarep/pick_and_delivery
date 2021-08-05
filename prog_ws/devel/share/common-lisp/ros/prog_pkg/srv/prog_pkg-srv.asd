
(cl:in-package :asdf)

(defsystem "prog_pkg-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "IsLoaded" :depends-on ("_package_IsLoaded"))
    (:file "_package_IsLoaded" :depends-on ("_package"))
  ))