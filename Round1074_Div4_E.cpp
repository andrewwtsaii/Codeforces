#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/*
    //need something in instructionLength linear time.
    //idea: maybe hashmap storing number of robots a certain distance away
    //we have a integer variable called ans, and subtract whenever a certain
    //key in the map gets too close?
    //probably wouldn't work lft distance and rht distance

cant do difference array constantly outputting answer
obs 1: robots never run into each other, instructions set to all robots at once

even if we determine how many L or R for a robot to die, we have to check for all robots
O(N * K) time

maybe use hashmap?? Find out overall how many L's or R's L = -1, R = + 1 (Commont trick)
when certain number is reached we delete those robots.

Obs 2: Each robot has 2 unique numbers that will kill them, smallest (negative) and largest (positive)
how to deal with both?

2 loops?

Idea 1: Since our current position is always a net positive or net negative we can use two maps, one for
smallest positive and one for smallest absolute positive (negative case) and whenever a certain dist
dies delete from map

idea 1 probably doesn't work, if we go from negative to positive we don't know which robots gotten rid of

can we do something simply by grouping robots the same distance away? Only need to loop through possible distances from a spike
not by number of robots?

we want similar to idea 1 but only 1 data structure
how to deal with L, R overlap?

maybe when we remove a robot, loop through map to find robots deleted and delete? <- slow?

idea use map to sets. We can easily store each robots right distance/left distance. Then
for each robot access map at the other distance and remove it

^^ Worked with K.H on this problem

shortest distance with binary search may have problems - not always possible
two pointers, one pointer on spike positions, one pointer on robot positions
*/

unordered_map<int, set<int>> lftDist;
unordered_map<int, set<int>> rhtDist;
unordered_map<int, int> robotLft;
unordered_map<int, int> robotRht;
vector<int> spikePositions;
vector<int> robotPositions;

int main(){
    ios::sync_with_stdio(0);
    cin.tie();

    int tests;
    cin >> tests;


    for(int t = 0; t < tests; t++){
        int robots, spikes, instructionLength;
        cin >> robots >> spikes >> instructionLength;

        string instructions;

        spikePositions.clear();
        robotPositions.clear();
        lftDist.clear();
        rhtDist.clear();
        robotRht.clear();
        robotLft.clear();

        for(int i = 0; i < robots; i++){
            ll num;
            cin >> num;
            robotPositions.push_back(num);
        }

        for(int i = 0; i < spikes; i++){
            int num;
            cin >> num;
            spikePositions.push_back(num);
        }

        sort(spikePositions.begin(), spikePositions.end());
        sort(robotPositions.begin(), robotPositions.end());

        ll lftSpike = 0;
        for(ll lftRobot = 0; lftRobot < robotPositions.size(); lftRobot++){
            while(lftSpike + 1 < spikePositions.size() && robotPositions[lftRobot] - spikePositions[lftSpike + 1] >= 0){
                lftSpike++;
            }

            ll currDist = robotPositions[lftRobot] - spikePositions[lftSpike];
            if(currDist >= 0){
                lftDist[currDist].insert(lftRobot);
                robotLft[lftRobot] = currDist;
            }
        }

        ll rhtSpike = spikePositions.size() - 1;
        for(ll rhtRobot = robotPositions.size() - 1; rhtRobot >= 0; rhtRobot--){
            while(rhtSpike - 1 >= 0 && spikePositions[rhtSpike - 1] - robotPositions[rhtRobot] >= 0){
                rhtSpike--;
            }

            ll currDist = spikePositions[rhtSpike] - robotPositions[rhtRobot];
            if(currDist >= 0){
                rhtDist[currDist].insert(rhtRobot);
                robotRht[rhtRobot] = currDist;
            }
        }

        /*cout << "LFT: ";
        for(auto s: lftDist){
            cout << s.first << ": ";
            for(auto u: s.second){
                cout << u << ", ";
            }
            cout << endl;
        }
        cout << "RHT: ";
        for(auto s: rhtDist){
            cout << s.first << ": ";
            for(auto u: s.second){
                cout << u << ", ";
            }
            cout << endl;
        }
        cout << "LFT IND" << endl;
        for(auto u: robotLft){
            cout << u.first << " " << u.second << endl;
        }

        cout << "RHT IND" << endl;
        for(auto u: robotRht){
            cout << u.first << " " << u.second << endl;
        }*/

        cin >> instructions;
        int ans = robots;
        int currDelta = 0;
        for(int i = 0; i < instructionLength; i++){
            if(instructions[i] == 'L'){
                currDelta--;
            } else{
                currDelta++;
            }

            if(currDelta < 0){
                if(lftDist.find(currDelta * (-1)) != lftDist.end()){
                    for(auto u: lftDist[currDelta * (-1)]){
                        if(rhtDist.find(robotRht[u]) != rhtDist.end()){
                            rhtDist[robotRht[u]].erase(u);
                        }
                    }
                    ans -= lftDist[currDelta * (-1)].size();
                    lftDist[currDelta * (-1)].clear();
                }
            } else{
                if(rhtDist.find(currDelta) != rhtDist.end()){
                    for(auto u: rhtDist[currDelta]){
                        if(lftDist.find(robotLft[u]) != lftDist.end()){
                            lftDist[robotLft[u]].erase(u);
                        }
                    }
                    ans -= rhtDist[currDelta].size();
                    rhtDist[currDelta].clear();
                }
            }


            cout << ans << " \n"[i == instructionLength - 1];
        }
    }

}
