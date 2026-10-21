class Node{
public:
    string data;
    Node* next;
    Node* back;
    Node() : data(""),next(nullptr),back(nullptr){};
    Node(string x) : data(x),next(nullptr),back(nullptr){};
    Node(string x,Node* next,Node* back):data(x),next(next),back(back){};
};
class BrowserHistory {
    Node* curr;
public:
    BrowserHistory(string homepage) {
        curr=new Node(homepage);

    }
    
    void visit(string url) {
        Node* newNode=new Node(url);
        curr->next=newNode;
        newNode->back=curr;
        curr=curr->next;
    }
    
    string back(int steps) {
        while(steps){
            if(curr->back){
                curr=curr->back;
            }
            else{
                break;
            }
            steps--;
        }
        return curr->data;
    }
    
    string forward(int steps) {
        while(steps){
            if(curr->next){
                curr=curr->next;
            }
            else{
                break;
            }
            steps--;
        }
        return curr->data;
        
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */