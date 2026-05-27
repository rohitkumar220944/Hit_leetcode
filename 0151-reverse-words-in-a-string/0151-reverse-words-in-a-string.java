// import java.util.Stack;

// class Solution {
//     public String reverseWords(String s) {

//         Stack<String> st = new Stack<>();
//         StringBuilder temp = new StringBuilder();

//         for (int i = 0; i < s.length(); i++) {

//             // skip spaces
//             while (i < s.length() && s.charAt(i) == ' ') {
//                 i++;
//             }

//             // collect word
//             while (i < s.length() && s.charAt(i) != ' ') {
//                 temp.append(s.charAt(i));
//                 i++;
//             }

//             if (temp.length() > 0) {
//                 st.push(temp.toString());
//                 temp.setLength(0);
//             }
//         }

//         StringBuilder ans = new StringBuilder();

//         while (!st.isEmpty()) {
//             ans.append(st.pop());
//             if (!st.isEmpty()) {
//                 ans.append(" ");
//             }
//         }

//         return ans.toString();
//     }
// }

class Solution {
    public String reverseWords(String s) {
        
        String []st=s.trim().split("\\s+");
        StringBuilder sr=new StringBuilder();

        for(int i=st.length-1;i>=0;i--)
        {
            sr.append(st[i]);

            if(i>0)
            {
                sr.append(" ");
            }

        }
        return sr.toString();


    }
}
