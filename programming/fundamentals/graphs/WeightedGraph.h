#include <map>
#include <vector>

class WeightedGraph {
  public:

    class Node {
      public:
        explicit Node(int v) : val(v), dist(std::numeric_limits<int>::max()) { }

        ~Node() { }

        int val;
        int dist;
    };

    typedef std::set<Node*> NodeSet;

    WeightedGraph() { }

    ~WeightedGraph() { }

    void addEdge(Node *u, Node *v, int weight) {
      adj_[u].push_back(std::make_pair(v, weight));
      adj_[v].push_back(std::make_pair(u, weight));
    }

    void removeEdge(Node *u, Node *v) {
      removeEdge_(u, v);  
      removeEdge_(v, u);  
    }

    std::vector<std::pair<Node*, int> > getNeighbors(Node *u) const {
      auto neighbors = adj_.find(u);
      if (neighbors != adj_.end()) {
        return *neighbors;
      }
      return std::vector<std::pair<Node*, int> >();
    }

    NodeSet *getAllVertices() const {
      NodeSet vertices;
      for (auto &adj : adj_) {
        for (auto &n : adj) {
          vertices.insert(n.first);
        }
      }
      return vertices;
    }

  private:
    void removeEdge_(Node *u, Node *v) {
      auto adjacent = adj_.find(u);
      if (adjacent != adj_.end()) {
        for(auto &a : *adjacent) {
          if (a.first == v) {
            adjacent->erase(a);
            break;
          }
        }
      }
    }

    std::map<Node*, std::vector<std::pair<Node*, int> > > adj_;
};
