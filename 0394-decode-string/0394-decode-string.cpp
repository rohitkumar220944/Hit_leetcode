class Solution {
public:
    string decodeString(string s) {
        stack<string>st;
        stack<int>num;
        int k=0;
        string curr="";

        for(auto ch:s)
        {
            if(isdigit(ch))
            {
                k=k*10+(ch-'0');
            }
            else if(ch=='[')
            {
                num.push(k);
                st.push(curr);
                k=0;
                curr="";
            }
            else if(ch==']')
            {
                int repeat=num.top();
                num.pop();
                string prev=st.top();
                st.pop();
                string expand="";
                for(int i=0;i<repeat;i++)
                {
                    expand+=curr;
                }
                curr=prev+expand;
            }
            else{
                curr+=ch;
            }
        }
        return curr;

    }
};