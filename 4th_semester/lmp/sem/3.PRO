database
  answers(string,string)
predicates
  answer()
  findanswer()
  processtoken(string)
clauses
  findanswer() :-
    write("Enter your question:"),
    readln(Question),
    nl,
    processtoken(Question).
  processtoken("") :-
    write("No answer found").
  processtoken(S) :-
    fronttoken(S,Head,_),
    answers(Head,Result),
    write(Result),nl.
  processtoken(S) :-
    fronttoken(S,_,Tail),
    processtoken(Tail).
  answer() :-
    assert(answers("badass","Vasya")),
    findanswer().