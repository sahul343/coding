#include<bits/stdc++.h>
using namespace std;
int
main ()
{
  int n;
  cin >> n;
  string s;
  cin >> s;
  int l = 0, r = 0;
  for (int i = 0; i < s.size (); i++)
    {
      if (s[i] == 'L')
	l++;
      else
	r++;
    }
  int ans = r + l + 1;
  cout << ans << endl;
  return 0;
}
