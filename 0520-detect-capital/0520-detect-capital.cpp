class Solution {
public:
    bool detectCapitalUse(string word) {
        bool allcapital = true;
        bool allsmall = true;
        bool firstcapi = false;

        if(word[0] >= 'A' && word[0] <= 'Z') {
            firstcapi = true;
        }

        for(int i = 1; i < word.size(); i++) {
            if(word[i] >= 'A' && word[i] <= 'Z') {
                allsmall = false;
            }
            else {
                allcapital = false;
            }
        }
        if(firstcapi) {
            if(allcapital || allsmall) {
                return true;
            }
        }
        else {
            if(allsmall) {
                return true;
            }
        }

        return false;
    }
};