class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* slow = head;
        ListNode* fast = head->next;
        ListNode* tempHead = NULL;
        head = head->next;

        while(fast) {
        ListNode* temp = fast->next;

            fast->next = slow;
            if(tempHead) {
                tempHead->next = fast;
            }
            slow->next = temp;
            tempHead = slow;

            if(temp) {
                fast = temp->next;
                slow = temp;
            } else {
                break;
            }
        }

        return head;
    }
};
