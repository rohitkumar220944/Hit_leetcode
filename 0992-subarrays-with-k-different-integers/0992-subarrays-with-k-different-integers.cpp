class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n= nums.size();
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            unordered_map<int,int>mp;
            for(int j=i;j<n;j++)
            {
                mp[nums[j]]++;
                if(mp.size()==k)
                {
                    cnt=cnt+1;
                }
                else if(mp.size()>k)
                {
                    break;
                }

            }
        }
        return cnt;
    }
};