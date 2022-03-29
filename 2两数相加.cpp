//给你两个 非空 的链表，表示两个非负的整数。
//它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
//请你将两个数相加，并以相同形式返回一个表示和的链表。
//你可以假设除了数字 0 之外，这两个数都不会以 0 开头。


#include "myhead.h"
 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = nullptr;
        ListNode* tail = nullptr;
        int carry = 0; //存储进位
        while (l1 || l2) {
            int n1 = l1 ? l1->val : 0;
            int n2 = l2 ? l2->val : 0;
            int sum = n1 + n2 + carry;
            if (!res) {
                tail = new ListNode(sum % 10);
                res = tail;
            }
            else {
                ListNode* temp = new ListNode(sum % 10);
                tail->next = temp;
                tail = tail->next;
            }
            carry = sum / 10;
            if (l1) {
                l1 = l1->next;
            }
            if (l2) {
                l2 = l2->next;
            }
        }
        if (carry > 0) { //如果进位大于0，需要额外开辟一个结点存储最高位
            ListNode* temp = new ListNode(carry);
            tail->next = temp;
        }
        return res;
    }
};