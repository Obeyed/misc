#include <iostream>
#include <assert.h>
using namespace std;

/**
  Compile with `g++ string-shift.cpp -o string-shift.out`,
  and run tests with  `./string-shift.out`

  Implement a class that does string manipulation by overloading the following 
  operators: <<, >>, = and ==. 
  For example consider the following code:
 
    StrShift example;
    example = “Microsoft”;
    printf(“\”example &lt;&lt; 2\” results in %s\n“, example &lt;&lt; 2);
 
  In the above code the output would be “ftMicroso” which shows the last two 
  characters of the string “Microsoft” rotated to the left of the string.  
  Please note that state is maintained so two calls of example << 1 would give 
  the same end result as calling example << 2 once.
*/
class StrShift {

  private:
    string str;
    unsigned int size;

    // Compute shift value. If size is 0 returns 0;
    unsigned int get_shift(const unsigned int n) {
      unsigned int result = 0;
      if (size)
        result = n % size;
      return result;
    };

    // Modifies the string w.r.t. the shift index
    string transform(unsigned int idx, const bool rshift) {
      if (rshift)
        idx = size - idx;
      return str = str.substr(idx) + str.substr(0, idx);
    };

  public:
    StrShift() { 
      str = ""; 
      size = 0;
    };

    ~StrShift() { };

    // Assignment
    void operator = (const string& x) {
      str = x;
      size = str.length();
    };

    // Equality
    bool operator == (const string& x) {
      return (str.compare(x) == 0);
    };

    // Left shift string representation (rotate/wrap string)
    string operator << (const unsigned int n) {
      return transform(get_shift(n), false);
    };

    // Right shift string representation (rotate/wrap string)
    string operator >> (const unsigned int n) {
      return transform(get_shift(n), true);
    };
};

int main(void) {
  string test_string = "This is a test";
  StrShift example;
  example = test_string;

  // should not change
  assert ((example << 0) == test_string);
  assert ((example >> 0) == test_string);
  // complete wrapping
  assert ((example << test_string.length()) == test_string);
  assert ((example >> test_string.length()) == test_string);

  // equality
  assert (example == test_string);
  example << 1;
  assert (!(example == test_string));
  example >> 1;

  // single steps should equal large step
  assert ((example << 1) == "his is a testT");
  assert ((example << 1) == "is is a testTh");
  assert ((example << 1) == "s is a testThi");
  assert ((example << 1) == " is a testThis");
  assert ((example << 1) == "is a testThis ");
  assert ((example >> 1) == " is a testThis");
  assert ((example >> 1) == "s is a testThi");
  assert ((example >> 1) == "is is a testTh");
  assert ((example >> 1) == "his is a testT");
  assert ((example >> 1) == "This is a test");

  // large step
  assert ((example << 5) == "is a testThis ");
  assert ((example >> 5) == "This is a test");

  // handling empty strings
  example = "";
  assert (example == "");
  assert ((example << 2) == "");
  assert ((example >> 3) == "");

  return 0;
};
