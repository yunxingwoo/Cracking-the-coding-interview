#include <iostream>
#include <string>

using namespace std;

char* replace1(char *c)
{
    if(c == NULL) return NULL;
    int len = strlen(c);
    if(len == 0) return NULL;
    int count = 0;
    for(int i=0;i<len;i++)
    {
       if(c[i]==' ')
           count++;
    }

    char *cc = new char[len+2*count+1];
    int p = 0;
    for(int j=0;j<len;j++)
    {
        if(c[j]==' ')
        {
            cc[p] = '%';
            cc[p+1]= '2';
            cc[p+2]= '0';
            p += 3;
        }
        else
        {
           cc[p]=c[j];
           p++;
        }
    }
    cc[p] = '\0';
    return cc;
}

int main()
{
    char c1[]="hello world.";
    char c2[]="i am a student.";
    cout<< replace1(c1) <<endl;
    cout<<"-----------------"<<endl;
    cout<< replace1(c2) <<endl;
    return 0;
}
