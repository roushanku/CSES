// J.S.R -- *roush*
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds; //find_by_order //order_of_key

void tower(int n , int a , int c , int b , vector <pair<int,int>> &v) {
    if(n == 0) return;

    tower(n-1,a,b,c,v);
    //cout<<a<<" "<<c<<"\n";
    v.push_back({a,c});

    tower(n-1,b,c,a,v);

}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n;
cin>>n;

vector <pair<int,int>> v;
tower(n,1,3,2,v);
cout<<v.size()<<"\n";
for(auto it:v) cout<<it.first<<" "<<it.second<<"\n";
return 0;
}