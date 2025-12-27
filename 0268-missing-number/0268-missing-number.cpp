class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0, j = 0; i < n; i++, j++) {
            if (nums[i] != j) {
                return j;
            }
        }
        return n;
    }
};
