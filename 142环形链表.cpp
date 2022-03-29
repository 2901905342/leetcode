//给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
//如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 
//为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。
//如果 pos 是 - 1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。
//不允许修改 链表。


//这道题目，不仅考察对链表的操作，而且还需要一些数学运算。
//主要考察两知识点：
//判断链表是否环
//如果有环，如何找到这个环的入口

//方法一  快慢指针法
//可以使用快慢指针法， 分别定义 fast 和 slow指针，从头结点出发，fast指针每次移动两个节点，
//slow指针每次移动一个节点，如果 fast 和 slow指针在途中相遇 ，说明这个链表有环。
//  详见  https://programmercarl.com/0142.%E7%8E%AF%E5%BD%A2%E9%93%BE%E8%A1%A8II.html#_142-%E7%8E%AF%E5%BD%A2%E9%93%BE%E8%A1%A8ii

//  Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
  };

class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        if (head == nullptr) return nullptr;  // 如果是空表，直接返回nullptr
        ListNode* fast = head;
        ListNode* low = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            low = low->next;
            if (fast == low) break;  //当快慢指针相遇时，跳出循环
        }
        if (fast != low || fast->next == nullptr) return nullptr;//当fast与low没有相遇或者 fast与low压根没走动（即链表只有一个非成环节点）返回nullptr
        ListNode* index1 = head; 
        ListNode* index2 = low;
        int i = 0;
        while (index1 != index2) {
            index1 = index1->next;
            index2 = index2->next;
            i++;
        }
        return index1; //index1与index2相遇的点即为环的入口。

    }
};





//方法2   hash表