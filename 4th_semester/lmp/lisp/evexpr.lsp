(defun pr (x)
  (cond
    ((equal x '+) 0)
    ((equal x '-) 0)
    ((equal x '*) 1)
    ((equal x '/) 1)
  )
)
(defun arith (x b a)
  (cond
    ((equal x '+) (+ a b))
    ((equal x '-) (- a b))
    ((equal x '*) (* a b))
    ((equal x '/) (/ a b))
  )
)

(defun evexpr (in ns os dop)
  (cond
    (dop (progn
      (cond 
        ((and (car os) (<= (pr dop) (pr (car os)))) 
          (evexpr 
            in 
            (cons (arith (car os) (car ns) (cadr ns)) (cddr ns)) 
            (cdr os)
            dop
          )
        )
        (T
          (evexpr 
            in 
            ns 
            (cons dop os)
            nil
          )
        )
      )
    ))
    ((null (car in))
      (cond
         ((null (car os)) (car ns))
         (T (evexpr in (cons (arith (car os) (car ns) (cadr ns)) (cddr ns)) (cdr os)))
      )
    )
    ((listp (car in)) (evexpr (cdr in) (cons (evexpr (car in)) ns) os))
    ((numberp (car in)) (evexpr (cdr in) (cons (car in) ns) os))
    (T (cond
      ((and (car os) (<= (pr (car in)) (pr (car os))))
        (evexpr (cdr in) ns os (car in))  
      )
      (T (evexpr (cdr in) ns (append (list (car in)) os))
      )
    ))
  )
) 