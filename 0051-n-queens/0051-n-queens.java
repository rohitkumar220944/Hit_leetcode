class Solution {
    public boolean isSafe(List<String>temp,int row,int col,int n)
    {
        for (int i = 0; i < row; i++) {
            if (temp.get(i).charAt(col) == 'Q') return false;
        }

       
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (temp.get(i).charAt(j) == 'Q') return false;
        }

          for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
            if (temp.get(i).charAt(j) == 'Q') return false;
        }

        return true;
    }
    public void solve(List<String>temp,List<List<String>>ans,int n,int row)
    {
        if(row==n)
        {
            ans.add(new ArrayList<>(temp));
            return ;
        }

        for(int col=0;col<n;col++)
        {
            if(isSafe(temp,row,col,n))
            {
                char[] arr = temp.get(row).toCharArray();
                arr[col] = 'Q';
                temp.set(row, new String(arr));

                solve(temp,ans,n,row+1);

                arr[col] = '.';
                temp.set(row, new String(arr));
            }
        }
    }
    public List<List<String>> solveNQueens(int n) {
        List<List<String>>ans=new ArrayList<>();
        List<String>temp=new ArrayList<>();

        for(int i=0;i<n;i++)
        {
            temp.add(".".repeat(n));
        }

        solve(temp,ans,n,0);
        return ans;

    }
}
