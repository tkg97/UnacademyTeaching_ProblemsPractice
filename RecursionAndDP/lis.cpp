// https://leetcode.com/problems/longest-increasing-subsequence/

#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
private:
    // find the largest element smaller than the k
    int findByBinarySearch(int k, vector<int> &nums)
    {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] >= k)
                high = mid - 1;
            else
            {
                if (mid < high && nums[mid + 1] < k)
                {
                    low = mid + 1;
                }
                else
                    return mid;
            }
        }

        return -1;
    }

public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 1);

        vector<int> lengthElem(n, INT_MAX);

        for (int i = 0; i < n; i++)
        {
            int index = findByBinarySearch(nums[i], lengthElem);
            dp[i] = index + 1 + 1;
            lengthElem[dp[i] - 1] = min(lengthElem[dp[i] - 1], nums[i]);
        }

        return *max_element(dp.begin(), dp.end());
    }
};