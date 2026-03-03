#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/*
binary search on answer

idea for each answer: set portal to lft +x loop to rht - x;

deal with edges seperately
*/
ll friends, teleports, X;

vector<ll> friendPos;
vector<ll> ans;

bool check(ll mid){
    bool res = false;
    vector<ll> currAns;
    ll currSpot = 0;
    ll currTeleports = 0;
    ll currLftFriend = 0;
    ll currRhtFriend = 1;

    if(friendPos.size() == 1){
        currRhtFriend = 0;
    }

    if(mid == 0){
        for(ll i = 0; i < teleports; i++){
            currAns.push_back(i);
        }
        ans.clear();
        for(auto u: currAns){
            ans.push_back(u);
        }
        return true;
    }

    while(currTeleports < teleports && currSpot <= X){
        if(abs(currSpot - friendPos[currLftFriend]) >= mid){
            currAns.push_back(currSpot);
            currTeleports++;
            currSpot++;
        } else{
            break;
        }
    }

    //cout << "T: "<< currTeleports << " " << teleports << " " << mid << endl;


    if(friendPos.size() != 1){
        currSpot = friendPos[currLftFriend] + mid;
        while(currTeleports < teleports && currSpot <= X){
            if(currRhtFriend >= friendPos.size()){
                break;
            }
            if(currSpot < friendPos[currRhtFriend]){
                while(abs(currSpot - friendPos[currRhtFriend]) >= mid && currTeleports < teleports){
                    //cout << currSpot << " " << currRhtFriend << endl;
                    currAns.push_back(currSpot);
                    currTeleports++;
                    currSpot++;
                }
                currLftFriend = currRhtFriend;
                currRhtFriend++;
                currSpot = friendPos[currLftFriend] + mid;
            } else{
                currLftFriend = currRhtFriend;
                currRhtFriend++;
                currSpot = friendPos[currLftFriend] + mid;
            }
        }
    }

    currRhtFriend = friendPos.size() - 1;
    currSpot = X;
    //cout << "T2: "<< currTeleports << " " << teleports << " " << mid << endl;

    while(currTeleports < teleports && currSpot >= 0){
        if(abs(currSpot - friendPos[currRhtFriend]) >= mid){
            currAns.push_back(currSpot);
            currTeleports++;
            currSpot--;
        } else{
            break;
        }
    }
    //cout << "T3: "<< currTeleports << " " << teleports << " " << mid << endl;

    if(currTeleports >= teleports){
        res = true;
    }

    if(res){
        ans.clear();
        for(auto u: currAns){
            ans.push_back(u);
        }
    }

    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie();

    ll tests;
    cin >> tests;

    for(ll t = 0; t < tests; t++){
        cin >> friends >> teleports >> X;

        friendPos.clear();
        ans.clear();

        for(ll i = 0; i < friends; i++){
            ll num;
            cin >> num;
            friendPos.push_back(num);
        }

        sort(friendPos.begin(), friendPos.end());

        ll lft = 0, rht = 1000000000;

        while(lft <= rht){
            ll mid = (lft + rht)/2;
            if(check(mid)){
                //cout << mid << endl;
                lft = mid + 1;
            } else{
                rht = mid - 1;
            }
        }
        //check(2);


        for(ll i = 0; i < ans.size(); i++){
            cout << ans[i] << " \n"[i == ans.size() - 1];
        }
    }

}
