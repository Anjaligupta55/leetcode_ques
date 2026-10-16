class Solution {
public:
    static const int MOD = 1e9 + 7;

    class SegmentTree {
    public:
        vector<long long> sum, sq, lazy;
        int n;

        SegmentTree(int n) : n(n) {
            sum.resize(4 * n, 0);
            sq.resize(4 * n, 0);
            lazy.resize(4 * n, 0);
        }

        void push(int node, int l, int r) {
            if (lazy[node] == 0) return;

            long long x = lazy[node];
            long long len = r - l + 1;

            sq[node] = (sq[node] + 2 * x * sum[node] % MOD
                        + x * x % MOD * len % MOD) % MOD;

            sum[node] = (sum[node] + x * len) % MOD;

            if (l != r) {
                lazy[node * 2] = (lazy[node * 2] + x) % MOD;
                lazy[node * 2 + 1] =
                    (lazy[node * 2 + 1] + x) % MOD;
            }

            lazy[node] = 0;
        }

        void update(int node, int l, int r, int ql, int qr) {
            push(node, l, r);

            if (r < ql || l > qr) return;

            if (ql <= l && r <= qr) {
                lazy[node] = 1;
                push(node, l, r);
                return;
            }

            int mid = l + (r - l) / 2;

            update(node * 2, l, mid, ql, qr);
            update(node * 2 + 1, mid + 1, r, ql, qr);

            sum[node] = (sum[node * 2] + sum[node * 2 + 1]) % MOD;
            sq[node] = (sq[node * 2] + sq[node * 2 + 1]) % MOD;
        }

        void update(int l, int r) {
            if (l <= r)
                update(1, 0, n - 1, l, r);
        }

        long long getSquareSum() {
            return sq[1];
        }
    };

    int sumCounts(vector<int>& nums) {
        int n = nums.size();

        SegmentTree st(n);
        unordered_map<int, int> last;
        long long ans = 0;

        for (int r = 0; r < n; r++) {
            int l = 0;

            if (last.count(nums[r]))
                l = last[nums[r]] + 1;

            st.update(l, r);
            last[nums[r]] = r;

            ans = (ans + st.getSquareSum()) % MOD;
        }

        return ans;
    }
};