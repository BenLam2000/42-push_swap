*This project has been created as part of the 42 curriculum by belam.*

# Description

Presents the project, including its goal and a brief overview.

# [Feature List]

# [Usage Examples]

# Instructions

Any relevant information about how others can compile, install, and/or execute your project.

# [Technical Choices]

push: add item to top of stack
pop: remove item from top of stack and return value of removed item

- stack implementation: linked list instead of array
  - size of stack fixed at compile time: array / linked list both viable
  - to do rotate:
    - array: waste a lot of computation to move all numbers up, since array size is fixed
    - liked list: free to add node at other end and just switch pointers to change stack head

# Findings

- since final goal is to stack A in ascending order, stack A must be remained as in ascending order as possible
- since there is no operation to move multiple numbers from B to A in a group (order unchanged), B must be as descending as possible, because pushing stack B to A will flip their order
- rotating either direction does NOT change the number sequence in a stack, only which number appears at the top
- worst case scenario for rotating to bring a specific number to the top is N/2, because any number that is further away from the center of the stack can use either R/RR to reach the top in less than N/2 steps 
- swap is useful when there are 2 numbers that need to be swapped are right next to each other
- any numbers within stack A still need to be rotated to the top regardless if the preceeding operation is swap or push, since both only happen at the top
- are we allowed to peek at the full stack A and B integers? yes

# Approaches

1. use stack B as the "sorting ground for out of place numbers"

# Resources

List of classic references related to the topic (documentation, articles, tutorials, etc.), as well as a description of how AI was used — specifying for which tasks and which parts of the project.

- [Stacks](https://en.wikipedia.org/wiki/Stack_(abstract_data_type))



# Todo

## Today:

- [x] learn how to create nodes, and join nodes to form  linked list

- [x] automate linked list creation from an array of integers
- [ ] code all operations and test each one





- [ ] draft the overall structure (pseudocode) for turk

- [ ] write helper functions for turk

- [ ] implement turk main algorithm

- [ ] input validation



# Functions

- [ ] create_stack_node

- [ ] create_stack
