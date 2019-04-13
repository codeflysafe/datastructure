# Stack
堆栈，也属于线性表，其操作为线性表操作的子集。即，它是一种受限的线性表，它只允许在自己的表尾进行插入和删除操作。在栈中，表尾被称为栈顶(`top`)，而表头称为栈底(`bottom`)。

假设栈 $a = (a_1,a_2,...,a_n)$，则称$a_n$为栈顶元素，而$a_1$为栈底元素。它是按照$a_1、a_2 ... a_n $的顺序入栈的，但是出栈的元素总是位于栈顶的元素。因此，它是一种先进后出(`last in first out` )的线性表(**LIFO**)。

结构示意图如下:

![](https://raw.githubusercontent.com/hsjfans/git_resource/master/20190411181235.png)

由于堆栈的操作是线性表的子集，可以采用链表或者数组等线性结构来模拟堆栈。

这里只是用链表来表示栈。顺序表的实现，只需要维护两个指针，栈顶(`top`)和栈底(`bottom`)，是线性表的操作子集，这里不再描述。

## Push
向堆栈内压入数据，新数据位于栈顶位置。

```c
void push(Element e, Stack *stack)
{
    StackNode *node = stack_node_new(e, stack->head);
    stack->head = node;
    stack->length++;
}

```


## Pop
删除栈顶的元素并返回该元素。

```c
Element pop(Stack *stack)
{
    if (is_empty(stack))
    {
        return NULL;
    }
    StackNode *node = stack->head;
    stack->head = node->next;
    stack->length--;
    Element e = node->e;
    free_node(node);
    return e;
}


```
此操作涉及节点回收
```c
void free_node(StackNode *node)
{
    if (node)
    {
        node->e = NULL;
        node->next = NULL;
        free(node);
    }
}
```


## Applications
由于堆栈后进先出的特性，因此有很多经典的应用场景。

### 数值转换
[leetcode](https://leetcode-cn.com/problems/convert-a-number-to-hexadecimal/)
十进制与其它进制的转换。
其计算过程如下

```
N = (N div d)x d + N mod d
```
以 1024 由`10进制`转`8进制`为例。

| value | div | mod |
| ----- | --- | --- |
| 1024  | 128 | 0   |
| 128   | 16  | 0   |
| 16    | 2   | 0   |
| 2     | 0   | 2   |

因此获取`8进制`表示为 `0x2000`

观察其计算过程，需要将其计算的最终结构反转。因此，使用堆栈来存储结构，然后在弹出即可。


```c

void conversion(int N, int d)
{
    Stack *stack = stack_new();
    while (N)
    {
        int temp = N % d;
        push(&temp, stack);
        N = N / d;
    }
    while (!is_empty(stack))
    {
        Element e = pop(stack);
        printf("%d", *(int *)e);
    }
}
```
### 括号匹配的检验
[leetcode](https://leetcode-cn.com/explore/learn/card/queue-stack/218/stack-last-in-first-out-data-structure/878/)
检测括号的合法性，所谓合法即:括号在正确的位置上成对出现。例如:

+ `(((())))` ==> 合法的
+ `()(()))(` ==> 不合法

```c++
bool isValid(string s) {
//        map<char,char> brackets= {
//                {'}','{'},
//                {']','['},
//                {')','['},
//        };
        stack<char> stack1 ;
        for(int i=0;i<s.size();i++){
            char temp = s[i];
            if (temp=='{' || temp=='[' || temp=='('){
                stack1.push(temp);
            }else {
                if (stack1.empty()) return false;
                if (temp == '}' && stack1.top() != '{') return false;
                if (temp == ')' && stack1.top() != '(') return false;
                if (temp == ']' && stack1.top() != '[') return false;
                stack1.pop();
            }
        }
        return  stack1.empty();

    }

```

### 迷宫求解

迷宫问题，即从入口到出口是一个经典的程序设计问题。当采取`穷举法`去求解时，需要采用沿着某一个方向向前探索，若能走通，则继续前进，否则回退到上个节点。因此，需要有一个数据结构来存储这种行走的路径，此时栈是一个很好的选择。

![](https://raw.githubusercontent.com/hsjfans/git_resource/master/20190412174818.png)

详细请见 [迷宫问题](./maze_problem.md)

### 表达式求值

表达式求值，是编译原理之中最基本的一个问题。它的实现是栈的典型应用之一。

假设四种运算操作`x,/,+,-`

首先明确其运算表达式的计算顺序
1. 先乘除，后加减

因此两个运算符的运算优先级之间只有三种关系
1. `A` 高于 `B`
2. `A` 等于 `B`
3. `A` 低于 `B`
 
这里采用两个栈来存储，一个存储运算符`OPTR`，另外一个存储待运算的数值记作`OPND`。 


