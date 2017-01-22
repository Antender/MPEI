(defun abs (x)
  (cond
    ((< x 0) (- 0 x))
    (T x)
  )
)

(defun agrange (accum fun start stop)
  (cond
    ((< start stop)
      (agrange
        (funcall fun accum start)
        fun
        (+ start 1)
        stop
      )
    )
    (T (funcall fun accum stop))
  )
)