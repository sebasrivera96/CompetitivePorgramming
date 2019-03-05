#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(){
    int T;
    cin >> T;
    string _;
    getline(cin, _);

    while(T--){
        string strHour = "";
        getline(cin, strHour);

        int iHour, iMins;
        int limit = strHour.find(':');

        istringstream issHours (strHour.substr(0,limit));
        istringstream issMins (strHour.substr(limit+1, strHour.length()));
        issHours >> iHour;
        issMins >> iMins;

        if(iMins != 0)
            cout << 0 << endl;
        else if(iHour <= 12)
            cout << iHour+12 << endl;
        else
            cout << iHour-12 << endl;
    }
}