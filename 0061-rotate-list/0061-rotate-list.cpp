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
        if(head==nullptr || k<=0) return head;
        int len=1;
        ListNode* temp=head;
        while(temp->next!=nullptr){
          len++;  
          temp=temp->next;
        }
        temp->next=head;
        temp=head;
        if(k>=len) k=k%len;
        while(len-k-1>0){
          len--;
          temp=temp->next;
        }
        head=temp->next;
        temp->next=nullptr;
        return head;
    }
};