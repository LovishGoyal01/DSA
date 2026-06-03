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
    ListNode* reverse(ListNode* node){
        ListNode* prev=nullptr;
        ListNode* temp=nullptr;
        while(node!=nullptr){
            temp=node->next;
            node->next=prev;
            prev=node;
            node=temp;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=nullptr && fast->next->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* newHead=reverse(slow->next);
        ListNode* first=head;
        ListNode* second=newHead;
        while(second!=nullptr){
            if(second->val!=first->val){
                reverse(newHead);
                 return false;
            }
            second=second->next;
            first=first->next;
        }
        reverse(newHead);
        return true;
    }
};