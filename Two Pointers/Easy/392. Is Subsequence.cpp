class Solution {
public:
    bool isSubsequence(string s, string t) {
        int ptr_s = 0 , ptr_t = 0;
        while(ptr_t < t.size())
        {
            if(s[ptr_s] == t[ptr_t]) ptr_s++,ptr_t++;
            else ptr_t++;
        }

        if(ptr_s == s.size()) return 1;
        return 0;
    }
};