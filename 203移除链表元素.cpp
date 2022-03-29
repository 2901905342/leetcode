//����һ�������ͷ�ڵ� head ��һ������ val ������ɾ���������������� Node.val == val �Ľڵ㣬������ �µ�ͷ�ڵ� ��



#include "myhead.h"
  //Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 

 // ����д���������������ݽṹ
  class Solution {
  public:
      ListNode* removeElements(ListNode* head, int val) {
          ListNode* vir = new ListNode(0);//����һ������ͷ�ڵ㣨��ΪʲôҪ�ڶ����أ���
          vir->next = head;  //������ͷ�ڵ�ָ��head,���������ɾ������
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

//�ⷨ��  �ݹ�д��

  //���ڸ������������ȶԳ���ͷ�ڵ� head ����Ľڵ����ɾ��������
  //Ȼ���ж� head �Ľڵ�ֵ�Ƿ���ڸ�����val
  //��� head �Ľڵ�ֵ���� val���� head ��Ҫ��ɾ�������ɾ���������ͷ�ڵ�Ϊ
  //head.next����� head �Ľڵ�ֵ������ val���� head ������
  //���ɾ���������ͷ�ڵ㻹��head��


  class Solution {  //û���ͷ��ڴ�ռ䣬������
  public:
      ListNode* removeElements(ListNode* head, int val) {
          if (head == nullptr) {
              return head;
          }
          head->next = removeElements(head->next, val);
          return head->val == val ? head->next : head;
      }
  };

 