// class Solution {
// public:
//     long long subArrayRanges(vector<int>& nums) {
//         long long ans=0;
       
//         for(int i=0;i<nums.size();i++)
//         {    int large=nums[i];
//              int small=nums[i];
//             for(int j=i;j<nums.size();j++)
//             {
//                 large=max(large,nums[j]);
//                 small=min(small,nums[j]);
//                 ans+=(large-small);
//             }
           
//         }
//         return ans;
//     }
// };



class Solution {
public:
    vector<long long>nextsmall(vector<int>&nums)
    {   int n=nums.size();
        vector<long long>ans(n,n);
        stack<int>s;
        for(int i=n-1;i>=0;i--)
        {
            int curr=nums[i];
            while(!s.empty()&&nums[s.top()]>curr)
            {
                s.pop();
            }
            ans[i]=s.empty() ?n:s.top();
            s.push(i);
        }
        return ans;
    }

    vector<long long>prevsmall(vector<int>&nums)
    {   int n=nums.size();
        vector<long long>ans(n,-1);
        stack<int>s;
        for(int i=0;i<n;i++)
        {
            int curr=nums[i];
            while(!s.empty()&&nums[s.top()]>=curr)
            {
                s.pop();
            }
            ans[i]=s.empty() ? -1 : s.top();
            s.push(i);
        }
        return ans;
    }

    long long subArraymin(vector<int>&nums)
    {
       vector<long long>next=nextsmall(nums);
       vector<long long>prev=prevsmall(nums);
       long long mini=0;

       for(int i=0;i<nums.size();i++)
       {
        long long left=i-prev[i];
        long long right=next[i]-i;
        mini+=(right*left)*nums[i];

       }
       return mini;

    }



      vector<long long>nextsm(vector<int>&nums)
    {   int n=nums.size();
        vector<long long>ans(n,n);
        stack<int>s;
        for(int i=n-1;i>=0;i--)
        {
            int curr=nums[i];
            while(!s.empty()&&nums[s.top()]<curr)
            {
                s.pop();
            }
            ans[i]=s.empty() ?n:s.top();
            s.push(i);
        }
        return ans;
    }

    vector<long long>prevsm(vector<int>&nums)
    {   int n=nums.size();
        vector<long long>ans(n,-1);
        stack<int>s;
        for(int i=0;i<n;i++)
        {
            int curr=nums[i];
            while(!s.empty()&&nums[s.top()]<=curr)
            {
                s.pop();
            }
            ans[i]=s.empty() ? -1 : s.top();
            s.push(i);
        }
        return ans;
    }

      long long subArraymax(vector<int>&nums)
    {
       vector<long long>next=nextsm(nums);
       vector<long long>prev=prevsm(nums);
       long long max=0;

       for(int i=0;i<nums.size();i++)
       {
        long long left=i-prev[i];
        long long right=next[i]-i;
        max+=(right*left)*nums[i];

       }
       return max;

    }


    


    long long subArrayRanges(vector<int>& nums) {
       
     return subArraymax(nums)-subArraymin(nums);

    }
};