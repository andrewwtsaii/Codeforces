#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/*
first idea: binary search on the answer?

if X works, then numbers >= X will also work. likewise if it doesn't numbers < X won't work.

we always want to set maximum animatronic to 0.

lft bound = 0, rht bound = night length

binary search might not work: IMPORTANT -> WE DON't ACTUALLY SEE THE ANIMATRONIC VALUES AFTER EACH NIGHT
WE MUST CONSIDER WORST CASE

note: if each animatronic value is spread out then flashlight won't help much, but if it isn't spread out
then it increases the maximum animatronic value

the worst case scenario for us is increasing x animatronics +1 where x = flashlights + 1.
This doesn't waste any additions.

Thus our X is simply the number the x'th animatronic will become

why are we given the specific times of each flashlight shine then? Because after each shine
we can focus additions on the animatronics who aren't reset

if animatronics <= flashlights, the answer is different

We need to figure out the method of adding to animatronics such that it results in the max overall danger.
Is it always optimal to only increase 2 animatronics?

obs: If we only have one animatronic the answer is simply nightLength - a[n]

if we only increase 2 animatronics does it matter how we split this up?
is the strategy to increase flashlights + 1 animatronics???
DEFINITELY NOT ONLY INCREASING 2 ANIMATRONICS

case: a = 8, 9  l = 12, animatronics = 4
increasing 2 gives 4
increasing 3 gives 6.
increasing 4 gives 5.
Do we binary search on the number of animatronics to increase? <- is it guaranteed if x works then x + 1 works?
no binary search probably won't help

Increasing flashlights + 1 animatronics is optimal since it guarantees all additions contribute in some way, we
split evenly so we don't waste adding to a maximum that will get destroyed anyways

Addition strategy: NEVER ADD TO THE CURRENT MAXIMUM UNLESS EVERYTHING IS TIED

other case: flashlights >= animatronics

Obs: Initial addition each animatronic = a[0]/animatronics. Then add 1 to each for remainder.

case 1: flashlights < animatronics
when flashlight used, add to remaining animatronics that we've already added to equally. (NEVER ADDING TO MAXIMUM UNLESS TIED).
case 2: flashlights >= animatronics
we just consider all animatronics. We add to all of them equally maximizing until flashlights remaining is < animatronics then
it's now case 1. How to simulate or get answer efficiently?

can't keep looping through checking minimums -> do we just keep track of currMaximum?
how to know if everything is maximum?

IMPORTANT: m*l <= 2*10^5

O(m*l) works!!!

Just brute force using our adding technique

quite easy problem actually

PROBLEM: WE NEED TO INCREMENT MINIMUM NOT JUST NON MAXIMUM
^^ RECEIVED WA IN CONTEST BECASUE OF THIS. TRY AND PROVE EVERYTHING

INCREMENTING NON MINIMUM WASTES INCREMENT SINCE EVEN IF NOT NEXT FLASHLIGHT, FOR EXAMPLE SECOND LAST FLASHLIGHT WOULD RESET IT ANYWAYS
*/
queue<ll> times;
vector<ll> v;
set<ll> flashed;
int main(){
    ios::sync_with_stdio(0);
    cin.tie();

    ll tests;
    cin >> tests;

    for(ll t = 0; t < tests; t++){
        ll flashlights, animatronics, nightLength;
        cin >> flashlights >> animatronics >> nightLength;

        while(!times.empty()){
            times.pop();
        }
        flashed.clear();
        v.clear();
        for(ll i = 0; i < flashlights; i++){
            ll num;
            cin >> num;
            times.push(num);
        }

        for(ll i = 0; i < animatronics; i++){
            v.push_back(0);
        }

        ll currTime = 1;
        while(currTime <= nightLength && times.size() >= animatronics){
            ll currMax = v[0];
            ll currMaxInd = 0;
            ll currMin = v[0];
            ll currMinInd = 0;
            for(ll i = 1; i < animatronics; i++){
                if(v[i] < currMin){
                    currMin = v[i];
                    currMinInd = i;
                }
            }

            v[currMinInd]++;


            if(currTime == times.front()){
                currMax = v[0];
                currMaxInd = 0;
                for(ll i = 1; i < animatronics; i++){
                    if(v[i] > currMax){
                        currMax = v[i];
                        currMaxInd = i;
                    }
                }

                v[currMaxInd] = 0;
                times.pop();
            }
            currTime++;
        }

        //if we start with less flashlights than animatronics - 1
        if(times.size() < animatronics - 1){
            for(ll i = times.size()+1; i < animatronics; i++){
                flashed.insert(i);
            }
        }

        //times.size is now animatronics - 1 which means we need EXACTLY n animatronics where n = total animatronics
        //once we remove an animatronic its gone forever don't both increasing UNLESS WE START WITH LESS
        while(currTime <= nightLength){
            ll currMax = v[0];
            ll currMaxInd = 0;
            ll currMin = v[0];
            ll currMinInd = 0;
            for(ll i = 0; i < animatronics; i++){
                if(flashed.find(i) == flashed.end()){
                    currMax = v[i];
                    currMaxInd = i;
                    currMin = v[i];
                    currMinInd = i;
                    break;
                }
            }
            bool same = true;
            for(ll i = 0; i < animatronics; i++){
                if(v[i] < currMin && flashed.find(i) == flashed.end()){
                    currMin = v[i];
                    currMinInd = i;
                }
            }

            v[currMinInd]++;
            for(ll i = 0; i < animatronics; i++){
                if(v[i] > currMax){
                    currMax = v[i];
                    currMaxInd = i;
                }
            }

            if(!times.empty() && currTime == times.front()){
                times.pop();
                flashed.insert(currMaxInd);
                v[currMaxInd] = 0;
            }

            currTime++;
        }


        ll ans = v[0];
        for(ll i = 0; i < v.size(); i++){
            ans = max(ans, v[i]);
        }

        cout << ans << endl;
    }

}
