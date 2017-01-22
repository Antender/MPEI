predicates
  gcdi(integer,integer,integer,integer)
  gcdf(integer,integer,integer)
  gcd(integer,integer)
  lcm(integer,integer)
  even(integer)
  odd(integer)
clauses
  even(A) :- bitand(A,1,B),B=0.
  odd(A) :- bitand(A,1,B),B=1.
  lcm(M,N) :- gcdf(M,N,Out), Res=M*N/Out, write(Res),nl. 
  gcd(M,N) :- gcdf(M,N,Out), write(Out),nl.
  gcdf(M,N,Out) :- M<0, Mnew=-M, gcdf(Mnew,N,Out).
  gcdf(M,N,Out) :- N<0, Nnew=-N, gcdf(M,Nnew,Out).
  gcdf(M,N,Out) :- gcdi(M,N,1,Res), Out=Res.
  gcdi(0,N,C,Res) :- Res=C*N.
  gcdi(M,0,C,Res) :- Res=C*M.
  gcdi(M,M,C,Res) :- Res=C*M.
  gcdi(M,N,C,Res) :- even(M),even(N),
    bitleft(C,1,Cnew),bitright(M,1,Mnew),
    bitright(N,1,Nnew),gcdi(Mnew,Nnew,Cnew,Res).
  gcdi(M,N,C,Res) :- even(M),bitright(M,1,Mnew),
    gcdi(Mnew,N,C,Res).
  gcdi(M,N,C,Res) :- even(N),bitright(N,1,Nnew),
    gcdi(M,Nnew,C,Res).
  gcdi(M,N,C,Res) :- N>M, Mnew1=N-M, 
    bitright(Mnew1,1,Mnew2), gcdi(Mnew2,M,C,Res).
  gcdi(M,N,C,Res) :- M>N, Mnew1=M-N,
    bitright(Mnew1,1,Mnew2), gcdi(Mnew2,N,C,Res). 