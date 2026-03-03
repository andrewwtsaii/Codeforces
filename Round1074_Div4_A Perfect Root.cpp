#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

//straight forward - read problem carefully
int main(){
    ios::sync_with_stdio(0);
    cin.tie();

    ll tests;
    cin >> tests;

    for(ll t = 0; t < tests; t++){
        ll n;
        cin >> n;

        for(ll i = 1; i <= n; i++){
            cout << i << " \n"[i == n];
        }
    }
}
