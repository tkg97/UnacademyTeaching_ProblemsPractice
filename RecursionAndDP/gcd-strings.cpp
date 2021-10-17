// https://www.hackerearth.com/practice/basic-programming/recursion/recursion-and-backtracking/practice-problems/algorithm/gcd-strings/

#include <iostream>
#include <math.h>
#include <unordered_map>
using namespace std;

int modAdd(int a, int b, int m)
{
    return ((long long)a + (long long)b + m) % m;
}

int modMultiply(int a, int b, int m)
{
    return ((long long)a * (long long)b) % m;
}

int fastExponent(int a, int b, int m)
{
    int res = 1;
    while (b != 0)
    {
        if (b % 2 == 1)
        {
            res = modMultiply(res, a, m);
        }
        a = modMultiply(a, a, m);
        b = b / 2;
    }
    return res;
}

int getModInverse(int a, int p)
{
    return fastExponent(a, p - 2, p);
}

int getFValue(int a, int b, int modConstant, unordered_map<int, int> &valueMap)
{
    long long result = 0;
    if (a % b == 0)
    {
        result = fastExponent(2, modAdd(a, -1, modConstant), modConstant);
    }
    else
    {
        int quotient = (a / b);
        int rem = a % b;
        int FValueOfChild = getFValue(b, rem, modConstant, valueMap);
        int remValue = 0;
        if (valueMap.find(rem) == valueMap.end())
        {
            remValue = fastExponent(2, modAdd(rem, -1, modConstant), modConstant);
        }
        else
        {
            remValue = valueMap[a % b];
        }
        int pow2rem = fastExponent(2, rem, modConstant);
        int pow2b = fastExponent(2, b, modConstant);
        int gpSum = modMultiply(modAdd(fastExponent(pow2b, quotient, modConstant), -1, modConstant), getModInverse(modAdd(pow2b, -1, modConstant), modConstant), modConstant);
        result = modAdd(remValue, modMultiply(modMultiply(pow2rem, FValueOfChild, modConstant), gpSum, modConstant), modConstant);
    }
    valueMap[a] = result;
    return result;
}

int main()
{

    int modConstant = 1000000007;

    int T;
    cin >> T;

    unordered_map<int, int> valueMap;

    while (T--)
    {
        int a, b;
        cin >> a >> b;

        valueMap.clear();
        cout << getFValue(a, b, modConstant, valueMap) << endl;
    }
}