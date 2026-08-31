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
- can only check sorted and size <= 1 after one full pass through input string
- How to use ./checker_linux properly:
  - based on subject: ARG="3 2 1 0"; ./push_swap \$ARG | ./checker_OS \$ARG
  - ./checker_linux "3 2 1 0" "\nrra\npb\nsa\nrra\npa"
    - this will FAIL because ./checker_linux only accepts arguments
    - "\n" in shell is not interpreted as newline, just literal '\' and 'n'
  - echo -ne "rra\npb\nsa\nrra\npa\n" | ./checker_linux "3 2 1 0"
    - this works because echo -ne enables interpretation of escape characters
  - ./checker_linux "3 2 1 0" -> key in instructions (ENTER after each) -> CTRL+D after last instruction to signal end of input
- when doing pointer surgery on linked list, always check if the node is NULL if there is dereferencing involved (ex. stack->head->next)
- size of stack only changes when:
  - creation of the stack
  - push (all other operations does not affect stack size)
- cost calculation has no penalty because this projects only measured resource is number of instructions

# Approaches

- use stack B as the "sorting ground for out of place numbers"

- for cost calculation, current stack and target stack is defined, so it can be generally used for initial push from A to B (current=A, target=B) and final push from B back to A (current=B, target=A)
  
  - rotate is +, reverse rotate is -

- functions such as update stack index should be bundled together in the functions that only need to use it, not in the turk algo function, to make the turk algo more readable

- at each stage of input parsing and stack creation, free input and keep malloced new array/stack

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
- [turk algorithm -medium](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)
- [push swap visualizer & argument generator](https://push-swap42-visualizer.vercel.app/)
- [python tutor - debug and visualize memory addresses](https://pythontutor.com/c.html#)
- [valgrind - memory leak checker](https://valgrind.org/docs/manual/quick-start.html)
- [Stacks](https://en.wikipedia.org/wiki/Stack_(abstract_data_type))
- [singly vs doubly linked lists](https://www.reddit.com/r/learnprogramming/comments/yh3c4d/singly_linked_list_vs_doubly_linked_list/)
- [singly linked lists - wikipedia](https://en.wikipedia.org/wiki/Linked_list#Singly_linked_list)
- [analysis of algorithms - wikipedia](https://en.wikipedia.org/wiki/Analysis_of_algorithms)
- [sorting algorithm visualizer - visualgo](https://visualgo.net/en/sorting)
- [Piping in Unix or Linux](https://www.geeksforgeeks.org/linux-unix/piping-in-unix-or-linux/)

### AI Usage

- perform input parsing, validation and duplicate checking concurrently with building stack nodes - [Chatgpt](https://chatgpt.com/share/6a7543b9-73b0-83ec-9ec8-2121d0ba5898)

- object files not linking with libft library - [Gemini](https://share.google/aimode/UJrJ8j0SgjhvKgMUf)

# Tasks

### Done:

- [x] learn how to create nodes, and join nodes to form singly linked list

- [x] automate linked list creation from an array of integers

- [x] convert singly to non-circular doubly linked list

- [x] input validation (spaces, non-int, overflow/underflow)

- [x] merge input parsing and stack building

- [x] check sorted

- [x] check duplicates

- [x] figure out how checker works

- [x] build + project structure

- [x] code and test all operations
  
  - [x] sa, sb, ss
  
  - [x] pa, pb
  
  - [x] ra, rb, rr
  
  - [x] rra, rrb, rrr

- [x] add target and index to node

- [x] ft_strcmp

- [x] implement turk algo
  
  - [x] push first 2 A nodes (similar to sorted stack in insertion sort)
  
  - [x] while stack A has more than 3 nodes:
    
    - [x] assign each node in A a target node (closest smaller number / which number to put on top of) from B (so that B is constantly being sorted in descending order)
    
    - [x] if no smaller number, target node is largest number (considering stacks are a loop, when sorted in descending order, the smallest number is always immediately above the largest number)
    
    - [x] cost calculation, find which node is cheapest to push (ops to bring A node on top + ops to bring A's target node on top + 1 push op (cancelled out)), if found that cost is 0, straight away implement that
      
      - [x] use rotate or reverse rotate only (if node is above halfway line, use rot, if below halfway line, use reverse rot)
      
      - [x] if exactly on halfway line, follow the direction of the other, so that can use rr or rrr
      
      - [x] if both A & B need to rotate in same direction, cost is the max of the 2 coz can rotate both simultaneously
    
    - [x] PB
    
    - [x] repeat
  
  - [x] sort 3
    
    - [x] max number at bottom
    
    - [x] swap first 2 numbers if still not sorted
  
  - [x] while stack B still has nodes:
    
    - [x] assign each node in B a target node (closest larger number / which number to put on top of) from A (so that A is constantly being sorted in ascending order)
    
    - [x] if no larger number, target node is smallest number (considering stacks are a loop, when sorted in ascending order, the largest number is always immediately above the smallest number)
    
    - [x] cost calculation, find which node is cheapest to push (ops to bring B node on top + ops to bring B's target node on top + 1 push op (cancelled out)), if found that cost is 0, straight away implement that
    
    - [x] use rotate or reverse rotate only (if node is above halfway line, use rot, if below halfway line, use reverse rot)
    
    - [x] if exactly on halfway line, follow the direction of the other, so that can use rr or rrr
    
    - [x] if both A & B need to rotate in same direction, cost is the max of the 2 coz can rotate both simultaneously
    
    - [x] repeat
  
  - [x] rotate / rev rotate until min is on top (using halfway line rule)
  
  - [x] free the stacks when done

- [x] check for edge case of 4 nodes, what will happen in turk()?

- [x] try to store dir and count directly in ops without having to set ops and set count, getting a bit too complicated for a reader

- [x] settle input parsing (string -> multiple arguments)

### Todo:

- [x] shrink files down to 5 functions per file

- [x] memleak
  
  - [x] ft_split
  
  - [x] free function in libft for split array
  
  - [x] free function for both stacks

- [x] find more suitable naming for set ops, dir, count, etc., very confusing for reader

- [x] change makefile to use full file names

- [x] remove unnecessary headers
  
  - [x] search "ft_" to find libft functions

- [ ] update readme

# Functions

- [x] create_node

- [x] create_stack

- [x] get_closest_smaller_node

- [x] get_max_node

- [x] update_stack_index

- [x] ft_arrlen

- [x] ft_arrjoin

# What I learned

### ft_atoi limitation

- even if there are trailing non-digit characters (ex: "  +123**abc**"), as long as initial portion is valid, it will return the int (123), so there is no way of figuring out if the integer encompasses the full string / at least know where the first nond-digit character starts
  
  - solution: return the address of a pointer (char **) passed in as input that will indicate where the first non-digit character starts

- if no number is found, atoi returns 0, which will be the same as if the number i '0', so there is no way to differentiate these 2 cases

- no checks for overflow and underflow

### Exit Codes and exit()

useful for debugging when unexpected behaviour occurs, can be viewed using `echo $?`

using exit() helps terminate the program immediately with desired exit code without having to pass exit code up the call stack if it is deep within the call stack

this allows much more granular error reporting

### Piping (|)

./checker_linux only accepts the list of integers as arguments on command line, but instructions from stdin (standard input). The reason

`./push_swap \$ARG | ./checker_OS \$ARG"`

works is because piping is a form of redirection that sends the stdout of the first command as stdin to the second command, so this simulates a user manually typing the instructions for ./checker_os. This is different than providing the instructions as a second argument to ./checker_os.

### Library sequence in compilation

cc main.o libft.a -o push_swap

- OK

cc libft.a main.o -o push_swap

- KO

make sure your main file is the first one and everything else follows order, dependencies also behind the source file that calls it

### Using GDB to debug

### Framework for linked list pointer surgery

1. draw out before and after of the operation for a simple linked list

2. imagine nodes to be moved being yanked out, label all affected pointers from top to bottom

3. declare temporary node variables for those that affected pointers come into contact with

4. code pointer surgery operations

5. add null checks for old node pointers that are dereferenced to avoid segfault

### Making functions dynamic

making functions that have current stack and target stack dynamic to be usable both during first push from A to B and final push back from B to A.

### Returning structs vs arrays from a function

locally defined structs and arrays:

when struct is returned, all the contents get copied over to the caller's stack frame, so even when the function exits and the function's stack frame dies, the value still retained in caller

for arrays, arrays' variable decays into a pointer to its first element, C does not auto copy array elements to caller's stack frame. So after function exits, the pointer returned points to memory that has died, hence a dangling pointer

# Mistakes I Made

# Requirements Checklist

- [x] input:
  
  - [x] integers can be negative
  
  - [x] accepts input as multiple arguments or a single argument with all numbers
    
    - [x] 2 3 4 5
    
    - [x] "2 3 4 5"
    
    - [x] 2 "3 4" 5
  
  - [x] first argument at the top of stack
  
  - [x] if no arguments specified, display nothing and return to prompt
  
  - [x] spaces at beginning or end, or consecutive space -> ERROR
  
  - [x] arguments not being integers (floating point/non-digit char) -> ERROR
  
  - [x] arguments exceeding INT_MAX / INT_MIN -> ERROR
  
  - [x] arguments containing duplicates -> ERROR
  
  - [x] input list already sorted -> ERROR

- [x] output:
  
  - [x] instructions only separated by '\n'
  
  - [x] must pass with checker for all benchmarks

- [x] build
  
  - [x] libft.a created using its own makefile
  
  - [x] push_swap has its own Makefile that builds libft.a and its source files

- [x] Benchmarks:
  
  - [x] number of instructions for 3 nums must be <= 3
  
  - [x] number of instructions for 5 nums must be <= 12
  
  - [x] number of instructions for 100 nums must be <= 700
  
  - [x] number of instructions for 500 nums must be <= 5500

- [x] program must compile wth makefile

- [x] no global variables

- [x] no memory leaks
  
  - [x] must free both stacks before ending program
  
  - [x] ft_split_strict mem leak
  
  - [x] verify with valgrind

Exit Code:

| Exit Code | Description                                        |
| --------- |:-------------------------------------------------- |
| 0         | OK!                                                |
| 1         | No arguments given                                 |
| 2         | Spaces at beginning or end, or consecutive spaces  |
| 3         | Arguments contain overflow                         |
| 4         | Arguments contain underflow                        |
| 5         | Arguments contain non-integers                     |
| 6         | stack size < 2                                     |
| 7         | Arguments contain duplicates                       |
| 8         | Input list is already sorted                       |
| 9         | Error allocating memory during stack node creation |

# Program Flow

1. loop through all argc, for each arg:
   1. parse input -> validate input -> check duplicates with previous nodes -> build node
   2. if at any point error -> free all previous nodes in stack and return
2. if stack successfully built -> check sorted -> if fail free stack and return also

# Pre-submission Checklist

- [x] Check if the subject version has updated and requirements have changed compared to your downloaded version

- [ ] Read through the subject / man page one last time. Did you miss any details?

- [ ] Does your file and folder structure meet the subject guidelines? (check hidden files and bonus too)

- [x] Did you refactor your code to make it as readable as possible?

- [x] Did you set internally used functions as static?

- [x] Header files
  
  - [x] do all header files have header inclusion guards?
  
  - [x] Check all source files only include required headers
  
  - [x] remove unused built-in headers

- [x] Are there any forbidden functions / unused headers / global variables / special functions in makefile (wildcard) (if disallowed)?
  
  - [x] printf
  - [x] patsubst

- [x] Remove unused comments

- [ ] Does your project pass all tests?

- [x] No memory leaks
  
  - [x] free any unused heap allocated memory
  
  - [x] free previously used heap allocated memory if malloc fails

- [x] Does your whole project folder pass norm? (except makefile)
  
  - [x] max 5 functions per file

- [ ] Did you push your project to vogsphere? Git clone from vogsphere and check all files are correct, for extra security, make sure the cloned repo passes norm and tests too
