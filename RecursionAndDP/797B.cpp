// https : //codeforces.com/contest/797/problem/B

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<long long> array(n);
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    vector<vector<long long>> dp(n + 1, vector<long long>(2));
    dp[0][0] = dp[0][1] = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (array[i] & 1)
        {
            dp[i + 1][0] = max(dp[i][0], array[i] + dp[i][1]);
            dp[i + 1][1] = max(dp[i][1], array[i] + max(dp[i][0], (long long)0));
        }
        else
        {
            dp[i + 1][0] = max(dp[i][0], array[i] + max(dp[i][0], (long long)0));
            dp[i + 1][1] = max(dp[i][1], array[i] + dp[i][1]);
        }
    }

    cout << dp[n][1] << endl;
}