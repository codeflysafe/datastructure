# skip list and redis


[跳表](./skip_list.md) 和 [redis](https://github.com/hsjfans/redis)


## Redis

![](https://redis.io/images/redis-white.png)

redis 是比较流行的基于内存的存储，它主要是用于 数据库，缓存以及消息队列等。

redis 的有序集合是采用 跳跃表来实现的。

```c
/* ZSETs use a specialized version of Skiplists */
typedef struct zskiplistNode {
    robj *obj;
    double score; // 
    struct zskiplistNode *backward;
    struct zskiplistLevel {
        struct zskiplistNode *forward;
        unsigned int span;
    } level[];
} zskiplistNode;

typedef struct zskiplist {
    struct zskiplistNode *header, *tail;
    unsigned long length;
    int level;
} zskiplist;

typedef struct zset {
    // 字典
    dict *dict;
    // 跳跃表
    zskiplist *zsl;
} zset;

```

![](https://redisbook.readthedocs.io/en/latest/_images/graphviz-66d218f87c15bc835d88c696af175d2ba39ae420.svg)


通过使用字典结构， 并将 member 作为键， score 作为值， 有序集可以在 O(1) 复杂度内：

- 检查给定 member 是否存在于有序集（被很多底层函数使用）；
- 取出 member 对应的 score 值（实现 ZSCORE 命令）。
  
另一方面， 通过使用跳跃表， 可以让有序集支持以下两种操作：

- 在 O(logN) 期望时间、 O(N) 最坏时间内根据 score 对 member 进行定位（被很多底层函数使用）；
- 范围性查找和处理操作，这是（高效地）实现 ZRANGE 、 ZRANK 和 ZINTERSTORE 等命令的关键。
- 
通过同时使用字典和跳跃表， 有序集可以高效地实现按成员查找和按顺序查找两种操作。

