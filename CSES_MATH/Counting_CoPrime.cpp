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
vector <long long> cnt(1e6+10,0);

for(int i=0;i<n;i++){
    cin>>arr[i];
    cnt[arr[i]]++; //step 1
}

vector <long long> cnt1(1e6+10,0); 

for(int i=1;i<=1000000;i++){
    for(int j=i;j<=1000000;j+=i){
        cnt1[i]+=cnt[j]; // step 2(count of total no of multiple of cnt1[i])
    }

    cnt1[i] = cnt1[i] * (cnt1[i]-1) / 2; //step 3 (count of pair- nc2) we cando it for triplet and so ond.....(ncr)
}

for(int i=1000000;i>=1;i--){
    for(int j=2*i;j<=1000000;j+=i){
        cnt1[i]-=cnt1[j];
    }
}

cout<<cnt1[1]<<"\n"; // bcz we have to find for gcd==1; we can do it for any val of gcd

return 0;
}