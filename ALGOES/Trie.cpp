
/*
As you probably know, the human information processor is a wonderful text recognizer that can handle even sentences that are garbled like the following:
The ACM Itrenntaoial Clloegaite Porgarmmnig Cnotset (IPCC) porvdies clolgee stuetnds wtih ooppriuntetiis to itnrecat wtih sutednts form ohetr uinevsrtieis.
People have claimed that understanding these sentences works in general when using the following rule: The first and last letters of each word remain unmodified and all the characters in the middle can be reordered freely. Since you are an ACM programmer, you immediately set on to write the following program: Given a sentence and a dictionary of words, how many different sentences can you find that could potentially be mapped to the same encoding?
Input
Input starts with an integer T (≤ 20), denoting the number of test cases.
Each case starts with a line containing the number n (0 ≤ n ≤ 10000) of words in the dictionary, which are printed on the following n lines. After this, there is a line containing the number m (0 ≤ m ≤ 10000) of sentences that should be tested with the preceding dictionary and then m lines containing those sentences. The sentences consist of letters from a to z, A to Z and spaces only and have a maximal length of 10000 characters. For each word in the dictionary a limitation of 100 characters can be assumed. The words are case sensitive. In any case, total number of characters in the sentences will be at most 105. And total characters in the dictionary will be at most 105.
Output
For each case, print the case number first. Then for each sentence, output the number of sentences that can be formed on an individual line. Result fits into 32 bit signed integer.


1
8
baggers
beggars
in
the
blowed
bowled
barn
bran
1
beggars bowled in the barn


Case 1:
8


*/
#include<bits/stdc++.h>
#define I int
#define LL long long int
#define UL unsigned long long int
#define D double
#define S(a) scanf("%d",&a)
#define S2(a,b) scanf("%d%d",&a,&b)
#define S3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define SL(a) scanf("%lld",&a)
#define P(a) printf("%d\n",a)
#define PL(a) printf("%lld\n",a)
#define PT(t) printf("Case %d: ",t)
#define PB(a) push_back(a)
#define FI first
#define SD second
#define SC scanf
#define PC printf
#define NL printf("\n")
#define SET(a) memset(a,0,sizeof a)
#define SETR(a) memset(a,-1,sizeof a)
#define SZ(a) ((int)a.size())

using namespace std;
#define MX 10000000000000;
#define MD  1000000007
struct node
{
    int info;
    int in[53];
    node()
    {
        info = 0;
        SET(in);
    }

};
int counter;
node data[100005];
void insert1(char *s,int l)
{
    if(l > 3)
        sort(s+1, s+l-1);
    int  cur = 1;
    for(int i = 0; i < l; i++)
    {
        int id;
        if(s[i] < 97)
            id = s[i] - 64;
        else id = s[i] - 70;
        if(data[cur].in[id] == 0)
        {
            data[cur].in[id] = ++counter;
        }
        cur = data[cur].in[id];
    }
    // NO;
    data[cur].info++;
}
int searc1(char *s,int l)
{
    if(l > 3)
        sort(s+1, s+l-1);
    //cout<<s<<endl;
    int cur = 1;
    for(int i = 0; i < l; i++)
    {
        int id;
        if(s[i] < 97)
            id = s[i] - 64;
        else id = s[i] - 70;
        if(data[cur].in[id] == 0)
        {
            return 0;
        }
        cur = data[cur].in[id];
    }
    return data[cur].info;
}
int main()
{
    int tc, cs = 1;
    S(tc);
    while(tc--)
    {
        counter = 1;
        int n;
        S(n);
        char h[103];
        for(int i = 1; i <= n; i++)
        {

            SC("%s",h);
            insert1(h,strlen(h));
        }
        int m;
        //input of m;
        PC("Case %d:\n", cs++);
        S(m);
        getchar();
        while(m--)
        {
            char s[100005],h[102];
            gets(s);
            LL ans = 1;
            istringstream is(s);
            while(is >> h && ans)
            {

                ans *= (LL)searc1(h,strlen(h));
            }
            PL(ans);
        }
        //de();
        SET(data);
    }
    return 0;
}

