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


int calcWaitTime(int n, int k){
    int c = ((n + k - 1) / k) * k;
    return c - n;
}


void solve() {
    int n, m, src, des, u, v, t, k;
    cin>>n>>m>>src>>des;

    vector<vector<vector<int>>> graph(n+1);
    for(int i=0; i<m; i++){
        cin>>u>>v>>t>>k;
        graph[u].push_back({v, t, k});
        graph[v].push_back({u, t, k});
    }

    vector<int> dis(n+1, INF);
    vector<bool> vis(n+1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    dis[src] = 0;

    while(!pq.empty()){
        int node = pq.top().second;
        int time = pq.top().first;
        pq.pop();

        if(vis[node]) continue;
        vis[node] = true;

        for(auto v:graph[node]){
            int nbr = v[0];
            int nbr_time = v[1];
            int train = v[2];
            int wait = calcWaitTime(time, train);
            if(time + nbr_time + wait < dis[nbr]){
                dis[nbr] = time + nbr_time + wait;
                pq.push({dis[nbr], nbr});
            }
        }
    }

    cout<<(dis[des] == INF ? -1 : dis[des]);

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



