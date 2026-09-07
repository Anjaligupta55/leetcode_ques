class Solution {
public:
    void solve(int i, int n, vector<int>& digits, vector<int>& ans,
               string& m, vector<int>& used) {

        if(m.size() == 3) {
            if(stoi(m) % 2 == 0) {
                ans.push_back(stoi(m));
            }
            return;
        }
        for(int i = 0; i < digits.size(); i++) {

            if(used[i] == 1) {
                continue;
            }
            if(m.size() == 0 && digits[i] == 0) {
                continue;
            }
            used[i] = 1;
            m += (digits[i] + '0');
            solve(i + 1, n, digits, ans, m, used);
            m.pop_back();
            used[i] = 0;
        }
    }
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();
        vector<int> ans;
        string m = "";
        vector<int> used(digits.size(), 0);
        solve(0, n, digits, ans, m, used);
        sort(ans.begin(), ans.end());
         ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};