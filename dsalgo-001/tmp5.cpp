/* ????????*/

#define MAXNUM 20

typedef int DataType;

struct ParTreeNode {
    DataType info;		/* ?????? */
    int     parent;	/* ???????? */
};

struct  ParTree { 
    int n;                 	/* ??????? */
    struct ParTreeNode nodelist[MAXNUM];  	/* ??????? */
};

typedef struct ParTree *PParTree;		/* ???????? */

int rightSibling_partree(PParTree t, int p) {
    int i;
    if (p >= 0 && p < t->n) {
        for (i = p+1; i <= t->n; i++)
            if (t->nodelist[i].parent == t->nodelist[p].parent)
                return i;
    }
    return -1;
}
