class Solution {
public:
    vector<int> prevsmall(vector<int>&heights)
    {
        stack<int>st;
        st.push(-1);
        vector<int>ans1(heights.size());
        for(int i=0;i<heights.size();i++)
        {
            int curr=heights[i];
            while(st.top()!=-1&&heights[st.top()]>=curr)
            {
                st.pop();
            }
           ans1[i]=st.top();
            st.push(i);
        }
        return ans1;
    }
    
    vector<int>nextsmall(vector<int>&heights)
    {
        stack<int>s;
        s.push(-1);
        vector<int>ans(heights.size());
        for(int i=heights.size()-1;i>=0;i--)
        {
            int curr=heights[i];
            while(s.top()!=-1&&heights[s.top()]>=curr)
            {
                s.pop();
            }
           ans[i]=s.top();
            s.push(i);
        }
        return ans;

    }


    int largestRectangleArea(vector<int>& heights) {
        
        vector<int>prev=prevsmall(heights);
        vector<int>next=nextsmall(heights);
        int maxArea=INT_MIN;
        int size=heights.size();
        for(int i=0;i<heights.size();i++)
        {
            int lenght=heights[i];
            if(next[i]==-1)
            {
                next[i]=size;
            }
            int width=next[i]-prev[i]-1;
            int area=lenght*width;
            maxArea=max(maxArea,area);

        }
        return maxArea;


    }
};