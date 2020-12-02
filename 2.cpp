#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class pw_line {
  public:
    int bottom_int;
    int top_int;
    char letter;
    string pw; 

    pw_line(int bottom_int, int top_int, char letter, string pw) {
      this->bottom_int = bottom_int;
      this->top_int = top_int;
      this->letter = letter;
      this-> pw = pw;
    }

    int validateChar(int index) {
      if(pw.size() +  1 > index && pw.at(index - 1) == letter) {
        return 1;
      }
      return 0;
    }

    int validatePassword(void) {
      int num_char = 0;

      for(int i = 0; i < pw.size(); i ++) {
        if(pw.at(i) == letter) {
          // the character we should count 
          num_char++;
        }
      }
    
      if(validateChar(bottom_int) + validateChar(top_int) == 1) {
          return 1;
      }

      return 0;
    }

};



int main() {
    // line comes in the format of bottom_int-top_int letter: password
    string filename = "2.txt";
    ifstream infile;
    infile.open(filename);
    if(!infile) {
      cout << "unable to open " << filename << endl;
      exit(1);
    }

    string bounding_ints, dirty_letter, password;
    int breaker = 0; 
    int counter = 0;

    while (infile >> bounding_ints >> dirty_letter >> password) {
      int bottom_int, top_int;
      bottom_int = stoi(bounding_ints.substr(0, bounding_ints.find("-")));
      top_int = stoi(bounding_ints.substr(bounding_ints.find("-") + 1, bounding_ints.size() - 1));

      pw_line pw(bottom_int, top_int, dirty_letter.at(0), password);
      if(pw.validatePassword()) {
        counter++;
      }
    }

    cout << "counter" << counter << endl;
    return 0;
}
      

