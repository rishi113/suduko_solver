#include<iostream>
using namespace std;
void printgrid(int grid[9][9])
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            cout<<grid[i][j]<<" ";
            if(j==2||j==5||j==8)
            cout<<"# ";
        }
        cout<<endl;
         if(i==2||i==5||i==8)
         {
             for(int i=0;i<12;i++)
             cout<<"# ";
             cout<<endl;
         }
    }
}
bool is_safe(int grid[9][9],int val,int row,int col,int boxr,int boxc)
{
    if(grid[row][col]==0)
    {
        for(int i=0;i<9;i++)
        {
            if(grid[row][i]==val)
            return false;
        }
        for(int j=0;j<9;j++)
        {
            if(grid[j][col]==val)
            return false;
        }
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(grid[i+boxr][j+boxc]==val)
                return false;
            }
        }
        return true;
    }
    else
    return false;
}
bool available(int grid[9][9],int& i,int& j)
{
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            if(grid[i][j]==0)
            return true;
        }
    }
    return false;
}
bool solver(int grid[9][9])
{
    int i,j;
    if(!available(grid,i,j))
    return true;
        for(int num=1;num<=9;num++)
        {
            if(is_safe(grid,num,i,j,i-(i%3),j-(j%3)))
            {
                grid[i][j]=num;
                if(solver(grid))
                return true;
                grid[i][j]=0;
            }
        }
return false;
}
int main()
{
    int grid[9][9]={ {2, 0, 0, 9, 0, 0, 0, 8, 1}, 
                     {3, 1, 0, 7, 0, 6, 9, 2, 0}, 
                     {0, 9, 5, 0, 0, 0, 6, 0, 0}, 
                     {0, 2, 0, 5, 0, 3, 0, 7, 9}, 
                     {0, 0, 0, 0, 7, 0, 0, 0, 0}, 
                     {9, 5, 0, 1, 0, 2, 0, 6, 0}, 
                     {0, 0, 2, 0, 0, 0, 7, 9, 0}, 
                     {0, 3, 1, 4, 0, 7, 0, 5, 8}, 
                     {7, 8, 0, 0, 0, 5, 0, 0, 4} };
    if (solver(grid) == true)
        printgrid(grid);
    else
        cout << "No solution exists";
    return 0;
}