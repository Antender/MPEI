domains
  list = symbol*
predicates
  palindrome(list)
  findrev(list,list,list)
  compare(list,list)
clauses
  palindrome(L1) :-
    findrev(L1,[],L2), compare(L1,L2).
  findrev([],L1,L1).
  findrev([Head|Tail],L1,L2) :-
    L1New=[Head|L1],findrev(Tail,L1New,L2).
  compare([],[]) :- true.
  compare([Head|L1],[Head|L2]) :-
    compare(L1,L2).
  compare([Head|L1],[NotHead|L2]) :-
    fail.