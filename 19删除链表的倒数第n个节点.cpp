//给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。



//////////思路///////////////////////////////
//双指针的经典应用，如果要删除倒数第n个节点，让fast移动n步，然后让fast和slow同时移动，
//直到fast指向链表末尾。删掉slow所指向的节点就可以了。
//定义fast指针和slow指针，初始值为虚拟头结点
//fast首先走n + 1步 ，为什么是n+1呢，因为只有这样同时移动的时候slow才能指向删除节点的上一个节点（方便做删除操作）
//删除slow指向的下一个节点



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
            fast = fast->next;  //fast向后移动n位
            n--;
        }
        fast = fast->next; //fast再提前走一步，因为需要让slow指向删除节点的上一个节点
        while (fast != nullptr) {
            fast = fast->next;
            low = low->next;   //移动low到倒数(n+1)位
        }
        ListNode* temp = low->next;
        low->next = low->next->next;
        delete temp;   //释放该节点空间
        return vir->next; //注意此处只能用vir->next  不能使用head，当删除节点就是第一个节点时，由于该节点已经被释放，使用head会直接报错
                         //就算没有用delete temp; 由于head是头节点，low此时为head的前一个节点即vir
                        //故low->next = low->next->next;等同于  vir->next = vir->next->next,只是将虚拟头节点指向第二个节点，head仍是头节点，返回head时头节点并没有被删除
                        //因此，只能使用vir->next  ！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
    }
};