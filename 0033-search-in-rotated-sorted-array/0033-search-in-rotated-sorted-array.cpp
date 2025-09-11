class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int s=0;
        int h=n-1;
        while(s<=h)
        {
            int m=(s+h)/2;
            if(nums[m]==target)
            {
                return m;
            }
            if(nums[s]<=nums[m])
            {
                if(nums[s]<=target && target<nums[m])
                {
                    h=m-1;
                }
                else{
                    s=m+1;
                }
            }
            else{
                if(nums[m]<target && target<=nums[h])
                {
                    s=m+1;
                }
                else{
                    h=m-1;
                }
            }
        }
        return -1;
    }
};