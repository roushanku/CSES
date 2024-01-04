// J.S.R -- *roush*
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds; //find_by_order //order_of_key

bool ispossible(string s , int mid) {
    int i = 0 , j = 0;
    int n = s.size();
    unordered_map <int,int> mp;
    bool ok = false;
    while(j < n) {
        mp[s[j]]++;

        if(j-i+1 == mid) {
            if(mp.size() == 1) {
                ok = true;
                break;
            }
            mp[s[i]]--;
            if(mp[s[i]] == 0) mp.erase(s[i]);
            i++;
        }
        j++;
    }

    return ok;
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
string s;
cin>>s;

 int ans = 0;

//apr 1 : varibale size sliding window
// int i = 0 , j = 0;
// int n = s.size();


// int ct = 0;
// while(j < n) {
//     if(s[j] == s[i]) {
//         ans = max(ans,j-i+1); // varibale size sliding window
//         j++;
//     }

//     while(s[j] != s[i]) {
//         i++;
//     }
    
// }
// cout<<ans<<"\n";


//apr 2 : using binary search + sliding window -> csec give TLE in one testcase

int n = s.size();
int l = 1 , r = n;

while (l <= r) {
    int mid = l + (r-l)/2;

    if(ispossible(s,mid)) {
        ans = max(ans,mid);
        l = mid+1;
    }

    else r = mid-1;
}
cout<<ans<<"\n";
return 0;
}