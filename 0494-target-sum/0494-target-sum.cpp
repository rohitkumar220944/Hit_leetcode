class Solution {
public:
    int f(int ind, vector<int>& arr, int sum)
    {
      if (ind < 0) {
           if (sum == 0) return 1;
            else return 0;
       }
        int add=f(ind-1, arr, sum+arr[ind]);
        
        int sub=f(ind-1, arr, sum-arr[ind]);

        return add+sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        return f(n-1, nums, target);
    }
};