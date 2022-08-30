#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findJudge(int n, vector<vector<int>> &trust)
    {
        unordered_map<int, int> mp, mp2;
        for (int i = 0; i < trust.size(); i++)
        {
            mp[trust[i][1]]++;
            mp2[trust[i][0]]++;
        }
        for (int i = 1; i <= n; i++)
        {
            if (mp[i] == (n - 1) && !mp2[i])
                return i;
        }
        return -1;
    }
};
