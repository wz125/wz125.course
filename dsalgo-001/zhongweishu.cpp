#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include <time.h>
using namespace std;

//?????
int randomized_partition(int* a, int p, int r);
int randomized_select(int* a, int p, int r, int i);

int main()
{
    int num;
	int a[10000];
	cin>>num;
	for(int i=0;i<num;i++){
		cin>>a[i];
	}
    //const int LEN =10000;
    //int a[LEN] = {5, 9, 56, 100, 23, 34, 22, 94, 100};
    if(num%2)
        cout<<""<<randomized_select(a, 0, num -1, (num -1)/2)<<endl;
    else
    {
        cout<<""<<randomized_select(a, 0, num -1, (num -1)/2)<<" and Y = "<<randomized_select(a, 0, num -1, (num -1)/2+1)<<endl;
    }
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
