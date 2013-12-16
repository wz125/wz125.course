#include <iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <time.h>
using namespace std;
int Partition(char* a[],long l,long h)
{
 char *temp=a[l];
 while(l<h)
 {
  //while(l<h&&a[h]>temp)
  while(l<h&&strcmp(a[h],temp)>0)
   h--;
  if(l<h){
   a[l]=a[h];
   l++;
  }
  //while(l<h&&a[l]<temp)
  while(l<h&&strcmp(a[l],temp)<0)
   l++;
  if(l<h){
   a[h]=a[l];
   h--;
  }
 }
 a[l]=temp;
 return l;
}
void QuickSort(char* a[],int l,int h)
{
 if(l>=h) return;
 long m=Partition(a,l,h);
 QuickSort(a,l,m-1);
 QuickSort(a,m+1,h);
}

int randomized_partition(int* a, int p, int r);
int randomized_select(int* a, int p, int r, int i);
int main()
{	
	
	char tab[]={'2','2','2','3','3','3','4','4','4','5','5','5','6','6','6','7',0,'7','7','8','8','8','9','9','9',0};
	int num;
	char *a[100000];
	char str0[100000][20];
	char str1[100000][20];
	
	cin>>num;
	for(int i=0;i<num;i++){
		cin>>str0[i];
		int idx=0;
		//tolower(int c)
		for(int k=0;k<strlen(str0[i]);k++){
			//printf("%d %d %c\n",i,k,0);
			int tmp=toupper(str0[i][k]);
			if((str0[i][k]>='a' && str0[i][k]<'z')||(str0[i][k]>='A' && str0[i][k]<'Z')){
				tmp=tab[(tmp-'A') % 26];
				//printf("%c %d\n",str0[i][k],tmp);
				str1[i][idx++]=tmp;
			}else if(str0[i][k]>='0' && str0[i][k]<='9'){
				str1[i][idx++]=tmp;
			}
			if(idx==3)
				str1[i][idx++]='-';
		}
		str1[i][idx]='\0';
		a[i]=str1[i];
		//printf(">>> %s\n",a[i]);
	}
	QuickSort(a,0,num-1);
	char *pre=NULL,*now=NULL;
	int sum=0,ishave=0;
	for(int i=0;i<num;i++){
		now=a[i];
		//printf(">>> %s %s\n",now,pre);
		if(pre!=NULL && strcmp(pre,now)!=0){
			if(sum>1){
				printf("%s %d\n",pre,sum);
				ishave=1;
			}
			sum=0;
		}
		//printf("zzz %s %s\n",now,pre);
		pre=a[i];
		sum++;
	}
	if(pre!=NULL && sum>1){
		printf("%s %d\n",pre,sum);
	}else if(ishave==0){
		printf("No duplicates.\n");
	}

	return 0;
/*
    if(num%2)
        cout<<""<<randomized_select(a, 0, num -1, (num -1)/2)<<endl;
    else
    {
        cout<<""<<randomized_select(a, 0, num -1, (num -1)/2)<<" and Y = "<<randomized_select(a, 0, num -1, (num -1)/2+1)<<endl;
    }
*/	
//	QuickSort(a,0,num-1);
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
