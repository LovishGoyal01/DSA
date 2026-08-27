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

    ListNode* getKNode(ListNode* temp, int k) {
        while(temp!=nullptr && k>1){
            temp=temp->next;
            k--;
        }
        return temp;
    }

    ListNode* ReverseList(ListNode* temp) {
        ListNode* prev  = nullptr;
        ListNode* nextNode = nullptr;
        while(temp!=nullptr){
          nextNode = temp->next;
          temp->next = prev;
          prev = temp;
          temp = nextNode;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head,int k) {
        ListNode* curr = head;
        ListNode* KthNode = nullptr;
        ListNode* prevLast = nullptr;
        while(curr!=nullptr){
           KthNode = getKNode(curr,k);
           if(KthNode==nullptr){
            if(prevLast) prevLast->next = curr;
             break;
           }
           
           ListNode* nextN = KthNode->next;
           KthNode->next = nullptr;
           ReverseList(curr);

           if(curr==head){
             head = KthNode;
           }else{
             prevLast ->next = KthNode;
           }
           prevLast = curr;
           curr = nextN;
        }
        return head;
    }
};