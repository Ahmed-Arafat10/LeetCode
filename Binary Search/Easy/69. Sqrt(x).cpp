class Solution {
public:
    int mySqrt(int x) {
        long long l = 0 , r = ceil(x*1.0/2), mid;
        long long res = 0;
        while(l<=r)// 0 1 2 3 4
        {
            mid = l+((r-l)/2);
            if(mid*mid == x) return mid;
            if(mid*mid > x) r = mid -1;
            else if(mid*mid < x) l = mid+1 , res = mid;
        }
        return res;
    }
};