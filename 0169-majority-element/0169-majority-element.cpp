class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size();

        for (int num : nums) {
            mp[num]++;                     // increment count
            if (mp[num] > n / 2) {         // check frequency
                return num;
            }
        }
        return -1; 
    }
};
