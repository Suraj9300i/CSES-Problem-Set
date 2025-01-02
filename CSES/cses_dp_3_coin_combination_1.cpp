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

    vector<int> dp(sum+1, 0);
    dp[0] = 1;
    for(int i=1; i<=sum; i++){
        int cnt = 0;
        for(int coin:coins){
            if(i - coin >= 0){
                cnt = (cnt + dp[i - coin]) % mod;
            }
        }
        dp[i] = cnt;
    }

    cout<<dp[sum];
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



