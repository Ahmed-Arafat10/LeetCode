typedef long long ll;
class Solution {
public:
    double myPow(double x,ll n) {
        if(n < 0) x = 1/x , n *= -1;
        if(!n) return 1;
        if(n&1) return x * myPow(x*x,n>>1);
        return myPow(x*x,n>>1);
    }
};
