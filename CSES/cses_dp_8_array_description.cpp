#include<bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9 + 7;
int n, m;
int memo[100001][101];

int rec(vector<int> &arr, int cur, int last){
    if(cur == n) return 1;
    if(memo[cur][last] != -1) return memo[cur][last];

    if(arr[cur] != 0){
        if(cur > 0 && abs(arr[cur] - last) > 1){
            return memo[cur][last] = 0;
        }
        return memo[cur][last] = rec(arr, cur+1, arr[cur]);
    }

    int start = (cur == 0) ? 1 : last-1;
    int end = (cur == 0) ? m : last+1;
    int cnt = 0;
    for(int i=start; i<=end; i++){
        if(i >= 1 && i <= m){
            cnt = (cnt + rec(arr, cur+1, i)) % mod;
        }
    }

    return memo[cur][last] = cnt;
}


void solve() {
    
    cin>>n>>m;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    memset(memo, -1, sizeof(memo));

    int ans = rec(arr, 0, 0);
    cout<<ans<<endl;


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



