/*Vova plans to go to the conference by train. Initially, the train is at the point 1 and the destination point of the path is the point L. 
The speed of the train is 1 length unit per minute (i.e. at the first minute the train is at the point 1, at the second minute — 
at the point 2 and so on).

There are lanterns on the path. They are placed at the points with coordinates divisible by v
(i.e. the first lantern is at the point v, the second is at the point 2v and so on).

There is also exactly one standing train which occupies all the points from l to r inclusive.

Vova can see the lantern at the point p if p is divisible by v and there is no standing train at this position (p∉[l;r]). 
Thus, if the point with the lantern is one of the points covered by the standing train, Vova can't see this lantern.

Your problem is to say the number of lanterns Vova will see during the path. Vova plans to go to t
different conferences, so you should answer t independent queries.

===== TEST CASE =====

Input

4
10 2 3 7
100 51 51 51
1234 1 100 199
1000000000 1 1 1000000000

Output

3
0
1134
0

*/

#include <iostream>
#include <math.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;

    while(t--){
        int L, v, l, r;
        int totalLanterns = 0;
        int blockedLanternsTillR = 0;
        int blockedLanternsTillL = 0;
        cin >> L >> v >> l >> r;

        // Get the num of lanterns by dividing L/v
        totalLanterns = L/v;

        // Compute the blocked ones
        blockedLanternsTillR = r/v;
        blockedLanternsTillL = (l-1)/v;
        
        cout << (totalLanterns - (blockedLanternsTillR - blockedLanternsTillL)) << endl;
    }
    

    return 0;
}
