#include <iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>

using namespace std;

string oper = "*+-/";
string num = "123456789";

constexpr auto eps = 1e-6;

vector<string> operands;
vector<string> numbers;

void genOperands(int n, string s)
{
	if (s.size() == 3)
	{
		do
		{
			operands.push_back(s);

		} while (next_permutation(s.begin(), s.end()));
	}

	for (int i = n; i < 4 and s.size() < 3; i++)
	{
		genOperands(i, s + oper[i]);
	}
}

void genNumbers(int n, string s)
{
	if (s.size() == 4)
		numbers.push_back(s);

	for (int i = n; i < 9 and s.size() < 4; i++)
	{
		genNumbers(i + 1, s + num[i]);
	}
}

bool isOperand(char c)
{
	return c == '+' or c == '-' or c == '*' or c == '/';
}

double evaluate(string& notation)
{
	stack<double> s;
	bool flag = true;

	for (auto a : notation)
	{
		if (isOperand(a))
		{
			double num2 = s.top();
			s.pop();

			double num1 = s.top();
			s.pop();

			if (num2 < eps)
				return -1;

			switch (a)
			{
			case '+':
				s.push(num1 + num2);
				break;
			case '-':
				s.push(num1 - num2);
				break;
			case '*':
				s.push(num1 * num2);
				break;
			case '/':
				s.push(num1 / num2);
				break;
			}
		}
		else
		{
			int num = a - '0';
			s.push(num);
		}
	}

	return s.top();
}

string findSet()
{
	int mx = 0;
	double res[5];

	string ans;

	for (auto i : numbers)
	{
		int nums[3500] = { 0 };

		do
		{
			string expr = "       ";

			for (auto j : operands)
			{
				expr[2] = j[0], expr[5] = j[1], expr[6] = j[2];
				expr[0] = i[0], expr[1] = i[1], expr[3] = i[2], expr[4] = i[3];
				res[0] = evaluate(expr);

				expr[2] = j[0], expr[4] = j[1], expr[6] = j[2];
				expr[0] = i[0], expr[1] = i[1], expr[3] = i[2], expr[5] = i[3];
				res[1] = evaluate(expr);

				expr[3] = j[0], expr[4] = j[1], expr[6] = j[2];
				expr[0] = i[0], expr[1] = i[1], expr[2] = i[2], expr[5] = i[3];
				res[2] = evaluate(expr);

				expr[3] = j[0], expr[5] = j[1], expr[6] = j[2];
				expr[0] = i[0], expr[1] = i[1], expr[2] = i[2], expr[4] = i[3];
				res[3] = evaluate(expr);

				expr[4] = j[0], expr[5] = j[1], expr[6] = j[2];
				expr[0] = i[0], expr[1] = i[1], expr[2] = i[2], expr[3] = i[3];
				res[4] = evaluate(expr);

				for (auto k : res)
					if (k > 0 and fabs(k - (int)k) < eps)
						nums[(int)k]++;
			}

		} while (next_permutation(i.begin(), i.end()));

		int it = 1;
		int count = 0;

		while (nums[it++])
			count++;

		if (count > mx)
		{
			mx = count;
			ans = i;
		}
	}

	return ans;
}

int main()
{
	genOperands(0, "");
	genNumbers(0, "");

	cout << findSet() << endl;

	return 0;
}