class Solution {
public:
    ListNode* sortList(ListNode* head) {

        if (!head || !head->next) {
            return head;
        }

        ListNode* prev = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        if (prev) {
            prev->next = nullptr;
        }

        ListNode* left = sortList(head);
        ListNode* right = sortList(slow);

        return merge(left, right);
    }

private:
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