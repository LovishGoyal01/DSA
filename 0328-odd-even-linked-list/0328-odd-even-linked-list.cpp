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
     ListNode* first = nullptr;
     ListNode* second = nullptr;
     ListNode* secondH = head->next;
     ListNode* curr = head; 
     int cnt=0;
     while(curr!=nullptr){
        cnt++;
       if(cnt%2==1){
          if(cnt==1){
           first=curr;
          }else{
            first->next=curr;
            first=first->next;
          } 
          curr=curr->next;
       }else{
          if(cnt==2){
           second=curr;
          }else{
            second->next=curr;
            second=second->next;
          }
           curr=curr->next;
           second->next=nullptr;
       }
     }  
     first->next=secondH;
     return head;
    }
};