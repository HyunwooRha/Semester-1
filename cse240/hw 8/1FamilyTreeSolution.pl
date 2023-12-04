/* Name: */
/* CSE 240 Fall 2023 */

/* Factbase for a family tree. It consists of facts and rules. */

/* Facts */

male(abe).
male(rob).
male(jim).
female(joy).
female(ana).

female(mae).
male(ben).
female(mia).
male(bud).
female(amy).
male(kai).
male(mac).
female(kim).
female(zoe).
female(val).
male(tex).
male(roy).
male(lee).
female(pam).

father_of(abe, ana). /* abe is the father of ana */
father_of(abe, rob). /* abe is the father of rob */
father_of(abe, jim). /* abe is the father of jim */
mother_of(joy, rob). /* joy is the mother of rob */
mother_of(joy, jim). /* joy is the mother of jim */
mother_of(joy, ana). /* joy is the mother of ana */

mother_of(mia, mac).
mother_of(mia, kim).

father_of(jim, mac).
father_of(jim, kim).

mother_of(mae, bud).
mother_of(mae, amy).

father_of(ben, bud).
father_of(ben, amy).

mother_of(ana, zoe).
mother_of(ana, val).
mother_of(ana, tex).
mother_of(ana, roy).

father_of(bud, zoe).
father_of(bud, val).
father_of(bud, tex).
father_of(bud, roy).

mother_of(amy, lee).
mother_of(amy, pam).

father_of(kai, lee).
father_of(kai, pam).


/* Complete the facts given in the diagram above */

/* Rules */
/* Question 1.1 */
is_male(X) :- male(X); father_of(X, _)

/* Question 1.2 */
is_female(X) :- female(X); mother_of(X, _).

/* Question 1.3 */
grandmother_of(X, Z) :- mother_of(X, Y), parent_of(Y, Z).

grandfather_of(X, Z) :- father_of(X, Y), parent_of(Y, Z).

/* Question 1.4 */
sibling_of(X, Y) :- parent_of(Z, X), parent_of(Z, Y), X \= Y.

/* Question 1.5 */
parent_of(X, Y) :- father_of(X, Y); mother_of(X, Y).

/* Question 1.6 */

descendent_of(X, Y) :- parent_of(Y, Z), descendent_of(X, Z).