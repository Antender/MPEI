domains
  title=string
  authorname=string
  book=book(title,authorname,size)
  size=integer
  count=integer
  threshold=integer
  author=author(authorname,size,count)
  booklist=book*
  authorlist=author*
predicates
  findbooks(booklist,threshold)
  findbigbooks(booklist,booklist,threshold,authorlist)
  findauthor(booklist,authorname,threshold,size,count)
  notinauthors(authorlist,authorname)
  excludeauthor(authorlist,booklist,authorname,threshold,authorlist)
clauses
  findbooks(Books,Threshold) :-
     findbigbooks(Books,Books,Threshold,Authors),
     write(Authors),nl.
  findbigbooks([],_,_,Authorlist) :- Authorlist=[].
  findbigbooks([book(Title,Author,Size)|Tail],Books,Threshold,Authorlistnew) :-
    findbigbooks(Tail,Books,Threshold,Authorlist),
    excludeauthor(Authorlist,Books,Author,Threshold,Authorlistnew).
  findauthor([],_,_,Sizesum,Count) :- Sizesum=0,Count=0.
  findauthor([book(_,Author,Size)|Tail],Authorname,Threshold,Sizesumnew,Countnew) :-
    Author=Authorname,
    Size>Threshold,!,
    findauthor(Tail,Authorname,Threshold,Sizesum,Count),
    Sizesumnew=Size+Sizesum,Countnew=Count+1.
  findauthor([book(_,_,_)|Tail],Authorname,Threshold,Sizesum,Count) :-
    findauthor(Tail,Authorname,Threshold,Sizesum,Count).
  notinauthors([],_).
  notinauthors([author(Author,_,_)|Tail],Authorname) :-
    Author<>Authorname,notinauthors(Tail,Authorname).
  excludeauthor(Authorlist,Books,Author,Threshold,Authorlistnew) :-
    notinauthors(Authorlist,Author),
    findauthor(Books,Author,Threshold,Size,Count),
    Authorlistnew=[author(Author,Size,Count)|Authorlist].
  excludeauthor(Authorlist,Books,Author,Threshold,Authorlistnew) :-
    Authorlistnew=Authorlist.
