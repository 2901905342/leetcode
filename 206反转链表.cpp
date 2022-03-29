//给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。


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
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head;
        ListNode* temp;
        ListNode* pre = nullptr;
        while (cur != nullptr) {
            temp = cur->next;//记录cur的下一个节点
            cur->next = pre;
            pre = cur;
            cur = temp;  //cur到原本链表的下一个节点
        }
        //遍历完后，cur为nullptr,pre到了原链表的最后一个节点
        return pre;

    }
};