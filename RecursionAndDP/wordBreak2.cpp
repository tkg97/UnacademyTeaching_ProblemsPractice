#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
private:
    void getPossibleSolutions(string &s, unordered_set<string> &dictionary, int index, string currString, vector<string> &solution)
    {
        if (index == s.size())
        {
            solution.push_back(currString);
            return;
        }
        string currWord = "";
        for (int i = index; i < s.size(); i++)
        {
            currWord += s[i];
            if (dictionary.find(currWord) != dictionary.end())
            {
                string resultString = (currString != "") ? currString + " " + currWord : currWord;
                getPossibleSolutions(s, dictionary, i + 1, resultString, solution);
            }
        }
        return;
    }

public:
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> dictionary;
        // process the wordDict in hashmap for quick search
        for (string word : wordDict)
        {
            dictionary.insert(word);
        }

        vector<string> solution;

        getPossibleSolutions(s, dictionary, 0, "", solution);

        return solution;
    }
};