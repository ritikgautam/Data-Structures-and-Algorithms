#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define scan(a) scanf("%d",&a)
#define forl(i,a,b) for(int i=a;i<b;i++)

typedef struct Edge
{
	int src,dst,weight;
}Edge;

int main()
{
	int v,e;
	scan(v);
	scan(e);
	Edge E[e];
	forl(i,0,e)
	{
		scan(E[i].src);
		scan(E[i].dst);
		scan(E[i].weight);
	}
	int dist[v];
	forl(s,0,v){
	forl(i,0,v)
	{
		if(i==s)
			dist[i] = 0;
		else
			dist[i] = INT_MAX;
	}
	forl(i,0,v-1)
	{
		forl(j,0,e)
		{
			if(dist[E[j].src]!=INT_MAX && dist[E[j].dst]>dist[E[j].src]+E[j].weight)
				dist[E[j].dst] = dist[E[j].src] + E[j].weight;
		}
	}
	forl(j,0,e)
	{
		if(dist[E[j].src]!=INT_MAX && dist[E[j].dst]>dist[E[j].src]+E[j].weight)
		{ printf("1\n"); return 0;}
	}}
	printf("-1\n");

}
