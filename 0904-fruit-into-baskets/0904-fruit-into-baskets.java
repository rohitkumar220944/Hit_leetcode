class Solution {
    public int totalFruit(int[] fruits) {

        int l=0;
        int r=0;
        int n=fruits.length;
        int maxlen=0;
        HashMap<Integer,Integer>mp=new HashMap<>();

        while(r<n)
        {
            mp.put(fruits[r],mp.getOrDefault(fruits[r],0)+1);

            
            while(mp.size()>2)
            {
                mp.put(fruits[l],mp.get(fruits[l])-1);
               
                if(mp.get(fruits[l])==0)
                {
                    mp.remove(fruits[l]);
                }
                l++;
            }
           
            maxlen=Math.max(maxlen,r-l+1);
            r++;
        }
        return maxlen;
        
    }
}