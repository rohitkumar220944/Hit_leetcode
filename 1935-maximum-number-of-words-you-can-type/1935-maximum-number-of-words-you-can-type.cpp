class Solution {
public:
    int solve(string s, string broken)
    {
        unordered_set<char>m(s.begin(),s.end());

        for(auto ch:broken)
        {
            if(m.find(ch)!=m.end())
            {
                return 0;
            }
           
        }
       return 1;
    }
    int canBeTypedWords(string text, string brokenLetters) {
        int n=text.size();
        int i=0;
        int j=0;
        int count=0;

        while(i<=n)
        {
            if(i==n || text[i]==' ')
            {
            string s=text.substr(j,i-j+1);
            count+=solve(s,brokenLetters);
             j=i+1;
            }

            i++;
        }
       return count;

    }
};