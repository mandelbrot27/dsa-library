#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll exp(ll a,ll b)
{
    if (b==0) return 1;
    if (b%2) return a*exp(a,b-1);
    else return exp(a*a,b/2);
}
int len(int a)
{
    string t= to_string(a);
    return t.size();
}

ll multiply(ll x, ll y, int sizex,int sizey)
{
    if (sizex/2==0 || sizey/2==0) return x*y;

    ll a= x/(exp(10,sizex/2));
    ll b= x%(exp(10,sizex/2));
    ll c= y/(exp(10,sizey/2));
    ll d= y%(exp(10,sizey/2));

    ll p0=multiply(a,c,len(a),len(c));
    ll p1=multiply(a+b,c+d,len(a+b),len(c+d));
    ll p2=multiply(b,d,len(b),len(d));

    ll s= p0*exp(10,sizex) + (p1-p0-p2)*exp(10,sizex/2) + p2;
    return s;
}


int main()
{
    ll a= 52;
    ll b= 42;
    printf("%lld\n",multiply(a,b,len(a),len(b)));
}
