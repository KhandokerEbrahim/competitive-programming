/*
A string is given .U have to say for every postion what is the max match of that string prefix
with every position
abababababcabc
14 0 8 0 6 0 4 0 2 0 0 2 0 0

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
char a[100008];
ll z[100008];
void zalgo()
{
    ll l,r;
    l=r=0;
    z[0]=strlen(a);
    for(ll i=1; i<z[0]; i++)
    {
        if(i>r)
        {
            l=r=i;
            for(ll j=i; j<z[0]; j++)
            {
                if(a[j-i]!=a[j])break;
                else r=j;
            }
            if(a[i]!=a[0])z[i]=0;
            else z[i]=r-l+1;
        }
        else
        {
            ll k=i-l;
            if(z[k]<r-i+1)
            {
                z[i]=z[k];
            }
            else
            {
                l=i;
                for(ll j=r+1; j<z[0]; j++)
                {
                    if(a[j-l]!=a[j])break;
                    else r=j;
                }
                z[i]=r-l+1;
            }

        }
    }
}
int main()
{
    scanf("%s",a);
    zalgo();
    for(ll i=0; i<strlen(a); i++)
        printf("%d ",z[i]);
    return 0;
}
