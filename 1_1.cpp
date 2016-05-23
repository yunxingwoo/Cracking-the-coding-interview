#include <iostream>
#include <cstring>

using namespace std;

bool isUnique1(string s)
{
    bool a[256];
    memset(a,0,sizeof(a));
    int len = s.length();
    for(int i=0;i < len; ++i)
    {
        int v = (int)s[i];
       // cout<<"output: "<< v <<"..."<<endl;
       if(a[v]) return false;
        a[v] = true;
    }

    return true;
}

bool isUnique2(string s)
{
    int a[8];
    memset(a,0,sizeof(a));
    int len = s.length();
    for (int i=0;i < len;i++)
    {
        int v = (int)s[i];
        int idx = v/32,shift = v%32;
        if(a[idx] & (1 << shift)) return false;
        a[idx] |= (1 << shift);

        cout <<"idx: "<< idx<<".." <<a[idx]<<"..."<<endl;
    }
    return true;
}

bool isUnique3(string s)
{
    int check = 0;
    int len = s.length();
    for(int i=0;i < len; i++)
    {
        int v = (int)(s[i] - 'a');
        if(check &(1<<v)) return false;
        check |=(1<<v);
    }
    return true;
}
int main()
{
    string s1 = "i am luckywoo.";
    string s2 = "qwertyuiop";
    cout<<isUnique2(s1)<<endl;
    cout<<isUnique2(s2)<<endl;
    return 0;
}
