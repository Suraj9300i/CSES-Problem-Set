/* 
# Description
You are given Q queries and have to perform the following operations:

add x - add element x at the end of queue
remove- delete front element of the queue, if queue is not empty
print - print the element at the first position, if queue is not empty, otherwise print 0

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
    cin>>n;

    queue<int> qu;
    string str;
    for(int q=0; q<n; q++){
        cin>>str;
        if(str == "add"){
            cin>>x;
            qu.push(x);
        }
        else if(str == "remove"){
            if(!qu.empty()) qu.pop();
        }
        else{
            if(qu.empty()) cout<<"0\n";
            else cout<<qu.front()<<endl;
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



