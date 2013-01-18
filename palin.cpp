#include <iostream>
#include <string>

using namespace std;

string reverse(string &ii)
{
    string res;
    for(int i=ii.size()-1;i>=0;--i) res.push_back(ii[i]);
    return res;
}

string incr(string &ii)
{
    int carry=1,sum=0;
    string res;
    int i;
    for(i=ii.size()-1;i>=0 && carry;--i)
    {
	sum=carry+(ii[i]-'0');
	if(sum>=10) 
	{
	    sum=sum-10;
	    carry=1;
	}
	else carry=0;
	res.push_back(sum+'0');
    }


    for(;i>=0;--i)
	res.push_back(ii[i]);

    if(carry) res.push_back('1');

    return reverse(res);
}

string nextPalin(string &num)
{
    int n=num.size();
    string temp(n,'9');

    if (num==temp) 
    {
	string res(n+1,'0');
	res[0]='1';
	res[n]='1';
	return res;
    }

    if (n%2==0)
    {
	string left=num.substr(0,n/2);
	string right=num.substr(n/2,n/2);

	string lrev=reverse(left);

	if(right<lrev)
	    return left+lrev;

	else
	{
	    string lstr=incr(left);
	    string rstr=reverse(lstr);
	    return lstr+rstr;
	}
    }

    else
    {
	string left=num.substr(0,n/2);
	string right=num.substr(n/2+1,n/2);
        
	string lrev=reverse(left);
	string mid;

	if (right==lrev)
	{
	    mid.push_back(num[n/2]=='9'?'0':num[n/2]+1);

	    if(num[n/2]!='9')
		return left+mid+right;
	}

	mid.clear();
	mid.push_back(num[n/2]);

	if(right<lrev) return left+mid+lrev;

	else
	{
	    if(num[n/2]!='9')
	    {
	      string lrev=reverse(left);
	      mid.clear();
	      mid.push_back(num[n/2]=='9'?'0':num[n/2]+1);
	      return left+mid+lrev;
	    }

	    string lstr=incr(left);
	    string rstr=reverse(lstr);
	    return lstr+"0"+rstr;
	}
    }
}

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;++i)
    {
	string s;
	cin>>s;
	cout<< nextPalin(s) <<endl;
    }
    return 0;
}
