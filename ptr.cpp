
//
// Created by jojo on 2/23/23.
//

#include <iostream>
#include <stack>
#include <vector>

using namespace std;
int main() {
  int a[] = {1, 2, 3, 4, 5};
  int *p = a;

  cout << a[2] << endl;
  cout << p[0] << endl;
  p += 5;
  cout << p[0] << endl;
  return 0;
}