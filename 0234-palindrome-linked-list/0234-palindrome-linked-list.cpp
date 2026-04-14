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
    
    ListNode* reverse(ListNode *head){
        if(head==nullptr || head->next==nullptr) return head;

        ListNode* curr = head;
        ListNode* prev=nullptr;
        ListNode* temp=nullptr;
        while(curr!=nullptr){
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
      ListNode* fast=head;  
      ListNode* slow=head;
      while(fast->next!=nullptr && fast->next->next!=nullptr){
        slow=slow->next;
        fast = fast->next->next;
      }
      ListNode* newhead= reverse(slow->next);
      ListNode* first=head;  
      ListNode* second=newhead;

      while(second!=nullptr){
        if(first->val!=second->val){
            reverse(newhead);
            return false;
        }
        first=first->next;
        second=second->next;
      }
      reverse(newhead);
      return true;

    }
};