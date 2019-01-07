#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <unistd.h>

using namespace std;

enum GridType {
  OPEN = 0,
  VISITED = 1,
  GOAL = 2
};

typedef vector<vector<GridType> > Grid;
typedef pair<int,int> Position;

#define OPEN_CHAR    "O"
#define VISITED_CHAR "x"
#define GOAL_CHAR    "#"

#define GRID_HEIGHT 25
#define GRID_WIDTH  25

static Grid createGrid() {
  Grid grid;
  for(int i = 0; i < GRID_HEIGHT; i++) {
    vector<GridType> row(GRID_WIDTH, OPEN);
    grid.push_back(row);
  }
  return grid;
}

static void refresh(const Grid &grid) {
  system("clear");
  cout << endl << endl;
  for(auto row : grid) {
    for(auto item : row) {
      switch(item) {
        case OPEN:
          cout << OPEN_CHAR;
          break;
        case VISITED:
          cout << VISITED_CHAR;
          break;
        case GOAL:
          cout << GOAL_CHAR;
          break;
      }
    }
    cout << endl;
  }
  cout << endl;
}

static vector<Position> getNeighbors(const Position &pos, const Grid &grid) {

  // 8 potential neighbors for each position, top left, top, top right, left, 
  // bottom left, bottom, bottom right, right
  vector<Position> neighbors;

  if(pos.first > 0) {
    if(pos.second > 0) {
      neighbors.push_back({pos.first-1, pos.second-1}); // top left
    }
    neighbors.push_back({pos.first-1, pos.second}); // top
    if(pos.second < GRID_WIDTH-1) {
      neighbors.push_back({pos.first, pos.second+1}); // top right
    }
  }

  if(pos.second < GRID_WIDTH-1) {
    neighbors.push_back({pos.first, pos.second+1}); // right
  }

  if(pos.first < GRID_HEIGHT-1) {
    if(pos.second < GRID_HEIGHT-1) {
      neighbors.push_back({pos.first+1, pos.second+1}); // bottom right
    }
    neighbors.push_back({pos.first+1, pos.second}); // bottom
  }

  if(pos.second > 0) {
    if(pos.first < GRID_HEIGHT-1) {
      neighbors.push_back({pos.first+1, pos.second-1}); // bottom left
    }
    neighbors.push_back({pos.first, pos.second-1}); // left
  } 

  return neighbors;
}

static void bfs(const Position &start, Grid &grid) {

  set<Position> visited, queued;
  queue<Position> q;
  q.push(start);

  while (!q.empty()) {
    Position cur = q.front();
    grid.at(cur.first).at(cur.second) = VISITED;
    visited.insert(cur);
    auto neighbors = getNeighbors(cur, grid);
    for(auto neighbor : neighbors) {
      if (visited.find(neighbor) == visited.end() && 
          queued.find(neighbor) == queued.end()) {
        queued.insert(neighbor);
        q.push(neighbor);
      }
    }
    q.pop();
    queued.erase(cur);
    refresh(grid);
    usleep(50*1000);
  }
}

int main(int argc, const char *argv[])
{
  Grid grid = createGrid();

  refresh(grid);
  bfs({10,5}, grid);

  return 0;
}
