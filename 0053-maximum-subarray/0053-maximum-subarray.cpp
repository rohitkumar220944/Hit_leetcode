class Solution {
public:
    
     int maxSubArray_Helper(vector<int>&nums,int start,int end)
     {  if(start==end) return nums[start];
        int MaxLeftBoaderSum=INT_MIN;
         int MaxRightBoaderSum=INT_MIN;
         int mid=start+((end-start)>>1);
         int MaxLeftSum=maxSubArray_Helper(nums,start,mid);
         int MaxRightSum=maxSubArray_Helper(nums,mid+1,end);

         int  LeftBoaderSum=0;
          int  RightBoaderSum=0;
         for(int i=mid;i>=start;--i)
         {
            LeftBoaderSum+=nums[i];
            if(LeftBoaderSum>MaxLeftBoaderSum)
            {
                  MaxLeftBoaderSum=LeftBoaderSum;
            }
         }

         for(int i=mid+1;i<=end;i++)
         {
            RightBoaderSum+=nums[i];
            if(RightBoaderSum>MaxRightBoaderSum)
            {
                  MaxRightBoaderSum=RightBoaderSum;
            }
         }
        int CrossBoaderSum=MaxLeftBoaderSum+MaxRightBoaderSum;

        return max(MaxLeftSum,max(MaxRightSum,CrossBoaderSum));

     }
    int maxSubArray(vector<int>& nums) {
      return maxSubArray_Helper(nums,0,nums.size()-1); 
    }
};