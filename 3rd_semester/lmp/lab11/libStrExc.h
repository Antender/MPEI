class StringTooLongException: exception {
  virtual const char* getMessage() const throw()
  {
    return "String is too long";
  }
} stringTooLongEx;

class StringIndexOutOfRangeException: exception {
  virtual const char* getMessage() const throw()
  {
    return "Incorrect index supplied";
  }
} stringIndexOutOfRangeEx;