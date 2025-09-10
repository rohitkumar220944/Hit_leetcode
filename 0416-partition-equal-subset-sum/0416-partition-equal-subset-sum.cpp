class Solution {
public:

    bool f(int ind, int k, vector<int>& nums, vector<vector<int>> &dp)
    {
        if(k==0)return 0;
        if(ind==0)return nums[0]=k;

        if(dp[ind][k]!=-1)return dp[ind][k];

        bool nottake=f(ind-1, k, nums, dp);
        bool take=false;
        if(k>=nums[ind])
        take=f(ind-1, k-nums[ind], nums, dp);

        return dp[ind][k]= take | nottake ; 
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        if(sum%2)return false;
        int k=sum/2;

        vector<vector<int>>dp(n,vector<int>(k+1,-1));
        return f(n-1, k, nums, dp);
    }
};