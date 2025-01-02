/* 
# Description

There are N objects, and each object has some price. The price of ith object is Ai.
You have total money M, and you want to buy as many objects as possible.
Find the maximum objects that you can buy?

*/


#include<bits/stdc++.h>

#define int long long
#define endl "\n"

using namespace std;

const int mod = 1e9 + 7;

void fastIO() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
}

/***********॥ ॐ श्री गणेशाय नमः, सरस्वत्यै नमः ॥****************/

void init() {
    int n, m;
    cin>>n>>m;

    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    sort(arr.begin(), arr.end());

    int cnt = 0;
    for(int price: arr){
        m -= price;
        if(m < 0) break;
        cnt++;
    }
    cout<<cnt<<endl;
    
}

signed main() {
    fastIO();
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        init();
    }
    return 0;
}



