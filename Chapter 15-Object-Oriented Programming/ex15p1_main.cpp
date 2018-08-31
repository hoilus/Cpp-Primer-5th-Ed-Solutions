#include "ex15p1_print.h"

int main(int argn, char *argv[]) {
  Quote itm("001-002-001", 11.2);
  cout << "book number is " << itm.isbn() 
       << ", sales price of one item is " << itm.net_price(1) << endl;

  return 0;
}
