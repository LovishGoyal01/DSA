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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr || head->next==nullptr || k==0 ) return head;
        ListNode* slow=head;
        ListNode* fast=head;
        int count = 0 ;
        while(slow!=nullptr){
            slow=slow->next;
            count++;
        }
        slow=head;
        
        k=k%count;
        if(k==0) return head;
  
        while(k>0){
        fast=fast->next;
        k--;
        }


        while(fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next;
        }
        ListNode* newHead = slow->next;
        slow->next=nullptr;
        fast->next=head;
        return newHead;
    }
};