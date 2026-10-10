class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {

        long long k = (long long)k1 + k2;
        vector<long long> diff(nums1.size());
        long long high = 0;
        for (int i = 0; i < nums1.size(); i++) {
            diff[i] = abs((long long)nums1[i] - nums2[i]);
            high = max(high, diff[i]);
        }
        long long low = 0;
        while (low < high) {
            long long mid = low + (high - low) / 2;
            long long operations = 0;
            for (long long d : diff) {
                if (d > mid) {
                    operations += d - mid;
                }
                if (operations > k) {
                    break;
                }
            }
            if (operations <= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        long long x = low;
        long long used = 0;
        for (int i = 0; i < diff.size(); i++) {
            if (diff[i] > x) {
                used += diff[i] - x;
                diff[i] = x;
            }
        }
        long long remaining = k - used;
        if (x > 0) {
            for (int i = 0; i < diff.size() && remaining > 0; i++) {
                if (diff[i] == x) {
                    diff[i]--;
                    remaining--;
                }
            }
        }
        long long ans = 0;
        for (long long d : diff) {
            ans += d * d;
        }
        return ans;
    }
};