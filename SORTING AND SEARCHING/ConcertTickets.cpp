// J.S.R -- *roush*
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds; //find_by_order //order_of_key

// pair <int,bool> Ispossible(int x , int arr[] , int n) {
//     int l = 0 , r = n-1;
//     bool ok = false;
//     pair <int,bool> p;
//     while(l <= r) {
//         int mid = l + (r-l)/2;

//         if(arr[mid] <= x) {
//             ok = true;
//             break;
//         }

//         else 

//     }
//     p = {l,ok};
//     return p;
// }
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int n,m;
cin>>n>>m;

int arr[n],brr[m];

multiset <int> mst;
for(int i = 0 ; i < n ; i++) {
    cin>>arr[i];
    mst.insert(arr[i]);
}

for(int j = 0 ; j < m ; j++) cin>>brr[j];

for(int i = 0 ; i < m ; i++) {
    auto it = mst.upper_bound(brr[i]);

    if(it == mst.begin()) cout<<-1<<"\n";

    else{
        cout<<*(--it)<<"\n";
        mst.erase(it);
    }
}
return 0;
}