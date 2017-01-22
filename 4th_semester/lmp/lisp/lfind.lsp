(defun lfind (l e)
  (cond
    ((null l) nil)
    ((equal e (car l)) T)
    (T (lfind (cdr l) e))
  )
)