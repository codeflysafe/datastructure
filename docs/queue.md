# Queue

与[栈](./stack.md) 相反，队列是一种(`FIFO`)的线性表，它允许在一端插入数据，另一端删除数据。总体类似于日常的排队机制。

队尾插入(`rear`),队头删除(`front`).假如存在一个队列
`q=(a_1,a_2,...,a_n)`，则`a_1`是队头元素，`a_n`是队尾元素，则出队过程为 `a_1,a_2,...,a_n` 的顺序
 
 ![](https://raw.githubusercontent.com/hsjfans/git_resource/master/20190416092630.png)

队列典型的应用，如操作系统的调度等

## 实现方式

它的实现方式分为两种，链表实现的队列(链队列)以及顺序表实现的队列(循环队列)。

### 链队列

队列的链表实现，其指针域需要两个指针`头指针`和`尾指针`。它维护一个`哑节点`，初始化时，头和尾指针都指向该节点。

![](https://raw.githubusercontent.com/hsjfans/git_resource/master/20190417105831.png)

#### 入队
入队有两种情况:
1. 队列为空
2. 队列不为空

##### 队列为空
此时，操作头指针，将其的后继节点指向新建节点，同时将尾指针指向新建节点。
![](https://raw.githubusercontent.com/hsjfans/git_resource/master/20190417110026.png)

##### 队列不为空
操作`rear`节点，将其的后继节点指向新节点，同时将其指向重置为新节点.
![](https://raw.githubusercontent.com/hsjfans/git_resource/master/20190417110208.png)

#### 出队
出队，即删除头节点元素。操作头节点，将其后继节点删掉

##### 队列元素大于1个
此时只需要按照单链表的删除流程，并将哑节点指向被删除节点的后继节点即可。
![](https://raw.githubusercontent.com/hsjfans/git_resource/master/20190417110658.png)

##### 队列元素为1个
此时，队列元素大于1个的出队不同时，最后将尾节点指向哑节点

![](https://raw.githubusercontent.com/hsjfans/git_resource/master/20190417111047.png)

#### 示意图

![](https://raw.githubusercontent.com/hsjfans/git_resource/master/20190417111201.png)


## 循环队列
循环队列，队列的顺序结构实现。此时使用两个指针`rear` 和 `front` 来只是尾节点和头节点的位置。`rear` 总是指向队列尾元素的下一个位置，而`front` 指向队列头元素。初始化时，```rear=front=0``` 。因此入队操作时，`rear`向后"+1",出队操作`front`也向后"+1"。

![](https://raw.githubusercontent.com/hsjfans/git_resource/master/20190417111837.png)

### 如何判断循环队列是否已满?
循环队列的核心问题是如何判断当前队列是否已满？

#### `rear == front `来判断
因为`rear` 总是指向尾元素的下一个位置，因此 存在`rear==front` 时，队列已满的情况。 

![](https://raw.githubusercontent.com/hsjfans/git_resource/master/20190417112402.png)

而初始化时，`front==rear`，因此无法简单通过这一条件来判断队列是否已满。

解决方法有很多种:
1. 使用一个标识位来区分队列是否已满的状态,如维护当前元素的数量`size`。
2. 舍弃一个节点的存储空间，将其尾元素的下一个位置，作为队列已满的标识位。
3. ...

这里假设采用第二种方法。
则队列是否已满以及队列当前数量的求法，就可以简单通过运算求得。

##### 队列是否已满
```c
boolean is_full(CircleQueue *queue)
{
    return (queue->rear + 1) % queue->capacity == queue->front ? 1 : 0;
}

```

##### 队列当前长度
```c
int len(CircleQueue *queue)
{
    return (queue->rear - queue->front + queue->capacity) % queue->capacity;
}
```

##### Tips
如果采用第一种方法，也很简单，只需要维护好这个`size`,在对应入队和出队操作时，来动态修改其数值即可。


### 入队和出队操作
知道如何确定循环队列的长度和判断是否已满之后，其入队和出队操作就很简单了。
入队即在其尾部增加元素，出队即删除当前头节点,此处不再想讲。


## Implements

[queue](../src/queue.c)
