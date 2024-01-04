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
for(int i = 0 ; i < n ; i++) cin>>arr[i];

unordered_map <long long,long long> mp;

long long i = 0 , j = 0;
long long mx = -1e9;
while(j < n) {
    mp[arr[j]]++;

    while(mp[arr[j]] > 1) {
        mp[arr[i]]--;
        if(mp[arr[i]] == 0) mp.erase(arr[i]);
        i++;
    }

    mx = max(mx,j-i+1);
    j++;
}

// while(j < n) {
//     i = max(mp[arr[j]],i);

//     mx = max(mx,j-i+1);

//     mp[arr[j]] = j+1;
//     j++;
// }

cout<<mx<<"\n";
return 0;
}