#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <malloc.h>
#include<stack>
#define M 100
#define N 100
#define INT_MAX 1000
using namespace std;
char pname[30][100];
char pnum[5];

typedef struct node
{
    int matrix[N][M];      //???? 
    int n;                 //??? 
    int e;                 //?? 
}MGraph; 

void DijkstraPath(MGraph g,int *dist,int *path,int v0)   //v0????? 
{
    int i,j,k;
    bool *visited=(bool *)malloc(sizeof(bool)*g.n);
    for(i=0;i<g.n;i++)     //??? 
    {
        if(g.matrix[v0][i]>0&&i!=v0)
        {
            dist[i]=g.matrix[v0][i];
            path[i]=v0;     //path????????v0?i?????? 
        }
        else
        {
            dist[i]=INT_MAX;    //?i??v0????,???????? 
            path[i]=-1;
        }
        visited[i]=false;
        path[v0]=v0;
        dist[v0]=0;
    }
    visited[v0]=true;
    for(i=1;i<g.n;i++)     //????n-1? 
    {
        int min=INT_MAX;
        int u;
        for(j=0;j<g.n;j++)    //?????????????? 
        {
            if(visited[j]==false&&dist[j]<min)
            {
                min=dist[j];
                u=j;        
            }
        } 
        visited[u]=true;
        for(k=0;k<g.n;k++)   //??dist????????? 
        {
            if(visited[k]==false&&g.matrix[u][k]>0&&min+g.matrix[u][k]<dist[k])
            {
                dist[k]=min+g.matrix[u][k];
                path[k]=u; 
            }
        }        
    }    
}

void showPath(MGraph g,int *path,int v,int v0)   //???????????? 
{
    stack<int> s;
    int u=v;
    while(v!=v0)
    {
        s.push(v);
        v=path[v];
		//cout<<"path:"<<v<<endl;
    }
    s.push(v);
	int now=-1,pre=-1;
    while(!s.empty())
    {
		now=s.top();
		if(pre>=0){
			cout<<"->("<<g.matrix[now][pre]<<")->";
		}
        cout<<pname[now];
        s.pop();
		pre=now;
    }
} 

int main(int argc, char *argv[])
{
	gets(pnum);
	int n=atoi(pnum);
    int i,j;
    int s,t,w; 
    MGraph g;
    int v0;
    int *dist=(int *)malloc(sizeof(int)*n);
    int *path=(int *)malloc(sizeof(int)*n);
    for(i=0;i<N;i++)
        for(j=0;j<M;j++)
            g.matrix[i][j]=0;

    g.n=n;
	for(int i=0;i<n;i++){
		gets(pname[i]);
		//cout<<pname[i]<<endl;
	}
	gets(pnum);
	int line_num=atoi(pnum);
    g.e=line_num;
	char buf[100];
	char snode[50],enode[50];
	char juli[20];
	for(int i=0;i<line_num;i++){
		gets(buf);
		//cout<<buf<<endl;
		sscanf(buf,"%s %s %s",snode,enode,juli);
		int snodeno=-1,enodeno=-1;
		for(int j=0;j<n;j++){
			if(strcmp(snode,pname[j])==0)
				snodeno=j;
			if(strcmp(enode,pname[j])==0)
				enodeno=j;
			if(snodeno>=0 && enodeno>=0)
				break;
		}
		g.matrix[snodeno][enodeno]=atoi(juli);
		g.matrix[enodeno][snodeno]=atoi(juli);
		//a[enodeno][snodeno]=atoi(juli);
		//cout<<snode<<"["<<snodeno<<"] - "<<enode<<" ["<<enodeno<<"] = "<<juli<<endl;
	}
	gets(pnum);
	int juli_num=atoi(pnum);
	for(int i=0;i<juli_num;i++){
		gets(buf);
		sscanf(buf,"%s %s",snode,enode);
		int snodeno=-1,enodeno=-1;
		for(int j=0;j<n;j++){
			if(strcmp(snode,pname[j])==0)
				snodeno=j;
			if(strcmp(enode,pname[j])==0)
				enodeno=j;
			if(snodeno>=0 && enodeno>=0)
				break;
		}
		//m=snodeno;
		//z=enodeno;
		//cout<<snodeno<<" - "<<enodeno<<endl;
		v0=snodeno;
		DijkstraPath(g,dist,path,v0);
        for(int j=0;j<n;j++)
        {
            if(j!=v0 && j==enodeno)
            {
                showPath(g,path,j,v0);
                //cout<<dist[j]<<endl;
                cout<<endl;
            }
        }
	}

	return 0;
	/*
    int n,e;     //??????????? 
    while(cin>>n>>e&&e!=0)
    {
        int i,j;
        int s,t,w;      //???????s->t,???w
        MGraph g;
        int v0;
        int *dist=(int *)malloc(sizeof(int)*n);
        int *path=(int *)malloc(sizeof(int)*n);
        for(i=0;i<N;i++)
            for(j=0;j<M;j++)
                g.matrix[i][j]=0;
        g.n=n;
        g.e=e;
        for(i=0;i<e;i++)
        {
            cin>>s>>t>>w;
            g.matrix[s][t]=w;
        }
        cin>>v0;        //????? 
        DijkstraPath(g,dist,path,v0);
        for(i=0;i<n;i++)
        {
            if(i!=v0)
            {
                showPath(path,i,v0);
                cout<<dist[i]<<endl;
            }
        }
    }
    return 0;
	*/
}

