/* 
# Description
Implement a queue using 2 stacks. You will be given the following type of Q queries:

push x - add x to the queue
pop - pop the front element of the queue, you also have to print the element you have popped.
front - find the element at the front of the queue

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

    stack<int> st1;
    stack<int> st2;
    string str;

    for(int q=0; q<n; q++){
        cin>>str;
        if(str == "push"){
            cin>>x;
            st1.push(x);
        }
        else if(str == "pop"){
            if(st2.empty()){
                while(!st1.empty()){
                    int ele = st1.top();
                    st1.pop();
                    st2.push(ele);
                }
            }
            cout<<st2.top()<<endl;
            st2.pop();
        }
        else{
            if(st2.empty()){
                while(!st1.empty()){
                    int ele = st1.top();
                    st1.pop();
                    st2.push(ele);
                }
            }
            cout<<st2.top()<<endl;
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



