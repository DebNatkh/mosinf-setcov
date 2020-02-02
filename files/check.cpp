#include <vector>
#include <string>
#include <set>
#include "testlib.h"
#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
  registerTestlibCmd(argc, argv);
  int n = 10;
  string anst, ost;
  int bugs = 0;
  for (int i = 0; i < n; ++i) {
      anst = ans.readWord();
      ost = ouf.readWord();
      if (anst != ost)
          bugs++;
      
  }
  double score = max(0, 30 - bugs * 3);
  quitp(score, "participant's solution is ok");

  return 0;
} 