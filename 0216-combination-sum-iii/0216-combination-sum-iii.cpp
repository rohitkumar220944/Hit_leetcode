class Solution {
public:
    void f(int k,int n,int last,vector<vector<int>>&ans, vector<int>&temp)
    {
        if(n==0 && temp.size()==k)
        {
            ans.push_back(temp);
            return ;
        }

        for(int i=last;i<=9;i++)
        {
            if(i<=n)
            {
               temp.push_back(i);
               f(k,n-i,i+1,ans,temp);
               temp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>temp;
        f(k,n,1,ans,temp);
        return ans;
    }
};