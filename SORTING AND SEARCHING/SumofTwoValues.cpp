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
int n,x;
cin>>n>>x;

vector <pair<int,int>> v;
for(int i = 0 ; i < n ; i++) {
    int x;
    cin>>x;

    v.push_back({x,i+1});
}

sort(v.begin(),v.end());

int i = 0 , j = n-1;
bool ok = false;
while(i < j) {
    if(v[i].first + v[j].first == x) {
        cout<<v[i].second<<" "<<v[j].second<<"\n";
        return 0;
    }

    else if(v[i].first + v[j].first >  x) j--;

    else i++;
}
cout<<"IMPOSSIBLE"<<"\n";

}