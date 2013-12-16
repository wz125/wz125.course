#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include <time.h>
using namespace std;

int c[50000];
int Partition(int* a,int* b,int l,int h)
{
 int temp=a[l];
 int temp1=b[l];
 while(l<h)
 {
  while(l<h&&a[h]>temp)
   h--;
  if(l<h){
   a[l]=a[h];
   b[l]=b[h];
   l++;
  }
  while(l<h&&a[l]<temp)
   l++;
  if(l<h){
   a[h]=a[l];
   b[h]=b[l];
   h--;
  }
 }
 a[l]=temp;
 b[l]=temp1;
 return l;
}
void QuickSort(int* a,int* b,int l,int h)
{
 if(l>=h) return;
 int m=Partition(a,b,l,h);
 QuickSort(a,b,l,m-1);
 QuickSort(a,b,m+1,h);
}

int randomized_partition(int* a, int p, int r);
int randomized_select(int* a, int p, int r, int i);

int main()
{
	int num,numk;
	int a[50000];
	int b[50000];
//	int c[50000];
	cin>>num>>numk;
	for(int i=0;i<num;i++){
		cin>>a[i]>>b[i];
		c[i]=b[i];
	}
/*
    if(num%2)
        cout<<""<<randomized_select(a, 0, num -1, (num -1)/2)<<endl;
    else
    {
        cout<<""<<randomized_select(a, 0, num -1, (num -1)/2)<<" and Y = "<<randomized_select(a, 0, num -1, (num -1)/2+1)<<endl;
    }
*/	
	QuickSort(a,b,0,num-1);
	int tmp=0;
	for(int i=num-1;i>num-numk-1;i--){
		//printf("..%d %d %d\n",i,a[i],b[i]);
		if(tmp<b[i])
			tmp=b[i];
	}
	for(int i=0;i<num;i++){
		if(c[i]==tmp){
			tmp=i+1;
			break;
		}
	}
	printf("%d\n",tmp);
	/*
	QuickSort(b,a,0,numk-1);
	if(num>0)
		printf("%d\n",c[0]+1);
	else
		printf("\n");
		*/
/*	
	for(int i=0;i<num;i++){
		printf("%d %d\n",a[i],b[i]);
	}
	*/
    return 0;
}

int randomized_partition(int* a, int p, int r)
{
    srand(time(NULL));
    int q = rand()%(r - p +1) + p;
    int temp = a[q];
    a[q] = a[r];
    a[r] = temp;

    int j = p;
    for(int i = p; i < r; i++)
    {
        if(a[i] < a[r])
        {
            if(i != j)
            {
                int temp2 = a[i];
                a[i] = a[j];
                a[j] = temp2;
            }
            j++;
        }
    }
    
    temp = a[j];
    a[j] = a[r];
    a[r] = temp;

    return j;
}

int randomized_select(int* a, int p, int r, int i)
{
    int q = randomized_partition(a, p, r);
    while(p != r)
    {
        if(i == q)
            return a[q];
        else if(i < q)
        {
            r = q -1;
            q = randomized_partition(a, p, r);
        }
        else
        {
            p = q +1;
            q = randomized_partition(a, p, r);
        }
    }
    return a[p];
}
