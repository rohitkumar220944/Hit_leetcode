// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         if (nums.size() < 3) return nums.size();
//         int i = 2;
//         while (i < nums.size()) {
//             if (nums[i] == nums[i - 1] && nums[i] == nums[i - 2]) {
//                 nums.erase(nums.begin() + i);
//             } else {
//                 i++;
//             }
//         }
//         return nums.size();
//     }
// };

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int j = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (j == 1 || nums[i] != nums[j - 2]) {
                nums[j++] = nums[i];
            }
        }
        return j;
    }
};