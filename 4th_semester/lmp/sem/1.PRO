domains
  object = integer
  list = integer*
  test = symbol
predicates
  find(object,list,test)
clauses
  find(_,[],_) :- fail.
  find(Object,[Head|Tail],">") :- Object>Head,write(Head).
  find(Object,[Head|Tail],"<") :- Object<Head,write(Head).
  find(Object,[Head|Tail],"=") :- Object=Head,write(Head).
  find(Object,[Head|Tail],"<=") :- Object<=Head,write(Head).
  find(Object,[Head|Tail],">=") :- Object>=Head,write(Head).
  find(Object,[Head|Tail],"<>") :- Object<>Head,write(Head).
  find(Object,[_|Tail],Operation) :- find(Object,Tail,Operation).