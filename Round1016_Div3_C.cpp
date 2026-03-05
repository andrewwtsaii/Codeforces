#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/*
obs: if k > 1, then the answer is instantly no.

suppose we have x.
the following subtracts k by 1 and can be repeated until k is 0

x = x * (digits in x * 10) + x;
= x(digits in x * 10 + 1)
this makes x composite unless x has 0 digits which isnt a case or if x = 1

if k = 1 we just need to check if x is prime

REMEMBER TO THINK OF EDGE CASES SUCH AS IF X = 1 WHERE ANSWER CHANGES DEPENDING ON K.

WRITE OUT TEST CASES
*/

int main(){
    ios::sync_with_stdio(0);
    cin.tie();

    ll tests;
    cin >> tests;

    for(ll t = 0; t < tests; t++){
        ll x, k;
        cin >> x >> k;

        if(x == 1 && k == 2){
            cout << "YES" << endl;
            continue;
        } else if(x == 1){
            cout << "NO" << endl;
            continue;
        }
        if(k > 1){
            cout << "NO" << endl;
        } else{
            bool possible = false;

            for(ll i = 2; i * i <= x; i++){
                if(x % i == 0){
                    possible = true;
                    cout << "NO" << endl;
                    break;
                }
            }
            if(!possible){
                cout << "YES" << endl;
            }
        }


    }
}
