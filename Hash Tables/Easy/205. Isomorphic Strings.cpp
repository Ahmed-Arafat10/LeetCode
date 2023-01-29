// Solution #1
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,pair<char,int>> mps,mpt;
        vector<pair<char,int>>v_s,v_t;
        char c = 'a';
        for(int i =0;i<s.size();i++)
        {
            if(!mps[s[i]].second)
            {
                mps[s[i]] = {c,1};
                c++;
            }
            else mps[s[i]] = {mps[s[i]].first,mps[s[i]].second+1};
            v_s.push_back({mps[s[i]].first,mps[s[i]].second});
        }
        c = 'a';
        for(int i =0;i<t.size();i++)
        {
            if(!mpt[t[i]].second)
            {
                mpt[t[i]] = {c,1};
                c++;
            }
            else mpt[t[i]] = {mpt[t[i]].first,mpt[t[i]].second+1};
            v_t.push_back({mpt[t[i]].first,mpt[t[i]].second});
        }
        if(v_s == v_t) return 1;
        return 0;
    }
};

// Solution #2
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<int,pair<int,int>> mps,mpt;
        map<char,pair<int,int>>temp1;
        //vector<pair<char,int>>v_s,v_t;
        char c = 'a';
        for(int i =0;i<s.size();i++)
        {
            if(!temp1[s[i]].second)
            {
                temp1[s[i]] = {temp1.size() + 1 , 1};
                mps[i] = { temp1.size() , 1 };
            }
            else
            {
                temp1[s[i]]  = {temp1[s[i]].first , temp1[s[i]].second + 1};
                mps[i] = temp1[s[i]];
            }
        }
        temp1.clear();
        for(int i =0;i<t.size();i++)
        {
            if(!temp1[t[i]].second)
            {
                temp1[t[i]] = {temp1.size() + 1 , 1};
                mpt[i] = { temp1.size() , 1 };
            }
            else
            {
                temp1[t[i]]  = {temp1[t[i]].first , temp1[t[i]].second + 1};
                mpt[i] = temp1[t[i]];
            }
        }
        if(mps == mpt) return 1;
        return 0;
    }
};


// Solution #3 Not Mine But Creative

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // Not Mine
        unordered_map<char, char> mp, mp2;
        for (int i=0; i<s.length(); i++) {
            if (mp[s[i]] && mp[s[i]]!=t[i]) return false;
            if (mp2[t[i]] && mp2[t[i]]!=s[i]) return false;
            mp[s[i]]=t[i];
            mp2[t[i]]=s[i];
        }
        return true;
    }
};

