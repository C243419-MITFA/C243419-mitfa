#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> ans;
vector<int> temp;

void solve(int idx, vector<int>& nums)
{
    if(idx == nums.size())
    {
        ans.push_back(temp);
        return;
    }

    // Don't take current element
    solve(idx + 1, nums);

    // Take current element
    temp.push_back(nums[idx]);
    solve(idx + 1, nums);

    // Backtrack
    temp.pop_back();
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);

    for(int i = 0; i < n; i++)
        cin >> nums[i];

    solve(0, nums);

    for(auto subset : ans)
    {
        cout << "[";
        for(int i = 0; i < subset.size(); i++)
        {
            cout << subset[i];
            if(i != subset.size() - 1)
                cout << " ";
        }
        cout << "]\n";
    }

    return 0;
}
