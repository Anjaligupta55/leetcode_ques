class Solution {
public:

    void solve(vector<int>& digits, vector<int>& used,
               int num, int count, set<int>& st) {

        if (count == 3) {
            if (num % 2 == 0)
                st.insert(num);
            return;
        }

        for (int i = 0; i < digits.size(); i++) {

            if (used[i])
                continue;
            if (count == 0 && digits[i] == 0)
                continue;

            used[i] = 1;

            solve(digits, used,
                  num * 10 + digits[i],
                  count + 1, st);

            used[i] = 0;
        }
    }

    int totalNumbers(vector<int>& digits) {

        vector<int> used(digits.size(), 0);

        set<int> st;

        solve(digits, used, 0, 0, st);

        return st.size();
    }
};