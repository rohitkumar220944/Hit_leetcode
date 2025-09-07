class Solution {
public:

    int robhelper(vector<int>& nums,int i)
    {
        if(i>=nums.size())
        {
            return 0;
        }
        int rob1=nums[i]+robhelper(nums,i+2);
        int rob2= 0 + robhelper(nums,i+1);
        return max(rob1,rob2);
    }
    int rob(vector<int>& nums) {
        return robhelper(nums,0);
    }
};