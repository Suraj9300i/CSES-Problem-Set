#include<bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9 + 7;
const int INF = 1e18;

void fastIO(bool useFiles = false) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    if (useFiles) {
        #ifndef ONLINE_JUDGE 
        freopen("input.txt", "r", stdin);
        freopen("output.txt","w",stdout);
        freopen("Error.txt","w",stderr);
        #endif
    }
}

// Debugging utilities
template<class T> void _print(T x) { cerr << x; }
template<class T> void _print(vector<T> v) { cerr << "[ "; for(T ele : v) cerr << ele << " "; cerr << "]\n"; }
template<class T> void _print(T arr[], int n) { cerr << "[ "; for (int i = 0; i < n; i++) cerr << arr[i] << " "; cerr << "]\n"; }
template<class T1, class T2> void _print(pair<T1, T2> p) { cerr << "{" << p.first << ", " << p.second << "} "; }
template<class T> void _print(set<T> v) { cerr << "[ "; for (T ele : v) cerr << ele << " "; cerr << "]"; }
template<class T1, class T2> void _print(map<T1, T2> m) { cerr << "[ "; for (auto p : m) cerr << "{" << p.first << ", " << p.second << "} "; cerr << "]"; }

int dfs(vector<vector<int>> &graph, vector<int> &cost, int node, vector<int> &vis, vector<int> &profit){
    if(vis[node] != -1) return vis[node];

    if(graph[node].size() == 0){
        return vis[node] = cost[node];
    }

    int buy = cost[node];
    int mxSell = 0;
    for(int nbr:graph[node]){
        mxSell = max(mxSell, dfs(graph, cost, nbr, vis, profit));
    }
    
    profit[node] = mxSell - buy;

    return vis[node] = mxSell;
}

void solve() {
    int n, m, u, v;
    cin>>n>>m;

    vector<vector<int>> graph(n+1);
    vector<int> cost(n+1, 0);

    for(int i=1; i<=n; i++){
        cin>>cost[i];
    }

    for(int i=1; i<=m; i++){
        cin>>u>>v;
        graph[u].push_back(v);
    }

    vector<int> indegree(n+1, 0);
    for(int i=1; i<=n; i++){
        for(int nbr:graph[i]){
            indegree[nbr]++;
        }
    }

    vector<int> vis(n+1, -1);
    vector<int> profit(n+1, -INF);
    for(int i=1; i<=n; i++){
        if(indegree[i] == 0){
            dfs(graph, cost, i, vis, profit);
        }
    }

    int mx = -INF;
    for(int i=1; i<=n; i++){
        mx = max(mx, profit[i]);
    }

    cout<<mx;
}

signed main() {
    fastIO(true);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}



