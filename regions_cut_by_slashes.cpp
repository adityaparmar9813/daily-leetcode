class UnionFind {
public:
  vector<int> parent, size;
  int count = 1;
  UnionFind(int n) {
    parent.resize(n);
    size.resize(n);

    for (int i = 0; i < n; i++) {
      parent[i] = i;
      size[i] = 1;
    }
  }

  int Find(int node) {
    if (node == parent[node]) {
      return node;
    }

    return parent[node] = Find(parent[node]);
  }

  void Union(int u, int v) {
    int p1 = Find(u);
    int p2 = Find(v);

    if (p1 == p2) {
      count++;
      return;
    }

    if (size[p1] < size[p2]) {
      parent[p1] = p2;
      size[p2] += size[p1];
    } else {
      parent[p2] = p1;
      size[p1] += size[p2];
    }
  }
};

class Solution {
public:
  int regionsBySlashes(vector<string> &grid) {
    int n = grid.size();
    int val = (n + 1) * (n + 1) + 1;

    UnionFind graph(val);

    for (int i = 0; i < n + 1; i++) {
      for (int j = 0; j < n + 1; j++) {
        if (i == 0 || j == 0 || i == n || j == n) {
          int cellno = (i * (n + 1)) + j;

          if (cellno != 0) {
            graph.Union(0, cellno);
          }
        }
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == '/') {
          int p1 = i * (n + 1) + (j + 1);
          int p2 = (i + 1) * (n + 1) + j;
          graph.Union(p1, p2);
        } else if (grid[i][j] == '\\') {
          int p1 = i * (n + 1) + (j);
          int p2 = (i + 1) * (n + 1) + (j + 1);
          graph.Union(p1, p2);
        }
      }
    }
    return graph.count;
  }
};

// Time Complexity : O(n ^ 2)
// Space Complexity : O(n ^ 2)
