(defun foldl (fun acc l)
  (cond
    ((cdr l) (foldl fun (funcall fun acc (car l)) (cdr l)))
    (T (funcall fun acc (car l)))
  )
)

(defun tfoldl (fun acc l)
    (cond
      ((null (car l)) acc)
      ((numberp (car l)) (tfoldl fun (funcall fun acc (car l)) (cdr l)))
      ((listp (car l))
        (tfoldl fun (tfoldl fun acc (car l)) (cdr l))
      )
      (T (tfoldl fun acc (cdr l)))
    )
)