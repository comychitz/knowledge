#include <map>
#include <set>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

struct GraphNode {
  int val;
  explicit GraphNode(int x) : val(x) { }
};

class Graph {
  public:
    Graph() { }
    ~Graph() { }

    /// adjacency list implementation
    map<GraphNode*, vector<GraphNode*> > neighbors;
};

static void printBFS(Graph &graph, GraphNode *start) {
  set<GraphNode*> visited;
  queue<GraphNode*> q;
  q.push(start);
  while(!q.empty()) {
    GraphNode *front = q.front();
    cout << front->val << endl;
    visited.insert(front);
    for(auto &neighbor : graph.neighbors[front]) {
      if(visited.find(neighbor) == visited.end()) {
        visited.insert(neighbor);
        q.push(neighbor);
      }
    }
    q.pop();
  }
}

static void printDFS(Graph &graph, GraphNode *node) {
  if(node == NULL) {
    return;
  }
  static set<GraphNode*> visited;
  cout << node->val << endl;
  visited.insert(node);
  for(auto &neighbor : graph.neighbors[node]) {
    if(visited.find(neighbor) == visited.end()) {
      printDFS(graph, neighbor);
    }
  }
}

int main(int argc, const char *argv[])
{
  //
  //    1
  //  /   \
  // 2     4
  //  \   /
  //    3
  //    |
  //    5
  //  
  // print BFS: 1 2 4 3 5
  // print DFS: 1 2 3 5 4
  //
  GraphNode n1(1), n2(2), n3(3), n4(4), n5(5);

  Graph graph;
  graph.neighbors[&n1] = {&n2, &n4};
  graph.neighbors[&n2] = {&n1, &n3};
  graph.neighbors[&n3] = {&n2, &n5, &n4};
  graph.neighbors[&n4] = {&n1, &n3};
  graph.neighbors[&n5] = {&n3};

  cout << "Print BFS: " << "-------" << endl;
  printBFS(graph, &n1);
  cout << "Print DFS: " << "-------" << endl;
  printDFS(graph, &n1);
  return 0;
}
