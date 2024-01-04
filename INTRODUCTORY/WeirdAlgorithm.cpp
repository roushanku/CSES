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

long long n;
cin>>n;
vector <long long> ans;
while( n != 1) {
    ans.push_back(n);
    if(n&1) n = (n*3 + 1);
    else n = (n>>1);
}
ans.push_back(1);
for(auto it:ans) cout<<it<<" ";
cout<<"\n";
return 0;
}