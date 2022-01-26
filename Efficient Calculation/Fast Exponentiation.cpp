#include<bits/stdc++.h>
using namespace std;

int exp(int a, int b)
{
  if (b==0) return 1;
  if (b%2) return a*exp(a,b-1);
  else return exp(a*a,b/2);
}

int main()
{
  printf("%d\n",exp(15,2));
}
