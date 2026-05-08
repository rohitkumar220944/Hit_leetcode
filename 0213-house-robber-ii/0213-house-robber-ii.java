class Solution {
    public int f(int[]nums, int s,int end,int[]dp)
    {
        if(s>end)return 0;

        if(dp[s]!=-1)return dp[s];

        int take=nums[s]+f(nums,s+2,end,dp);
        int notake=f(nums,s+1,end,dp);

        return dp[s]=Math.max(take,notake);

    }
    public int rob(int[] nums) {
        int n=nums.length;
        
       

        if(n==1)return nums[0];

        int[] dp1 = new int[n];
        Arrays.fill(dp1, -1);

        int case1=f(nums,0,n-2,dp1);


        int[] dp2 = new int[n];
        Arrays.fill(dp2, -1);
        int case2=f(nums,1,n-1,dp2);

        return Math.max(case1,case2);
    }
}