#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int N = 8;

struct pair_hash
{
    inline size_t operator()(const pair<int, int> &v) const
    {
        return hash<int>()(v.first * N + v.second);
    }
};

void printPath(vector<pair<int, int>> &path)
{
    for (pair<int, int> p : path)
    {
        cout << "(" << p.first << ", " << p.second << ")"
             << " -> ";
    }
    cout << "| " << path.size() << endl
         << endl;

    exit(0);
}

bool isWithinBoard(pair<int, int> &pos)
{
    return (pos.first >= 0 && pos.first < N) && (pos.second >= 0 && pos.second < N);
}

vector<pair<int, int>> getNextPossibleMoves(pair<int, int> &currentPosition, unordered_set<pair<int, int>, pair_hash> visited)
{
    vector<pair<int, int>> resultSet;
    // vector<pair<int, int>> possibleMovements{{+1, +2}, {+1, -2}, {-1, +2}, {-1, -2}, {+2, +1}, {+2, -1}, {-2, +1}, {-2, -1}};
    // This order matters, the order in which we search can drastically affect our searching time
    vector<pair<int, int>> possibleMovements{{+2, +1}, {+1, +2}, {-1, +2}, {-2, +1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
    for (pair<int, int> move : possibleMovements)
    {
        pair<int, int> newPosition = {currentPosition.first + move.first, currentPosition.second + move.second};
        if (isWithinBoard(newPosition) && (visited.find(newPosition) == visited.end()))
        {
            resultSet.push_back(newPosition);
        }
    }
    return resultSet;
}

void generateAllPaths(pair<int, int> &currentPosition, unordered_set<pair<int, int>, pair_hash> &visited, vector<pair<int, int>> &currentPath)
{
    visited.insert(currentPosition);
    currentPath.push_back(currentPosition);
    if (visited.size() == N * N)
    {
        cout << "**HERE**" << endl;
        printPath(currentPath);
    }
    else
    {
        // find the eligible positions and start backtracking there
        vector<pair<int, int>> nextPossibleMoves = getNextPossibleMoves(currentPosition, visited);
        for (pair<int, int> nextPos : nextPossibleMoves)
        {
            generateAllPaths(nextPos, visited, currentPath);
        }
    }
    currentPath.pop_back();
    visited.erase(currentPosition);
}

int main()
{
    // chess board of N*N

    pair<int, int> initialPosition = {0, 0};

    unordered_set<pair<int, int>, pair_hash> visitedSet;
    vector<pair<int, int>> currentPath;

    generateAllPaths(initialPosition, visitedSet, currentPath);
}