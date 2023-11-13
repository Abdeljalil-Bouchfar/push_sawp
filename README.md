# push_sawp
Create an algorithm to sort data on a stack in the fewest operations possible, using a limited set of instructions.

## Understand the project:
The goal is to sort in ascending order numbers into stack a. To do so you have the following operations at your disposal:

    - sa (swap a): Swap the first 2 elements at the top of stack a, Do nothing if there is only one or no elements.
    - sb (swap b): Swap the first 2 elements at the top of stack b, Do nothing if there is only one or no elements.
    - ss : sa and sb at the same time.
    - pa (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
    - pb (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
    - ra (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.
    - rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.
    - rr : ra and rb at the same time.
    - rra (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.
    - rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.
    - rrr : rra and rrb at the same time.

  - [Check this article to understand those operations in depth](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)

## My Solution
The goal of this project is to organize Stack A in as few actions as possible, so to achieve that, I use two approaches, one for small stacks (size ≤ 10) and the second for big Stacks (size > 10).

- Small Stack Approach:
  1. Find the smallest number in stack A and reverse from the closer side until using (**ra** or **rra**)it’s at the top of stack A then push to stack B using **pb,**  and repeat as long as stack A size is bigger than 3.
  2. When stack A size is equal to 3, sort it using (**sa**, **ra**, **rra**).
  3. Push all numbers from stack B back to stack A (**pa**).

- Big stack Approach:
  1. The first thing I do is the partitioning, which is done by specifying a frame (aka chunk size), and the max and med number in that frame.
  2. Push all numbers in the specified frame from Stack A to Stack B., Numbers that are bigger than Frame Medium go to the top of Stack B, and Numbers that are smaller than Frame Medium go to the bottom of Stack B, and repeat that until Stack A is empty.
  3. Find the biggest three numbers in stack B, push back to stack A with the right order, and repeat until stack B is empty.
