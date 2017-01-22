(defun lunion (l l2 res)
  (cond
    ((null l) res)
    ((lfind l2 (car l)) (lunion (cdr l) l2 (cons (car l) res)))
    (T (lunion (cdr l) l2 res))
  )
)