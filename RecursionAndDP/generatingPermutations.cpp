#include <iostream>
#include <algorithm>

using namespace std;

void printString(string &s)
{
    static int count = 1;

    cout << count++ << " | " << s << endl;
}

void generatePermutations(string &s, int index)
{
    if (index == s.size())
    {
        printString(s);
        return;
    }
    for (int i = index; i < s.size(); i++)
    {
        swap(s[index], s[i]);
        generatePermutations(s, index + 1);
        swap(s[index], s[i]);
    }
}

int main()
{
    string s = "abcd";

    generatePermutations(s, 0);
}