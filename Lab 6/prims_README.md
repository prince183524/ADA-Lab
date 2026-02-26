# Prim's Minimum Spanning Tree (MST)

This program implements Prim's algorithm for finding the Minimum Spanning Tree in a graph in C++.

## Description
Prim's algorithm finds a subset of the edges that forms a tree including every vertex, where the total weight of all the edges in the tree is minimized. It grows the MST one edge at a time.

## Usage
- Input: Weighted undirected graph (adjacency matrix or list)
- Output: Edges in the MST and their total weight

## Time Complexity
- O(V^2) or O(E + V log V) with min-heap

## File
- prims.cpp