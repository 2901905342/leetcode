//给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
//
//你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。





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
    ListNode* swapPairs(ListNode* head) {

        ListNode* vir = new ListNode();
        vir->next = head;  //设置一个虚拟头节点
        ListNode* cur = vir;//cur位于虚拟头节点
        while (cur->next != nullptr && cur->next->next != nullptr) {//保证cur后至少有两个非空节点可以交换
            ListNode* temp1 = cur->next;  //临时保存cur后一个结点
            ListNode* temp2 = cur->next->next;  //临时保存cur后第二个节点
            cur->next = temp1;         //步骤1
            temp1->next = temp2->next;  //步骤2
            temp2->next = temp1;      //步骤3
            cur = cur->next;         //cur移动两位，准备下一轮交换
        }
        return head;
    }
};