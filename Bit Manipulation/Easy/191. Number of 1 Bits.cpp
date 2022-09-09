class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
      while(n>0)
       {
           if(n&1) cnt++;
            n >>= 1;
       }
        return cnt;
    }
};
//--------------------
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while(n > 0)
        {
            int bit = n % 10;
            if(bit == 1) cnt++;
            n/=10;
            //cout<<n<<" ";
        }
        return cnt;
    }
};

// ---- Another approach

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0 , t = 0, tt = 32;
        while(tt--)
        {
            int x = 1<<t;
            if(x & n) cnt++; 
            t++;
        }
        return cnt;
    }
};