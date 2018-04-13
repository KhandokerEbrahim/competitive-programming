/*
A string is a finite sequence of symbols that are chosen from an alphabet. In this problem you are given a string T and n queries each with a string Pi, where the strings contain lower case English alphabets only. You have to find the number of times Pi occurs as a substring of T.
Input
Input starts with an integer T (≤ 10), denoting the number of test cases.
Each case starts with a line containing an integer n (1 ≤ n ≤ 500). The next line contains the string T (1 ≤ |T| ≤ 106). Each of the next n lines contains a string Pi (1 ≤ |Pi| ≤ 500).
Output
For each case, print the case number in a single line first. Then for each string Pi, report the number of times it occurs as a substring of T in a single line.
Input:
2
5
ababacbabc
aba
ba
ac
a
abc
3
lightoj
oj
light
lit
Output:
Case 1:
2
3
1
4
1
Case 2:
1
1
0
*/
#include<bits/stdc++.h>
using namespace std;
#define mx 1000000//Number of charter of main string
#define mx1 250000// Number off character of total charcater
#define mx2 500// Number of pattern and number of ch of each pattern
struct node
{
    int link[27];
    node()
    {
        memset(link,-1,sizeof link);
    }
};
node a[mx1+4];
char s[mx+4];
char ch[mx2+4];
int suffix[mx1+4];
int val[mx1+4];
int path[mx1+4];
int en[mx2+4];
int num;
int koto=0;
void init()
{
    memset(a,-1,sizeof a);
    memset(suffix,0,sizeof suffix);
    memset(val,0,sizeof val);
    memset(path,0,sizeof path);
    num=0;
    koto=0;

}
void maketrie(int j,int l)
{
    int cur=0;
    for(int i=1; i<=l; i++)
    {

        int x=ch[i]-96;
        if(a[cur].link[x]==-1)
        {
            a[cur].link[x]=++num;
        }
        cur=a[cur].link[x];
    }
    en[j]=cur;

}
void bfs()
{
    queue<int>q;
    for(int i=1; i<=26; i++)
    {
        if(a[0].link[i]==-1)
        {
            a[0].link[i]=0;
        }
        else
        {
            q.push(a[0].link[i]);
            suffix[a[0].link[i]]=0;
        }
    }
    while(!q.empty())
    {
        int f=q.front();
        q.pop();
        for(int i=1; i<=26; i++)
        {
            int  x=a[f].link[i];
            if(x==-1)
            {
                a[f].link[i]=a[suffix[f]].link[i];
            }
            else
            {
                q.push(x);
                suffix[x]=a[suffix[f]].link[i];
                path[++koto]=x;
            }

        }
    }
}
void search(int l)
{

    int cur=0;
    for(int i=1; i<=l; i++)
    {
        int x=s[i]-96;
        cur=a[cur].link[x];
        val[cur]++;
    }
    for(int i=koto; i>=1; i--)
    {

        val[suffix[path[i]]]+=val[path[i]];

    }
}
int main()
{

    int tc,cs=0;
    scanf("%d",&tc);
    while(tc--)
    {
        init();
        int n;
        scanf("%d",&n);
        scanf("%s",s+1);
        for(int i=1; i<=n; i++)
        {
            scanf("%s",ch+1);
            int l=strlen(ch+1);
            maketrie(i,l);
        }
        bfs();
        int le=strlen(s+1);
        search(le);
        printf("Case %d:\n",++cs);
        for(int i=1; i<=n; i++)
        {
            printf("%d\n",val[en[i]]);
        }
      

    }
    return 0;
}
