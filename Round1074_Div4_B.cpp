#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

//main idea: we just want maximum number at front
//this maximizes number of terms the biggest number is in.
//answer is just that number * number of terms
int main(){
    ios::sync_with_stdio(0);
    cin.tie();


    ll tests;
    cin >> tests;

    for(ll t = 0; t < tests; t++){
        ll nums;
        cin >> nums;

        ll maxNum = 0;
        for(ll i = 0; i < nums; i++){
            ll num;
            cin >> num;
            maxNum = max(num, maxNum); //we want the maximum number at front
            //so its in most sum terms
        }

        ll ans = 0;
        ans = nums * maxNum;

        cout << ans << endl;


    }
}
