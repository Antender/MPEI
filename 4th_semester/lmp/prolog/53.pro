domains
  list=integer*
predicates
  max(list)
  maxi(list,integer)
clauses
  max([Head|Tail]) :- maxi(Tail,Head).
  maxi([],Max) :- write(Max), nl.
  maxi([Head|Tail],Max) :- Head>Max, maxi(Tail,Head).
  maxi([Head|Tail],Max) :- maxi(Tail,Max).