# data_structure 

![](https://raw.githubusercontent.com/hsjfans/git_resource/master/20190526132608.png)

> [English](./readme.md) [简体中文](./readme_zh.md)

## 关于英文以及一些复杂数据结构的实现

最近评估了工作量，发现英文文档以及一些复杂数据结构的实现不是几个月能够完成的事情。
因此决定按照以下方式进行:

1. 先骨骼，再经络: 即先将数据结构的雏形搭建出来，后面在进行一遍测试加完善
2. 兼测试，兼英文: 因为第一遍，主要是概念的理解以及基础结构的搭建，因此英文文档和测试放到第二遍进行完善。
3. 坚守 PDCA 计划，争取打造出高质量的开源项目
4. 由于最近计划考研，所以一些完善估计要放到年末开始，在此之前以广而理解为主

## `leetcode` 相关
> 在部分文档中，会涉及到 `leetcode` 的一些题目，它的一些实现请看 
> [leetcode](https://github.com/hsjfans/leetcode)
> [online judge](https://github.com/hsjfans/Online-Judge#Leetcode)

本仓库包含了基础的数据结构以及算法，每一种数据结构以及算法都有自己对应的`md`文档，以及参考链接

注意: 此项目代码**未在生产环境使用过**，仅用于学习和交流。同时代码还未进行测试！

## 整体

![](https://raw.githubusercontent.com/hsjfans/git_resource/master/20190518111146.png)

## 数据结构
> 数据结构是计算机体系的基础骨骼部分，是相互之间存在一种或者多种特定关系的数据元素的集合，当然又包含了对应的一些函数或者方法

### list 
- [x] [array_list](./docs/array_list.md)
- [x] [linked_list](./docs/linked_list.md)
- [x] [double_linked_list](./docs/double_linked_list.md)
- [x] [queue](./docs/queue.md)
- [x] [stack](./docs/stack.md)
- [x] [skip_list](./docs/skip_list.md)
- [ ] and other ...
 
### string
- [ ] [string](./docs/string.md)

### tree
- [x] [tree](./docs/tree.md)
- [x] [binary_tree](./docs/binary_tree.md)
- [x] [binary_search_tree](./docs/binary_search_tree.md)
- [x] [avl_tree](./docs/avl_tree.md)
- [x] [red_black_tree](./docs/red_black_tree.md)
- [x] [b_tree](./docs/b_tree.md)
- [x] [b_plus_tree](./docs/b_plus_tree.md)
- [ ] [segment_tree](./docs/segment_tree.md)
- [ ] [prefix_tree](./docs/prefix_tree.md)
- [ ]  and other ...
  
### map
- [x] [hash_table](./docs/hash_table.md) tree_map;hash_table 

### heap
- [x] [heap](./docs/heap.md) 
- [ ] [d-heap](./dosc/d_heap.md)


### set
- [x] [set](./docs/set.md) tree_set;...
- [ ] [disjoint_set](./docs/disjoint_set.md)


### graph
- [ ] [graph](./docs/graph.md)


## 算法

### sorting

- [ ] [bubble_sort](./docs/bubble_sort.md)
- [ ] [quick_sort](./docs/quick_sort.md)
  


## Testing

- [ ] [array_list](./test/array_list_test.c) 
- [ ] [linked_list](./test/linked_list_test.c)
- [ ] [double_linked_list](./test/double_linked_list.c)
- [ ] [queue](./test/queue.c)
- [ ] [stack](./test/stack.c)
- [ ] [skip_list](./test/skip_list.c)
- [ ] and other ...


## Reference

本仓库的概念以及相关代码，大部分参考 <<算法导论>> 以及 <<数据结构与算法分析>>, 
还有一些参考 论文或者 博客等
