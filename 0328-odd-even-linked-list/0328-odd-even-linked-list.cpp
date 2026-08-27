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
        if(head==nullptr) return head;
        ListNode* dummyOdd = new ListNode(-1);
        ListNode* dummyEven = new ListNode(-1);
        ListNode* dummyOHead = dummyOdd;
        ListNode* dummyEHead = dummyEven;
        int count = 1; 
        while(head!=nullptr){
           if(count%2==1){
             dummyOdd->next = head;
             dummyOdd = dummyOdd->next;
           }else{
             dummyEven->next = head;
             dummyEven = dummyEven->next;
           }
           head = head->next;
           count++;
        }
        dummyEven->next = nullptr;
        dummyOdd->next = dummyEHead ->next;
        return dummyOHead->next;
    }
};