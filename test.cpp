#include <bits/stdc++.h>
using namespace std;
int a[11],n;
int main()
{
	int h;
	for (int i=1;i<=10;i++)
	cin >>a[i];
	cin >>h;
	h+=30;
	for (int i=1;i<=10;i++)
	  if (h>=a[i])
	  n+=1;
	cout<<n;
	return 0;
}