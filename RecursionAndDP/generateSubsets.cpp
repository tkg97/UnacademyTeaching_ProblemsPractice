#include <iostream>
#include <vector>
using namespace std;

void printArray(vector<int> &array)
{
    static int num = 0;

    cout << "------------------------------" << endl;
    cout << num++ << " | ";
    for (int a : array)
    {
        cout << a << " ";
    }
    cout << endl;
}

void generateSubsets(int index, vector<int> &numbers, vector<int> &placeHolder)
{
    if (index == numbers.size())
    {
        printArray(placeHolder);
        return;
    }
    generateSubsets(index + 1, numbers, placeHolder);
    placeHolder.push_back(numbers[index]);
    generateSubsets(index + 1, numbers, placeHolder);
    placeHolder.pop_back();
}

int main()
{
    int n = 4;
    vector<int> numbers(n, 0);
    for (int i = 0; i < n; i++)
    {
        numbers[i] = i;
    }

    vector<int> placeHolder;
    generateSubsets(0, numbers, placeHolder);
}