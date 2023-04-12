#include <iostream>
#include <vector>
using namespace std;
bool is_ip(vector<int> &ip) {
  for (int i = 0; i < 4; ++i) {
    if (ip[i] > 255 || ip[i] < 0)
      return false;
  }
  return true;
}
bool is_mask(vector<int> &mask) {
  unsigned b = 0;
  for (int i = 0; i < 4; ++i)
    b = (b << 8) + mask[i];
  if (!b)
    return false;
  b = ~b + 1;
  if (b == 1)
    return false;
  if ((b & (b - 1)) == 0)
    return true;
  return false;
}
int main() {
  vector<int> mask(4);
  vector<int> ip1(4);
  vector<int> ip2(4);

  char ch;
  while (cin >> mask[0] >> ch >> mask[1] >> ch >> mask[2] >> ch >> mask[3]) {

    int res = 0;

    cin >> ip1[0] >> ch >> ip1[1] >> ch >> ip1[2] >> ch >> ip1[3];
    cin >> ip2[0] >> ch >> ip2[1] >> ch >> ip2[2] >> ch >> ip2[3];
    if (!(is_ip(mask) && is_mask(mask) && is_ip(ip1) && is_ip(ip2)))
      res = 1;

    if (res == 0) {
      for (int i = 0; i < 4; ++i) {
        int num1 = ip1[i] & mask[i];
        int num2 = ip2[i] & mask[i];
        if (num1 != num2) {
          res = 2;
          break;
        }
      }
    }

    cout << res << endl;
  }
}
// 64 位输出请用 printf("%lld")