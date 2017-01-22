(defun evenlength (l)
  (if (listp l) (evenp (length l)))
)

(defun oddlength (l)
  (if (listp l) (oddp (length l)))
)