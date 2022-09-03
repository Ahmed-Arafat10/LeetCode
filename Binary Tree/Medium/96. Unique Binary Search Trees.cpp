typedef long long ll;
class Solution
{
public:
    unordered_map<ll,ll>memo;
    void solve()
    {
        memo[0] = memo[1] = 1;
        for(ll i =2; i<=19; i++)
        {
            ll res = 0, x, y;
            for(ll j = 1; j<=i; j++)
            {
                if(memo[j-1]) x = memo[j-1];
                if(memo[i-j]) y = memo[i-j];
                res += x * y ;
            }
            memo[i] = res;
        }
    }
    ll numTrees(ll n)
    {
        solve();
        return memo[n];
    }
};
