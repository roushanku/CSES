// J.S.R -- *roush*
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds; //find_by_order //order_of_key
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int n;
cin>>n;

int arr[n];
for(int i = 0 ; i < n ; i++) cin>>arr[i];

multiset <int> mst;
int ct = 0;
for(int i = 0 ; i < n ; i++) {
    auto it = mst.upper_bound(arr[i]);
    if(it == mst.end()) {
        mst.insert(arr[i]);
    }

    else{
        mst.erase(it);
        mst.insert(arr[i]);
    }
}

cout<<mst.size()<<"\n";
return 0;
}