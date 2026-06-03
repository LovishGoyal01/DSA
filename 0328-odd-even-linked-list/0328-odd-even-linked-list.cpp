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
    ListNode* oddEvenList(ListNode* head) {
     if(head==nullptr || head->next==nullptr) return head;
     ListNode* first = head;
     ListNode* second = head->next;
     ListNode* secondH = head->next;
     while(second!=nullptr && second->next!=nullptr){
      first->next=first->next->next;
      second->next=second->next->next;
      first=first->next;
      second=second->next;
     }  
     first->next=secondH;
     return head;
    }
};