#include <bits/stdc++.h>

using namespace std;

template <typename T>
class disjoint_set
{
  struct node {
    T data;
    long int rank;
    long int size;
    node *parent;
  };
  unordered_map<T, node *> elements;
public:

  unordered_set<T> leader;   
  
  void makeset(long int n)
    { 
      for(T i=0;i<n;i++)
      { node* np = new node;
        np->parent = np;
        np->data = i;
        np->rank = 0;
        np->size = 1;
        leader.insert(i);
        elements[i] = np;
      }
      
    }

  node* find(node*a)
  {
     if(a->parent != a)
     {
         a->parent = find(a->parent);
     }
   return a->parent;  
  }

  void merge(node*a, node*b)
  {
      node* a_root = find(a);
      node* b_root = find(b);
     if(a_root != b_root)
      {
          if(a_root->size > b_root->size)
        {
          b_root->parent = a_root;
          a_root->size += b_root->size;
          leader.erase(b_root->data);
        }
      else if(b_root->size > a_root->size)
        {
        a_root->parent = b_root;
        b_root->size += a_root->size;
        leader.erase(a_root->data);
        }
      else if(a_root->size == b_root->size)
        {
        b_root->parent = a_root;
        a_root->size += b_root->size; 
        a_root->rank++;
        leader.erase(b_root->data);
        }
      
      }
  }

  void merge(T a,T b)
  {
      return merge(elements[a], elements[b]);
  }
  
  T getsize(T num)
  {
    return find(elements[num])->size;
    
  }
};
