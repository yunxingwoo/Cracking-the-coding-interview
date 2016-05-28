#include <iostream>
#include <string>

using namespace std;

void swap(int &a,int &b)
{
    int t = a;
    a = b;
    b = t;
}

void transpose1(int s[][4],int n)
{
    for(int i = 0;i<n;i++)
    {
        for(int j = i+1;j<n;j++)
        {
          swap(s[i][j],s[j][i]);
        }
    }

    for(int i=0;i<n/2;i++)
    {
        for(int j=0;j<n;j++)
        {
            swap(s[i][j],s[n-i-1][j]);
        }
    }
}

void transpose2(int s[][5],int n)
{

    for(int i = 0;i<n;i++)
    {
        for(int j = i+1;j<n;j++)
        {
          swap(s[i][j],s[j][i]);
        }
    }

    for(int i=0;i<n/2;i++)
    {
        for(int j=0;j<n;j++)
        {
            swap(s[i][j],s[n-i-1][j]);
        }
    }
}
int main()
{
    int a[4][4]=
    {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12},
            {13, 14, 15, 16}
    };

    int b[5][5] =
    {
            {1,2,3,4,5},
            {6,7,8,9,10},
            {11,12,13,14,15},
            {16,17,18,19,20},
            {21,22,23,24,25}
    };
//-----------------------------------
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    transpose1(a,4);
    cout<<endl;
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
//------------------------------------
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
            cout<<b[i][j]<<" ";
        cout<<endl;
    }
    transpose2(b,5);
    cout<<endl;
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
            cout<<b[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}
