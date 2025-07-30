class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int j = n -1;
        while(j>0)
        {
            if(nums[j]>nums[j-1] )
            {
                break;
            }
            j--;
        }

        if(j == 0)
        {
            reverse(nums.begin(), nums.end());
            return;
        }

        int i = n -1;
        while(i>=j)
        {
            if(nums[i]>nums[j-1])
            {
                break;
            }
            i--;
        }

        swap(nums[i], nums[j-1]);
        reverse(nums.begin()+j, nums.end());
       
      return;
        
        
    }
};
