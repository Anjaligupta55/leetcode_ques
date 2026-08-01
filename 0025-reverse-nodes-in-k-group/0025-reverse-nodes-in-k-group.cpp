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
    ListNode* reverseKGroup(ListNode* head, int k) {
         vector<int>arr;
        ListNode* temp=head;
        while(temp){
            arr.push_back(temp->val);
            temp=temp->next;
        }
        // vector<int>arr2;
        // for(int i=0;i<k;i++){
        //     arr2.push_back(arr[i]);
        // }
        // reverse(arr2.begin(),arr2.end());
        // for(int i=k;i<arr.size();i++){
        //     arr2.push_back(arr[i]);
        // }
        for (int i = 0; i + k <= arr.size(); i += k) {
            reverse(arr.begin() + i, arr.begin() + i + k);
        }
        ListNode* ans=nullptr;
        ListNode* tail=nullptr;
        for(int i=0;i<arr.size();i++){
            ListNode* newnode=new ListNode(arr[i]);
            if(ans==nullptr){
                ans=newnode;
                tail=newnode;
            }
            else{
                tail->next=newnode;
                tail=newnode;
            }
        }
        return ans;
        
    }
};