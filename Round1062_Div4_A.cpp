#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie();

    ll tests;
    cin >> tests;

    for(ll t = 0; t < tests; t++){
        ll a, b, c, d;
        cin >> a >> b >> c >> d;

        if(a == b && b == c && c == d && d == a){
            cout << "YES" << endl;
        } else{
            cout << "NO" << endl;
        }
    }

}
