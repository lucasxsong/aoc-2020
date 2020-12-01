#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
  ifstream ifile;
  string filename = "1.txt";
  ifile.open(filename);
  if(!ifile) {
    cout << "unable to open " << filename << endl;
    exit(1);
  }

  int x;
  vector<int> v;

  while(ifile >> x) {
    v.push_back(x);
  }

  for(int i = 0; i < v.size(); i++) {
    for (int j = 0; j < v.size(); j++) {
      for (int k = 0; k < v.size(); k++) {
        if(v.at(i) + v.at(j) + v.at(k) == 2020) {
          cout << "Product of " << v.at(i) << ", " << v.at(j) << " and " << v.at(k) << " is " << v.at(j) * v.at(i) * v.at(k) << endl;
        }
    }
    }
  }

  return 0;
}
  

