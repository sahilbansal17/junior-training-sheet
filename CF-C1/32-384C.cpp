#include<bits/stdc++.h>
using namespace std;
long long n,i,x,one,ans;
int main()
{
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&x);
		if(x==1) one++;
		else ans+=one;
	}
	printf("%lld",ans);
}
