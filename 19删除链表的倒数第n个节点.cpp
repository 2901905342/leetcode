//����һ������ɾ������ĵ����� n ����㣬���ҷ��������ͷ��㡣



//////////˼·///////////////////////////////
//˫ָ��ľ���Ӧ�ã����Ҫɾ��������n���ڵ㣬��fast�ƶ�n����Ȼ����fast��slowͬʱ�ƶ���
//ֱ��fastָ������ĩβ��ɾ��slow��ָ��Ľڵ�Ϳ����ˡ�
//����fastָ���slowָ�룬��ʼֵΪ����ͷ���
//fast������n + 1�� ��Ϊʲô��n+1�أ���Ϊֻ������ͬʱ�ƶ���ʱ��slow����ָ��ɾ���ڵ����һ���ڵ㣨������ɾ��������
//ɾ��slowָ�����һ���ڵ�



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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* vir = new ListNode();
        vir->next = head;
        ListNode* fast = vir;
        ListNode* low = vir;
        while (n > 0 && fast != nullptr) {
            fast = fast->next;  //fast����ƶ�nλ
            n--;
        }
        fast = fast->next; //fast����ǰ��һ������Ϊ��Ҫ��slowָ��ɾ���ڵ����һ���ڵ�
        while (fast != nullptr) {
            fast = fast->next;
            low = low->next;   //�ƶ�low������(n+1)λ
        }
        ListNode* temp = low->next;
        low->next = low->next->next;
        delete temp;   //�ͷŸýڵ�ռ�
        return vir->next; //ע��˴�ֻ����vir->next  ����ʹ��head����ɾ���ڵ���ǵ�һ���ڵ�ʱ�����ڸýڵ��Ѿ����ͷţ�ʹ��head��ֱ�ӱ���
                         //����û����delete temp; ����head��ͷ�ڵ㣬low��ʱΪhead��ǰһ���ڵ㼴vir
                        //��low->next = low->next->next;��ͬ��  vir->next = vir->next->next,ֻ�ǽ�����ͷ�ڵ�ָ��ڶ����ڵ㣬head����ͷ�ڵ㣬����headʱͷ�ڵ㲢û�б�ɾ��
                        //��ˣ�ֻ��ʹ��vir->next  ������������������������������������������������������������������
    }
};