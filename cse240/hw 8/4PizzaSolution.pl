/* Name: */
/* CSE 240 Fall 2023 */

/* Rule to calculate the number of each topping on a pizza */
pizza(P, S, B, O, M) :-
    /* The weight of each topping */
    Pepperoni = 4, Sausage = 10, Bacon = 6, Onion = 5, Mushroom = 7,
    /* The total weight of the toppings on the pizza */
    Total is P*Pepperoni + S*Sausage + B*Bacon + O*Onion + M*Mushroom,
    /* The total weight of the toppings must be exactly 40 ounces */
    Total = 40,
    /* The number of each topping must be a non-negative integer */
    P >= 0, S >= 0, B >= 0, O >= 0, M >= 0.