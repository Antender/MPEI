(defun @PRINTBLNK (list1 list2)
  (setq rewindl list2)
  (defun printblnk! (el sp)
    (loop
      ((null el) (TERPRI 1) T)
      (cond
        ((null sp) (spaces (car rewindl)) (write (car el)) (setq el (cdr el)) (setq sp (cdr rewindl)))
        (T (spaces (car sp)) (write (car el)) (setq el (cdr el)) (setq sp (cdr sp)))
      )
    )
  )
  (printblnk! list1 list2)
)