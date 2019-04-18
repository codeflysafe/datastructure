# SkipList (跳表)
跳表是一种允许以`O(logn)`时间复杂度进行查询和插入的数据结构,它相比与`红黑树`或者`平衡树`来说实现更加简单。

## 引出
假设一个[单链表](./linked_list.md)结构，即使是有序的，要查询某个元素时，也只能进行遍历查询，即时间复杂度为`O(n)`(即使，采用[双向链表](./double_linked_list.md),其时间复杂度也是`O(N)`)。

![](https://raw.githubusercontent.com/hsjfans/git_resource/master/20190418115602.png)

因此如何提高链表的检索效率？

### 双层链表

![](https://raw.githubusercontent.com/hsjfans/git_resource/master/20190418115638.png)


// todo 以后争取更换成 `ipad` 画图。


### 多层链表

依次类推，当层高为`K`时，在合适的散列情况下，最坏时间复杂度是
`O(k*(n)^(1/n))`

特殊情况，当 `k=logN` 时,时间复杂度为:

```
T=logN*(n^(1/logN)) =  logN*(2^(1/logN*logN)) = logN
```


## 查询

跳表如何进行查询?
![](https://raw.githubusercontent.com/hsjfans/git_resource/master/20190418121429.png)

如上图，想要查询出`47`这个元素所在的节点，其查询路线如曲线所示。

查询过程如下:

> 从某一层链表某个的元素向后遍历，若刚好存在一个节点的值等于`A`，则返回该节点，查询完成。否则，取最后一个值小于`A`的节点`C`，如果`C`已处于底层，则返回空，查询结束(此时未查询到)。若`C`还有更低层，向下一层遍历重复该步骤。


代码实现如下:
```c

```







## Related

1. [avl_tree](./avl_tree.md)
2. [red_blank_tree](./red_blank_tree.md)



## References

1. [skip list wiki](https://en.wikipedia.org/wiki/Skip_list)
2. [mit skip list](https://www.youtube.com/watch?v=2g9OSRKJuzM&list=PLUl4u3cNGP6317WaSNfmCvGym2ucw3oGp&index=11)
