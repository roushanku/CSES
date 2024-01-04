//https://codeforces.com/problemset/problem/295/B

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

int a[n+1][n+1];
for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
        cin>>a[i][j];
    }
}

vector <int> arr(n);
for(int i=0;i<n;i++) cin>>arr[i];
reverse(arr.begin(),arr.end());

vector <long long> ans;
for(int via=0;via<n;via++){
    int k = arr[via];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            a[i][j] = min(a[i][j],a[i][k]+a[k][j]);
        }
    }
    long long sum=0;
    for(int i=0;i<=via;i++){
        for(int j=0;j<=via;j++){
            sum+=a[arr[i]][arr[j]];
        }
    }
    ans.push_back(sum);
}

reverse(ans.begin(),ans.end());

for(auto it:ans) cout<<it<<" ";
cout<<"\n";
return 0;
}