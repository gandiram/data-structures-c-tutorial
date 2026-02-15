# Stacks and Queues

## Stack ADT
A stack is a linear data structure that follows the Last In First Out (LIFO) principle. The Stack ADT consists of the following operations:
- **push(item)**: Adds an item to the top of the stack.
- **pop()**: Removes and returns the item from the top of the stack.
- **peek()**: Returns the item at the top of the stack without removing it.
- **isEmpty()**: Checks if the stack is empty.

### Applications of Stacks
- **Infix to Postfix Conversion**: The process of transforming an infix expression (like `A + B`) into a postfix expression (like `A B +`) using a stack to hold operators.
- **Postfix Evaluation**: Evaluating expressions written in postfix form using a stack to hold operands and applying operators as they appear.
- **Balancing Symbols**: Using stacks to check for balanced parentheses, brackets, and braces in expressions.
- **Expression Trees**: Constructing binary trees from postfix expressions for efficient expression evaluation.

## Queue ADT
A queue is a linear data structure that follows the First In First Out (FIFO) principle. The Queue ADT consists of the following operations:
- **enqueue(item)**: Adds an item to the end of the queue.
- **dequeue()**: Removes and returns the item from the front of the queue.
- **front()**: Returns the item at the front of the queue without removing it.
- **isEmpty()**: Checks if the queue is empty.