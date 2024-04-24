#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct CaseArg {
  int N;
  vector<int> As;
};

string solve(CaseArg ca) {
  int m = 0;
  int s = 0;
  for (int i = 0; i < ca.As.size(); i++) {
    m = max(m, ca.As[i]);
    s += ca.As[i];
  }
  if (m * 2 > s || (s & 1) == 1) {
    return "T";
  }
  return "HL";
}

void runCase(istream& in, ostream& out) {
  int case_num;
  in >> case_num;
  for (int i = 0; i < case_num; i++) {
    CaseArg ca;
    in >> ca.N;
    ca.As.resize(ca.N);
    for (int i = 0; i < ca.N; i++) {
      in >> ca.As[i];
    }
    out << solve(ca) << endl;
  }
}

void testCases() {
  ifstream fin;
  ofstream fout;
  fin.open("input.txt", ios::in);
  fout.open("output.txt", ios::out);
  int cases_num = 1;
  for (int i = 0; i < cases_num; i++) {
    runCase(fin, fout);
  }
}

int main() {
  // testCases();
  runCase(cin, cout);
}