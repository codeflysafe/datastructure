# QuickSort

QuickSort is an efficient sorting algorithm,whose average time complexity is `O(nlogn)` and the worst time complexity is `O(n^2)`.When implemented well , it's easy to avoid the bad affair.

## How it works ?

QuickSort is [divided-and-conquer](https://en.wikipedia.org/wiki/Divide-and-conquer_algorithm) algorithm. It divides an unsorted array to two subArray: the less and the bigger , then recursive the subArray to repeat the previous steps. The detailed steps as following:

1. Select an pivot : an element called pivot, which is a somewhat arbitrary element in an array.
2. Partition array : reorder the unsorted array , so that the smaller element than pivot before it and the bigger element than pivot after it.
3. Recursive: recursive the subArray using above steps.

There are **two core steps** after observation:
1. Select an pivot.
2. Partition unsorted array.

## How to select an pivot from unsorted array ?
It's very import to choose an suitable pivot for q_sort. The worst case 
will appear when choosing the min pivot from array.



