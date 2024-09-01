#include <bits/stdc++.h>
using namespace std;

int findMinimumCost(string str)
{
  // Write your code here
  if (str.size() % 2 != 0)
  {
    // odd length
    return -1;
  }
  stack<char> check;
  int open = 0;
  int close = 0;
  for (auto i : str)
  {
    if (i == '{')
    {
      check.push(i);
    }
    else
    {
      if (check.empty())
      {
        check.push(i);
      }
      else if (check.top() == '{')
      {
        check.pop();
      }
      else
      {
        check.push(i);
      }
    }
  }

  while (!check.empty())
  {
    char element_at_top = check.top();
    if (element_at_top == '{')
    {
      open++;
    }
    else
    {
      close++;
    }
    check.pop();
  }

  int cost = 0;
  if (open != 0 && close == 0)
  {
    // only open braces
    cost = open / 2;
  }
  else if (open == 0 && close != 0)
  {
    // only close braces
    cost = close / 2;
  }
  else
  {
    // Both Present
    if (open % 2 == 0 && close % 2 == 0)
    {
      cost = (open + close) / 2;
    }
    else
    {
      cost = ((open + close) / 2) + 1;
    }
  }
  return cost;
}

int main(void)
{

  /*
  5
{{{}
{{}{}}
{}}{}}
{{{{
{{{}}

  */
  string expression = "{}}{}}";
  int answer = findMinimumCost(expression);
  cout << answer << endl;
}