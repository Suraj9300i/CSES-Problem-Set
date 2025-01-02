#include<bits/stdc++.h>

#define int long long
#define endl "\n"

using namespace std;

const int mod = 1e9 + 7;
const int INF = 1e18;

void fastIO() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin);
    freopen("output.txt","w",stdout);
    freopen("Error.txt","w",stderr);
    #endif
}

/***********॥ ॐ श्री गणेशाय नमः, सरस्वत्यै नमः ॥****************/

void init() {
    int m, des, n, s, d, p, k;
    cin >> m; // cities
    cin >> des; // destination
    cin >> n; // flights

    vector<vector<pair<int, int>>> graph(m); // Fixed graph declaration

    for (int i = 0; i < n; i++) {
        cin >> s >> d >> p;
        s--, d--;
        graph[s].push_back({d, p});
    }
    cin >> k;

    vector<vector<int>> price(m, vector<int>(k + 1, INF)); 
    vector<vector<bool>> vis(m, vector<bool>(k + 1, false));

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({0, {0, 0}}); // (price, (flights_used, current_node))
    price[0][0] = 0;

    while (!pq.empty()) {
        int cur_node = pq.top().second.second;
        int flights_till_node = pq.top().second.first;
        int price_till_node = pq.top().first;
        pq.pop();

        if (vis[cur_node][flights_till_node]) continue;
        vis[cur_node][flights_till_node] = true;

        for (auto nbr : graph[cur_node]) {
            int nbr_node = nbr.first;
            int nbr_cost = nbr.second;
            if ((flights_till_node + 1) <= k && (price_till_node + nbr_cost) < price[nbr_node][flights_till_node + 1]) {
                price[nbr_node][flights_till_node + 1] = price_till_node + nbr_cost;
                pq.push({price[nbr_node][flights_till_node + 1], {flights_till_node + 1, nbr_node}});
            }
        }
    }

    int mn = INF;
    for (int i = 0; i <= k; i++) {
        mn = min(mn, price[des - 1][i]);
    }

    cout << (mn == INF ? -1 : mn) << endl; 
}

signed main() {
    fastIO();
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        init();
    }
    return 0;
}