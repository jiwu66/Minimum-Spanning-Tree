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

### Detail on Design Decision

#### graph

#### node

#### pri_queue

### Test Cases

### Performance
