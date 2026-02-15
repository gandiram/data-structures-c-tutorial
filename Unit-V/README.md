# Trees and Graphs

## Introduction
Trees and Graphs are fundamental data structures in computer science used to represent hierarchical and non-linear relationships among data. They are crucial for designing efficient algorithms and building various applications.

## Types of Trees
- **General Trees**: Trees with nodes having an arbitrary number of children.
- **Binary Trees**: Each node has at most two children, typically referred to as left and right.
- **Binary Search Trees (BST)**: A binary tree where the left child's value is less than the parent's, and the right child's value is greater.
- **Balanced Trees**: Trees like AVL trees or Red-Black trees that maintain balance to ensure efficient operation.
- **Trie**: A tree used for storing a dynamic set or associative array where keys are usually strings.

## Binary Tree Creation
A binary tree can be created using a class-based model:
```python
class Node:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.val = key
```

## Traversal
Common ways to traverse a binary tree include:
1. Preorder (Root, Left, Right)
2. Inorder (Left, Root, Right)
3. Postorder (Left, Right, Root)
4. Level-order traversal (Breadth-First)

## Binary Search Trees and Operations
### Operations:
- **Insertion**: Add a new node while maintaining BST properties.
- **Deletion**: Remove a node, ensuring to maintain the properties of the tree.
- **Search**: Find a node by comparing values.
  
### Example:
```python
def insert(root, key):
    if root is None:
        return Node(key)
    else:
        if root.val < key:
            root.right = insert(root.right, key)
        else:
            root.left = insert(root.left, key)
    return root
```

## Graph Representation
Graphs can be represented using:
- **Adjacency Matrix**: A 2D array where a value indicates the presence of an edge between vertices.
- **Adjacency List**: A list where each vertex has a list of connected vertices.

## Traversal Algorithms
- **Depth-First Search (DFS)**: Explores as far as possible along each branch before backtracking.
- **Breadth-First Search (BFS)**: Explores all the neighbor nodes at the present depth before moving on to nodes at the next depth level.
  
### Example:
```python
def dfs(vertex, visited):
    visited.add(vertex)
    for neighbor in graph[vertex]:
        if neighbor not in visited:
            dfs(neighbor, visited)
```

## Graph ADT
Graph Abstract Data Type defines the structure and operations for graph data structures, like adding/deleting vertices and edges, searching, etc.

## Applications
- **Networking**: Routers use graphs to determine the best paths.
- **Social Networks**: Represent relationships among users.
- **Web Page Link Structures**: Pages are vertices, and links are edges.
- **Route Planning**: Find the shortest or least-cost path between points.