#include <iostream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

vector<string> ans;

void solve(string &s, int idx)
{
    if(idx == s.size())
    {
        ans.push_back(s);
        return;
    }

    if(isdigit(s[idx]))
    {
        solve(s, idx + 1);
    }
    else
    {
        s[idx] = tolower(s[idx]);
        solve(s, idx + 1);

        s[idx] = toupper(s[idx]);
        solve(s, idx + 1);
    }
}

int main()
{
    string s;
    cin >> s;

    solve(s, 0);

    for(string str : ans)
        cout << str << endl;

    return 0;
}
