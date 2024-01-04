// J.S.R -- *roush*
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds; //find_by_order //order_of_key

bool sortbysecdesc(const pair<int,int> &a,
                   const pair<int,int> &b)
{
       return a.second<b.second;
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int n;
cin>>n;

vector <pair<int,int>> v;

for(int i = 1 ; i <= n ; i++) {
    int a,b;
    cin>>a>>b;

    v.push_back({a,b});
}

sort(v.begin(),v.end(),sortbysecdesc);

int last = v[0].second;
int ct = 1;

for(int i = 1 ; i < n ; i++) {
    //cout<<"a"<<"\n";
    if(v[i].first < last) {

        continue;
    }

    last = v[i].second;
    ct++;
}

cout<<ct<<"\n";
return 0;
}