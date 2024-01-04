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
 
int n,m,k;
cin>>n>>m>>k;
 
int arr[n];
int brr[m];
for(int i = 0 ; i < n ; i++) cin>>arr[i];
 
for(int j = 0 ; j < m ; j++) cin>>brr[j];
 
sort(arr,arr+n);
sort(brr,brr+m);
 
int ct = 0;

int i = 0 , j = 0;

while(i < n && j < m) {
    long long check = abs(arr[i] - brr[j]);

    if(check <= k) {
        ct++;
        i++;
        j++;
    }

    else {
        if(arr[i] - brr[j] > k) j++;
        else i++;
    }
}
 
cout<<ct<<"\n";
return 0;
}