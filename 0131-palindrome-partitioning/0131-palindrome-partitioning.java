class Solution {
    public boolean check(int s,int e,String str)
    {
        while(s < e)
        {
            if(str.charAt(s)!=str.charAt(e))
            {
                return false;
            }
            s++;
            e--;
        }
        return true;
    }
    public void f(int ind, List<List<String>>ans, List<String>temp, String s)
    {
        if(ind==s.length())
        {
            ans.add(new ArrayList<>(temp));
            return ;
        }

        for(int i=ind;i<s.length();i++)
        {
            if(check(ind,i,s))
            {
                temp.add(s.substring(ind,i+1));
                f(i+1,ans,temp,s);
                temp.remove(temp.size()-1);
            }
        }
    }
    public List<List<String>> partition(String s) {
        List<List<String>>ans=new ArrayList<>();
        List<String>temp=new ArrayList<>();
        f(0,ans,temp,s);
        return ans;
    }
}