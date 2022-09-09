#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
    static ll  p = 1;
class Solution {

public:

    bool isPowerOfTwo(ll n) {
        if(n == p) 
        {
            p =1;
            return 1;
        }
        if(p > n) 
        {   p =1;
            return 0;
        }
        p*=2;
        return isPowerOfTwo(n);
    }
};

//---------------------------------
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
class Solution {

public:

    bool isPowerOfTwo(ll n) {
         ll cnt = 0;
       while(n>0)
       {
           if(n&1) cnt++;
            n >>= 1;
       }
       if(cnt == 1) return 1;
       return 0;
    }
};
