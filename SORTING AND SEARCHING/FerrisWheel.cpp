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

int arr[n];
for(int i = 0 ; i < n ; i++) cin>>arr[i];

long long ct = 0;
sort(arr,arr+n);
int i = 0 , j = n-1;
vector <int> vis(n,0);
while(i < j) {
    long long temp = arr[i] + arr[j];

    if(temp > x) {
        j--;
    }

    else {
        
        ct++;
        vis[i] = 1;
        vis[j] = 1;
        i++;
        j--;
    }

}
for(int i = 0 ; i < n ; i++) {
    if(!vis[i]) ct++;
}
cout<<ct<<"\n";
return 0;
}