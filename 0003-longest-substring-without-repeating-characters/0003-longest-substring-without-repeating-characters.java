class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n=s.length();
        HashMap<Character,Integer>mp=new HashMap<>();

        int l=0;
       
        int maxlen=0;
        for(int r=0;r<n;r++)
        {
            char c=s.charAt(r);
            if(mp.containsKey(c))
            {
                l=Math.max(l,mp.get(c)+1);
            }
            mp.put(c,r);
            maxlen=Math.max(maxlen,r-l+1);
            
        }
        return maxlen;
    }
}