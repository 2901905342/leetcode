//设计链表的实现。您可以选择使用单链表或双链表。单链表中的节点应该具有两个属性：val 和 next。
// val 是当前节点的值，next 是指向下一个节点的指针 / 引用。
// 如果要使用双向链表，则还需要一个属性 prev 以指示链表中的上一个节点。假设链表中的所有节点都是 0 - index 的。
//
//在链表类中实现这些功能：
//
//get(index)：获取链表中第 index 个节点的值。如果索引无效，则返回 - 1。
//addAtHead(val)：在链表的第一个元素之前添加一个值为 val 的节点。插入后，新节点将成为链表的第一个节点。
//addAtTail(val)：将值为 val 的节点追加到链表的最后一个元素。
//addAtIndex(index, val)：在链表中的第 index 个节点之前添加值为 val  的节点。如果 index 等于链表的长度，则该节点将附加到链表的末尾。
// 如果 index 大于链表长度，则不会插入节点。如果index小于0，则在头部插入节点。
//deleteAtIndex(index)：如果索引 index 有效，则删除链表中的第 index 个节点。


////////////////////////////////////解题思路/////////////////////////////////////////////////////////
// //对于添加和删除链表中的index节点都是定位index的前一个节点进行操作
//对于读取index节点的值，则直接定位到index节点
//用link_size变量来维护链表的长度

class MyLinkedList {
public:
    int link_size;  //记录链表的长度；
    struct ListNode {
        int val;
        ListNode* next;
        ListNode() :val(0), next(nullptr) {}
        ListNode(int x) :val(x), next(nullptr) {}
        ListNode(int x, ListNode* next) :val(x), next(next) {}
    };
    ListNode* vir;  //设置虚拟头节点
    MyLinkedList() {
        vir = new ListNode(0); //创建一个虚拟头节点
        link_size = 0; //此时链表长度为0
    }

    int get(int index) {
        if (index > link_size - 1 || index < 0) return -1;
        ListNode* cur = vir->next;  //cur现在为头节点
        int i = 0;
        while (i < index) {
            cur = cur->next;   //遍历到第index个节点
            i++;
        }
        return cur->val;  //返回第index节点的值
    }

    void addAtHead(int val) {
        ListNode* temp = new ListNode(val); //创建一个新的节点
        temp->next = vir->next; //temp指向原链表的头节点
        vir->next = temp;  //虚拟头节点指向temp
        link_size++;    //链表长度加一
    }

    void addAtTail(int val) {
        ListNode* tail = new ListNode(val);//创建一个新的节点
        ListNode* cur = vir;//cur位于虚拟头节点
        while (cur->next != nullptr) { //cur移动到链表的末尾
            cur = cur->next;
        }
        cur->next = tail;
        link_size++;//链表长度加一

    }

    void addAtIndex(int index, int val) {
        if (index > link_size)  return;
        ListNode* mid = new ListNode(val);//创建一个新的节点

        int i = 0;
        ListNode* cur = vir; //cur位于虚拟头节点
        while (i < index) {   //cur 遍历到index的前一个节点
            cur = cur->next;
            i++;
        }
        mid->next = cur->next;  //mid节点指向cur的下一节点
        cur->next = mid;    //cur 的下一节点指向mid
        link_size++; //链表的长度加一

    }

    void deleteAtIndex(int index) {
        if (index > link_size - 1 || index < 0)  return;
        ListNode* cur = vir;//cur指向虚拟头节点
        int i = 0;
        while (i < index) {  //遍历到index的前一个节点
            cur = cur->next;
            i++;
        }
        ListNode* temp = cur->next;  //temp为要删除的index节点

        cur->next = cur->next->next;  //cur指向index的后一个节点
        delete temp;   //删除temp节点
        link_size--; //链表的长度减一
    }
};
