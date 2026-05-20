class Solution {
    public int numberOfSubstrings(String s) {
        int l=0,r=0;
        int n=s.length();
        int ans=0;

        HashMap<Character,Integer>mp=new HashMap<>();

        while(r<n)
        {
            char c=s.charAt(r);
            mp.put(c,mp.getOrDefault(c,0)+1);

            while(mp.size()==3)
            {
                char lc=s.charAt(l);
                mp.put(lc,mp.get(lc)-1);
                ans+=n-r;
                if(mp.get(lc)==0)
                {
                    mp.remove(lc);
                }
                l++;
            }
            r++;
        }
        return ans;
    }
}