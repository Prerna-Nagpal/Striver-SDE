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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* l1 = list1;
        ListNode* l2 = list2;
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        if(l1==NULL && l2==NULL) return NULL;
        while(l1!=NULL && l2!=NULL){
        if(l1->val <l2->val){
            temp->next = l1;
            l1=l1->next;
        }
        else {
            temp->next = l2;
            l2=l2->next;
        }
        temp=temp->next;
        }
        while(l1!=NULL){
            temp->next = l1;
            temp=temp->next;
            l1=l1->next;

        }
        while(l2!=NULL){
            temp->next = l2;
            temp=temp->next;
            l2=l2->next;
        }
return dummy->next;
    }
};