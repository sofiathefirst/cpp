#include <string>
#include <string.h>
#include "kv.pb.h"
#include "head.pb.h"
#include <iostream>
using namespace std;
 
int main(int argc, char** argv)
{
  kv k;
  k.set_key("company");
  k.set_value("leoox");
 
  cout << k.key() << ":" << k.value() << endl;
 
  head h;
  h.set_type(2014);
  h.set_st("good luck");
  cout << h.type() << ":" << h.st() << endl;
  return 0;
}