# LinkedList Concept
> [ArrayList](./array_list.md)的特点是顺序存储，导致其移动和删除需要大量的复制开销。因此出现了另外一种，非连续存储的结构，链表。它拥有高效的插入和删除，但是失去了高效访问的优点。


它的一些特点：
+ 动态扩容: 因为它是不连续存储的，它不需要预先分配好一定的长度作为容器。理论上，内存足够的话，它可以无效拓展。
+ 非并发安全: 非线程安全的容器


## Linked Node
链表是一组节点构成的序列，节点之间通过指针相连。每一个节点，都包含: `数据`(该节点要存储的数据) 和 `指针`(指向其它节点)。(即数据域与指针域)
它的基本结构如下:

![](https://raw.githubusercontent.com/hsjfans/git_resource/master/20190409172002.png)

它包含一个头指针，它是一个`哑节点`,作用是为了方便操作使用。
各个节点的位置可以是离散的，最后一个节点指向一个"空"(**NULL**)。


## Classify
除了一些简单的单链表，还有一些变种线性结构，如:

+ [DoubleLinkedList](./double_linked_list.md)
+ [CircleLinkedList](./circle_linked_list)
+ ...



## Applications

1. 由于它高效删除和插入的特点，且无需提前分配空间等优点，因此它是实现一些其它线性结构的基础。一些常见应用:
   - [Queue](./queue.md)
   - [Stack](./stack.md)






## References
1. [LinkedList Wiki](https://en.wikipedia.org/wiki/Linked_list)

