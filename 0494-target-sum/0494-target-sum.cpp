class Solution {
public:
    int f(int ind, vector<int>& arr, int sum, vector<unordered_map<int,int>> &dp)
    {
      if (ind < 0) {
           if (sum == 0) return 1;
            else return 0;
       }

       if(dp[ind].count(sum))return dp[ind][sum];

        int add=f(ind-1, arr, sum+arr[ind], dp);
        
        int sub=f(ind-1, arr, sum-arr[ind], dp);

        return dp[ind][sum]= add+sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        vector<unordered_map<int,int>>dp(n);
        return f(n-1, nums, target, dp);
    }
};