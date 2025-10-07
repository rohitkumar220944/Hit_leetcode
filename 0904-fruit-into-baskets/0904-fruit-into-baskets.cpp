class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>mp;
        int maxlen=0;
        int n=fruits.size();
        int l=0;
        int r=0;
        while(r<n)
        {
            mp[fruits[r]]++;

            if(mp.size()>2)
            {
                mp[fruits[l]]--;

                if(mp[fruits[l]]==0)
                {
                mp.erase(fruits[l]);
                }
                l++;
            }
            if(mp.size()<=2)
            {
                maxlen=max(maxlen,r-l+1);
            }
            r++;

        }
        return maxlen;
       
    }
};