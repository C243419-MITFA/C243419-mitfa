#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> ans;
vector<int> temp;

void solve(int start, int n, int k)
{
    if(temp.size() == k)
    {
        ans.push_back(temp);
        return;
    }

    for(int i = start; i <= n; i++)
    {
        temp.push_back(i);
        solve(i + 1, n, k);
        temp.pop_back();
    }
}

int main()
{
    int n, k;
    cin >> n >> k;

    solve(1, n, k);

    for(auto v : ans)
    {
        cout << "[";
        for(int i = 0; i < v.size(); i++)
        {
            cout << v[i];
            if(i != v.size() - 1)
                cout << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
