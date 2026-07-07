// class Solution {
// public:
//     ListNode* deleteDuplicates(ListNode* head) {
       
//         if (head == nullptr) return head;
        
//         ListNode* curr = head;
        
       
//         while (curr != nullptr && curr->next != nullptr) {
           
//             if (curr->val == curr->next->val) {
//                 ListNode* duplicate = curr->next;
//                 curr->next = curr->next->next; 
//                 delete duplicate;            
//             } else {
               
//                 curr = curr->next;
//             }
//         }
        
//         return head;
//     }
// };
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
      
        ListNode* dummy = new ListNode(0, head);
     
        ListNode* prev = dummy;
        
        while (head != nullptr) {
          
            if (head->next != nullptr && head->val == head->next->val) {
               
                while (head->next != nullptr && head->val == head->next->val) {
                    head = head->next;
                }
               
                prev->next = head->next;
            } else {
              
                prev = prev->next;
            }
         
            head = head->next;
        }
        
        ListNode* newHead = dummy->next;
        delete dummy; 
        return newHead;
    }
};