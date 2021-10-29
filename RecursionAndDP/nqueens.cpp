#include <iostream>
#include <vector>

using namespace std;

bool isValid(vector<int> positions)
{
    int n = positions.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            // (positions[i], i) and (positions[j], j)
            if ((i + positions[i] == j + positions[j]) || (i - positions[i] == j - positions[j]))
                return false;
        }
    }
    return true;
}

bool checkIfPossible(int n, int index, vector<int> &solution)
{
    if (index == n)
    {
        return isValid(solution);
    }
    for (int i = index; i < n; i++)
    {
        swap(solution[index], solution[i]);
        if (checkIfPossible(n, index + 1, solution))
            return true;
        swap(solution[index], solution[i]);
    }
    return false;
}

int main()
{
    int n;
    cin >> n;

    vector<int> validPositions;
    for (int i = 0; i < n; i++)
    {
        validPositions.push_back(i);
    }

    if (checkIfPossible(n, 0, validPositions))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << ((validPositions[i] == j) ? 1 : 0) << " ";
            }
            cout << endl;
        }
    }
    else
        cout << "Not possible" << endl;
}