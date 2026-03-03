#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie();

    ll tests;
    cin >> tests;

    for(ll q = 0; q < tests; q++){
        ll n;
        cin >> n;

        map<char, int> freq1;
        map<char, int> freq2;

        string s, t;
        cin >> s >> t;

        for(auto u: s){
            freq1[u]++;
        }

        for(auto u: t){
            freq2[u]++;
        }

        bool possible = true;

        for(auto u: freq1){
            if(freq2.find(u.first) == freq2.end()){
                possible = false;
                break;
            } else if(freq2[u.first] != u.second){
                possible = false;
                break;
            }
        }


        if(possible){
            cout << "YES" << endl;
        } else{
            cout << "NO" << endl;
        }
    }

}
