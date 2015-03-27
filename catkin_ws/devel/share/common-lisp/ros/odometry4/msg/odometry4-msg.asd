
(cl:in-package :asdf)

(defsystem "odometry4-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :std_msgs-msg
)
  :components ((:file "_package")
    (:file "MyOdometry4" :depends-on ("_package_MyOdometry4"))
    (:file "_package_MyOdometry4" :depends-on ("_package"))
    (:file "MyOdometry4" :depends-on ("_package_MyOdometry4"))
    (:file "_package_MyOdometry4" :depends-on ("_package"))
  ))