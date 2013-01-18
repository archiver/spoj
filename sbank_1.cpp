#include <iostream>
#include <algorithm>
#include <string>
#include <stdio.h>

#define N 100000
using namespace std;

struct node
{
  bool isleaf;
  int count;
  node* ptrs[10];
  node():isleaf(false),count(0)
  {
    for(int i=0;i<10;++i) ptrs[i]=NULL;
  }
};

struct trie
{
   node* head;
   trie()
   {
     head=new node();
   }

   void insert(string s)
   {
     node* iter=head;
     int pos;
     for(int i=0;i<s.size();++i)
     {
       if(s[i]==' ') continue;
       pos=s[i]-'0';
       if(!iter->ptrs[pos])
         iter->ptrs[pos]=new node();
       iter=iter->ptrs[pos];
     }
     iter->isleaf=true;
     iter->count+=1;
   }

   void traverse(node* iter, string cur, int pos)
   {
     if(!iter) return;
     if(iter->isleaf)
     {
       cout<<iter->count<<" "<<cur<<endl;
       return;
     }

     for(int i=0;i<10;++i)
     {
       cur[pos]=i+'0';
       traverse(iter->ptrs[i],cur,pos+1);
     }
   }

   void present()
   {
     string cur(26,'0');
     int pos=0;
     traverse(head,cur,0);
   }
};

int main()
{
  int t;
  scanf("%d\n",&t);
  trie T;
  string s;
  for(int i=0;i<t;++i)
  {
    getline(cin,s);
    T.insert(s);
  }
  T.present();
  return 0;
}
