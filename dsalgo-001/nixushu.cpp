#include<cstdio>
#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<cstring>
using namespace std;
const int maxn = 20000 + 10;

int a[maxn];
int t[maxn];
int n;
int ans;

void merge_sort(int *a, int x, int y, int *t)
{
	if(y-x > 1)
	{
		int m = x + (y-x)/2;
		int p = x, q = m, i = x;
	 
		merge_sort(a, x, m, t);
		merge_sort(a, m, y, t);
		
		while(p < m && q < y) //?? 
		{
			if(a[p] <= a[q]) t[i++] = a[p++];
			else
			{
				t[i++] = a[q++];//a[p]>a[q]
				ans += m-p;
			} 
		}	
		while(p < m) t[i++] = a[p++];
		while(q < y) t[i++] = a[q++];
		
		for(i = x; i < y; i++) a[i] = t[i];
	}
}
int main()
{
	while(1){
		int num;
		cin>>num;
		if(num==0)
			break;
		//memset(a,0x0,20010*sizeof(int));
		ans=0;
		for(int i=0;i<num;i++)
		{
			int tmp;
			cin>>tmp;
			a[i]=tmp;
			//printf(">>>%d\n",tmp);	
		}
		merge_sort(a, 0, num, t); 
		printf("%d\n", ans);  
	}
	return 0;
}

