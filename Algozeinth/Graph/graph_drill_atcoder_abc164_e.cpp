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
    int n, m, s, u, v, c, d, a, b;
    cin>>n>>m>>s;
    int amax = 0;

    // node, silver, time
    vector<vector<vector<int>>> graph(n+1);
    for(int i=0; i<m; i++){
        cin>>u>>v>>a>>b;
        graph[u].push_back({v, a, b});
        graph[v].push_back({u, a, b});
    }

    // silver, time
    vector<pair<int, int>> city(n+1);
    for(int i=1; i<=n; i++){
        cin>>city[i].first>>city[i].second;
    }

    int msn = 2500;

    s = min(s, msn);

    vector<vector<int>> dis(n+1, vector<int>(msn + 1, INF));
    vector<vector<bool>> vis(n+1, vector<bool>(msn + 1, false));
    priority_queue<state, vector<state>, greater<state>> pq;
    pq.push({0, {1, s}});
    dis[1][s] = 0;

    while(!pq.empty()){
        int time = pq.top().first;
        int node = pq.top().second.first;
        int silver = pq.top().second.second;
        int mxex = (msn + city[node].first - 1) / city[node].first;
        pq.pop();


        if(vis[node][silver]) continue;
        vis[node][silver] = true;

        for(auto nbr:graph[node]){
            int nbr_node = nbr[0];
            int nbr_silver = nbr[1];
            int nbr_time = nbr[2];
            if(silver - nbr_silver >= 0 && time + nbr_time <= dis[nbr_node][silver - nbr_silver]){
                dis[nbr_node][silver - nbr_silver] = time + nbr_time;
                pq.push({dis[nbr_node][silver - nbr_silver], {nbr_node, silver - nbr_silver}});
            }
        }

        if(silver < msn){
            int ns = min(silver + city[node].first, msn);
            pq.push({time + city[node].second, {node, ns}});
        }
    }

    for(int i=2; i<=n; i++){
        int mn = INF;
        for(int j=0; j<=msn; j++){
            mn = min(mn, dis[i][j]);
        }
        cout<<mn<<endl;
    }
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



