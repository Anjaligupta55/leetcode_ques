class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {

        vector<double> ans;
        vector<double> window;
        for(int i = 0; i < k; i++) {
            window.push_back((double)nums[i]);
        }

        sort(window.begin(), window.end());

        double median = 0;
        if(k % 2 == 0) {
            median = (window[k / 2] + window[(k / 2) - 1]) / 2.0;
        }
        else {
            median = window[k / 2];
        }

        ans.push_back(median);

        for(int i = k; i < nums.size(); i++) {
            double remove = (double)nums[i - k];

            int index = lower_bound(window.begin(), window.end(), remove) - window.begin();

            window.erase(window.begin() + index);
            double add = (double)nums[i];
            int pos = lower_bound(window.begin(), window.end(), add)- window.begin();
            window.insert(window.begin() + pos, add);
            if(k % 2 == 0) {
                median = (window[k / 2] + window[(k / 2) - 1]) / 2.0;
            }
            else {
                median = window[k / 2];
            }
            ans.push_back(median);
        }
        return ans;
    }
};