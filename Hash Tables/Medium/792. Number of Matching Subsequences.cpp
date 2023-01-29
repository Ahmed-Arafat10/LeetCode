// Created by ahmed on 1/29/2023.
class Solution {
public:
    int numMatchingSubseq(string s, vector <string> &words) {
        int res = 0;
        map<char, vector<int>> mp;
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]].push_back(i);
        }
        for (int i = 0; i < words.size(); i++) {
            bool flag = true;
            int mx = INT_MIN;
            for (int j = 0; j < words[i].size(); j++) {
                char cur = words[i][j];
                if (mp.find(cur) == mp.end()) {
                    flag = false;
                    break;
                }
                if (j == 0) mx = mp[cur][0];
                else {
                    auto it = upper_bound(mp[cur].begin(), mp[cur].end(), mx);
                    if (it != mp[cur].end())
                        mx = *it;
                    else {
                        flag = false;
                        break;
                    }
                }
            }
            if (flag) res++;
        }
        return res;
    }
};
