class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> v1;
        for(int i =0;i<nums.size();i++)
        {
             v1.push_back(nums[nums[i]]);
        }
        return v1;
    }
};