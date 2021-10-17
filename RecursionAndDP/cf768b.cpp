// https://codeforces.com/problemset/problem/768/B

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

void getBitsFromRightToLeft(long long n, vector<int> &bitsFromRightToLeft)
{
    while (n != 0)
    {
        bitsFromRightToLeft.push_back(n % 2);
        n = n / 2;
    }
}

long long getCountOfOnes(long long sleft, long long sright, long long qleft, long long qright, vector<int> &bitsFromRightToLeft, int level)
{
    if (sright < qleft || sleft > qright)
        return 0;
    if (sright - sleft == 0)
        return bitsFromRightToLeft[level];
    if (sright - sleft <= 1)
        return 1;
    long long mid = sleft + (sright - sleft) / 2;
    return getCountOfOnes(sleft, mid - 1, qleft, qright, bitsFromRightToLeft, level + 1) + getCountOfOnes(mid, mid, qleft, qright, bitsFromRightToLeft, level) + getCountOfOnes(mid + 1, sright, qleft, qright, bitsFromRightToLeft, level + 1);
}

int main()
{
    long long n, l, r;

    cin >> n >> l >> r;

    vector<int> bitsFromRightToLeft;
    getBitsFromRightToLeft(n, bitsFromRightToLeft);

    int numBits = bitsFromRightToLeft.size();

    // l and r can be between [1, pow(2, numBits)-1] inclusive

    cout << getCountOfOnes(1, pow(2L, numBits) - 1, l, r, bitsFromRightToLeft, /*level=*/0) << endl;
}