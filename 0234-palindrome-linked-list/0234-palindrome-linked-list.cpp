
class Solution {
public:
    ListNode* reverselist(ListNode* temp) {
        ListNode* prev = NULL;

        while (temp != NULL) {
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return true;
        }

        ListNode* slow = head, *fast = head;

        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* newhead = reverselist(slow->next);

        ListNode* first = head;
        ListNode* second = newhead;

        while (second != NULL) {
            if (first->val != second->val) {
                reverselist(newhead);
                return false;
            }

            second = second->next;
            first = first->next;
        }

        reverselist(newhead);
        return true;
    }
};
