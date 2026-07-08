class Solution {
public:
    bool isPrime(int n) {
        if (n < 2) return false;

        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0)
                return false;
        }
        return true;
    }

    int countPrimeSetBits(int left, int right) {
        int ans = 0;

        for (int i = left; i <= right; i++) {
            int cnt = 0;
            int x = i;

            while (x > 0) {
                if (x % 2 == 1)
                    cnt++;
                x /= 2;
            }

            if (isPrime(cnt))
                ans++;
        }

        return ans;
    }
};