class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>map;
        int left=0;
        int right=0;
        int maxlen=0;
        while(right<s.length())
        {
            if(!map.contains(s[right]))
            {
                map.insert(s[right]);
                maxlen=max(maxlen,right-left+1);
                right++;
            }
            else
            {
                map.erase(s[left]);
                left++;
            }
        }
        return maxlen;
    }
};