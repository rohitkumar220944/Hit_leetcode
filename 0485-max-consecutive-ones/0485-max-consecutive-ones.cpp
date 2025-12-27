class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        int maxcnt=0;
        int i=0;
        while(i<n)
        {
            if(nums[i]==1)
            {
                cnt +=1;
                i++;
            }
            else{
                cnt=0;
                i++;
            }
             maxcnt=max(cnt,maxcnt);
        }
        return maxcnt;
    }
};