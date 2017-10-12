/*
10109 Solving Systems of Linear Equations
You may have solved linear equation early in the school. Problems involving solving sets of linear
equation are very important in the field of Engineering and Mathematics.
Let us consider that we have a system of linear equations
a11 x1 + a12 x2 + a13 x3 = c1
a21 x1 + a22 x2 + a23 x3 = c2
a31 x1 + a32 x2 + a33 x3 = c3
We can solve it by reducing technique:
Now do as step 1 for second row and so on.
This can be made more effective using matrix method. The set of equation for n unknowns can be
written as
a11 x1 + a12 x2 + a13 x3 + . . . + a1n xn = c1
a21 x1 + a22 x2 + a23 x3 + . . . + a2n xn = c2
a31 x1 + a32 x2 + a33 x3 + . . . + a3n xn = c3
Compactly [A] ∗ {X} = {C}
From this we can solve values of X’s. The matrix [AC] is called an augmented (see example below)
matrix. If after elimination process the rank of matrix [A] and rank of matrix [AC] not equals, the
system is called inconsistent and it does not have a solution. If the matrix is consistent and number
of unknowns is greater then rank of matrix then the matrix system has arbitarily many solutions
containing (NumberOfUnknowns-rank) arbitary constants. Rank of a matrix is defined as the number
of non zero rows of a matrix system. Otherwise if the rank and number of unknows equals then the
system has been solved.
For example let a system of equations be
Universidad de Valladolid OJ: 10109 – Solving Systems of Linear Equations 2/5
9x1 + 4x2 + x3 = −17
x1 − 2x2 − 6x3 = 14
x1 + 6x2 = 4
This sets of equation can be written as
9 4 1 −17
1 −2 −6 14
1 6 0 4
So the steps involving the solution is Step : 1
1 −2 −6 14
1 6 0 4
9 4 1 −17
Step : 2
1 −2 −6 14
0 8 6 −10
0 22 55 −143
Step : 3
1 −2 −6 14
0 1 3/4 −5/4
0 0 77/2 −231/2
Step : 4
1 −2 −6 14
0 1 3/4 −5/4
0 0 1 −3
Step : 5
1 −2 0 −4
0 1 0 1
0 0 1 −3
Step : 6
1 0 0 −2
0 1 0 1
0 0 1 −3
and then, the solution is
x1 = −2, x2 = 1, x3 = −3
Again consider this system
2x1 + 2x2 + 2x3 = 2
4x1 + 4x2 + 4x3 = 4
16x1 + 16x2 + 16x3 = 16
Steps are: Step : 1
Universidad de Valladolid OJ: 10109 – Solving Systems of Linear Equations 3/5
2 2 2 2
4 4 4 4
16 16 16 16
Step : 2
1 1 1 1
0 0 0 0
0 0 0 0
This system has number of unknowns 3 and rank is 1. So this system has arbitarily many solutions
containing (3-1) = 2 arbitary constants.
Another system
x + y = 10, x + y = 20, 2x + 2y = 50
Steps are: Step : 1
1 1 10
1 1 20
2 2 50
Step : 2
1 1 10
0 0 10
0 0 30
Step : 3
1 1 10
0 0 10
0 0 30
Step : 4
1 1 10
0 0 10
0 0 1
Step : 5
1 1 0
0 0 0
0 0 1
Step : 6
1 1 0
0 0 0
0 0 1
As rank of [A] (in this case: rank(A) = 1) is not equal to the rank of augmented matrix [AC] (in
this case: rank(AC) = 2) , the system has no solution.
However though there are other methods to compute this solution for the matrix system, the main
problem occurs are
1. Round off errors or computational error due to the use of floating point number
Universidad de Valladolid OJ: 10109 – Solving Systems of Linear Equations 4/5
2. Error due to wrong order of the given equation.
To prevent round off error due to floating point number an approach can be used, similar to the
process of doing fractional number. So we may use 1/3 as a expression of two integer, the numerator
and the denominator, instead of .333333 (with loss of precision). Thus we can prevent this kind of
error.
Consider this set of equations
5x3 = 10
3x2 − 3x3 = 3
2x1 − x2 + 2x3 = 7
This set of equations can be written as
0 0 5 10
0 3 −3 3
2 −1 2 7
Now how will you evaluate this matrix without ordering?
Input
The first line of input is the number of the problem. The next line contains two integers - NumberOfUnknowns
and NumberOfEquations (none of these is less then or equal to 0 and greater then 50). The
next lines contains the matrix for the system of linear equations. There are number of rows equal to
the NumberOfEquations and number of column equal to the NumberOfUnknowns+1. The numbers
may be fractional, that is there may be numbers like 1/3 or 6/8. An problem number zero indicates
the end of input.
Output
First print (without the quotation mark)
"Solution for Matrix System # N"
Here ‘N’ is the problem number as taken from input. Then on the next line, for each system of
equations output the solution (if exists) expressed in the fractional form in each line. You may assume
each of the numerator and denominator part will not exceed the limit of data type long long (64 bit).
If there are many solutions as described above print (without the quotation mark)
"Infinitely many solutions containing n arbitrary constants."
(here ‘n’ is the number as described above) , and if there is no solutions print (without the quotation
mark)
"No Solution."
Print a blank line between two systems of linear equations.
Sample Input
1
3 3
9 4 1 -17
1 -2 -6 14
1 6 0 4
Universidad de Valladolid OJ: 10109 – Solving Systems of Linear Equations 5/5
2
3 3
2 2 2 2
4 4 4 4
16/1 16/1 16/1 16/1
3
2 3
1 1 10
1 1 20
2 2 50
4
1 1
3 10
0
Sample Output
Solution for Matrix System # 1
x[1] = -2
x[2] = 1
x[3] = -3
Solution for Matrix System # 2
Infinitely many solutions containing 2 arbitrary constants.
Solution for Matrix System # 3
No Solution.
Solution for Matrix System # 4
x[1] = 10/3
*/


#include<bits/stdc++.h>
#define I int
#define ll long long int
#define S(a) scanf("%lld",&a)
#define S2(a,b) scanf("%lld%lld",&a,&b)
#define S3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define PL(a) printf("%d\n",a)
#define P(a) printf("%lld\n",a)
#define PT(t) printf("Case %lld: ",t)
#define PB(a) push_back(a)
#define xx first
#define yy second
#define SC scanf
#define PC printf
#define NL printf("\n")
#define pi 2.0*acos(0.0)
using namespace std;
typedef pair<ll,ll  >P;
////////define value//////////ŝ
ll gcd(ll x,ll y)
{

    if(x < 0)   x *= -1;
    if(y < 0)   y *= -1;
    if(x==0&&y==0)return 1;
    if(!x)return y;
    if(!y)  return x;
    long long t;
    while(x%y)
        t = x, x = y, y = t%y;
    return y;
}
ll lcm(ll x,ll y)
{
    return (x/gcd(x,y))*y;
}
P add(P x,P y)
{
    P sum;
    sum.yy=lcm(x.yy,y.yy);
    sum.xx=(sum.yy/x.yy)*x.xx+(sum.yy/y.yy)*y.xx;

    ll gc=gcd(sum.xx,sum.yy);
    sum.xx/=gc;
    sum.yy/=gc;
    return sum;

}
P diff(P x,P y)
{

    P sum;
    sum.yy=lcm(x.yy,y.yy);
    sum.xx=(sum.yy/x.yy)*x.xx-(sum.yy/y.yy)*y.xx;
    ll gc=gcd(sum.xx,sum.yy);
    sum.xx/=gc;
    sum.yy/=gc;
    return sum;

}
P mul(P x,P y)
{
    P sum;
    ll opo=gcd(x.xx,y.yy);
    x.xx/=opo;
    y.yy/=opo;
    opo=gcd(y.xx,x.yy);
    y.xx/=opo;
    x.yy/=opo;
    sum.xx=x.xx*y.xx;
    sum.yy=x.yy*y.yy;
    ll gc=gcd(sum.xx,sum.yy);
    sum.xx/=gc;
    sum.yy/=gc;
    return sum;

}
P dev(P x,P y)
{
    P sum;
    swap(y.xx,y.yy);
    sum= mul(x,y);
    if(sum.yy<0)
    {
        sum.xx*=-1;
        sum.yy*=-1;
    }
    return sum;
}
P a[55][60];
void solve(ll n,ll m)
{
    ll row=1;
    for(ll col=1; col<=n; col++)
    {

        for(ll i=row; i<=m; i++)
        {
            if(a[i][col].xx!=0)
            {
                for(ll j=1; j<=n+1; j++)
                {
                    swap(a[i][j],a[row][j]);
                }
                break;
            }
        }
        if(a[row][col].xx==0)
        {
            continue;
        }
        P so;
        so=a[row][col];
        for(ll i=col; i<=n+1; i++)
        {
            a[row][i]=dev(a[row][i],so);
        }
        so=a[row][col];
        for( ll i=row+1; i<=m; i++)
        {
            bool fl=0;
            P bol=a[i][col];
            for(ll j=col; j<=n+1; j++)
            {
                P lol=mul(bol,a[row][j]);

                a[i][j]=diff(a[i][j],dev(lol,so));
                if(j==n+1&&fl==0&&a[i][j].xx!=0)
                {
                    PC("No Solution.\n");
                    return ;
                }
                if(a[i][j].xx!=0)fl=1;
            }
        }

        row++;
    }
    ll ran=n;
    for(ll i=1; i<=n; i++)
    {
        bool fl=0;
        for(ll j=1; j<=n+1; j++)
        {
            if(a[i][j].xx!=0)fl=1;
        }
        if(fl==0)
        {
            ran=min(ran,i-1);
        }
    }
    if(ran<n)
    {
        PC("Infinitely many solutions containing %lld arbitrary constants.\n",n-ran);
        return;
    }
    P ab[60+2];
    ab[n]=a[n][n+1];

    for(ll i=n-1; i>=1; i--)
    {
        P lp=make_pair(0,1);
        for(ll j=n+1; j>i; j--)
        {
            if(j==n+1)
                lp=diff(lp,a[i][j]);
            else lp=add(lp,mul(ab[j],a[i][j]));
        }
        lp.xx*=-1;
        ab[i]=lp;
    }
    for(ll i=1; i<=n; i++)
    {
        PC("x[%lld] = ",i);
        if(ab[i].yy==1)P(ab[i].xx);
        else PC("%lld/%lld\n",ab[i].xx,ab[i].yy);
    }
    return;

}
int main()
{
    ll t;
    ll opo=0;
    while(S(t))
    {

        if(t==0)break;
        opo++;
        if(opo>1)
            NL;
        ll n,m;
        S2(n,m);
        char ch[1000];
        ll st,len;
        for(ll i=1; i<=m; i++)
        {
            for(ll j=1; j<=n+1; j++)
            {
                a[i][j].xx=1;
                a[i][j].yy=1;
                SC("%s",&ch);
                st=0;
                if(ch[0]=='-')
                {
                    a[i][j].xx*=-1;
                    st=1;
                }
                len=strlen(ch);
                ll sum=0,su=0;
                for(ll k=st; k<len; k++)
                {
                    if(ch[k]=='/')
                    {
                        for(ll op=k+1; op<len; op++)
                        {
                            su=(su*10ll+ch[op]-'0');
                        }
                        break;
                    }
                    else sum=(sum*10ll+ch[k]-'0');
                }
                a[i][j].xx*=sum;
                if(su!=0)a[i][j].yy=su;
                P ok;
                ok.xx=1;
                ok.yy=1;
            }
        }
        if(m<n)
        {
            for(ll i=m+1; i<=n; i++)
            {
                for(ll j=1; j<=n+1; j++)
                {
                    a[i][j].xx=0;
                    a[i][j].yy=1;
                    m=n;
                }
            }
        }
        PC("Solution for Matrix System # %lld\n",t);
        solve(n,m);
    }

    return 0;
}
