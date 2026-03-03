#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll arr[200001];

/*
obs 1: all diff parity, just sort
obs 2: all same parity, leave

can we split up somehow or something?

5 1 7 2
2 5 1 7
1 5 2 7
1 2 5 7

do we just count how many even numbers and then insert between odd nums? WHy does this work?

5 1 7 8
8 5 1 7
1 8 5 7
1 5 8 7
1 5 7 8

even numbers let us move things around?
a[0] = even
a[even] = a[0]
a[want] = a[even]
swap
we can move anything around using the even number

for every even number we optimize by 1 number?

just implementation somehow?

a number can only be moved to the next front position if a number exists of different parity to that new position
2 3 1 4
1 need to go to where 2 is. We need an odd number, we have
1 3 2 4
2 needs to go where 3 is, we need an even number
1 2 3 4

4 1 5 7 8 8 1 2
1 needs to go where 4 is, need odd number
1 4 5 7 8 8 1 2
1 needs to go where 4 is, need odd number
1 1 4 5 7 8 8 2
2 needs to go where 4 is need odd number not used
1 1 2 4 5 7 8 8
sorted

TOO SLOW, no proof

obs: we can swap ANY 2 numbers as long as a number of different parity exists outside of the current
sorted prefix of the array

possible idea: if 1 number exists of other parity you can just sort, otherwise its the same
^^ turns out to be solution
*/
int main(){
    ios::sync_with_stdio(0);
    cin.tie();

    // 2 5 1 7
    //1 5 2 7
    //1 2 5 7


    ll tests;
    cin >> tests;

    for(ll t = 0; t < tests; t++){
        ll toys;
        cin >> toys;

        memset(arr, 0, sizeof(arr));

        bool even = false, odd = false;
        for(ll i = 0; i < toys; i++){
            cin >> arr[i];
            if(arr[i] % 2 == 0){
                even = true;
            } else{
                odd = true;
            }
        }

        if(even == true && odd == true){
            sort(arr, arr + toys);
        }

        for(ll i = 0; i < toys; i++){
            cout << arr[i] << " \n"[i == toys - 1];
        }
    }

}

