# Proposition
- A proposition is declarative a statement that is either true or false
- It cannot be true and false at the same time
- Statements like ``x + 2 = 4`` are not propositions because they are not declarative
- Statements like ``1+1=2`` are propositions because they are declarative
- Statements like ``x + 2 = 4, where x is 2`` are propositions because they are declarative

## Propositional Variables
- A propositional variable is a variable that represents a proposition
- A statements can be represented by a propositional variable

# Compound Propositions
- Compound propositions are formed by combining propositions using logical operators
- These logical operators are called ``connectives``

## Connectives
- The ``negation`` of a proposition ``p`` is denoted by ``~p`` and is read as ``not p``
- The ``conjunction`` of propositions ``p`` and ``q`` is denoted by ``p ^ q`` and is read as ``p and q``
- The ``disjunction`` of propositions ``p`` and ``q`` is denoted by ``p v q`` and is read as ``p or q``
    - This is an inclusive operator
- The ``exclusive or`` of propositions ``p`` and ``q`` is denoted by ``p xor q`` and is read as ``p or q but not both``
  - This is the exclusive operator for ``disjunction``
  - Denoted by ``⨁``
- The ``implication`` of propositions ``p`` and ``q`` is denoted by ``p -> q`` and is read as ``if p then q``
- The ``biconditional`` of propositions ``p`` and ``q`` is denoted by ``p <-> q`` and is read as ``p if and only if q``
  - This can also be written as a conjunction of two implications
    - ``p <-> q`` is equivalent to ``(p -> q) ^ (q -> p)``
- The ``Contropositive`` of propositions ``p`` and ``q`` is denoted by ``~q -> ~p`` and is read as ``if not q then not p``

## Truth Tables
- Each row of a truth table gives us one possiblity for the truth values of the propositions.

### Truth Table for Negation
p | ~p
--|---
T | F
F | T

### Truth Table for Conjunction
p | q | p ^ q
--|---|------
T | T | T
T | F | F
F | T | F
F | F | F

### Truth Table for Disjunction
p | q | p v q
--|---|------
T | T | T
T | F | T
F | T | T
F | F | F

### Truth Table for Exclusive Or
p | q | p xor q
--|---|--------
T | T | F
T | F | T
F | T | T
F | F | F

### Truth Table for Implication
p | q | p -> q
--|---|------
T | T | T
T | F | F
F | T | T
F | F | T

### Truth Table for Biconditional
p | q | p <-> q
--|---|--------
T | T | T
T | F | F
F | T | F
F | F | T

### Truth Table for Contropositive
p | q | p->q | ~q -> ~p
--|---|------|----------
T | T | T    | T
T | F | F    | F
F | T | T    | T
F | F | T    | T

*Note that the truth table for implication and contropositive are the same*

# Logical Equivalences
- Two compound propositions are said to be logically equivalent if they have the same truth values for all possible truth values of their propositional variables
- We can use truth tables to determine if two compound propositions are logically equivalent