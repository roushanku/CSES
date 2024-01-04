// J.S.R -- *roush*
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds; //find_by_order //order_of_key

int trailingZero(int n) {
    if(n <= 0) return 0;

    int ct = 0;
    for(int i = 5 ; n / i >= 1 ; i *= 5) {
        ct += (n/i);
    }

    return ct;
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int n;
cin>>n;
// int two = 0 , five = 0;
// for(int i = 1 ; i <= n ; i++) {
//     int p = i;

// //    while(p%2 == 0){
// //         two++;
// //         p/=2;
// //     }

//     while(p%5 == 0){
//         five++;
//         p/=5;
//     }
// }

//Trailing 0s in n! = Count of 5s in prime factors of n! = floor(n/5) + floor(n/25) + floor(n/125) + ....
int ans = trailingZero(n);
cout<<ans<<"\n";
return 0;
}