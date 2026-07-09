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
// for only smaller values
//  class Solution {
// public:
//     ListNode* rotateRight(ListNode* head, int k) {
//         ListNode* temp=head;
//         int i=1;
//         while(i<=k){
//             while(temp->next->next!=NULL) temp=temp->next;
//             temp->next->next=head;
//             head=temp->next;
//             temp->next=NULL;
//             temp=head;
//             i++;
//         }

//    return head; }
// };
class Solution {
public:
    ListNode* findlastnode(ListNode* temp, int k) {
        int count = 1;
        while (temp != NULL) {
            if (count == k) {
                return temp;
            }
            count++;
            temp = temp->next;
        }
        return temp;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || k == 0) {
            return head;
        }
        ListNode* temp = head;
        int len = 1;
        while (temp->next != NULL) {
            temp = temp->next;
            len++;
        }
        if (k % len == 0) {
            return head;
        }
        k = k % len;
        temp->next = head;
        ListNode* lastnode = findlastnode(head, len - k);
        head = lastnode->next;
        lastnode->next = NULL;

        return head;
    }
};