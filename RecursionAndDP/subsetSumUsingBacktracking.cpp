#include <iostream>
#include <vector>

using namespace std;

bool isSubsetPresent(vector<int> &array, int requiredSum, int index, int currSum)
{
    if (currSum > requiredSum)
        return false;
    if (currSum == requiredSum)
        return true;
    if (index == array.size())
        return false;

    return isSubsetPresent(array, requiredSum, index + 1, currSum + array[index]) || isSubsetPresent(array, requiredSum, index + 1, currSum);
}

int main()
{
    vector<int> array({1, 2, 3, 4});
    int requiredSum = 8;

    cout << isSubsetPresent(array, requiredSum, 0, 0);
}