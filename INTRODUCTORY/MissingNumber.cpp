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


long long sum = 0;
// long long check = (n*(n+1))/2;
vector <int> vis(n+1,0);

for(int i = 0 ; i < n-1 ; i++) {
    int u;
    cin>>u;
    vis[u] = 1;
}

for(int i = 1 ; i <= n ; i++) {
    if(!vis[i]) {
        cout<<i<<"\n";
        break;
    }
}
return 0;
}