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
// Definition for singly-linked list.

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Initialize the dummy node and the current node to build the result list
        ListNode* dummy = new ListNode();
        ListNode* current = dummy;
        int carry = 0;

        // Iterate through both linked lists
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            // Get the values of the current nodes (if they exist)
            int x = (l1 != nullptr) ? l1->val : 0;
            int y = (l2 != nullptr) ? l2->val : 0;

            // Calculate the sum and carry
            int sum = x + y + carry;
            carry = sum / 10;

            // Add the sum's last digit as the next node in the result list
            current->next = new ListNode(sum % 10);
            current = current->next;

            // Move to the next nodes in the input lists (if they exist)
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }

        // Return the next node of dummy (which is the start of the result list)
        return dummy->next;
    }
};
