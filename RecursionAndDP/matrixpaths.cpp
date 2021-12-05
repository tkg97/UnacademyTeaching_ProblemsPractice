#include <bits/stdc++.h>
using namespace std;

// consider corners, boundaries, visted and then return the next possible cells out of the 4 neighbours
vector<pair<int, int>> getNextPossibleStates(pair<int, int> currPos, vector<vector<int>> &visited)
{
    // implement it yourself;
}

void populateCount(int &count, pair<int, int> currPos, vector<vector<int>> &visited)
{
    int x = currPos.first;
    int y = currPos.second;
    visited[x][y] = 1;

    if (x == 6 && y == 6)
    {
        if (visited.size() == 49)
            count++;
        else
            return;
    }

    // find next possible states
    vector<pair<int, int>> nextPossibleStates = getNextPossibleStates(currPos, visited);

    for (pair<int, int> nextCell : nextPossibleStates)
    {
        populateCount(count, nextCell, visited);
    }

    visited[x][y] = 0;
}