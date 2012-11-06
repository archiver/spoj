#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())

typedef pair<char,int> pc;
map<char,int> preced;

struct node
{
  char val;
  node *left,*right;
  node(char v):val(v),left(NULL),right(NULL){}
};

struct ast
{
  node* root;
  string output;
  ast():root(NULL){}
  ast(string p) { build(p);}
  void build(string p);
  void inorder(node* start);
  string clean() { inorder(root); return output;}
};

void init()
{
  preced.insert(pc('+',0));
  preced.insert(pc('-',0));
  preced.insert(pc('*',1));
  preced.insert(pc('/',1));
}

string postfix(string &e)
{
  stack<char> opstack;
  string output;
  for(int i=0;i<e.size();++i)
  {
    if(present(preced,e[i]))
    {
      char top;
      int precedence=preced.find(e[i])->second;
      while(!opstack.empty())
      {
        top=opstack.top();
	if(top=='(')
	{
	  opstack.pop();
	  break;
	}
	if(preced.find(top)->second>=precedence)
	{
	  output.pb(top);
	  opstack.pop();
	}
      }
   
      opstack.push(e[i]); 
    }

    else if(e[i]==')')
    {
      char top;
      while(!opstack.empty())
      {
        top=opstack.top();
	if(top=='(') {opstack.pop(); break;}
	output.pb(top);
	opstack.pop();
      }
    }

    else if(e[i]=='(') opstack.push('(');

    else output.pb(e[i]);
  }

  return output;
}

void ast::build(string p)
{
  int sz=p.size();
  stack<node*> estack;
  node *right,*left;

  tr(p,it)
  {
    node *n=new node(*it);

    if(present(preced,*it))
    {
      right=estack.top();
      estack.pop();
      left=estack.top();
      estack.pop();
 
      n->left=left;
      n->right=right;
    }

    estack.push(n);
  }

  root=estack.top();
  estack.pop();
  //assert(estack.empty());
}

void ast::inorder(node* start)
{
  if(!start) return;

  node* left=start->left;
  node* right=start->right;
  //strictly higher precendence affects left & right for / & *
  if(present(preced,start->val))
  {
    if(left && present(preced,left->val))
    {
      if(preced[start->val]>preced[left->val])
      {
        output.pb('(');
        inorder(left);
        output.pb(')');
      }
      else inorder(left);
    }
    else inorder(left);

    output.pb(start->val);

    if(right && present(preced,right->val))
    {
      if(preced[start->val]>preced[right->val])
      {
        output.pb('(');
        inorder(right);
        output.pb(')');
      }
     //equal precedence affects right for / & -
      else if((start->val=='-' || start->val=='/') && \
      preced[start->val]==preced[right->val]) 
      { 
        output.pb('(');
	inorder(right);
	output.pb(')');
      }
      else inorder(right);
    }
    else inorder(right);
  }

  else
  {
    inorder(left);
    output.pb(start->val);
    inorder(right);
  }
}

int main()
{
  int cases;
  string s;
  cin>>cases;
  init();
  for(int i=0;i<cases;++i)
  {
    cin>>s;
    ast syntree(postfix(s));
    cout<< syntree.clean() <<endl;
  } 
  return 0;
}
