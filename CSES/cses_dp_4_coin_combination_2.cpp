#include<bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9 + 7;


void solve() {
    int n, sum;
    cin>>n>>sum;
    vector<int> coins(n);
    for(int i=0; i<n; i++){
        cin>>coins[i];
    }

    vector<int> lasRow(sum+1, 0);
    lasRow[0] = 1;

    for(int i=1; i<=n; i++){
        vector<int> curRow(sum+1, 0);
        curRow[0] = 1;
        for(int j=1; j<=sum; j++){
            if(j < coins[i-1]) curRow[j] = lasRow[j];
            else curRow[j] = (lasRow[j] + curRow[j - coins[i-1]]) % mod;
        }
        lasRow = curRow;
    }

    cout<<lasRow[sum];
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



