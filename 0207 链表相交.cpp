//���������������ͷ�ڵ� headA �� headB �������ҳ������������������ཻ����ʼ�ڵ㡣
//�����������û�н��㣬���� null ��


//����˵������������������ڵ��ָ�롣 
//����ͬѧ��Ҫע�⣬���㲻����ֵ��ȣ�����ָ����ȡ�
//��������������ĿǰcurAָ������A��ͷ��㣬curBָ������B��ͷ��㣺

//��������ĳ��ȣ���������������ȵĲ�ֵ��
//Ȼ����curA�ƶ�����ʹ��curAĩβ��curB ĩβ�����λ��
//��ʱ���ǾͿ��ԱȽ�curA��curB�Ƿ���ͬ��
//�������ͬ��ͬʱ����ƶ�curA��curB���������curA == curB�����ҵ�����
//����ѭ���˳����ؿ�ָ�롣




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
        while (curA != nullptr) {//������A�ĳ���
            curA = curA->next;
            Alen++;
        }
        while (curB != nullptr) {//������B�ĳ���
            curB = curB->next;
            Blen++;
        }
        curA = headA;
        curB = headB;
        //��curAΪ������ͷ��lenAΪ�䳤��
        if (Blen > Alen) {
            swap(Alen, Blen);  //swap���������ڵ���������
            swap(curA, curB);
        }
        //
        int dif_len = Alen - Blen;//�󳤶Ȳ�
        while (dif_len--) {
            curA = curA->next;  //��curA��curB��ͬһ����ϣ�ĩβλ�ö��룩
        }
        while (curA != nullptr) {
            if (curA == curB) return curA;  //����curA��curB����ͬ��ֱ�ӷ���
            curA = curA->next;
            curB = curB->next;
        }
        return nullptr;
    }
};