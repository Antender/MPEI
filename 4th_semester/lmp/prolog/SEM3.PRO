domains
  surname = string
  debtvalue = real
database
  debts(surname,surname,debtvalue).
  unpayable(surname,surname,debtvalue).
predicates
  return_debt(surname,debtvalue)
  debtpay(surname,debtvalue,debtvalue,debtvalue)
  add_debt(surname,surname,debtvalue)
clauses
  return_debt(Surname,0) :-
    true.
  return_debt(Surname,Cash) :-
    debts(Surname,Lender,Value),
    debtpay(Surname,Value,Cash,CashNew),
    return_debt(Surname,CashNew).
  return_debt(Surname,Cash) :-
    write(Surname," has ",Cash," cash"),nl,
    true.
  debtpay(Surname,Value,Cash,CashNew) :-
    Cash>=Value,
    CashNew = Cash - Value,
    retract(debts(Surname,Lender,Value)),
    return_debt(Lender,Value). 
  debtpay(Surname,Value,Cash,CashNew) :-
    ValueNew = Value - Cash,
    CashNew = 0, 
    retract(debts(Surname,Lender,Value)),
    assert(debts(Surname,Lender,ValueNew)),
    return_debt(Lender,Cash).
  add_debt(Surname,Lender,Value) :-
    assert(debts(Surname,Lender,Value)).