#include <iostream>
#include <cstring>
using namespace std;

void zero(int a[][4],int m,int n)
{
    bool row[m],col[n];
    memset(row,false,sizeof(row));
    memset(col,false,sizeof(col));

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i][j] == 0)
            {
                row[i] = true;
                col[j] = true;
            }
        }
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
             if(row[i]||col[j])
             {
                 a[i][j] = 0;
             }
        }
    }
}

int main()
{
    int array[][4]=
    {
        {1,2,6,4},
        {2,3,0,8},
        {3,4,6,9}
    };

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            cout<<array[i][j]<<" ";
        }
        cout<<endl;
    }

    zero(array,3,4);

    cout<<endl;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            cout<<array[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

