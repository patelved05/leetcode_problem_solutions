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
ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
    ListNode* getnode(ListNode* temp, int k) {
        k = k - 1;
        while (temp != NULL && k > 0) {
            k--;
            temp = temp->next;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevs = NULL;
        while (temp != NULL) {
            ListNode* kthnode = getnode(temp, k);
            if (kthnode == NULL) {
                if (prevs) {
                    prevs->next = temp;
                }
                break;
            }
            ListNode* nextnode=kthnode->next;
            kthnode->next=NULL;
            reverseList(temp);
            if(temp==head){
                head=kthnode;
            }else{
                prevs->next=kthnode;
            }
            prevs=temp;
            temp=nextnode;
        }
        return head;
    }
};