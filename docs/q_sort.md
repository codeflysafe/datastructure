# QuickSort
快排(`partition-exchange sort`)是一种高效的排序方式，它的平均时间复杂度为`O(nlogn)`，最坏时间复杂度为`O(n^2)`。但是稍微努力，就可以避免最坏的情况出现。
## How it works ? 

快排的思想属于`分治法`([Divide-and-conquer algorithm](https://en.wikipedia.org/wiki/Divide-and-conquer_algorithm))。它将一个大的序列划分为两个子序列:较小的和较大的。然后递归的对子序列排序。步骤如下:

1. 选取基准值:从数组中选取一个基准值 `pivot`
2. 分区:对数组重新排序,使基准左边的数据都小于(等于)基准值，其后面的数据都大于基准值。经过分区之后，此时基准在其合适的位置。
3. 递归排序字串: 对各个字串递归重复以上的过程。

观察以上步骤，有两步是关键
1. 选择基准(`pivot`)
2. 分区运算(`partition operation`)

![](https://raw.githubusercontent.com/hsjfans/git_resource/master/20190410154011.png)


### How to select an pivot from array ?

基准点的选择是很关键的,最坏的情况是选择了最小的数值作为基准点。这样，它的时间复杂度达到最大`O(N^2)`。


因此也就有有了很多种选择基准点的方式,最简的是 `取首或者尾元素`作为基准点。还有一些常见的如`median-of-three quicksort`算法,来定位基准点。


### Partition Array Process

这里选取最后一个元素作为基准点，来演示一下大概的排序过程:
 
![](https://raw.githubusercontent.com/hsjfans/git_resource/master/20190410172956.png)


当然实现的时候可以在进行优化，使用双指针来减少交换次数,如下,

![](https://raw.githubusercontent.com/hsjfans/git_resource/master/20190410180714.png)




## Time complexity

时间复杂度计算


## Array

```c
void q_sort(ArrayList *array, unsigned int left, unsigned int right, compare_func cmp)
{
    if (left >= right)
        return;

    // first select the mid one as the datum mark
    unsigned int mid = (left + right) / 2, startIndex = left;
    // swap
    Swap(array->elements[right], array->elements[mid]);
    for (unsigned int i = left; i < right; i++)
    {
        if (cmp(array->elements[i], array->elements[right]) < 0)
        {
            Swap(array->elements[startIndex++], array->elements[i]);
        }
    }

    // swap the
    Swap(array->elements[right], array->elements[startIndex]);
    // recursive subArray
    q_sort(array, left, startIndex - 1, cmp);
    q_sort(array, startIndex + 1, right, cmp);
}

void sort(ArrayList *array, compare_func cmp)
{
    q_sort(array, 0, array->length - 1, cmp);
}

```


## Linked


## Related
1. [merge sort](./merge_sort.md)
2. [heap sort](./heap_sort.md)
3. [Divide and Conquer](./divide_and_conquer.md)


## References
1. [QuickSort Wiki](https://en.wikipedia.org/wiki/Quicksort)
2. [QuickSort](https://medium.com/basecs/pivoting-to-understand-quicksort-part-1-75178dfb9313)


