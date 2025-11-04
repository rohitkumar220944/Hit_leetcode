class Solution {
public:



    int largestRectangleArea(vector<int>& heights) {
        
        int n=heights.size();
        stack<int>st;
        int maxi=0;
        for(int i=0;i<=n;i++)
        {
            while(!st.empty() && (i==n || heights[st.top()]>=heights[i]))
            {
                int high=heights[st.top()];
                st.pop();
                int width;
                if(st.empty())
                {
                    width=i;
                }
                else{
                    width=i-st.top()-1;
                }
               maxi=max(maxi,high*width);
            }
            st.push(i);
        }
        return maxi;

    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxArea=0;
        int rows = matrix.size();
        int cols =matrix[0].size();
        vector<int>h(cols,0);
       
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
               if(matrix[i][j]=='1')h[j]++;
               else
               h[j]=0;
            }
             int area=largestRectangleArea(h);
          maxArea=max(maxArea,area);
        }
       
        return maxArea;
    }
};