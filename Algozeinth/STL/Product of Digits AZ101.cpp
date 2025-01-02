/* 
# Description

You are given the digits of a positive number N. 
Find the product of its digits. 
Since the product can be large, print it modulo 109 + 7.
It is guaranteed that the number begins with a non-zero digit.

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
    int n,x;
    cin>>n;

    int prod = 1;
    for(int i=0; i<n; i++){
        cin>>x;
        prod = (prod * x) % mod;
    }
    cout<<prod<<endl;
    
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



