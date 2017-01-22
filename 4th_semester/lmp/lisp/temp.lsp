(defun max-atom (l s)
  (cadr (max-atom! l s))
)

(defun max-atom! (l s)
  (cond
    ((null l) nil)
    ((listp (car l)) (max-atom!! (cdr l) s (max-atom! (car l) s)))
    (T (max-atom!! (cdr l) s (cons (count-ins s (unpack (car l))) (car l))))
  )
)

(defun max-atom!! (l s max)
  (cond
    ((null l) max)
    ((listp (car l))
      (setq res (max-atom!! (car l) s max))
      (cond
         ((> (car res) (car max)) (max-atom!! (cdr l) s res))
         (T (max-atom!! (cdr l) s max))
      )
    )
    (T
      (setq cnt (count-ins s (unpack (car l))))
      (cond
        ((> cnt (car max)) (max-atom!! (cdr l) s (cons cnt (car l))))
        (T (max-atom!! (cdr l) s max))
      )
    )
  )
)

(defun count-ins (s l)
  (cond
    ((null l) 0)
    ((eq s (car l)) (+ 1 (count-ins s (cdr l))))
    (T (count-ins s (cdr l)))
  )
)