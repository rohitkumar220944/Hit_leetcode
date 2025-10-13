class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int maxlen=0;
        for(int i=0;i<n;i++)
        {
            unordered_map<char,int>mp;
            int maxf=0;
            for(int j=i;j<n;j++)
            {
                 mp[s[j]]++;
                 maxf=max(maxf,mp[s[j]]);
                 int change=(j-i+1)-maxf;
                 if(change<=k)
                 {
                    maxlen=max(maxlen,j-i+1);
                 }
                 else
                 break;
            }
        }
        return maxlen;
    }
};