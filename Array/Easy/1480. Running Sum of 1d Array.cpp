// Created by ahmed on 1/29/2023.
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int res = nums[0];
        for(int i = 1;i<nums.size();i++)
        {
            nums[i]+=res;
            res=nums[i];
        }
        return nums;
    }
};
