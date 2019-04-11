# CircularLinkedList

循环链表，它是链表存储的一种形式，其特点为:
其尾节点的后继节点指向头节点，形成一个环，这样从每个节点出发都能访问所有节点。
它可以采用是单链表也可以是双链表，这里只讨论单链表的情况。

循环链表的操作基本与链表一致，只是在遍历时的结束条件更改为后继节点是否为`头指针`。


```c
 while (node)
    {
        LinkedNode *tmp = node->next;
        node->next = first;
        first->next = tmp;
        root->next = node;
        first = node;
        node = tmp;
    }

    // change to 
while (node!=head)
    {
        LinkedNode *tmp = node->next;
        node->next = first;
        first->next = tmp;
        root->next = node;
        first = node;
        node = tmp;
    }

```

