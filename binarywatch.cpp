#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int turnedOn;
    cin >> turnedOn;

    vector<string> ans;

    for(int h = 0; h < 12; h++)
    {
        for(int m = 0; m < 60; m++)
        {
            if(__builtin_popcount(h) + __builtin_popcount(m) == turnedOn)
            {
                string time = to_string(h) + ":";

                if(m < 10)
                    time += "0";

                time += to_string(m);

                ans.push_back(time);
            }
        }
    }

    for(string s : ans)
        cout << s << endl;

    return 0;
}
