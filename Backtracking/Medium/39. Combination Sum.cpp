class Solution
{
public:
    int sum = 0;
    vector<int> memo;
    vector<vector<int>> res;

    void solve(vector<int> &candidates, int target, int idx) // [2,3,5]   8
    {
        if (sum == target)
        {
            res.push_back(memo);
            return;
        }
        else if (sum > target || idx >= candidates.size()) return;
        int num = candidates[idx];
        sum += num;
        memo.push_back(num);
        solve(candidates, target, idx);
        sum -= num;
        memo.erase(memo.end() - 1);
        solve(candidates, target, idx + 1);
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        solve(candidates, target, 0);
        return res;
    }
};