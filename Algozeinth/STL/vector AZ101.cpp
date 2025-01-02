/* 
# Description
You are given Q queries and have to perform the following operations:

add x - add element x at the end of vector
remove - delete last element of the vector, if vector is not empty
print x - print the x-th character of the vector, if it exists, otherwise print 0. (0-indexing)
clear - empty the vector

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
    int n, x;
    vector<int> v;
    cin>>n;

    string str;
    for(int q=0; q<n; q++){
        cin>>str;
        if(str == "add"){
            cin>>x;
            v.push_back(x);
        }
        else if(str == "remove"){
            if(v.size() > 0) v.pop_back();
        }
        else if(str == "print"){
            cin>>x;
            if(x < v.size()) cout<<v[x]<<endl;
            else cout<<"0\n";
        }
        else{
            v.clear();
        }
    }

    
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



