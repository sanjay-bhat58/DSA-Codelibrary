#include<stdio.h>
#include<conio.h>
int a[20][20],reach[20],n;
void dfs(int v) {
    static int count=1;
	int i;
	reach[v]=1;
	for (i=1;i<=n;i++)
	  if(a[v][i] && !reach[i])
    {
		printf(" %d->%d",v,i);
		count++;
		dfs(i);
	}
	//if(count>1)
	printf("\t%d\n",count);
	count=1;
	if(v<=n)
        dfs(v+1);
}
void main() {
	int i,j,count=0;
	printf("\n Enter number of vertices:");
	scanf("%d",&n);
	for (i=1;i<=n;i++) {
		reach[i]=0;
		for (j=1;j<=n;j++)
		   a[i][j]=0;
	}
	printf("\n Enter the adjacency matrix:\n");
	for (i=1;i<=n;i++)
	  for (j=1;j<=n;j++)
	   scanf("%d",&a[i][j]);
	dfs(1);
	printf("\n");
	for (i=1;i<=n;i++) {
		if(reach[i])
		   count++;
	}
}
