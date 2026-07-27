class Solution {
    public void moveZeroes(int[] nums) {

        int k = 0;

        // Move all non-zero elements to the front
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != 0) {
                nums[k] = nums[i];
                k++;
            }
        }

        // Fill remaining positions with zeroes
        while (k < nums.length) {
            nums[k] = 0;
            k++;
        }
    }
}