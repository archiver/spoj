#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
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

map<char,int> preced;
set<char> rassoc;
set <char> braces;
typedef pair<char,int> pci;

void convert(string &exp)
{

 
  stack<char> opstack;
  vector<char> output;
  tr(exp,it)
  {
    if(present(preced,*it)) //operator
    {
      bool left=!present(rassoc,*it);
      if(left)
      {
        char top;
	int precedence=preced.find(*it)->second;
        while(!opstack.empty() && opstack.top()!='(')
	{ 
	  top=opstack.top();
	  if(preced.find(top)->second>=precedence)
	  {
	    output.pb(top);
	    opstack.pop();
	  }
	  else
	    break;
	}
      }
      else
      {
        char top;
	int precedence=preced.find(*it)->second;
        while(!opstack.empty() && opstack.top()!='(')
	{ 
	  top=opstack.top();
	  if(preced.find(top)->second>precedence)
	  {
	    output.pb(top);
	    opstack.pop();
	  }
	  else
	    break;
	}
     
      }
      opstack.push(*it);
    }
    else if(present(braces,*it)) //braces
    {
      if(*it=='(') opstack.push('(');
      else
      {
        char top;
        while(!opstack.empty())
	{
	  top=opstack.top();
	  if(top!='(')
	  {
	    output.pb(top);
	    opstack.pop();
	  }
	  else
	  {
	    opstack.pop();
	    break;
	  }
	}
      }
    }
    else //token
    {
      output.pb(*it);
    }
  }

  while(!opstack.empty())
  {
    output.pb(opstack.top());
    opstack.pop();
  }

  tr(output,itr)  cout<<*itr;
  cout<<endl;
}

void init()
{
  preced.insert(pci('+',0));
  preced.insert(pci('-',0));
  preced.insert(pci('*',1));
  preced.insert(pci('/',1));
  preced.insert(pci('^',2));

  rassoc.insert('^'); 

  braces.insert('(');
  braces.insert(')');
}

int main()
{
  int cases;
  string input;
  cin>>cases;
  init();
  for(int i=0;i<cases;++i)
  {
    cin>>input;
    convert(input);
  }
  return 0;
}
