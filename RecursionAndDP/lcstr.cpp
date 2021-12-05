// a version of longest common substring problem on leetcode: https://leetcode.com/problems/maximum-length-of-repeated-subarray/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findLength(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int m = nums2.size();

        vector<int> dp(m + 1, 0);

        int answer = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = m; j > 0; j--)
            {
                if (nums1[i - 1] == nums2[j - 1])
                    dp[j] = dp[j - 1] + 1;
                else
                    dp[j] = 0;

                answer = max(answer, dp[j]);
            }
        }
        return answer;
    }
};
