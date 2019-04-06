#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

template <typename T>
class disjoint_set 
{
  vector<T> rank,size;
  vector<T> parent;
  
  public:
    unordered_set<T> leader;
    
  void makeset(T n) 
  {
      rank.resize(n);
      parent.resize(n);
      size.resize(n);
      for (T i = 1; i <= n; i++) 
      {
        parent[i] = i;
        rank[i] = 0;
        size[i] = 1;
        leader.insert(i);
      }
  }

  T find(T i) 
  {
    if (parent[i] != i)
      parent[i] = find(parent[i]);
    return parent[i];
  }

  void merge(T x,T y) 
  {
   T x_root = find(x);
   T y_root = find(y);
    if (x_root != y_root) 
    {
      if (size[x_root] < size[y_root])
        {
            parent[x_root] = y_root;
            size[y_root] += size[x_root];
            leader.erase(x_root);
            
       }
       else if (size[x_root] > size[y_root])
        {
         parent[y_root] = x_root;
         size[x_root] += size[y_root];
         leader.erase(y_root);

        }
        else 
        {
          parent[y_root] = x_root;
          rank[x_root]++;
          size[x_root] += size[y_root];
          leader.erase(y_root);
          
        }
      }
    }

    T getsize(T x)
    {
        return size[find(x)];

    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    long int n,q;
    cin>>n>>q;
    disjoint_set ds;
    ds.makeset(n);
    return 0;
}
