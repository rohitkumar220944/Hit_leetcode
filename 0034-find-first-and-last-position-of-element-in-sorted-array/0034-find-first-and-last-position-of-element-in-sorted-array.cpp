// class Solution {
// public:
//     vector<int> searchRange(vector<int>& nums, int target) {
//        int start=-1;
//        int end=-1;
//        int n=nums.size();
//        for(int i=0;i<n;i++)
//        {
//         if(nums[i]==target)
//         {
//             start=i;
//             break;
//         }
//        }

//        for(int i=n-1;i>=0;i--)
//        {
//         if(nums[i]==target)
//         {
//             end=i;
//             break;
//         }
//        }
//        return{start,end};
//     }
// };

class Solution {
public:
    int lowerbound(vector<int>&nums, int target)
    {
        int s=0;
        int e=nums.size()-1;
        int ans=nums.size();
        while(s<=e)
        {
            int mid=s+(e-s)/2;

            if(nums[mid]>=target)
            {
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }

    int upperbound(vector<int>&nums, int target)
    {
        int s=0;
        int e=nums.size()-1;
        int ans=nums.size();
        while(s<=e)
        {
            int mid=s+(e-s)/2;

            if(nums[mid]>target)
            {
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
        
    }
    vector<int> searchRange(vector<int>& nums, int target) {
       int lb=lowerbound(nums,target);
       if(lb==nums.size() || nums[lb]!=target)return{-1,-1};
       return {lb,upperbound(nums,target)-1};
       
    }
};