#include "linked_list.h"
/*
 * Linked list
 */

#include <stdio.h>		/* printf */
#include <stdlib.h>		/* malloc, free */
#include <assert.h>		/* assert */

/* functions to create lists */
node *make_node (int v, node * q)
{
  node *p = malloc (sizeof (node));
  p->value = v;

  if (q == &SENTINEL_node)
    p->next = &SENTINEL_node;
  else
    p->next = q;
  return p;
}

/* free all nodes in the list p */
void free_list (node * p)
{
  node *q = p;
  while (q != &SENTINEL_node)
    {
      node *t = q->next;
      free (q);
      q = t;
    }
}


/* print list to console */
void print_list (node * p)
{
  if (p == &SENTINEL_node) 
    return;
  else 
    printf("%d",p->value);
    print_list(p->next);
    return;

}

int sum_squares (node * p)
{
  int sum = 0;

  //If the end is reached 0 is returned
  if (p == &SENTINEL_node)
    return 0;
  else //calculate square of current value and add next value through a recursive function
    sum = square(p->value) + sum_squares(p->next);
    return sum;
    
}

node *map (node * p, int (*f) (int))
{
  //If the end is reached a sentinel-node is returned
  if (p == &SENTINEL_node)
    return &SENTINEL_node;
  else //Make a new node with the value from node p squared, and a new node
    return make_node(f(p->value),map(p->next,f));
    
}


int square (int x)
{
  return x * x;
}
