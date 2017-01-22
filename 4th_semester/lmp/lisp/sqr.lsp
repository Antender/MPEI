(defun sqr! (a x n)
  (cond
     ((< n 5) (print (sqr! a (/ (+ (/ a x) x) 2) (+ n 1))))
     (T x)
  )
)

(defun sqr (a)
  (sqr! a (/ a 3) 1)
)