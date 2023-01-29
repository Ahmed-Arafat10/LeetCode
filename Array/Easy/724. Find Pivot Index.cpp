// Created by ahmed on 1/29/2023.
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sumr=0, suml=0;
        for(int i=0;i<nums.size();i++)
        {
            sumr+=nums[i];
        }

        for(int i=0;i<nums.size();i++)// 0 27
        {
            sumr-=nums[i];
            if(suml == sumr) return i;
            suml+=nums[i];
        }
        return -1;
    }
};
