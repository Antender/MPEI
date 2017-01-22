(defun depth (l)
  (cond
    ((null l) 1)
    ((listp l) (+ 1 (apply 'max (mapcar 'depth l))))
    (T 0)
  )
)