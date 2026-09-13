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
    ListNode* sortList(ListNode* head) {
        // Base case: 0 or 1 node is already sorted
        if (!head || !head->next) {
            return head;
        }

        // 1. Split the list into two halves
        ListNode* mid = getMid(head);

        // 2. Recursively sort both halves
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);

        // 3. Merge the sorted halves
        return merge(left, right);
    }


    // Finds left-middle node and severs the link between halves
    ListNode* getMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next; // Starts at head->next to safely split 2-node lists

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* mid = slow->next;
        slow->next = nullptr; // Sever connection
        return mid;
    }

    // Merges two sorted lists in ascending order
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy(0); // Stack-allocated dummy head node
        ListNode* tail = &dummy;

        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val <= l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        // Attach remaining non-empty list
        tail->next = (l1 != nullptr) ? l1 : l2;
        return dummy.next;
    }
};