import java.util.ArrayList;

class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {

        int i = 0, j = 0;
        int n1 = nums1.length;
        int n2 = nums2.length;

        ArrayList<Integer> list = new ArrayList<>();

        // Merge both arrays
        while (i < n1 && j < n2) {
            if (nums1[i] < nums2[j]) {
                list.add(nums1[i++]);
            } else {
                list.add(nums2[j++]);
            }
        }

        // Remaining elements of nums1
        while (i < n1) {
            list.add(nums1[i++]);
        }

        // Remaining elements of nums2
        while (j < n2) {
            list.add(nums2[j++]);
        }

        int n = list.size();

        // Find median
        if (n % 2 == 1) {
            return list.get(n / 2);
        } else {
            return (list.get(n / 2 - 1) + list.get(n / 2)) / 2.0;
        }
    }
}
