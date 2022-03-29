//给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。
//如果两个链表没有交点，返回 null 。


//简单来说，就是求两个链表交点节点的指针。 
//这里同学们要注意，交点不是数值相等，而是指针相等。
//看如下两个链表，目前curA指向链表A的头结点，curB指向链表B的头结点：

//两个链表的长度，并求出两个链表长度的差值，
//然后让curA移动到，使得curA末尾和curB 末尾对齐的位置
//此时我们就可以比较curA和curB是否相同，
//如果不相同，同时向后移动curA和curB，如果遇到curA == curB，则找到交点
//否则循环退出返回空指针。




#include "myhead.h"

//Definition for singly-linked list.
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
  };
 
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* curA = headA;
        ListNode* curB = headB;
        int Alen = 0;
        int Blen = 0;
        while (curA != nullptr) {//求链表A的长度
            curA = curA->next;
            Alen++;
        }
        while (curB != nullptr) {//求链表B的长度
            curB = curB->next;
            Blen++;
        }
        curA = headA;
        curB = headB;
        //让curA为最长链表的头，lenA为其长度
        if (Blen > Alen) {
            swap(Alen, Blen);  //swap交换括号内的两个变量
            swap(curA, curB);
        }
        //
        int dif_len = Alen - Blen;//求长度差
        while (dif_len--) {
            curA = curA->next;  //让curA与curB在同一起点上（末尾位置对齐）
        }
        while (curA != nullptr) {
            if (curA == curB) return curA;  //遍历curA和curB，相同则直接返回
            curA = curA->next;
            curB = curB->next;
        }
        return nullptr;
    }
};