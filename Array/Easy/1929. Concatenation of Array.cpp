class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans;
        int t = 2;
        while(t--)
        {
            for(int i =0;i<nums.size();i++)
            {
             ans.push_back(nums[i]);   
            }
        }
        return ans;
    }
};


//// Another Approach

    class Solution {
    public:
        vector<int> getConcatenation(vector<int>& nums) {
            vector<int> ans(nums.size() * 2);
            for(int i =0;i<nums.size();i++)
                {
                 ans[i] = nums[i];
                 ans[i + nums.size()] = nums[i];
                }
            return ans;
        }
    };