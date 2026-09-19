class Solution {
public:
    string reversePrefix(string word, char ch) {
        int p=-1;
        for(int i=0;i<word.size();i++){
            if(ch==word[i]){
                p=i;
                break;
            }
        }
        if(p==-1){
            return word;
        }
        reverse(word.begin(),word.begin()+p+1);
        return word;
    }
};