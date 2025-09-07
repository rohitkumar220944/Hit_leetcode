class Solution {
public:


int f(vector<int>&value)
{
    int n=value.size();
    if (n == 0) return 0;        
    if (n == 1) return value[0];
    vector<int>dp(n,0);

    dp[0]=value[0];
    for(int i=1;i<n;i++)
    {
        int pick=value[i];
        if(i>1)
        pick+=dp[i-2];
        int notpick=0+dp[i-1];
        dp[i]=max(pick,notpick);
    }
    return dp[n-1];
}
    int rob(vector<int>& nums) {
        vector<int>temp1,temp2;
        int n =nums.size();
        if(n==1)return nums[0];
        for(int i=0;i<n;i++)
        {
            if(i!=0)temp1.push_back(nums[i]);
            if(i!=n-1)temp2.push_back(nums[i]);
        }
        return max(f(temp1),f(temp2));
    }
};