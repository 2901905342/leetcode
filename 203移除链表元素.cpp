//给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。



#include "myhead.h"
  //Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 

 // 迭代写法，理解链表的数据结构
  class Solution {
  public:
      ListNode* removeElements(ListNode* head, int val) {
          ListNode* vir = new ListNode(0);//设置一个虚拟头节点（但为什么要在堆区呢？）
          vir->next = head;  //将虚拟头节点指向head,方便后面做删除操作
          ListNode* cur = vir;
          while (cur->next != nullptr) {
              if (cur->next->val == val) {
                  ListNode* temp = cur->next;
                  cur->next = cur->next->next;
                  delete temp;
              }
              else  cur = cur->next;
          }
          head = vir->next;
          delete vir;
          return head;
      }
  };

//解法二  递归写法

  //对于给定的链表，首先对除了头节点 head 以外的节点进行删除操作，
  //然后判断 head 的节点值是否等于给定的val
  //如果 head 的节点值等于 val，则 head 需要被删除，因此删除操作后的头节点为
  //head.next；如果 head 的节点值不等于 val，则 head 保留，
  //因此删除操作后的头节点还是head。


  class Solution {  //没有释放内存空间，并不好
  public:
      ListNode* removeElements(ListNode* head, int val) {
          if (head == nullptr) {
              return head;
          }
          head->next = removeElements(head->next, val);
          return head->val == val ? head->next : head;
      }
  };

 