#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;

/*
木の直径
重みを考慮しない場合は全て1にする
ref: https://algo-logic.info/tree-diameter/
test: https://atcoder.jp/contests/typical90/tasks/typical90_c
*/

using Graph = vector<vector<pair<ll, int>>>;

template<typename T>
pair<T, int> dfs(const Graph &G, int v, int par) {
  pair<T, int> ret((T)0, v);
  for(auto g : G[v]){
    if(g.second == par) continue;
    auto next = dfs<T>(G, g.second, v);
    next.first += g.first;
    if(ret.first < next.first) ret = next;
  }
  return ret;
}

template<typename T>
T tree_diameter(const Graph &G){
  pair<T, int> p = dfs<T>(G, 0, -1);
  pair<T, int> q = dfs<T>(G, p.second, -1);
  return q.first;
}

int main() {
  int N;
  cin >> N;
  Graph G(N);
  for (int i = 0; i < N - 1; ++i) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    G[a].push_back({1, b});
    G[b].push_back({1, a});
  }

  auto ans = tree_diameter<ll>(G);
  cout << ans + 1 << endl;
}
