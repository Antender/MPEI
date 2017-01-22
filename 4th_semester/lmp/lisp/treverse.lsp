(defun treverse (l res)
  (cond
    ((null l) res)
    ((listp (car l)) (treverse (cdr l) (cons (treverse (car l)) res)))
    (T (treverse (cdr l) (cons (car l) res)))
  )
)