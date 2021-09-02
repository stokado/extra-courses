// Problem
// You are given two non-empty linked lists representing two non-negative integers. 
// The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

#include <iostream>


using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

//ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
//    ListNode *p = l1, *q = l2;
//    ListNode *answer = new ListNode(0);
//    ListNode *dummy = answer;
//    int extra = 0;
//    do {
//        int x = (p != nullptr) ? p->val : 0;
//        int y = (q != nullptr) ? q->val : 0;
//        int sum = x + y + extra;
//        extra = sum / 10;
//        answer->next = new ListNode(sum % 10);
//        answer = answer->next;
//        if (p != nullptr){
//            p = p->next;
//        }
//        if (q != nullptr){
//            q = q->next;
//        }
//
//    } while (p->next != nullptr && q->next != nullptr);
//    return answer;
//}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummyHead = new ListNode(0);
    ListNode* p = l1, *q = l2, *curr = dummyHead;
    int carry = 0;
    while (p != nullptr || q != nullptr) {
        int x = (p != nullptr) ? p->val : 0;
        int y = (q != nullptr) ? q->val : 0;
        int sum = carry + x + y;
        carry = sum / 10;
        curr->next = new ListNode(sum % 10);
        curr = curr->next;
        if (p != nullptr) p = p->next;
        if (q != nullptr) q = q->next;
    }
    if (carry > 0) {
        curr->next = new ListNode(carry);
    }
    return dummyHead->next;
}

int main(){
    ListNode* l1 = new ListNode(2, new ListNode(4, new ListNode(9)));
    ListNode* l2 = new ListNode(5, new ListNode(6, new ListNode(8)));
    ListNode* answer = addTwoNumbers(l1, l2);
    return 0;
}