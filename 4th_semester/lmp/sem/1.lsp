(defun @FIND (object list test)
  (cond
    ((null test) (FIND! object list equal))
    (T (FIND! object list test))
  )
)

(defun FIND! (object list test)
  (cond
    ((null list) nil)
    ((funcall test object (car list)) (car list))
    (T (FIND! object (cdr list) test))
  )
)

(defun @FIND-IF (test list)
  (cond
    ((null list) nil)
    ((funcall test (car list)) (car list))
    (T (@FIND-IF test (cdr list)))
  )
)