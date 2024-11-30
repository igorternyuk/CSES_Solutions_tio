#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define SIZE 8

char board[SIZE][SIZE];
ll ans = 0;

/*
    "........",
    "........",
    "..*.....",
    "........",
    "........",
    ".....**.",
    "...*....",
    "........"
*/
std::vector<std::string> testInput
{
    "........",
    "........",
    "..*.....",
    "........",
    "........",
    ".....**.",
    "...*....",
    "........"
};
void readBoard()
{
    std::string row;
    for(size_t i = 0; i < SIZE; ++i)
    {
        std::cin >> row;
        for(size_t j = 0; j < SIZE; ++j)
        {
            board[i][j] = /*testInput[i][j]*/row[j];
        }
    }
}

void printBoard()
{
    for(size_t i = 0; i < SIZE; ++i)
    {
        for(size_t j = 0; j < SIZE; ++j)
        {
            std::cout << board[i][j];
        }
        std::cout<<std::endl;
    }
    std::cout<< "----------\n";
}

bool checkBounds(int i, int j)
{
    return i >= 0 && i < SIZE && j >= 0 && j < SIZE;
}

bool canPlaceQueen(int ii, int jj)
{
    if(board[ii][jj] == '*')
        return false;
    //Check vertical
    for(int i = 0; i < SIZE; ++i)
        if(board[i][jj] == 'Q')
            return false;
    //Check horizontal
    for(int j = 0; j < SIZE; ++j)
        if(board[ii][j] == 'Q')
            return false;
    //Check diagonals
    for(int k = 0; k < SIZE; ++k)
    {
        int i = ii-k;
        int j = jj-k;
        if(checkBounds(i, j) && board[i][j] == 'Q')
            return false;
        i = ii+k;
        j = jj+k;
        if(checkBounds(i, j) && board[i][j] == 'Q')
            return false;

        i = ii-k;
        j = jj+k;
        if(checkBounds(i, j) && board[i][j] == 'Q')
            return false;
        i = ii+k;
        j = jj-k;
        if(checkBounds(i, j) && board[i][j] == 'Q')
            return false;
    }

    return true;
}

bool placeQueen(int j)
{
    bool res = false;
    for(int i = 0; i < SIZE; ++i)
    {
        if(canPlaceQueen(i,j))
        {
            board[i][j] = 'Q';
            if(j == SIZE - 1)
            {
                //printBoard();
                board[i][j] = '.';
                ++ans;
            }
            else
            {
                res = placeQueen(j+1);
                if(!res)
                {
                    board[i][j] = '.';
                }
            }
        }
    }

    return res;
}

int main()
{
    readBoard();
    placeQueen(0);
    std::cout << ans << std::endl;

    return 0;
}

