#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll arr[100001];
vector<int> v;
/*
obs (From K.H): answer must be prime
suppose it's not prime, it can be broken into prime factors. None of its prime factors are divisible, since no
prime factors are shared (otherwise it would be divisible)

we can minimize primes checking to 53.

If 59 is our answer then that means all numbers are divisible by all primes from 1 to 53.
This then means that they have to be the products of all primes from 1 to 53. This is > 10^18 though

needed editorial (K.H + AI)
*/

vector<ll> primes = {1,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};

int main(){
    ios::sync_with_stdio(0);
    cin.tie();

    ll tests;
    cin >> tests;

    for(ll t = 0; t < tests; t++){
        ll n;
        cin >> n;

        memset(arr, 0, sizeof(arr));
        bool done = false;

        ll curr = 53;
        for(ll i = 0; i < n; i++){
            cin >> arr[i];

            if(!done){
                for(auto u: primes){
                    if(arr[i] % u != 0){
                        curr = min(curr, u);
                        break;
                    }
                }
            }
        }

        cout << curr << endl;

    }

}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll arr[100001];
vector<int> v;
/*
obs (From K.H): answer must be prime
suppose it's not prime, it can be broken into prime factors. None of its prime factors are divisible, since no
prime factors are shared (otherwise it would be divisible)

we can minimize primes checking to 53.

If 59 is our answer then that means all numbers are divisible by all primes from 1 to 53.
This then means that they have to be the products of all primes from 1 to 53. This is > 10^18 though

needed editorial (K.H + AI)
*/

vector<ll> primes = {1,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};

int main(){
    ios::sync_with_stdio(0);
    cin.tie();

    ll tests;
    cin >> tests;

    for(ll t = 0; t < tests; t++){
        ll n;
        cin >> n;

        memset(arr, 0, sizeof(arr));
        bool done = false;

        ll curr = 53;
        for(ll i = 0; i < n; i++){
            cin >> arr[i];

            if(!done){
                for(auto u: primes){
                    if(arr[i] % u != 0){
                        curr = min(curr, u);
                        break;
                    }
                }
            }
        }

        cout << curr << endl;

    }

}
