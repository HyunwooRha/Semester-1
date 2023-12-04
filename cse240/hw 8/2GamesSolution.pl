/* Name: */
/* CSE 240 Fall 2023 */

/* Facts */
genre(planetDrop, action).
focus(planetDrop, gameplay).
focus(planetDrop, graphics).
element(gameplay, mechanics).
element(graphics, framerate).
element(graphics, rendering).
element(graphics, meshes).

/* Rules */
/* Question 2.1 */
game(X, Y) :- genre(X, Y); focus(X, Y).

/* Question 2.2 */
creation(X, Y) :- focus(X, Z), element(Z, Y).