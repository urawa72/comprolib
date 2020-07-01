#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

vector<bool> seen;
void dfs(const Graph &g, int v){
    seen[v] = true;
    for(auto next_v : g[v]){
        if(seen[next_v]) continue;
        dfs(g, next_v);
    }
}

// DFS
int main() {
    int n, m; cin >> n >> m;
    Graph g(n);
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        // 無向グラフ
        g[a].push_back(b);
        g[b].push_back(a);
    }
    seen.assign(n, false);
    dfs(g, 0);
}
