class Solution {
    public int beautySum(String s) {
         int n=s.length();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            HashMap<Character,Integer>mp=new HashMap<>();

            for(int j=i;j<n;j++)
            {
                char c=s.charAt(j);
                mp.put(c,mp.getOrDefault(c,0)+1);
                int mini=Integer.MAX_VALUE;
                int maxi=Integer.MIN_VALUE;

                for(int v:mp.values())
                {
                    mini=Math.min(mini,v);
                    maxi=Math.max(maxi,v);
                }
                ans+=maxi-mini;
            }
           
        }
         return ans;
    }
}