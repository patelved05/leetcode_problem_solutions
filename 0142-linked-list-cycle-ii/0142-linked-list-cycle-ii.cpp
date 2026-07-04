/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        bool yes = false;
// cheak  loop 
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                yes = true;
                break;
            }
        }
        // cheak true false condition 
        if (!yes) {
            return NULL;
        }
        slow = head;
       
        while (slow != fast) {
            slow = slow->next;
           
            fast = fast->next;
        }
        
        return slow;
    }
};