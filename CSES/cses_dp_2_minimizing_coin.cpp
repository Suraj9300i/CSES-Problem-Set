#include<bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9 + 7;
const int INF = 1e9;

void solve() {
    int n, sum;
    cin>>n>>sum;

    vector<int> coins(n);
    for(int i=0; i<n; i++){
        cin>>coins[i];
    }


    vector<int> lastRow(sum+1, INF);
    lastRow[0] = 0;

    for(int i=1; i<=n; i++){
        vector<int> curRow(sum+1, INF);
        for(int j=0; j<=sum; j++){
            if(j < coins[i-1]) curRow[j] = lastRow[j];
            else curRow[j] = min(lastRow[j], 1 + curRow[j-coins[i-1]]);
        }
        lastRow = curRow;
    }

    cout<<(lastRow[sum] >= INF ? -1 : lastRow[sum]);
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin);
    freopen("output.txt","w",stdout);
    freopen("Error.txt","w",stderr);
    #endif

    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}



