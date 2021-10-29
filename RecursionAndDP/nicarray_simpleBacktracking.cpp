// First one may try out simple backtracking, but will give TLE in the second case
// We still need to do backtracking, but a bit smartly

#include <iostream>
#include <vector>
using namespace std;

int modConstant = 1000000007;

int modSum(int a, int b)
{
    return ((long long)a + (long long)b) % modConstant;
}

int gcd(int a, int b)
{
    if (a < b)
    {
        if (a == 0)
            return b;
        return gcd(b % a, a);
    }
    else
    {
        if (b == 0)
            return a;
        return gcd(a % b, b);
    }
}

int calculateNicenessOfAParticularCase(vector<int> &array)
{
    int n = array.size();
    int niceness = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            niceness = modSum(niceness, gcd(array[i], array[j]));
        }
    }
    return niceness;
}

int calculateNiceNess(vector<int> &array, int index, int sumLeft)
{
    if (index == array.size())
    {
        return (sumLeft == 0) ? calculateNicenessOfAParticularCase(array) : 0;
    }
    if (sumLeft <= 0)
        return 0;
    if (array[index] != -1)
        return calculateNiceNess(array, index + 1, sumLeft - array[index]);

    int niceness = 0;

    for (int k = 1; k <= sumLeft; k++)
    {
        array[index] = k;
        niceness = modSum(niceness, calculateNiceNess(array, index + 1, sumLeft - array[index]));
        array[index] = -1;
    }

    return niceness;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, s;
        cin >> n >> s;
        vector<int> array(n, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> array[i];
        }

        cout << calculateNiceNess(array, 0, s) << endl;
    }
}