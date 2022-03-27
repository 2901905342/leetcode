//存在一个按升序排列的链表，给你这个链表的头节点 head ，请你删除所有重复的元素，使每个元素只出现一次 。
//返回同样按升序排列的结果链表。


#include "myhead.h"
// * Definition for singly-linked list./
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur = head;  //可知头结点一定不会被删除，所以可以不使用虚拟头结点
        if (head == nullptr) return head;
        while (cur->next != nullptr) {
            if (cur->val == cur->next->val) {
                ListNode* temp = cur->next;
                cur->next = cur->next->next;
                delete temp;
            }
            else cur = cur->next;
        }
        return head;
    }
};