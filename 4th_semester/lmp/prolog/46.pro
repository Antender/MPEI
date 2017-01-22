predicates
  sumsquares(integer,integer)
  squares(integer,integer,integer)
clauses
  sumsquares(M,N) :- M>N,squares(N,M,0).
  sumsquares(M,N) :- squares(M,N,0).
  squares(M,N,Sq) :- M<>N, Mnew=M+1,Sqnew=Sq+M*M,squares(Mnew,N,Sqnew).
  squares(M,N,Sq) :- M=N, Sqnew=Sq+M*M,write(Sqnew),nl.