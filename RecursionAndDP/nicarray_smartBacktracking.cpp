#include <iostream>
#include <vector>
using namespace std;

int modConstant = 1000000007;

vector<int> factorials(51, 1);

void printArray(vector<int> &array)
{
    for (int a : array)
    {
        cout << a << " ";
    }
    cout << endl;
}

int modSum(int a, int b)
{
    return ((long long)a + (long long)b) % modConstant;
}

int modMultiply(int a, int b)
{
    return ((long long)a * (long long)b) % modConstant;
}

int fastExponent(int a, int b)
{
    int res = 1;
    while (b != 0)
    {
        if (b & 1)
        {
            res = modMultiply(res, a);
        }
        b = b / 2;
        a = modMultiply(a, a);
    }
    return res;
}

int moduloInverseWrtModConstant(int a)
{
    return fastExponent(a, modConstant - 2);
}

void preComputeFactorials()
{
    for (int i = 1; i <= 50; i++)
    {
        factorials[i] = modMultiply(factorials[i - 1], i);
    }
}

int numPermutationsOfASequence(vector<int> &array)
{

    vector<int> freq(51, 0);
    for (int a : array)
    {
        freq[a]++;
    }

    int numerator = factorials[array.size()];
    int denominator = 1;
    for (int i = 0; i <= 50; i++)
    {
        denominator = modMultiply(denominator, factorials[freq[i]]);
    }

    return modMultiply(numerator, moduloInverseWrtModConstant(denominator));
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

int calculateNiceness(vector<int> &chosenValues, vector<int> &preFilledValues)
{
    int n = chosenValues.size();
    int m = preFilledValues.size();

    int niceness = 0;

    for (int i = 0; i < (n + m); i++)
    {
        for (int j = i + 1; j < (n + m); j++)
        {
            int a = (i < n) ? chosenValues[i] : preFilledValues[i - n];
            int b = (j < n) ? chosenValues[j] : preFilledValues[j - n];

            niceness = modSum(niceness, gcd(a, b));
        }
    }

    return niceness;
}

int getPartitionNiceness(int sumLeft, int numPlaces, int index, int prevValue, vector<int> &placeHolder, vector<int> &filledValues)
{
    if (index == numPlaces)
    {
        return (sumLeft == 0) ? modMultiply(calculateNiceness(placeHolder, filledValues), numPermutationsOfASequence(placeHolder)) : 0;
    }
    if (sumLeft < prevValue)
        return 0;

    int niceness = 0;
    for (int k = prevValue; k <= sumLeft; k++)
    {
        placeHolder[index] = k;
        niceness = modSum(niceness, getPartitionNiceness(sumLeft - k, numPlaces, index + 1, k, placeHolder, filledValues));
        placeHolder[index] = -1;
    }
    return niceness;
}

int main()
{
    int t;
    cin >> t;

    preComputeFactorials();

    while (t--)
    {
        int n, s;
        cin >> n >> s;

        vector<int> array(n, 0);

        int sumLeft = s;
        int numEmptyPlaces = 0;

        vector<int> filledValuesPlaceHolder;
        vector<int> partitionPlaceHolder;
        for (int i = 0; i < n; i++)
        {
            cin >> array[i];
            if (array[i] == -1)
            {
                numEmptyPlaces++;
                partitionPlaceHolder.push_back(array[i]);
            }
            else
            {
                filledValuesPlaceHolder.push_back(array[i]);
                sumLeft -= array[i];
            }
        }

        // now find number of partitions of sumLeft in numEmptyPlaces
        // for each partition, do backtracking
        // multiply the value with number of permutations of the corresponding sequence

        int niceness = getPartitionNiceness(sumLeft, numEmptyPlaces, 0, 1, partitionPlaceHolder, filledValuesPlaceHolder);
        cout << niceness << endl;
    }
}