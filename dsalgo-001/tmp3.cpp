#include<iostream>
#include<vector>
#include<cstring>
#include<stack>
using namespace std;

#define  LEN 500
struct point
{
	char s[LEN];   
	vector<point*> v;
	point*father;
};
char s1[LEN],s2[LEN];
point *root=NULL;
bool the_find(point*p)
{
	if(p!=root&&strcmp(p->s,s2)==0)
	{
		point *t=p->father;
		int n=t->v.end()-t->v.begin(),i=0,j=0;
		for(i=0;i<n;++i) 
			if(t->v[i]==p)
				break;
		for(j=i+1;j<n;++j)
			cout<<t->v[j]->s;
		return true;
	}
	int len=p->v.end()-p->v.begin();
	for(int k=0;k<len;++k)
		if(the_find(p->v[k]))
			return true;
	return false;
}

void the_delete(point*p)    
{
	int i,j,n=p->v.end()-p->v.begin();
	for(i=0;i<n;++i)
		the_delete(p->v[i]);
	delete p;
	p=NULL;
}

int main()
{
	int n,i,j;
	cin>>n;
	cin.get();

	while(n--)                             
	{
		stack<point*> a;
		point *p1=NULL, *p2=NULL;
		root=new point;                    //??????
		root->father=NULL;
		a.push(root);

		while(1)
		{
			cin.getline(s1,LEN);           
			//cin.get();
			int len=strlen(s1);
			if(len==0) break;
			if(s1[0]=='{')
				a.push(p2);
			else if(s1[0]=='}')
				a.pop();
			else                   
			{
				p1=new point;
				strcpy(p1->s,s1);
				point*t=a.top();
				p1->father=t;
				t->v.push_back(p1);
				p2=p1;            
			}
		}
		cin.getline(s2,LEN);
		if(!the_find(root))
			cout<<"No";
		cout<<endl;
		the_delete(root);
		cin.get();cin.get();
	}
	cin.getline(s1,LEN);
	return 0;
}

