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
   ListNode* reverselist(ListNode* head){
    ListNode* pre = NULL;
    ListNode* nex = NULL;
    while(head != NULL){
        nex = head->next;
        head->next = pre;
        pre = head;
        head = nex;
    }
    return pre;
   }
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = reverselist(slow->next);
        slow = slow->next;
        while(slow != NULL){
            if(head->val != slow->val) return false;
            slow=slow->next;
            head=head->next;
        }
        return true;

        
    }
};