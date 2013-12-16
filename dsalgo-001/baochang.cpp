#include <cstdio>
#include <cstdlib>
#include <queue>
#include <algorithm>
using namespace std;

class rot
{
  public:
	int sr;
	int de;
	int len;
	  rot (int s, int d, int l):sr (s), de (d), len (l)
	{
	};
};

bool operator< (rot a, rot b)
{
	return a.len > b.len;
}

class node
{
  public:
	node * father;
	node ():father (NULL)
	{
	};
};

node *qutheori (node * a)
{
	if (a->father == NULL)
		return a;
	else
	{
		a->father = qutheori (a->father);	
		return a->father;
	}
}

bool isconnect (node * a, node * b)	
{
	return qutheori (a) == qutheori (b);
}

void connect (node * a, node * b)
{
	if (a->father == NULL)
		a->father = b;
	else
		a->father->father = b;	
	return;
}

int main ()
{
	int the_poisum = 0, roadsum = 0;
	char c_src, c_dest;
	int i_src = 0, i_dest = 0, consum = 0, length = 0;

	priority_queue < rot > pq;

	scanf ("%d", &the_poisum);
	node *poi = new node[the_poisum + 2];
	for (int i = 0; i < the_poisum - 1; ++i)
	{
		while(true)
		{
			c_src = getchar();
			if (c_src >= 'A' && c_src <= 'Z') break;
		}
		scanf ("%d", &consum);
		i_src = c_src - 'A';
		for (int j = 0; j < consum; ++j)
		{
			while(true)
			{
				c_dest = getchar();
				if (c_dest >= 'A' && c_dest <= 'Z') break;
			}
			scanf ("%d", &length);
			i_dest = c_dest - 'A';
			pq.push (rot (i_src, i_dest, length));
			++roadsum;
		}
	}

	int usedrot = 0, thelen = 0;

	while (usedrot < the_poisum - 1)	
	{
		rot r_temp = pq.top ();	

		if (!isconnect (&poi[r_temp.sr], &poi[r_temp.de]))
		{
			thelen += r_temp.len;
			++usedrot;
			connect (&poi[r_temp.sr], &poi[r_temp.de]);
		}
		pq.pop ();
	}
	printf ("%d\n", thelen);
	delete poi;

	return 0;
}

