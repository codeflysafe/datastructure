# SkipList (跳表)
跳表是一种允许以`O(logn)`时间复杂度进行查询和插入的数据结构,它相比与`红黑树`或者`平衡树`来说实现更加简单。

## 引出
假设一个[单链表](./linked_list.md)结构，即使是有序的，要查询某个元素时，也只能进行遍历查询，即时间复杂度为`O(n)`(即使，采用双向链表,其时间复杂度也是`O(N)`)。因此如何提高链表的检索效率，



## Related

1. [avl_tree](./avl_tree.md)
2. [red_blank_tree](./red_blank_tree.md)


## References

1. [skip list wiki](https://en.wikipedia.org/wiki/Skip_list)
2. [mit skip list](https://www.youtube.com/watch?v=2g9OSRKJuzM&list=PLUl4u3cNGP6317WaSNfmCvGym2ucw3oGp&index=11)
