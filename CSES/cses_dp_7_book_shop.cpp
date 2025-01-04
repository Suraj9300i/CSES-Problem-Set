#include<bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9 + 7;


void solve() {
    int n, price;
    cin>>n>>price;

    vector<int> prices(n), pages(n);
    for(int i=0; i<n; i++) cin>>prices[i];
    for(int i=0; i<n; i++) cin>>pages[i];

    vector<int> lastRow(price+1, 0);
    
    for(int i=1; i<=n; i++){
        vector<int> curRow(price+1, 0);
        for(int j=1; j<=price; j++){
            if(j < prices[i-1]) curRow[j] = lastRow[j];
            else curRow[j] = max(lastRow[j], lastRow[j-prices[i-1]] + pages[i-1]);
        }
        lastRow = curRow;
    }

    cout<<lastRow[price];
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



