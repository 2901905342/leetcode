//����һ���������������������ڵĽڵ㣬�����ؽ����������
//
//�㲻��ֻ�ǵ����ĸı�ڵ��ڲ���ֵ��������Ҫʵ�ʵĽ��нڵ㽻����





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
        vir->next = head;  //����һ������ͷ�ڵ�
        ListNode* cur = vir;//curλ������ͷ�ڵ�
        while (cur->next != nullptr && cur->next->next != nullptr) {//��֤cur�������������ǿսڵ���Խ���
            ListNode* temp1 = cur->next;  //��ʱ����cur��һ�����
            ListNode* temp2 = cur->next->next;  //��ʱ����cur��ڶ����ڵ�
            cur->next = temp1;         //����1
            temp1->next = temp2->next;  //����2
            temp2->next = temp1;      //����3
            cur = cur->next;         //cur�ƶ���λ��׼����һ�ֽ���
        }
        return head;
    }
};