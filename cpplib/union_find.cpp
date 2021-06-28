#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;

/*
 * UnionFind
 * 連結判定
 * ref: https://algo-logic.info/union-find-tree/
 * test: https://atcoder.jp/contests/typical90/tasks/typical90_l
 */

struct UnionFind {
  vector<int> size, parents;

  UnionFind() {}
  UnionFind(int n) {
    size.resize(n, 0);
    parents.resize(n, 0);
    for (int i = 0; i < n; i++) {
      makeTree(i);
    }
  }

  void makeTree(int x) {
    parents[x] = x;
    size[x] = 1;
  }

  bool isSame(int x, int y) { return findRoot(x) == findRoot(y); }

  bool unite(int x, int y) {
    x = findRoot(x);
    y = findRoot(y);
    if (x == y) return false;
    // sizeが大きい方を親にする
    if (size[x] > size[y]) {
      parents[y] = x;
      size[x] += size[y];
    } else {
      parents[x] = y;
      size[y] += size[x];
    }
    return true;
  }

  int findRoot(int x) {
    if (x != parents[x]) {
      parents[x] = findRoot(parents[x]);
    }
    return parents[x];
  }

  int treeSize(int x) { return size[findRoot(x)]; }
};


int H, W, Q;
UnionFind UF;
bool used[2010][2010];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
void query1(int x, int y) {
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (used[nx][ny] == false) continue;
    int hash1 = (x - 1) * W + (y - 1);
    int hash2 = (nx - 1) * W + (ny - 1);
    UF.unite(hash1, hash2);
  }
  used[x][y] = true;
}

bool query2(int xa, int ya, int xb, int yb) {
  if (used[xa][ya] == false || used[xb][yb] == false) {
    return false;
  }
  int hash1 = (xa - 1) * W + (ya - 1);
  int hash2 = (xb - 1) * W + (yb - 1);
  return UF.isSame(hash1, hash2);
}

int main() {
  cin >> H >> W >> Q;
  UF = UnionFind(H * W);

  for (int i = 0; i < Q; i++) {
    int ty;
    cin >> ty;
    if (ty == 1) {
      int x, y;
      cin >> x >> y;
      query1(x, y);
    }
    if (ty == 2) {
      int xa, ya, xb, yb;
      cin >> xa >> ya >> xb >> yb;
      bool ans = query2(xa, ya, xb, yb);
      if (ans)
        cout << "Yes" << endl;
      else
        cout << "No" << endl;
    }
  }
  return 0;
}
