#include <iostream>
#include <string>

using namespace std;

string removeDuplicate1(string s)
{
    int check =0;
    int len = s.length();
    if(len < 2) return s;
    string str = "";
    for(int i=0; i<len; i++)
    {
        int v = (int)(s[i]-'a');
        if((check & (1<<v)) == 0)//当字符不重复时，进入if
        {
            str += s[i];
            check |= (1<<v);
        }
    }
    return str;
}

string removeDuplicate2(string s)
{
    int len = s.length();
    if (len < 2) return s;
    string str = "";
    for(int i=0; i<len; i++)
    {
        if(s[i]!='\0')
        {
            str += s[i];
            for(int j=i+1;j<len;j++)
            {
                if(s[j]==s[i])
                {
                    s[j]='\0';
                }
            }
        }
    }
    return str;
}

//只能用额外的变量来实现
void removeDuplicate3(char s[])
{
    int len = strlen(s);
    if (len < 2) return;
    int p = 0;
    for(int i=0; i<len; i++)
    {
        if(s[i] != '\0')
        {
            s[p++] = s[i];
            for(int j = i+1;j<len;j++)
            {
                if(s[j] == s[i])
                {
                    s[j]='\0';
                }
            }
        }
    }
    s[p] = '\0';
}

//开一个固定大小，与问题规模(即字符串长度)无关的数组
void removeDuplicate4(char s[])
{
    int len = strlen(s);
    if(len < 2) return;
    bool c[256];          //256个ASCII码字符
    memset(c,0,sizeof(c));//用来给c[256]初始化 0
    int p = 0;            //用来更新string的变量
    for(int i=0; i<len; i++)
    {
        if(!c[s[i]]) //当没有重复字符时，进入if，设标志位为true
        {
            s[p++]=s[i]; //更新，赋值
            c[s[i]] = true;//设标志位
        }
    }
    s[p]='\0';//C语法字符串最后一位是'\0'

}

//如果字符集更小一些，比如只是a-z，即字符串里只包含小写字母
void removeDuplicate5(char s[])
{
    int len = strlen(s);
    if(len<2) return;
    int check=0,p=0;
    for(int i=0; i< len; i++)
    {
        int v =(int)(s[i]-'a');
        if((check & (1<<v))==0)
        {
            s[p++]=s[i];
            check |=(1<<v);
        }
    }
    s[p]='\0';
}

int main()
{
    string s1 = "abcdeeqwr";
    string s2 = "qqqqaaabbb";
    string s3 = "";
    string s4 = "abababcd";
    string s5 = "bbbbbbbb";
    cout<<removeDuplicate1(s1)<<" "<<removeDuplicate2(s1)<<endl;
    cout<<removeDuplicate1(s2)<<" "<<removeDuplicate2(s2)<<endl;
    cout<<removeDuplicate1(s3)<<" "<<removeDuplicate2(s3)<<endl;
    cout<<removeDuplicate1(s4)<<" "<<removeDuplicate2(s4)<<endl;
    cout<<removeDuplicate1(s5)<<" "<<removeDuplicate2(s5)<<endl;
    char ss1[] = "wuyunxing";
    char ss2[] = "aaabbb";
    char ss3[] = "";
    char ss4[] = "abababc";
    char ss5[] = "ccccc";
    removeDuplicate3(ss1);
    removeDuplicate4(ss2);
    removeDuplicate4(ss3);
    removeDuplicate4(ss4);
    removeDuplicate4(ss5);
    cout<<ss1<<" "<<ss2<<" "<<ss3<<" "<<ss4<<" "<<ss5<<endl;
    return 0;
}
