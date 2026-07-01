#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> ans;

void solve(string s, int open, int close, int n)
{
    if(s.size() == 2 * n)
    {
        ans.push_back(s);
        return;
    }

    if(open < n)
        solve(s + "(", open + 1, close, n);

    if(close < open)
        solve(s + ")", open, close + 1, n);
}

int main()
{
    int n;
    cin >> n;

    solve("", 0, 0, n);

    for(string s : ans)
        cout << s << endl;

    return 0;
}
