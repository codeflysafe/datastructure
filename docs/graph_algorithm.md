# Problems of graph


## 1.[1021 Deepest Root (25分)](https://pintia.cn/problem-sets/994805342720868352/problems/994805482919673856)

采用 bfs 遍历来求解最大深度,同时判断图是否有环等问题


```c++

#include<iostream>
#include<queue>
using namespace std;

void pat_1021()
{
    int i, n;
    cin >> n;
    int maps[n + 1][n + 1];
    // 0 代表为无路径，1代表有通路
    // 采用邻接矩阵法（无向图）
    fill(maps[0], maps[0] + (n + 1) * (n + 1), 0);
    int x, y;
    int depths[n + 1], visits[n + 1], wholes[n + 1];
    int nums[n + 1];
    // 该节点是否访问过，可能存在单独的节点
    fill(wholes, wholes + n + 1, 0);
    for (i = 0; i < n - 1; i++)
    {
        cin >> x >> y;
        // 无向图
        maps[x][y] = 1;
        maps[y][x] = 1;
    }
    int j, k = 0, max = 0;
    // 是否存在环
    bool circle = false;
    for (j = 1; j <= n; j++)
    {
        if (wholes[j] == 0)
            k++;
        // 每个节点访问已经访问过的节点的数量
        // 一般是1，超过1的便存在环，此时便构不成一棵树
        fill(nums, nums + n + 1, 0);
        // 该节点是否访问过，可能存在单独的节点
        fill(visits, visits + n + 1, 0);
        int size, t;
        queue<int> q;
        q.push(j);
        depths[j] = 0;
        visits[j]++;
        while (!q.empty())
        {
            size = q.size();
            depths[j]++;
            for (int k = 0; k < size; k++)
            {
                t = q.front();
                q.pop();
                for (i = 1; i <= n; i++)
                {
                    if (i != t && maps[t][i] == 1)
                    {
                        // 未访问过
                        if (visits[i] == 0)
                        {
                            visits[i]++;
                            wholes[i]++;
                            q.push(i);
                        }
                        // 该节点已经访问过多少次已经访问过的节点
                        else
                            nums[t]++;
                        // 此处有环
                        if (nums[t] > 1)
                            circle = true;
                    }
                }
            }
        }
        // printf(" %d %d\n",j,depths[j]);
        if (max < depths[j])
            max = depths[j];
    }

    // 无环且未连接图
    if (k > 1 || circle)
        printf("Error: %d components\n", k);
    else
    {
        for (i = 1; i <= n; i++)
        {
            if (depths[i] == max)
                cout << i << endl;
        }
    }
}

int main()
{
    pat_1021();
    return 0;
}


```