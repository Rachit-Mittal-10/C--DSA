#include <bits/stdc++.h>
using namespace std;

int celebrity(vector<vector<int>> &M, int n)
{
  // code here
  stack<int> Person;
  for (int i = 0; i < n; i++)
  {
    Person.push(i);
  }
  int A, B;
  while (Person.size() != 1)
  {
    A = Person.top();
    Person.pop();
    B = Person.top();
    Person.pop();
    if (M[A][B]){
      Person.push(B);
    }
    else if(M[B][A]){
      Person.push(A);
    }else{
      Person.push(A);
      Person.push(B);
    }
  }
  if (Person.size() == 0)
  {
    return -1;
  }
  else
  {
    return Person.top();
  }
}

int main(void)
{
  vector<vector<int>> Celeb(3,vector<int>(3,0));
  cout << celebrity(Celeb,3) << endl;
}