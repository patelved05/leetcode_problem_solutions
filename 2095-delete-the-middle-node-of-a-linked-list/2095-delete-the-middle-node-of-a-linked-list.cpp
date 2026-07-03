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

//  THIS CODE TAKE FROM GFG AND EDIT SMALL CHANGE 
// class Solution {
    
//     ListNode* delPos(ListNode* head, int x) {
//         if (head == nullptr)
//             return nullptr;
//         if (x == 1) {
//             ListNode* newHead = head->next;
//             delete head;
//             return newHead;
//         }
        
//         ListNode* prevs = head;
//         int count = 1;
        
//         for (ListNode* curr = head->next; curr != nullptr; curr = curr->next) {
//             count++;
//             if (count == x) {
//                 prevs->next = curr->next;
//                 delete curr;
//                 break;
//             }
//             prevs = curr;
//         }
        
//         return head;
//     }	
    

// public:
//     ListNode* deleteMiddle(ListNode* head) {
//         if (head == nullptr || head->next == nullptr) 
//             return nullptr;
        
  
//         int length = 0;
//         ListNode* temp = head;
//         while (temp != nullptr) {
//             length++;
//             temp = temp->next;
//         }
        
//         int mid = (length / 2) + 1;  
        
//         return delPos(head, mid);
//     }
// };
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (head->next == nullptr)
        {
            return NULL;
        }
        else if (head->next->next == nullptr)
        {
            ListNode* temp = head->next;
            head->next = nullptr;
            delete temp;
            return head;
        }
        else
        {
            ListNode* fp = head;
            ListNode* sp = head;
            while (sp->next->next != nullptr && sp->next->next->next != nullptr)
            {
                sp = sp->next->next;
                fp = fp->next;
            }
            ListNode* temp = fp->next;
            fp->next = fp->next->next;
            delete temp;
            return head;
        }
        
    }
};