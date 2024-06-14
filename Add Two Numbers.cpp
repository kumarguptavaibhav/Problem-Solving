class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* current = dummyNode;
        int carry = 0;
        while(temp1 != NULL || temp2 != NULL){
            int sum = carry;
            if(temp1){
                sum = sum + temp1->val;
            }
            if(temp2){
                sum = sum + temp2->val;
            }
            ListNode* NewNode = new ListNode(sum % 10);

            carry = sum/10;

            current->next = NewNode;
            current = current->next;
            // for increment of loop
            if(temp1){
                temp1 = temp1->next;
            }
            if(temp2){
                temp2 = temp2->next;
            }
        }

        if(carry){
            ListNode* NewNode = new ListNode(carry);
            current->next = NewNode;
        }

        return dummyNode->next;
    }
};