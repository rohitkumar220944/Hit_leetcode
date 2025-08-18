class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        st.push(-1);
        unordered_map<int,int>ans;
         vector<int> result;
     
            for(int j=nums2.size()-1;j>=0;j--)
            {
                
                    int curr=nums2[j];
                    while(st.top()!=-1&&st.top()<=curr)
                    {
                        st.pop();
                    }
                    ans[nums2[j]]=st.top();
                    st.push(nums2[j]);
        
            }

        for(auto num:nums1)
        {
            result.push_back(ans[num]);
        }
        return result;

    }
};