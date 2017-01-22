domains
  list=integer*
predicates
  sum(list)
  sumi(list,integer,integer)
clauses
  sum(L) :- sumi(L,0,0).
  sumi([],Sum,Count) :- write(Sum), write(":"),write(Count), nl.
  sumi([Head|Tail],Sum,Count) :- SumNew=Sum+Head,CountNew=Count+1,sumi(Tail,SumNew,CountNew).
