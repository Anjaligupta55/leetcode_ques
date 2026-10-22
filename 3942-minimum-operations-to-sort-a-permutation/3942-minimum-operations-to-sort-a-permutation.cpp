class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        bool inc = true, dec = true;

        for (int i = 0; i < n; i++) {
            int next = nums[(i + 1) % n];
            if (next != (nums[i] + 1) % n)     inc = false;  // 0,1,2,... cyclic
            if (next != (nums[i] - 1 + n) % n) dec = false;  // n-1,...,1,0 cyclic
        }

        if (inc) {
            int k = nums[0];                 // how far the array is rotated
            if (k == 0) return 0;            // already sorted
            return min(n - k, k + 2);        // rotate left n-k times, or reverse + rotate k + reverse
        }

        if (dec) {
            int p = find(nums.begin(), nums.end(), n - 1) - nums.begin();
            return min(p + 1, n - p + 1);    // rotate p times + reverse, or reverse + rotate (n-p) times
        }

        return -1;
    }
};