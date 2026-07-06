/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        vector<int>arr;
        ListNode* temp=head;
        while(temp!=nullptr){
            arr.push_back(temp->val);
            temp=temp->next;
        }
        ListNode* h=new ListNode(0);
        temp=h;
        int n=arr.size();
        for(int i=0;i<n;i+=2){
            temp->next=new ListNode(arr[i]);
            temp=temp->next;
        }
        for(int i=1;i<n;i+=2){
            temp->next=new ListNode(arr[i]);
            temp=temp->next;
        }
        return h->next;
        
    }
};