# Minimum-Spanning-Tree

- [Introduction](#introduction)
- [Design Document](#design-document)
  * [Summary](#summary)
  * [Detail on Design Decision](#detail-on-design-decision)
    + [graph](#graph)
    + [node](#node)
    + [pri_queue](#pri_queue)
  * [Test Cases](#test-cases)
  * [Performance](#performance)

## Introduction
This project implements Prim-Jarnik Algorithm. The algorithm is to calculate the Minimum Spanning tree of a graph.\
The program will allow the user to build and modify a graph. The following functions will be implemented for the user to use.

**insert_edge**:\
Description: Add an edge between two nodes, if there exists an edge between them, replace it with the new edge.
Parameter: node1; node2; edge_value
Return: 

**erase_edge**:\
Description: Erase the edge between teo nodes. If there are no edge between them, return false
Parameter: node1; node2; edge_value
Return: 1 if succeed, 0 if failed

**adjacent**:\
Description: Check if two nodes are connected with an edge.
Parameter: node1; node2; edge_value
Return: return 1 if node1 and node2 are connected by a edge of edge_value, else return false.

**degree**:\
Description: Count the number of edges on one node.
Parameter: node1
Return: number of edges on node1.

**edge_count**:\
Description: Count the total number of edge in the graph.
Parameter: 
Return: number of edges in the graph

**clear**:\
Description: Clear all edges in the graph
Parameter: 
Return: 

**mst**:\
Description: Calculate the Minimum Spanning Tree of the graph
Parameter: node1
Return: Return true if the graph is connected, else return false.

## Design Document

### Summary
For this project, I designed four classes: 1. graph 2. node 3. pri_queue 4. illegal_exception.\
• The graph class contains two matrix representing the relationship and edge between each vertex and an array representing the degree of each vertex. It also holds the size and number of edges in the graph. Member functions can be used to access and modify the private variables.\
• The node class represent each element of the priority queue. Each node represents a vertex in the priority queue. It holds the index and key of the vertex. Member functions can be used to access and modify the private variables.\
• The pri_queue class contains an array of node as a priority queue. The queue contains heapify, build, extract_min functinos which can be used to modify the priority queue.\
![image](https://user-images.githubusercontent.com/58014412/132144494-5bd03f7b-4006-465e-aad3-cc6337c11c2c.png)

### Detail on Design Decision

#### graph
• Constructor: the constructor initializes the private variables. The graph class represent relationship and edge matrix using vectors, and they will be initialized to be arrays of vectors where the arrays and each vector in array have a size of the input value. The degree array will be initialized to have a size of the input value as well to store the degree of each vertex. Number of edges will be initialized to be 0.\
• Destructor will be used to deallocate memory if needed. In this case, p_vertex, p_edge and p_degree requested memory allocation and should be deleted and set to nullptr.\
• No operator was overridden.\
• Since we do not want the parameters to change during the program, all parameters should be passed using const and reference.

#### node
• Constructor: initializes the private variables. q_ind, g-ind and key will be set to input value, parent will be set to nullptr.\
• Destructor: will be used to deallocate memory if needed. In this case, no memory needs to be deallocated.\
• No operator was overridden.\
• Since we do not want the parameters to change during the program, all parameter will be passed using cons and reference except set_parent.

#### pri_queue
• Constructor: initializes the private variables. It takes in a root and a size value and initialize p_queue to be an array of nodes. The node with the index of root will be set to key = 0 while others will be set to infinite.\
• Destructor: will be used to deallocate memory if needed. In this case, p_queue requested memory and will be deallocated.\
• No operator was overridden.\
• Since we do not want the parameters to change during the program, all parameters will be passed using const and reference.

### Test Cases
I tested each function separately and then did comprehensive tests. I also tested for illegal arguments.\
• Repeatedly insert different edge value to the two same vertexes, use adjacent to check if their edge value. The edge value should be updated every time.\
• Repeatedly insert, check adjacent, erase edge and check adjacent between two nodes. The two nodes should not be adjacent after erase.\
• Insert multiple times to one vertex between every other vertexes, and check if the degree and number of edges changes correctly. Erase multiple times and check again. Clear and check again.\
• Insert to create a connected graph, do mst on every node to see if they always give the same value which is the MST.\
• Insert to create a unconnected graph, do mst on every node to see if it always returns “not connected”.

### Performance
• I, e, adjacent, degree, edge_count all require a runtime of O(1). For i, e, and adjacent, we are only modifying or check the entries of arrays. For degree and edge_count, we are only returning the private variables.\
• clear requires a runtime of O(m) where m is the number of vertexes in the graph. Clear traverse through the arrays and clear or integers all vectors in it.\
• Mst requires O(ElgV) runtime. Extract_min and modify_key requires O(lgV). They will be called in loops, giving the function O(ElgV) runtime.
