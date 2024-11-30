#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define SIZE 7

bool grid[SIZE][SIZE];
std::string path;
//??????R??????U??????????????????????????LD????D?
ll ans;

bool checkCell(int i, int j)
{
    return i >= 0 && i < SIZE && j >= 0 && j < SIZE && !grid[i][j];
}

void fillGrid()
{
    for(int i = 0; i < SIZE; ++i)
        for(int j = 0; j < SIZE; ++j)
            grid[i][j] = false;
}

void dfs(int i, int j, int depth)
{
    //std::cout << i << " " << j << " " << depth << std::endl;

    if(i == SIZE-1 && j==0)
    {
        if(depth == 48)
            ++ans;
        return;
    }

    grid[i][j] = true;

    if(path[depth] == 'L' || path[depth] == '?')
    {
        if(checkCell(i,j-1) && !(!checkCell(i,j-2) && checkCell(i-1,j-1) && checkCell(i+1,j-1)))
            dfs(i,j-1,depth+1);
    }
    if(path[depth] == 'R' || path[depth] == '?')
    {
        if(checkCell(i,j+1) && !(!checkCell(i,j+2) && checkCell(i-1,j+1) && checkCell(i+1,j+1)))
            dfs(i,j+1,depth+1);
    }
    if(path[depth] == 'U' || path[depth] == '?')
    {
        if(checkCell(i-1,j) && !(!checkCell(i-2,j) && checkCell(i-1,j-1) && checkCell(i-1,j+1)))
            dfs(i-1,j,depth+1);
    }
    if(path[depth] == 'D' || path[depth] == '?')
    {
        if(checkCell(i+1,j) && !(!checkCell(i+2,j) && checkCell(i+1,j-1) && checkCell(i+1,j+1)))
            dfs(i+1,j,depth+1);
    }
    grid[i][j] = false;
}

int main()
{
    //path = "??????R??????U??????????????????????????LD????D?";
    std::cin >> path;
    fillGrid();
    dfs(0,0,0);
    std::cout << ans << std::endl;
    return 0;
}

