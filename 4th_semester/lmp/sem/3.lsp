(deframeq answers)

(setq curslot 0)
(defun add_answer (keyword answer)
  (setq slot (car (fquery 'answers NIL '$VALUE answer)))
  (cond
    ((null slot)
      (fput 'answers curslot '$VALUE answer)
      (fput 'answers curslot 'keywords keyword)
      (setq curslot (+ curslot 1))
    )
    (T
      (fput 'answers slot '$VALUE answer)
      (fput 'answers slot 'keywords keyword)
    )
  )
)

(defun answer (question)
  (loop
    ((null question) '(answer not found))
    (setq res (fquery 'answers NIL 'keywords (car question)))
    ((not (null res)) (fget 'answers (car res)))
    (setq question (cdr question))
  )
)