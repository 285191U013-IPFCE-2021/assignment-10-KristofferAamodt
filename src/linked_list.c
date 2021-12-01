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

  if (q == NULL)
    p->next = NULL;
  else
    p->next = q;
  return p;
}

/* free all nodes in the list p */
void free_list (node * p)
{
  node *temp = p;
  while (p != NULL)
    {
      temp = p;
      p = p->next;
      free (temp);
    }
    p = NULL;
}


/* print list to console */
void print_list (node * p)
{
  if (p->next == NULL) 
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
  if (p == NULL)
    return 0;
  else //calculate square of current value and add next value through a recursive function
    sum = square(p->value) + sum_squares(p->next);
    return sum;
    
}

node *map (node * p, int (*f) (int))
{
  //If the end is reached a sentinel-node is returned
  if (p == NULL)
    return 0;
  else //Make a new node with the value from node p squared, and a new node
    return make_node(f(p->value),map(p->next,f));
    
}


int square (int x)
{
  return x * x;
}
