// https://www.codechef.com/INOIPRAC/problems/INOI1502
// We could have easily optimize it with DP, but in this session, only recursion is in focus and hence this solution.
// Simply add hashmap to convert it to top down memoization approach.
// This solution surely has repetition due to overlapping subproblems and seems inefficient, but passes all the test cases.
// The reason becomes clear when we calculate the time complexity, where repetition is not that bad.

#include <iostream>
#include <vector>
using namespace std;

vector<int> powersOf2ModM;

void preComputePowerOf2sModM(int n, int m)
{
    long long res = 1;
    for (int i = 0; i <= n; i++)
    {
        powersOf2ModM.push_back(res);
        res = (res * 2) % m;
    }
}

int getNumberOfNonPeriodicStrings(int n, int m)
{
    if (n == 1)
        return 2;
    long long numberOfPeriodicStrings = 0;
    for (int i = 1; i * i <= n; i++)
    {
        if ((n % i) == 0)
        {
            long long first = getNumberOfNonPeriodicStrings(i, m);
            long long second = (i != 1 && (n != i * i)) ? getNumberOfNonPeriodicStrings(n / i, m) : 0;
            numberOfPeriodicStrings = (numberOfPeriodicStrings + first + second) % m;
        }
    }
    return (m - numberOfPeriodicStrings + powersOf2ModM[n]) % m;
}

int main()
{
    int n, m;
    cin >> n >> m;

    preComputePowerOf2sModM(n, m);

    cout << getNumberOfNonPeriodicStrings(n, m) << endl;
    return 0;
}