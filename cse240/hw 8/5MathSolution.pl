/* Name: */
/* CSE 240 Fall 2023 */

/* Define the foo function according to the given conditions */
foo(_, Y, Y) :- Y =< 0.
foo(X, _, X) :- X =< 0.
foo(X, Y, F) :- X >= Y, X1 is X - 1, Y1 is Y - 2, foo(X1, Y1, F1), F is X + F1.
foo(X, Y, F) :- X < Y, X1 is X - 2, Y1 is Y - 3, foo(X1, Y1, F1), F is Y + F1.