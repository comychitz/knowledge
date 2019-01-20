#include "WeightedGraph.h"

#include <iostream>

/**
 * Test program for implementing Djikstra's algorithm - the variant where it
 * finds the shortest path between two specified nodes
 */

bool djikstra(Node *start, Node *goal, WeightedGraph &graph) {

  WeightedGraph::NodeSet vertices = graph.getAllVertices();

  std::priority_queue<Node*> q;

  for (auto &vertex : vertices) {
    q.push(vertex);
  }
  
  start->dist = 0;

  while (!q.empty()) {

    Node *n = q.front();
    std::vector<std::pair<Node*, int> > neighbors = graph.getNeighbors(n);

    for (auto &neighbor : neighbors) {
      int alt = n->first + neighbor.second;
      if (alt < neighbor.first->dist) {
        neighbor.first->dist = alt;

        // TODO need to update neighbor's priority in q?
      }
      q.pop();
    }
  }
  
  return true; // TODO check if we found it!
}


