// https://www.codechef.com/problems/KCHAR

#include <iostream>
using namespace std;

char flipAandC(char c)
{
    switch (c)
    {
    case 'a':
        return 'c';
    case 'c':
        return 'a';
    default:
        return c;
    }
}

char getCharAtK(long long k, int seqNum)
{
    long long one = 1;
    long long num = (one << (seqNum - 1));
    if (k == num - 1) {
        return 'a';

    }
    else if (k < num - 1) {
        return getCharAtK(k, seqNum - 1);
    }
    else
    {
        return flipAandC(getCharAtK(num -1 - (k - num + 1), seqNum - 1));
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long k;
        cin >> k;

        cout << getCharAtK(--k, 64) << endl;
    }
}