// J.S.R -- *roush*
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds; //find_by_order //order_of_key

long long FindmnWt(int level , long long arr[] , long long sum , long long currsum,int n) {
    if(level >= n) {
        return (abs(sum - (2*currsum)));
        
    }

    return min(FindmnWt(level+1,arr,sum,currsum+arr[level],n) , FindmnWt(level+1,arr,sum,currsum,n));


}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int n;
cin>>n;

long long arr[n];
long long sum = 0;
for(int i = 0 ; i < n ; i++) {
    cin>>arr[i];
    sum += arr[i];
}

// bool dp[n+1][sum+1];

// for(int i = 0 ; i < n+1 ; i++) {
//     for(long long j = 0 ; j < sum+1 ; j++) {

//         if(i == 0) dp[i][j] = false;
//         if(j == 0) dp[i][j] = true;

//     }
// }

// for(long long i = 1 ; i < n+1 ; i++) {
//     for(long long j = 1 ; j < sum+1 ; j++) {
//         if(arr[i-1] <= j) {
//             dp[i][j] = dp[i-1][j-arr[i-1]] | dp[i-1][j];
//         }
//         else dp[i][j] = dp[i-1][j];
//     }
// }

// long long mn = 1e12;
// for(long long i = 0 ; i <= (sum/2) ; i++) {
//     if(dp[n][i]) mn = min(mn,sum-(2*i));
// }

long long ans = FindmnWt(0,arr,sum,0,n);
cout<<ans<<"\n";
return 0;
}