#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
private:
    bool isPossible(string &s, unordered_set<string> &dictionary, int index)
    {
        if (index == s.size())
            return true;
        string currString = "";
        for (int i = index; i < s.size(); i++)
        {
            currString += s[i];
            if (dictionary.find(currString) != dictionary.end())
            {
                if (isPossible(s, dictionary, i + 1))
                    return true;
            }
        }
        return false;
    }

public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> dictionary;
        // process the wordDict in hashmap for quick search
        for (string word : wordDict)
        {
            dictionary.insert(word);
        }

        return isPossible(s, dictionary, 0);
    }
};