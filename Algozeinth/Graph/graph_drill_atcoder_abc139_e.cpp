#include<bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9 + 7;

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
    int n, ele;
    cin>>n;

    int x = 1;

    map<pair<int, int>, int> mp;
    map<int, vector<int>> graph;
    

    for(int i=1; i<=n; i++){
        int node = -1;
        for(int j=1; j<n;j++){
            cin>>ele;

            int nbr = -1;
            if(mp.find({i, ele}) != mp.end()) nbr = mp[{i, ele}];
            else if(mp.find({ele, i}) != mp.end()) nbr = mp[{ele, i}];
            else{
                nbr = x++;
                mp[{i, ele}] = nbr;
                mp[{ele, i}] = nbr;
            }

            if(j != 1){
                graph[node].push_back(nbr);
            }
            node = nbr;
        }
    }

    vector<int> indegree(x, 0);
    for(int i=1; i<x; i++){
        for(int nbr:graph[i]){
            indegree[nbr]++;
        }
    }

    queue<int> qu;
    vector<int> dis(x, 0);
    vector<int> topo;
    for(int i=1; i<x; i++){
        if(indegree[i] == 0){
            qu.push(i);
            dis[i] = 1;
        }
    }

    while(!qu.empty()){
        int node = qu.front();
        qu.pop();

        topo.push_back(node);

        for(int nbr:graph[node]){
            if(indegree[nbr] > 0){
                indegree[nbr]--;

                if(indegree[nbr] == 0){
                    qu.push(nbr);
                    dis[nbr] = dis[node] + 1;
                }
            }
        }
    }

    int ans = 1;
    for(int i=1; i<x; i++){
        ans = max(ans, dis[i]);
    }

    if(topo.size() != x-1) cout<<-1;
    else cout<<ans;
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



