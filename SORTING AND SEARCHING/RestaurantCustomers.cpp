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
//We actually cannot compute the prefix sum array directly since 
//10^9
// and we will run out of memory when creating an array of size 

//Instead, we can either coordinate compress and compute the prefix sum over interesting intervals or 
//sweep over the intervals while maintaining a running prefix sum.

//If we put the start and end points into a list and sort them, 
//all we need to do is find the max sum of values over all prefixes of the list.

vector <pair<int,int>> v;

while(n--) {
    int a,b;
    cin>>a>>b;

    v.push_back({a,1});
    v.push_back({b,-1});
}

long long sum = 0;
long long mxsum = -1e15;
sort(v.begin(),v.end());

for(auto it : v){
    sum += it.second;
    mxsum = max(mxsum,sum);
}

cout<<mxsum<<"\n";
return 0;
}