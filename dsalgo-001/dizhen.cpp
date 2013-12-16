#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>

#define MAXN 120
#define inf 1000000000

double len[MAXN * 2][MAXN * 2] = {0};

class poi
{
public:
	int x;
	int y;
};
poi po[MAXN];

typedef double elem_t;

elem_t edmonds (int n, elem_t mat[][MAXN * 2], int *pre)
{
	elem_t ret = 0;
	int c[MAXN * 2][MAXN * 2], l[MAXN * 2], p[MAXN * 2], m = n, t, i, j, k;

	for (i = 0; i < n; l[i] = i, i++);
	do
	{
		memset (c, 0, sizeof (c)), memset (p, 0xff, sizeof (p));
		for (t = m, i = 0; i < m; c[i][i] = 1, i++);
		for (i = 0; i < t; i++)
			if (l[i] == i && pre[i] != -1)
			{
				for (j = 0; j < m; j++)
					if (l[j] == j && i != j && mat[j][i] < inf
						&& (p[i] == -1 || mat[j][i] < mat[p[i]][i]))
						p[i] = j;
				if ((pre[i] = p[i]) == -1)
					return -1;
				if (c[i][p[i]])
				{
					for (j = 0; j <= m; mat[j][m] = mat[m][j] = inf, j++);
					for (k = i; l[k] != m; l[k] = m, k = p[k])
						for (j = 0; j < m; j++)
							if (l[j] == j)
							{
								if (mat[j][k] - mat[p[k]][k] < mat[j][m])
									mat[j][m] = mat[j][k] - mat[p[k]][k];
								if (mat[k][j] < mat[m][j])
									mat[m][j] = mat[k][j];
							}
					c[m][m] = 1, l[m] = m, m++;
				}
				for (j = 0; j < m; j++)
					if (c[i][j])
						for (k = p[i]; k != -1 && l[k] == k;
							 c[k][j] = 1, k = p[k]);
			}
	}
	while (t < m);
	for (; m-- > n; pre[k] = pre[m])
		for (i = 0; i < m; i++)
			if (l[i] == m)
			{
				for (j = 0; j < m; j++)
					if (pre[j] == m && mat[i][j] == mat[m][j])
						pre[j] = i;
				if (mat[pre[m]][m] == mat[pre[m]][i] - mat[pre[i]][i])
					k = i;
			}
	for (i = 0; i < n; i++)
		if (pre[i] != -1)
			ret += mat[pre[i]][i];
	return ret;
}


int main()
{
	int poin = 0, linen = 0;
	int par[MAXN] = {0};
	while(scanf ("%d%d", &poin, &linen) != EOF)
	{
		//init
		memset(par, 0, sizeof(par));
		memset(len, 0, sizeof(len));
		par[0] = -1;
		for (int i = 0; i < MAXN; ++i)
		for (int j = 0; j < MAXN; ++j)
		{
			if (i == j) len[i][j] = 0;
			else len[i][j] = inf;
		}
		int ix = 0, iy = 0;
		for (int i = 0; i < poin; ++i)
		{
			scanf("%d%d", &ix, &iy);
			po[i].x = ix;
			po[i].y = iy;
		}
		int src = 0, dest = 0;
		for (int i = 0; i < linen; ++i)
		{
			scanf("%d%d", &src, &dest);
			--src;
			--dest;
			double dx = po[src].x - po[dest].x;
			double dy = po[src].y - po[dest].y;
			double length = sqrt(dx*dx + dy*dy);
			if (len[src][dest] > length)
			{
				len[src][dest] = length;
			}
		}
		double ans = edmonds (poin, len, par);
		if (ans >= 0) printf("%.2lf\n", ans);
		else printf("NO\n");
	}
	return 0;
}
