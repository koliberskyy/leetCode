//koliberskyy@yandex.ru
#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isValid(string s);
bool test();
void info();

int main()
{
	test();
	info();
	return 0;
}

void info()
{
	cout << "\"(\"="<< int('(') << endl;
	cout << "\")\"="<< int(')') << endl;
	cout << "\"[\"="<< int('[') << endl;
	cout << "\"]\"="<< int(']') << endl;
	cout << "\"{\"="<< int('{') << endl;
	cout << "\"}\"="<< int('}') << endl;
	cout << "\"(+)\"="<< int('(') + int(')') << endl;
	cout << "\"[+]\"="<< int(']') + int('[') << endl;
	cout << "\"{+}\"="<< int('{') + int('}') << endl;
}

bool isValid(string s)
{
	stack <char> st;
	//проверяем четность строки
	if((s.size()%2 != 0) || (s.size() == 0))
		return false;

	for(int i = 0; i < s.size(); i++)
	{
		if( (s[i] == '(') || (s[i] == '{') || (s[i] == '[') )
		{
			st.push(s[i]);
		}
		else if( (s[i] == ')') || (s[i] == '}') || (s[i] == ']') )
		{
			if(st.empty())
				return false;
			switch(s[i])
			{
				case ')':
					if(st.top() != '(')
						return false;
					break;
				case '}':
					if(st.top() != '{')
						return false;
					break;
				case ']':
					if(st.top() != '[')
						return false;
					break;
			}

			st.pop();
		}
		else
			return false;
	}
	if (st.empty())
		return true;
	else
		return false;
}

//unit-test*******
bool test()
{
	cout << "testing..." << endl;
	string s0 = "((";
	string s1 = "(){}[]";
	string s2 = "(){}}{";
	string s3 = "[]{}()[](){}[()][][][]";
	string s4 = "[][][][}[][]";
	int testComplited = 0;

	if(isValid(s0) == true)
	{
		cout << "test 1 failed" << endl;
		testComplited++;
	}
	if(isValid(s1) == false)
	{
		cout << "test 2 failed" << endl;
		testComplited++;
	}
	if(isValid(s2) == true)
	{
		cout << "test 3 failed" << endl;
		testComplited++;
	}
	if(isValid(s3) == false)
	{
		cout << "test 4 failed" << endl;
		testComplited++;
	}
	if(isValid(s4) == true)
	{
		cout << "test 5 failed" << endl;
		testComplited++;
	}
	if(testComplited == 0)
	{
		cout << "tests sucsess" << endl;
		return true;
	}
	else
	{
		return false;
	}
			
}
