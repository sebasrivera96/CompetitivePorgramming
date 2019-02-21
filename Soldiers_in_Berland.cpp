/*Very soon there will be a parade of victory over alien invaders in Berland. Unfortunately, all soldiers died in the war and now the army consists of entirely new recruits, many of whom do not even know from which leg they should begin to march. The civilian population also poorly understands from which leg recruits begin to march, so it is only important how many soldiers march in step.

There will be n columns participating in the parade, the i-th column consists of li soldiers, who start to march from left leg, and ri soldiers, who start to march from right leg.

The beauty of the parade is calculated by the following formula: if L is the total number of soldiers on the parade who start to march from the left leg, and R is the total number of soldiers on the parade who start to march from the right leg, so the beauty will equal |L - R|.

No more than once you can choose one column and tell all the soldiers in this column to switch starting leg, i.e. everyone in this columns who starts the march from left leg will now start it from right leg, and vice versa. Formally, you can pick no more than one index i and swap values li and ri.

Find the index of the column, such that switching the starting leg for soldiers in it will maximize the the beauty of the parade, or determine, that no such operation can increase the current beauty. */


/* ===== TEST CASES =====


Input
3
5 6
8 9
10 3
Output
3

Input
6
5 9
1 3
4 8
4 5
23 54
12 32
Output
0

*/

#include <iostream>
#include <math.h>
#include <utility>
#include <vector>
#include <stdlib.h>     /* abs */

using namespace std;

int main(){
    int n, tN;
    int L = 0, R = 0;
    int maxBeautyIndex = 0;
    cin >> n;
    tN = n;
    vector< pair<int,int> > columnsOfSoldiers;
    while(tN--){
        pair<int,int> newCol;
        cin >> newCol.first >> newCol.second;
        int l = newCol.first;
        int r = newCol.second;
        L += l; R += r;

        columnsOfSoldiers.push_back(newCol);
    }
    int maxBeauty = abs(L - R);


    for(int i = 0; i < n; i++){
        int tLeft = columnsOfSoldiers[i].first;
        int tRight = columnsOfSoldiers[i].second;
        int tL = L - tLeft + tRight;
        int tR = R - tRight + tLeft;
        int newBeauty = abs(tL - tR);

        if(newBeauty > maxBeauty){
            maxBeauty = newBeauty;
            maxBeautyIndex = i+1;
        }

    }
    cout << maxBeautyIndex << endl;
}