#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<malloc.h>
#include<queue>
int n,m;
int vis[1000][1000];
int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
struct node
{
	int x,y,step;	
};
int map[1000][1000];
int main()
{
	node sta,end,pre,cur;
	int ty,tx;
	queue<node>q;
	Loop:while(~scanf("%d %d",&n,&m))
	{
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
			{
				scanf("%d",&map[i][j]);
				if(map[i][j]==-2)
				{
					sta.x=i;
					sta.y=j;
					sta.step=0;
				}
				else if(map[i][j]==-3)
				{
					end.x=i;
					end.y=j;
				}
			}
		q.push(sta);
		flag[sta.y][sta.y]=1;
		while(!q.empty())
		{
			pre=q.front();
			q.pop();
			if(pre.x==end.x&&pre.y==end.y)
			{
				printf("%d\n",pre.step);
				goto Loop;
			}
			for(int i=0;i<4;i++)
			{
				tx=pre.x+dir[i][0];
				ty=pre.y+dir[i][1];
				if(tx>=0&&tx<n&&ty>=0&&ty<m&&flag[tx][ty]==0&&map[ty][tx]!=-1)
				{
					cur.x=tx;
					cur.y=ty;
					cur.step=pre.step+1;
					q.push(cur);
					flag[tx][ty]=1;
				}
				if(map[pre.x][pre.y]>0)
				{
					tx=pre.x+dir[i][0]*map[pre.x][pre.y];
					ty=pre.y+dir[i][1]*map[pre.x][pre.y];
					if(tx>=0&&tx<n&&ty>=0&&ty<m&&flag[tx][ty]==0&&map[ty][tx]!=-1)
					{
						cur.x=tx;
						cur.y=ty;
						cur.step=pre.step+1;
						q.push(cur);
						flag[tx][ty]=1;
					}
				}
			}
		}
		printf("-1\n");
	}
	return 0;
}
