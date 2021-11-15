#include "btree.h"

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>


struct tree_node * Insert (int x, struct tree_node *t)
{
  // Insert item x into the tree t
  if(Empty(t)) 
  {
    //Insert item x into node and initialize left and right node
    t->item=x;
    t->left=Initialize(t->left);
    t->right=Initialize(t->right);
    return NULL;
  }
  else //Resend the left of right node, dependent on the size of the item x
  {
    if(x>t->item) //Either left or right leaf
    {
      Insert(x,t->right);
      return NULL;
    }
    else 
    {
      Insert(x,t->left);
      return NULL;
    }

  }

}


struct tree_node * Remove (int x, struct tree_node *t)
{
  //If the value is not in the tree, the operation is cancelled and nothing happens
  //What happens if one wants to remove a value that are not a leaf?
  if (Contains(x,t)==0){
    return NULL;
  }
  else if(Empty(t)){ //Check if a leaf is reached
    return NULL;
  }
  else{
    if(x>t->item){ //Goes right way
        return Remove(x,t->right); //Resend the right node
    }
    else if(x=t->item){ //Remove value
      if (t->left->left == NULL){ 
        free(t->left->left);
        free(t->left->right);
        t->left = NULL;
        return NULL;
      } 
      else{
        return Remove(x,t->left);
      }
    }

  }  

  return NULL;
}


int Contains (int x, struct tree_node *t)
{
  // Return true if the tree t contains item x. Return false otherwise.
  
  //If a leaf is reached, return false
  if(Empty(t)) 
  {
    return 0;
  }
  else 
  {
    if(t->item==x) //Positive answer if the value is found
    {
      return 1;
    }
    else //If not, check the right or left node, depending on x being bigger or smaller than the current value
    {
      int answer = 0;
      if(x>t->item) 
      {
        answer = Contains(x,t->right); 
      }
      else 
      {
        answer = Contains(x,t->left);
      
      }

      return answer;
    }

  }

}


struct tree_node * Initialize (struct tree_node *t)
{
  //A initialized node will have a left and a right branch consisting of NULL
  struct tree_node *element = (struct tree_node*) malloc(sizeof(struct tree_node));
  element->left=NULL;
  element->right=NULL;
  return element;

}

int Empty (struct tree_node *t)
{
  //If the tree node does not have any items, it is empty
  if(t->left && t->right==NULL)
    return 1;
  else
    return 0; 
}

int Full (struct tree_node *t)
{
    //I do not get what the full function should do? Are there defined any maximal number of nodes in the three?
    return 0;
}
