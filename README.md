# Push_swap

A sorting algorithm project that requires you to sort a stack of integers using a very limited set of operations, aiming to do so in as few moves as possible.

## Project Goal

The goal is to sort a list of integers using two stacks (`a` and `b`) and a restricted set of operations:

You have 2 stacks named a and b.
- At the beginning:
- The stack a contains a random number of unique negative and/or positive
integers.
- The stack b is empty.

- `sa`, `sb`, `ss` — swap the top elements
- `pa`, `pb` — push between stacks
- `ra`, `rb`, `rr` — rotate upwards
- `rra`, `rrb`, `rrr` — rotate downwards

The program should output a sequence of operations that will sort the stack in the fewest possible moves.

## Learning Outcomes

- Designing and implementing sorting algorithms
- Understanding and applying stack data structures
- Optimizing algorithms under strict constraints
- Practicing memory management and input validation
- Writing clean, modular code within the 42 Norm restrictions

## Project Challenges

- You are not allowed to use standard sorting functions like `qsort`.
- You must sort using only allowed operations.
- Optimization matters—your performance is graded based on the number of operations used.
- You must handle invalid input (e.g., duplicates, non-numeric characters).
