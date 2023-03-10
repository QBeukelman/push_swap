
# push_swap

The core curriculum of all 42 schools worldwide includes a case study on sorting algorithms and their performances. This project involves the task of sorting a sequence of random numbers that are arranged in a stack data structure (stack_A), with the assistance of an empty auxiliary stack (stack B) and a set of specific stack operations. Our task specifies the operations allowed, which are described as follows:

> **`sa`** : **swap a** - Swap the first 2 elements at the top of stack_A. Do nothing if there is only one or no elements).

> **`sb`** : **swap b** - Swap the first 2 elements at the top of stack_B. Do nothing if there is only one or no elements).

> **`ss`** : **`sa`** and **`sb`** at the same time.

> **`pa`** : **push a** - take the first element at the top of b and put it at the top of a. Do nothing if B is empty.

> **`pb`** : **push b** - take the first element at the top of a and put it at the top of b. Do nothing if A is empty.

> **`ra`** : **rotate a** - shift up all elements of stack_A by 1. The first element becomes the last one.

> **`rb`** : **rotate b** - shift up all elements of stack_B by 1. The first element becomes the last one.

> **`rr`** : **`ra`** and **`rb`** at the same time.

> **`rra`** : **reverse rotate a** - shift down all elements of stack_A by 1. The last element becomes the first one.

> **`rrb`** : **reverse rotate b** - shift down all elements of stack_B by 1. The last element becomes the first one.

> **`rrr`** : **`rra`** and **`rrb`** at the same time.

---

<br />


## The push_swap program

The primary goal of `push_swap` is to output to `STDOUT` a series of instructions necessary to sort the **stack_A** provided as the program's argument. Each instruction should be followed by a line break (\n). The **stack_A** should be sorted such that its lowest element is at the top, and **stack_B** should be empty.

```shell
$ ARG='4 0 1 3 2'; ./push_swap $ARG

pb
pb
sa
ra
pa
pa
ra
```
---
<br />


# The Algorithm

## Sorting 3 Random Numbers

Upon investigation, I have discovered that there are five potential scenarios for arranging a set of three random numbers in Stack_A. My objective is to sort these numbers in ascending order, using no more than two steps. The specific actions I take will depend on the initial positions of the top, middle, and bottom numbers. To determine the appropriate course of action for each scenario, I compare the top to the middle number, the middle to the bottom number, and the bottom to the top number. Based on these comparisons, I determine which actions to take in order to sort the numbers correctly.

*source:* `Jamie Dawson` [Push_Swap: The least amount of moves with two stacks](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)

---

<br />


## Sorting 5 Random Numbers

We must now sort a set of five random numbers placed in Stack_A, while adhering to the limit of 12 actions. We can optimize our code by building on the logic used for sorting three random numbers. To accomplish this, we will move the first two numbers from the top of Stack_A to Stack_B, and bring them back once the three remaining numbers in Stack_A are sorted in ascending order.

*source:* `Jamie Dawson` [Push_Swap: The least amount of moves with two stacks](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)

---

<br />


## Sorting 100 Random Numbers `Bucket Sort Algorythm`

> **Moves** `+-1000`

![alt text](https://uploads-ssl.webflow.com/60255c87f21230edfb5fa38e/6405ec7eda2becbc0ecef677_push_swap%20100.gif)

To sort a list of 100 random numbers in less than the allowed 1500 operations, we will need to adopt a new approach. For this I have chosen to use a combination of the `Bucket Sort Algorythm` and the `Incertion Sort Algorythm`. To do so, first numbers are grouped into buckets of similar values from `stack_A`, into `stack_B`. Then the largest number, within the range of a bucket, is brought to the top of `stack_B`. Then the largest number is pushed from `stack B` to `stack A`.

#### First: Push stack_A to stack_B using Buckets

Let's assume a random list of 100 numbers 0-99, and the number of buckets to be 5.

> Bucket 1 is 0-19

> Bucket 5 is 80-99

> Note: With this implementation of bucket sort, we will need to index stack_A. This is because, when presented with outliers, the buckts loose effectiveness. E.g. Suppose the above list of random numbers from 0-99, and add one more integer to the stack, say 2,147,483,647. With the outlier, all values 0-99 will be present in the first bucket. Indexing stack_A, and determining the bucket values using the index, will correctly handle outliers.

**Step 1:** Traverse stack_A in the forward direction to find the fist occurance of a number in bracket 1. Let's call this **hold_first**.

**Step 2:** Traverse stack_A in the backward direction to find the fist occurance of a number in bracket 1. Call this **hold_second**.

**Step 3:** Compare the number of operations needed to move hold_first and hold_second, respectivly, to the top of stack_A. If a number occures in the first half of the list, we can simply perform the **RA** operation untill the number surfaces. If the number occurs in the second half of the list, we can perform the **RRA** operation untill this number surfaces. To do so, first, we find the center of the list by dividing its length by 2. Then, given the positions of hold_first and hold_socond, determine which is nearest their respective edge of the list. Push your choise of hold_first or hold_second, now at the top of stack_A, to the op of stack_B.

#### Second: Push stack_B back to stack_A starting with the highest value

Once the stack_A is empty, all numbers should be in their respective groups contained in stack_B. We will now employ the `Incertion Sort Algorythm` to push each node back to stack_A, starting from the highest value. Search for the highest number in stack_B, within the range of the group. Bring the highest number to the top of stack_B using, first the RB operation, then push this number to the top of stack_A. Don't forget to keep the grouped stack_B in order, by reversing the changes using the RRB operation to place any displaced number back to their respective groups. Repeat this process for each group and untill stack_B is empty. Voil??, the list of 100 random numbers is sorted.

*source:* `Jamie Dawson` [Push_Swap: The least amount of moves with two stacks](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)

---

<br />


## Sorting 500 Random Numbers `Radix Sort Algorythm`

> **Moves** `+-5000`

![alt text](https://uploads-ssl.webflow.com/60255c87f21230edfb5fa38e/6405eba6d9b73ba37d36ab0c_push_swap%20500.gif)

With the above `Bucket Sort Algorythm`, I was not able to sort a list of 500 integers with `11500 operations`, which coincidentally, is the maximum number of moves for this section of the assignemnt. To sort a list of 500 random numbers in less than the allowed 11500 operations, we will need to adopt a new approach.

For this I have chosen to use the `Radix Sort Algorythm`, for it is both stable and effecient with large lists. The time complexity of radix sort is O(n * d), where d is the number of digits in the largest number k, expressed in base b, and can be computed as d = floor(log_b(k) + 1) for a given base b. This algorithm is highly efficient for sorting non-negative integers.

### First: Index stack_A

As the radix sort algorythm only works with positive numbers, we will need to index the stack. Traverse the stack to find the lowest value, set its index to 0, inrement the index, and repeate the process untill all nodes have been indexed. As well as the index represented as in integer, we will also store the index value for each node as a 32 bit binary.

### Second: Push nodes with bit value 0 to stack_B

Each of the nodes in stack_A now contains an integer index as well as the same integer index, but expressed in a 32 bit binary char array, as shown below. With this, we will decide how many significant bits are present in our 32 bit binary indexes. For the decimal number 100, there are 4 significant bits in the binary array, as shown below. To implement the radix sort algorythm, start at the least significant bit, the rightmost bit, in this case 0. The node with value 100, has a 0 in the position of the least significant bit, so we shall push it to stack_B. The process is repeated until, stack_A contains nodes ending in 1, and stack_B contains nodes where the binary array ends only in a 0. Now, push all nodes from stack_B, back to the top of stack_A. Repeat this process for each of the significant bits in the binary char array, and stack_A will be in order.

```shell
# Decimal 100 represented in 32 bit binary
00000000000000000000000000001010
```

*source:* `Leo Fu` [Push_Swap Tutorial](https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e)

---
<br />
