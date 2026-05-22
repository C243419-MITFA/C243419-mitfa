#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n;

    cout << "Enter size of array: ";
    cin >> n;

    int a[n], dp[n];

    cout << "Enter array elements:\n";

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < n; i++)
        dp[i] = 1;

    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(a[i] > a[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    int ans = 0;

    for(int i = 0; i < n; i++)
        ans = max(ans, dp[i]);

    cout << "Length of LIS = " << ans;

    return 0;
}
