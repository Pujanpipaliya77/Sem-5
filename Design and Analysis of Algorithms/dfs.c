#include <stdio.h>




int dfshelper(int v[7][7], int visited[], int key)
{
    int i, j = 0;
    
    if (visited[key] == 1)
    {
        return 0;
    }
    printf("%d ", key+1);
    visited[key] = 1;
    for (i = 0; i < 7; i++)
    {
        if (v[key][i] == 1 && visited[i] == 0)
        {
            dfshelper(v, visited, i);
                

        }
    }
    return 1;
}

int dfs(int v[7][7]){
    int visited[7] = {0};
    dfshelper(v, visited, 0);
}

void main()
{
    int v[7][7] =
    {
        {0, 1, 0, 1, 0, 0, 0},
        {1, 0, 1, 1, 1, 0, 0},
        {0, 1, 0, 0, 1, 0, 0},
        {1, 1, 0, 0, 1, 1, 0},
        {0, 1, 1, 1, 0, 1, 1},
        {0, 0, 0, 1, 1, 0, 1},
        {0, 0, 0, 0, 1, 1, 0}
    };
    dfs(v);
}

