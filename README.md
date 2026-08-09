*This project has been created as part of the 42 curriculum by belam.*

# Description

Presents the project, including its goal and a brief overview.

main goal of the project is to prioritize move efficiency, okay to spend more computation to find the least number of moves, time and space complexity is not really the key thing here. The reason why turk's algo works so well is because of the cost calculating part, the rest is just basic insertion sort, which has complexity of n^2.

# [Feature List]

# [Topics covered]

- linked lists

- bit shifting

- sorting algorithms

# [Usage Examples]

# Instructions

Any relevant information about how others can compile, install, and/or execute your project.

# Technical Choices

push: add item to top of stack
pop: remove item from top of stack and return value of removed item

### stack implementation

- **linked list** vs array
  
  - size of stack known only at runtime (user input arguments): fixed size array not possible, must use malloc (array or linked list)
  - each node will not only contain num, also other info, so structs can group data for each node neatly without needing multiple arrays for each data
  - to do rotate:
    - array: waste a lot of computation to move all numbers up, since array size is fixed
    - liked list: free to add node at other end and just switch pointers to change stack head

- singly vs **doubly** linked list
  
  - doubly is useful when you need to traverse backwards, singly would have to traverse whole linked list
  - pointer to previous node comes in handy for setting 2nd last node to point to NULL and set it as new TAIL when reverse rotate

- circular vs **non-circular** doubly linked list
  
  - boundary conditions might be harder to check for circular, whereas non-circular only needs to check for NULL
  - circular requires more pointer "surgery" when removing/inserting nodes

- reference pointers:
  
  - HEAD
  - TAIL: make accessing last node more efficient for rotate operations

Input can be multiple arguments or single string (must use ft_split)

### Input parsing and stack building

option 1: separate passes

- 1st pass through input string to validate input & count numbers

- allocate memory for array

- 2nd pass through input string to store numbers into array

- do duplicate checking on number array

- if no duplicates, build stack using number array

- cons: extra memory used for intermediate array

option 2: concurrent

- 1st pass through input string, for each parsed number:
  
  - validate input
  
  - check duplicates (traverse from head to latest node)
  
  - if no error, build new stack node
  
  - keep track of stack size / number count

- pros: save memory, no intermedate array, stack itself becomes storage for duplicate checking

- cons: if any error, need to be careful to free and destroy the whole stack node by node

# Findings

- since final goal is to stack A in ascending order, stack A must be remained as in ascending order as possible
- since there is no operation to move multiple numbers from B to A in a group (order unchanged), B must be as descending as possible, because pushing stack B to A will flip their order
- rotating either direction does NOT change the number sequence in a stack, only which number appears at the top
- worst case scenario for rotating to bring a specific number to the top is N/2, because any number that is further away from the center of the stack can use either R/RR to reach the top in less than N/2 steps 
- swap is useful when there are 2 numbers that need to be swapped are right next to each other
- any numbers within stack A still need to be rotated to the top regardless if the preceeding operation is swap or push, since both only happen at the top
- are we allowed to peek at the full stack A and B integers? yes
- for sorting check, the error it should be catching is when the whole list of numbers is fully sorted, but there is no point checking halfway through because there is not enough info yet

# Approaches

1. use stack B as the "sorting ground for out of place numbers"

# Tests

- single string input

- mutliple arguments input

- input with non-integer (float)

- input with overflow/underflow value

- input with duplicate values

- no input specified

- number of values specified is < 2 (no need to sort)

# Resources

List of classic references related to the topic (documentation, articles, tutorials, etc.), as well as a description of how AI was used — specifying for which tasks and which parts of the project.

- [push swap subject](https://cdn.intra.42.fr/pdf/pdf/209331/en.subject.pdf)
- [push swap tutorial - Thuggonaut](https://youtu.be/wRvipSG4Mmk?si=JCr7SIRVP9npqGqh)
- [Stacks](https://en.wikipedia.org/wiki/Stack_(abstract_data_type))
- [singly vs doubly linked lists](https://www.reddit.com/r/learnprogramming/comments/yh3c4d/singly_linked_list_vs_doubly_linked_list/)
- [singly linked lists - wikipedia](https://en.wikipedia.org/wiki/Linked_list#Singly_linked_list)
- [analysis of algorithms - wikipedia](https://en.wikipedia.org/wiki/Analysis_of_algorithms)
- [sorting algorithm visualizer - visualgo](https://visualgo.net/en/sorting)

### AI Usage

- perform input parsing, validation and duplicate checking concurrently with building stack nodes - [Chatgpt](https://chatgpt.com/share/6a7543b9-73b0-83ec-9ec8-2121d0ba5898)

- 

# Tasks

### Done:

- [x] learn how to create nodes, and join nodes to form singly linked list

- [x] automate linked list creation from an array of integers

- [x] convert singly to non-circular doubly linked list

- [x] input validation (spaces, non-int, overflow/underflow)

- [x] merge input parsing and stack building

- [x] check sorted

- [x] check duplicates

### Today:

- [ ] settle input parsing (string->/multiple arguments)

- [ ] check with Hannah why checker linux doesn't work

### Todo:

- [ ] code all operations

- [ ] test all operations (with stack A and B)

- [ ] draft the overall structure (pseudocode) for turk

- [ ] write helper functions for turk

- [ ] implement turk main algorithm

- [ ] 

# Functions

- [x] create_node

- [x] create_stack

# What I learned

### ft_atoi limitation

- even if there are trailing non-digit characters (ex: "  +123**abc**"), as long as initial portion is valid, it will return the int (123), so there is no way of figuring out if the integer encompasses the full string / at least know where the first nond-digit character starts
  
  - solution: return the address of a pointer (char **) passed in as input that will indicate where the first non-digit character starts

- if no number is found, atoi returns 0, which will be the same as if the number i '0', so there is no way to differentiate these 2 cases

- no checks for overflow and underflow

# Mistakes I Made

# Requirements Checklist

- [ ] input:
  
  - [x] integers can be negative
  
  - [ ] accepts input as multiple arguments or a single argument with all numbers
  
  - [x] first argument at the top of stack
  
  - [x] if no arguments specified, display nothing and return to prompt
  
  - [x] spaces at beginning or end, or consecutive space -> ERROR
  
  - [x] arguments not being integers (floating point/non-digit char) -> ERROR
  
  - [x] arguments exceeding INT_MAX / INT_MIN -> ERROR
  
  - [x] arguments containing duplicates -> ERROR
  
  - [x] input list already sorted -> ERROR

- [ ] instructions only separated by '\n'

- [ ] number of instructions for 3 nums must be < 3

- [ ] number of instructions for 5 nums must be > 12

- [ ] program must compile wth makefile

- [ ] no global variables

Exit Code:

| Exit Code | Description                                                       |
| --------- |:----------------------------------------------------------------- |
| 0         | OK!                                                               |
| 1         | No arguments given                                                |
| 2         | Spaces at beginning or end, or consecutive spaces between numbers |
| 3         | Arguments contain non-integers                                    |
| 4         | Arguments contain overflow / underflow                            |
| 5         | Arguments contain duplicates                                      |
| 6         | Input numbers / stack size <= 1                                   |
| 7         | Input list is already sorted                                      |
| 8         | Error allocating memory during stack node creation                |

# Program Flow

1. Input validation (one full pass)
