/* Name: */
/* CSE 240 Fall 2023 */

/* Quicksort implementation where the second element is the pivot */

qsort2([], []).

qsort2([X], [X]).

qsort2([First, Pivot|Tail], Sorted):-
   split(First, Pivot, Tail, Less, Greater),
   
   qsort2(Less, SortedLess),
   qsort2(Greater, SortedGreater),

   append(SortedLess, [Pivot|SortedGreater], Sorted).

split(_, _, [], [], []).

split(First, Pivot, [Head|Tail], [First, Head|Less], Greater):-
   Head =< Pivot, split(First, Pivot, Tail, Less, Greater).
split(First, Pivot, [Head|Tail], Less, [Head|Greater]):-
   Head > Pivot, split(First, Pivot, Tail, Less, Greater).