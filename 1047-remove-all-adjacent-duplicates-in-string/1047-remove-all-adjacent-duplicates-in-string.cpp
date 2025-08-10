class Solution {
public:
    string removeDuplicates(string s) {
    //     string ans="";
       
    //     for( int i=0;i<s.length();i++)
    //     {  
        
    //         if(ans.length()>0 && ans[ans.length()-1]==s[i])
    //         {
    //             ans.pop_back();
    //         }
    //         else{
    //             ans.push_back(s[i]);
            
    //         }

    //     }
    //     return ans;

     stack<char>st;
     for(auto ch:s)
     {
        if(!st.empty()&&st.top()==ch)
        {
            st.pop();
        }
        else {
              
            st.push(ch);
        }

     }
        string ans="";
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
     


    }
};