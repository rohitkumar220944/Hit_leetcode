class Solution {

    public void f(int ind, int[] can,ArrayList<Integer>temp,List<List<Integer>>list)
    {
        
    list.add(new ArrayList<>(temp)); 

    for (int i = ind; i < can.length; i++)
        {

            // Skip duplicates at the same recursion level
            if (i > ind && can[i] == can[i - 1]) continue;

            temp.add(can[i]);
            f(i+1,can,temp,list);
            temp.remove(temp.size()-1);
         }  
    }
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        List<List<Integer>>list=new ArrayList<>();
        Arrays.sort(nums);
        ArrayList<Integer>temp=new ArrayList<>();
        f(0,nums,temp,list);
        return list; 
    }
}