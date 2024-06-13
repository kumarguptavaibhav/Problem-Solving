class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummyNode = new ListNode(0, head);
        ListNode* pred = dummyNode; // Predecessor node that trails behind the current node
        ListNode* curr = head; // Current node we're examining

        // Traverse the list
        while (curr) {
            // Skip duplicate nodes
            while (curr->next && curr->next->val == curr->val) {
                curr = curr->next;
            }
            // If the predecessor's next is the current node, no duplicates were found
            // Move the predecessor to the current node
            if (pred->next == curr) {
                pred = curr;
            } else {
                // Skip the duplicate nodes by linking the predecessor's next to the current's next
                pred->next = curr->next;
            }
            // Move to the next node
            curr = curr->next;
        }
        // Return the modified list, excluding the dummy node
        return dummyNode->next;
        
    }
};