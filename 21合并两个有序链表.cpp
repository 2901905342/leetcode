//将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。


#include "myhead.h"

//  Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
  /////////////思路1 ：迭代模拟
  /////值得注意的是要使用虚拟头结点，而且是两个虚拟头结点（res和vir)。res保持不动，保证返回值为res->next;
  //  vir用于链接下一个节点，具体过程看代码

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;
        ListNode* vir = new ListNode(0);
        ListNode* res = vir;
        ListNode* cur1 = list1;
        ListNode* cur2 = list2;
        while (cur1 != nullptr && cur2 != nullptr) {
            if (cur1->val < cur2->val) {
                vir->next = cur1;
                cur1 = cur1->next;
            }
            else {
                vir->next = cur2;
                cur2 = cur2->next;
            }
            vir = vir->next;
        }
        if (cur1 != nullptr) vir->next = cur1;
        if (cur2 != nullptr) vir->next = cur2;
        return res->next;
    }
};

/////////////思路2:暴力递归
////

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) {
            return l2;
        }
        else if (l2 == nullptr) {
            return l1;
        }
        else if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};

