domains
  list=symbol*
predicates
  notfound(list,symbol)
  intersect(list,list)
  intersecti(list,list,list)
clauses
  notfound([],Sym) :- true.
  notfound([Head|Tail],Sym) :- Head<>Sym, notfound(Tail,Sym).
  intersect(L1,L2) :- intersecti(L1,L2,[]).
  intersecti([],[],L3) :- write(L3), nl.
  intersecti([],[Head|Tail],L3) :- notfound(L3,Head),
    L3New=[Head|L3],intersecti([],Tail,L3New).
  intersecti([],[Head|Tail],L3) :- intersecti([],Tail,L3).
  intersecti([Head|Tail],L2,L3) :- notfound(L3,Head),
    L3New=[Head|L3],intersecti(Tail,L2,L3New).
  intersecti([Head|Tail],L2,L3) :- intersecti(Tail,L2,L3).
