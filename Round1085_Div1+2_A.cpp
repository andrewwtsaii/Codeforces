#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/*
always optimal to change everything possible to 1's first this allows us to perform the most operations since
a number needs to be between two 1s.

for min 0's we want to change from left to right since it gives us the most space to change most 1's to 0's.
*/
int main(){
    ios::sync_with_stdio(0);
    cin.tie();

    ll tests;
    cin >> tests;

    for(ll t = 0; t < tests; t++){
        ll n;
        cin >> n;

        string s;
        cin >> s;

        for(ll i = 1; i < s.size() - 1; i++){
            if(s[i-1] == '1' && s[i+1] == '1'){
                s[i] = '1';
            }
        }

        ll minAns = 0, maxAns = 0;

        for(ll i = 0; i < s.size(); i++){
            if(s[i] == '1'){
                maxAns++;
            }
        }

        for(ll i = 1; i < s.size() - 1; i++){
            if(s[i-1] == '1' && s[i+1] == '1'){
                s[i] = '0';
            }
        }
        for(ll i = 0; i < s.size(); i++){
            if(s[i] == '1'){
                minAns++;
            }
        }

        cout << minAns << " " << maxAns << endl;
    }


}
