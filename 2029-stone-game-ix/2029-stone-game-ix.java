class Solution {
    public boolean stoneGameIX(int[] stones) {

        int[] count = new int[3];

        // Count remainder 0, 1, 2
        for (int stone : stones) {
            count[stone % 3]++;
        }

        // count[0] is even
        if (count[0] % 2 == 0) {
            return count[1] > 0 && count[2] > 0;
        }

        // count[0] is odd
        return Math.abs(count[1] - count[2]) > 2;
    }
}