class Solution {
public:

    int robhelper(vector<int>& nums,int ind,vector<int>&dp)
    {
       if(ind==0)return nums[ind];
       if(ind<0)return 0;
       if(dp[ind]!=-1)return dp[ind];

        int rob1=nums[ind]+robhelper(nums,ind-2,dp);
        int rob2= 0 + robhelper(nums,ind-1,dp);
        return dp[ind]= max(rob1,rob2);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return robhelper(nums,n-1,dp);
    }
};