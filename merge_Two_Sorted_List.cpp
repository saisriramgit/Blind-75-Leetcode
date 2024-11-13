//Time Complexity: O(N)
//Space Complexity: O(1)

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        while(list1 != NULL && list2 != NULL) {
            if(list1->val < list2->val) {
                curr->next = list1;
                list1 = list1->next;
            } else {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }
        if(list1 != NULL) {
            curr->next = list1;
            list1 = list1->next;
        }
        if(list2 != NULL) {
            curr->next = list2;
            list2 = list2->next;
        }
        return dummy->next;
    }
};