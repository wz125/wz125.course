/* By Vamei */
/* binary search tree */
#include <stdio.h>
#include  <string.h>
#include <stdlib.h>
FILE *fp;

typedef struct node *position;
typedef int ElementTP;

struct node {
    position parent;
    ElementTP element;
    position lchild;
    position rchild;
};

/* pointer => root node of the tree */
typedef struct node *TREE;

void print_sorted_tree(TREE);
position find_min(TREE);
position find_max(TREE);
position find_value(TREE, ElementTP);
position insert_value(TREE, ElementTP);
ElementTP delete_node(position);

static int is_root(position);
static int is_leaf(position);
static ElementTP delete_leaf(position);
static void insert_node_to_nonempty_tree(TREE, position);

int main(void) 
{

        fp=stdin;

    	TREE tr;
    	position np;
    	ElementTP element;
    	tr = NULL;

        const int len = 1000;
        char buf[len];
		char tmp[10];
        fgets(buf, len, fp);
        buf[strlen(buf) - 1] = '\0';

		char * pch;
  		pch=buf;
		int pos=0;
		int start=0;
		printf("%s\n",buf);
  		while (start<strlen(buf))
  		{
			tmp[pos]=buf[start];
			if(tmp[pos]>'9'|| tmp[pos]<'0'){
				tmp[pos]='\0';
				//printf(">>>%s\n",tmp);
    			tr=insert_value(tr,atoi(tmp));
				pos=0;
			}else{
				pos++;
			}
			start++;
  		}
    		//tr = insert_value(tr, 18);
    print_sorted_tree(tr);
	printf("\n");
    np = find_value(tr, 8);
    if(np != NULL) {
        delete_node(np);
        printf("After deletio\n:\n");
        print_sorted_tree(tr);
    }

	return 0;
}


/* 
 * print values of the tree inn sorted order
 */
void print_sorted_tree(TREE tr)
{
    if (tr == NULL) return;
    printf("%d ", tr->element);
    print_sorted_tree(tr->lchild);
    //printf("%d ", tr->element);
    print_sorted_tree(tr->rchild);
	delete tr;
}

/*
 * search for minimum value
 * traverse lchild
 */
position find_min(TREE tr)
{
    position np;
    np = tr;
    if (np == NULL) return NULL;
    while(np->lchild != NULL) {
        np = np->lchild;
    }
    return np;
}

/*
 * search for maximum value
 * traverse rchild
 */
position find_max(TREE tr)
{
    position np;
    np = tr;
    if (np == NULL) return NULL;
    while(np->rchild != NULL) {
        np = np->rchild;
    }
    return np;
}

/*
 * search for value
 *
 */
position find_value(TREE tr, ElementTP value) 
{
    if (tr == NULL) return NULL; 

    if (tr->element == value) {
        return tr;
    }
    else if (value < tr->element) {
        return find_value(tr->lchild, value);
    }
    else {
        return find_value(tr->rchild, value);
    }
}

/* 
 * delete node np 
 */
ElementTP delete_node(position np) 
{
    position replace;
    ElementTP element;
    if (is_leaf(np)) {
        return delete_leaf(np);
    }   
    else {
        /* if a node is not a leaf, then we need to find a replacement */
        replace = (np->lchild != NULL) ? find_max(np->lchild) : find_min(np->rchild);
        element = np->element;
        np->element = delete_node(replace);
        return element;
    }
}

/* 
 * insert a value into the tree
 * return root address of the tree
 */
position insert_value(TREE tr, ElementTP value) {
    position np;
    /* prepare the node */
    np = (position) malloc(sizeof(struct node));
    np->element = value;
    np->parent  = NULL;
    np->lchild  = NULL;
    np->rchild  = NULL;
 
    if (tr == NULL) tr = np;
    else {
        insert_node_to_nonempty_tree(tr, np);
    }
    return tr;
}


//=============================================

/*
 * np is root?
 */
static int is_root(position np)
{
    return (np->parent == NULL);
}

/*
 * np is leaf?
 */
static int is_leaf(position np)
{
    return (np->lchild == NULL && np->rchild == NULL);
}

/* 
 * if an element is a leaf, 
 * then it could be removed with no side effect.
 */
static ElementTP delete_leaf(position np)
{
    ElementTP element;
    position parent;
    element = np->element;
    parent  = np->parent;
    if(!is_root(np)) {
        if (parent->lchild == np) {
            parent->lchild = NULL;
        }
        else {
            parent->rchild = NULL;
        }
    }
    free(np);
    return element;
}

/*
 * insert a node to a non-empty tree
 * called by insert_value()
 */
static void insert_node_to_nonempty_tree(TREE tr, position np)
{
    /* insert the node */
    if(np->element < tr->element) {
        if (tr->lchild == NULL) {
            /* then tr->lchild is the proper place */
            tr->lchild = np;
            np->parent = tr;
            return;
        }
        else {
            insert_node_to_nonempty_tree(tr->lchild, np);
        }
    }
    else if(np->element > tr->element) {
        if (tr->rchild == NULL) {
            tr->rchild = np;
            np->parent = tr;
            return;
        }
        else {
            insert_node_to_nonempty_tree(tr->rchild, np);
        }
    }else{
		delete np;
	}
}
