#include<bits/stdc++.h>
#define int long long
#define state pair<int, pair<int, int>>
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


void solve() {
    int n, m, u, v, c;
    cin>>n>>m;
    vector<vector<pair<int, int>>> graph(n+1);
    for(int i=0; i<m; i++){
        cin>>u>>v>>c;
        graph[u].push_back({v, c});
        graph[v].push_back({u, c});
    }

    vector<int> dis(n+1, INF);
    vector<bool> vis(n+1, false);
    priority_queue<state, vector<state>, greater<state>> pq;

    pq.push({0, {1, -1}});
    dis[1] = 0;

    while(!pq.empty()){
        int time = pq.top().first;
        int node = pq.top().second.first;
        int com = pq.top().second.second;
        pq.pop();

        if(vis[node]) continue;
        vis[node] = true;


        for(auto nbr:graph[node]){
            int nbr_node = nbr.first;
            int nbr_com = nbr.second;
            int cost = (nbr_com != com ? 1 : 0);
            if(time + cost < dis[nbr_node]){
                dis[nbr_node] = time + cost;
                pq.push({dis[nbr_node], {nbr_node, nbr_com}});
            }
        }

    }

    cout<<(dis[n] == INF ? -1 : dis[n]);
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



