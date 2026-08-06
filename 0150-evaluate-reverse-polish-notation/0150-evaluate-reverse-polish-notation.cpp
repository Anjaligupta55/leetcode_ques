class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>num;
        
        for(int i=0;i<tokens.size();i++){
            string ch=tokens[i];
            if (ch != "+" && ch != "-" && ch != "*" && ch != "/"){
                num.push(stoi(ch));
            }
            else{
                //char chs=tokens[i];
                
                int a=num.top();
                num.pop();
                int b=num.top();
                num.pop();
                int result;
                // switch(ch){
                //     case "+":
                //     result=a+b;
                //     break;
                //     case "-":
                //     result=a-b;
                //     break;
                //     case "*":
                //     result=a*b;
                //     break;
                //     case "/":
                //     result=a/b;
                //     break;
                //     default:
                //     return;

                // }
                if (ch=="+"){
                    result=a+b;
                }
                else if (ch=="-"){
                    result=b-a;
                }
                else if (ch=="*"){
                    result=a*b;
                }
                else if (ch=="/"){
                    result=b/a;
                }
                num.push(result);
                
            }
        }
        return num.top();
        
    }
};