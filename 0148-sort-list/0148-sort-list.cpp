class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;

        
        int length = 0;
        ListNode* curr = head;
        while (curr) {
            length++;
            curr = curr->next;
        }

        ListNode dummy(0);
        dummy.next = head;

       
        for (int step = 1; step < length; step <<= 1) {
            ListNode* prev = &dummy;
            curr = dummy.next;

            while (curr) {
                ListNode* left = curr;
                ListNode* right = split(left, step);
                curr = split(right, step); 

                prev->next = merge(left, right);
                while (prev->next) {
                    prev = prev->next;
                }
            }
        }

        return dummy.next;
    }

private:
   
    ListNode* split(ListNode* head, int step) {
        if (!head)
            return nullptr;

        for (int i = 1; head->next && i < step; ++i) {
            head = head->next;
        }

        ListNode* rest = head->next;
        head->next = nullptr;
        return rest;
    }

    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (list1 && list2) {
            if (list1->val < list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        tail->next = list1 ? list1 : list2;
        return dummy.next;
    }
};