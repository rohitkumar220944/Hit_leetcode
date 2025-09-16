class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int total = 0, n = nums.size();
        for(int i = 0; i < n; ++i) total += nums[i];
        return total % 2 == 0 ? n - 1 : 0;
    }
};