class Solution {

    long hoursRequired(int[] piles, int speed) {
        long totalHour = 0;

        for (int i = 0; i < piles.length; i++) {
            totalHour += (piles[i] + speed - 1L) / speed;
        }
        return totalHour;
    }

    public int minEatingSpeed(int[] piles, int h) {

        int s = 1;
        int e = 0;

        for (int p : piles) {
            e = Math.max(e, p);
        }

        int ans = e;

        while (s <= e) {
            int mid = s + (e - s) / 2;

            long totalHour = hoursRequired(piles, mid);

            if (totalHour <= h) {
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return ans;
    }
}
