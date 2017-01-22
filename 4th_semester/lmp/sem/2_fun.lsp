(defun @PRINTBLNK (list1 list2)
  (setq rewindl list2)
  (defun printblnk! (el sp)
    (mapc
      '(lambda (el_)
        (cond
          ((null sp) (setq sp rewindl))
          (T)
        )
        (spaces (car sp))
        (write el_)
        (setq sp (cdr sp))
      )
      el
    )
    (TERPRI 1) T
  )
  (printblnk! list1 list2)
)