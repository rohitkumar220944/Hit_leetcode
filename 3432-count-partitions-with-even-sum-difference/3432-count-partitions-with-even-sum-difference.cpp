// class Solution {
// public:
//     int countPartitions(vector<int>& nums) {
//         int total = 0, n = nums.size();
//         for(int i = 0; i < n; ++i) total += nums[i];
//         if(total % 2==0)
//         {
//             return n-1;
//         }
//         else{
//             return 0;
//         }
//     }
// };



class Solution {
public:
    int countPartitions(vector<int>& nums) {
      int totsum=0;
      int count=0;
      int n=nums.size();

      for(auto &it:nums)totsum+=it;
      
      int leftsum=0;
      
      for(int i=0;i<n-1;i++)
      {
        leftsum+=nums[i];
        int rightsum=totsum-leftsum;
        if((leftsum-rightsum)%2==0)
        {
            count++;
        }
        else{
            return 0;
        }



      }
      return count;
    }
};