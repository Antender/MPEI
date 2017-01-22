predicates
  fib(integer)
  fibi(integer,integer,integer)
clauses
  fib(0) :- write(0),nl.
  fib(N) :- fibi(0,1,N).
  fibi(A,B,1) :- write(B),nl.
  fibi(A,B,N) :- Nnew=N-1,Bnew=A+B, fibi(B,Bnew,Nnew). 