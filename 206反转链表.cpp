//���㵥�����ͷ�ڵ� head �����㷴ת���������ط�ת�������


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
            temp = cur->next;//��¼cur����һ���ڵ�
            cur->next = pre;
            pre = cur;
            cur = temp;  //cur��ԭ���������һ���ڵ�
        }
        //�������curΪnullptr,pre����ԭ��������һ���ڵ�
        return pre;

    }
};