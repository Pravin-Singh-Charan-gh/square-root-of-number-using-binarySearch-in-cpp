#include <iostream>
using namespace std;
float
sqdec (int n, float ans, int prec)
{
  float factor = 1;
  for (int i = 1; i <= prec; i++)
    {
      factor = factor / 10;
      for (float j = ans; j * j <= n; j = j + factor)
	ans = j;
    }
  return ans;
}

float
sqroot (int n)
{
  int s = 0, e = n, mid = s + (e - s) / 2;
  int ans;
  while (s <= e)
    {
      int sq = mid * mid;

      if (sq == n)
	return mid;
      if (sq < n)
	{
	  ans = mid;
	  s = mid + 1;
	}
      else
	e = mid - 1;
      mid = s + (e - s) / 2;
    }
  if (ans * ans == n)
    return ans;
  else
    return sqdec (n, ans, 3);
}

int
main ()
{
  int n;
  cout << "Enter number to find square root : ";
  cin >> n;
  if (n < 0)
    cout << "Imaginary root.";
  else
    cout << "Square root of " << n << " is " << sqroot (n);
  return 0;
}
