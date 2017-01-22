(defun flatten (input res)
  (cond
    ((null input) (reverse res))
    ((listp (car input)) (flatten (cdr input) (append (reverse (flatten (car input))) res)))
    (T (flatten (cdr input) (cons (car input) res)))
  )
)