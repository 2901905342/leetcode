//给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
//请你将两个数相加，并以相同形式返回一个表示和的链表。
//你可以假设除了数字 0 之外，这两个数都不会以 0 开头。

#include "myhead.h"
//  Definition for singly-linked list.
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
        ListNode* virhead = new ListNode(); //设置虚拟头结点
        ListNode* cur = new ListNode();
        ListNode* tail;
        virhead->next = cur;
        int addin = 0;  //设置进位
        while (l1 != nullptr || l2 != nullptr) {
            int c1 = (l1 != nullptr) ? l1->val : 0;
            int c2 = (l2 != nullptr) ? l2->val : 0;
            cur->val = (c1 + c2 + addin) % 10;  //注意计算表达式
            addin = (c1 + c2 + addin) / 10;    //注意计算表达式
            tail = cur;   //记录倒数第二个节点
            ListNode* temp = new ListNode();
            cur->next = temp;
            cur = cur->next;
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }
        if (addin) cur->val = addin; //将尾节点的值设置为addin
        else tail->next = nullptr; //将倒数第二个节点指向空
        return virhead->next;
    }

};