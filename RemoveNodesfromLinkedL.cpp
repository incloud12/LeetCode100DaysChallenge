class Solution {
public:
ListNode* reverse(ListNode* head){
    ListNode* curr=head;
    ListNode* prev=0;
    ListNode* nextptr=0;
    while(curr){
        nextptr=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextptr;
    }
    return prev;
}
    ListNode* removeNodes(ListNode* head) {
        ListNode* curr=head;
         ListNode* dummy=new ListNode(-1);
         ListNode* tail=dummy;
        curr=reverse(head);
        int maxi=INT_MIN;
        while(curr){
            if(curr->val>=maxi){
                tail->next=curr;
                tail=tail->next;
            }
            maxi=max(maxi,curr->val);
            curr=curr->next;
        }
        tail->next=0;
        return reverse(dummy->next);
    }
};
