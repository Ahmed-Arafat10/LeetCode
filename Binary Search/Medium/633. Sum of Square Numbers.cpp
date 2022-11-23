// Binary Search
typedef long long ll;
class Solution {
public:
    bool BS(ll l , ll r , ll T )
    {
        while(l<=r)
        {
           ll mid = l + (r-l)/2;
            if(mid*mid == T) return 1;
            else if (mid*mid > T) r = mid - 1;
            else l = mid + 1;
        }
        return 0;
    }
    
    bool judgeSquareSum(int c) {
        for(ll i =0;i*i<=c;i++)
        {
            ll b = c - (i*i);
            //b =floor(sqrt(b));
            if(BS(0,c,b)) return 1;
        }
        return 0;
    }
};
//----------------------

// Two Pointers
class Solution {
public:
    bool judgeSquareSum(int c) {
        long long left = 0 ,right = ceil(sqrt(c));
        while(left <= right)
        {
            long long res = left*left + right*right;
            if(res == c) return 1;
            else if(res > c) right--;
            else left++;
        }
        return 0;
    }
};