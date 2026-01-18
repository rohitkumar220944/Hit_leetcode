class Solution {
    public int myAtoi(String s) {
        s=s.trim();
        if(s.isEmpty())
        {
            return 0;
        }
       int i=0;
       int sign=1;
       if(s.charAt(0)=='-')
       {
        sign=-1;
        i++;
       }
       else if(s.charAt(0)=='+')
       {
        i++;
       }
       long ans = 0;

    while (i < s.length() && Character.isDigit(s.charAt(i)))
     {
        ans = ans * 10 + (s.charAt(i) - '0');

        if (ans * sign > Integer.MAX_VALUE)
          return Integer.MAX_VALUE;
        if (ans * sign < Integer.MIN_VALUE)
           return Integer.MIN_VALUE;

        i++;
     }

      return (int)(ans * sign);

    }
}