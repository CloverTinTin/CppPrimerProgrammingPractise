#include <iostream>
#include <string>
#include <stack>
using namespace std;

void replaceParenthesisExpr(string &expr)
{
    stack<char> stk;
    int seen = 0;
    for(char c: expr)
    {
	if(c != ')')
	{
	    stk.push(c);
	    if(c == '(')
		++seen;
	}
	else if(seen > 0)
	{
	    while(stk.top() != '(')
		stk.pop();
	    stk.pop();
	    --seen;
	    stk.push('#');
	}
    }
    expr.clear();
    while(!stk.empty())
    {
	expr.insert(expr.begin(), stk.top());
	stk.pop();
    }
}

int main()
{
    string expr = "abc(kjdakjfka)jfjak) jkall (kkkd) hfjd";
    cout << expr << endl;
    replaceParenthesisExpr(expr);
    cout << expr << endl;
    return 0;
}
