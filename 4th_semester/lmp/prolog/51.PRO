domains
  list = symbol*
predicates
  last(list)
clauses
  last([Head|Tail]) :- Tail=[], write(Head), nl.
  last([Head|Tail]) :- last(Tail).