# Trees and Graphs Examples

This document provides comprehensive examples for various tree and graph algorithms. It includes 30+ code examples covering tree traversals, BST operations, graph algorithms, shortest paths, and minimum spanning trees.

## Table of Contents
1. [Tree Traversals](#tree-traversals)
2. [Binary Search Tree Operations](#binary-search-tree-operations)
3. [Graph Algorithms](#graph-algorithms)
4. [Shortest Path Algorithms](#shortest-path-algorithms)
5. [Minimum Spanning Trees](#minimum-spanning-trees)

---

## Tree Traversals

### 1. Inorder Traversal
```python
class Node:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.val = key

# Inorder recursive function

def inorder(root):
    return inorder(root.left) + [root.val] + inorder(root.right) if root else []
```

### 2. Preorder Traversal
```python
# Preorder recursive function

def preorder(root):
    return [root.val] + preorder(root.left) + preorder(root.right) if root else []
```

### 3. Postorder Traversal
```python
# Postorder recursive function

def postorder(root):
    return postorder(root.left) + postorder(root.right) + [root.val] if root else []
```

---

## Binary Search Tree Operations

### 1. Insertion
```python
# Insert function

def insert(root, key):
    if root is None:
        return Node(key)
    else:
        if key < root.val:
            root.left = insert(root.left, key)
        else:
            root.right = insert(root.right, key)
    return root
```

### 2. Deletion
```python
# Delete function

def delete(root, key):
    if root is None:
        return root
    if key < root.val:
        root.left = delete(root.left, key)
    elif key > root.val:
        root.right = delete(root.right, key)
    else:
        if root.left is None:
            return root.right
        elif root.right is None:
            return root.left
        min_larger_node = root.right
        while min_larger_node.left is not None:
            min_larger_node = min_larger_node.left
        root.val = min_larger_node.val
        root.right = delete(root.right, min_larger_node.val)
    return root
```

---

## Graph Algorithms

### 1. Depth First Search (DFS)
```python
# DFS algorithm

def dfs(graph, start, visited=None):
    if visited is None:
        visited = set()
    visited.add(start)
    for next in graph[start] - visited:
        dfs(graph, next, visited)
    return visited
```

### 2. Breadth First Search (BFS)
```python
from collections import deque

# BFS algorithm

def bfs(graph, start):
    visited = set()
    queue = deque([start])
    while queue:
        vertex = queue.popleft()  
        if vertex not in visited:
            visited.add(vertex)
            queue.extend(graph[vertex] - visited)
    return visited
```

---

## Shortest Path Algorithms

### 1. Dijkstra's Algorithm
```python
import heapq

# Dijkstra's algorithm

def dijkstra(graph, start):
    queue = [(0, start)]
    distances = {vertex: float('infinity') for vertex in graph}
    distances[start] = 0
    while queue:
        current_distance, current_vertex = heapq.heappop(queue)
        if current_distance > distances[current_vertex]:
            continue
        for neighbor, weight in graph[current_vertex].items():
            distance = current_distance + weight
            if distance < distances[neighbor]:
                distances[neighbor] = distance
                heapq.heappush(queue, (distance, neighbor))
    return distances
```

---

## Minimum Spanning Trees

### 1. Prim's Algorithm
```python
import heapq

# Prim's algorithm

def prim(graph):
    mst = []
    visited = set()
    min_edges = [(0, (None, next(iter(graph))))]
    while min_edges:
        weight, (from_vertex, to_vertex) = heapq.heappop(min_edges)
        if to_vertex not in visited:
            visited.add(to_vertex)
            mst.append((from_vertex, to_vertex, weight))
            for to_next, weight in graph[to_vertex].items():
                if to_next not in visited:
                    heapq.heappush(min_edges, (weight, (to_vertex, to_next)))
    return mst
```

---

This document contains numerous examples of efficient algorithms that handle trees and graphs. Review each code snippet for a deeper understanding of its implementation and application across various scenarios in computer science. 

For further information, consult the respective algorithmic documentation or textbooks for advanced topics regarding complexity and optimization strategies.
