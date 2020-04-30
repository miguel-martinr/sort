#include "../include/ISBN.hpp"

unsigned long ISBN::cmpCount_;

ISBN::ISBN(void) {
    srand(time(NULL));
    num_ = rand() % 10000000000;
}

ISBN::ISBN(unsigned long num) {
  num_ = num;
}

void ISBN::operator=(const ISBN& A) {
  setNum(A.getNum());
}

bool ISBN::operator==(const ISBN& A) {
  cmpCount_++;
  return (getNum() == A.getNum());
}

bool ISBN::operator<(const ISBN& A) {
  cmpCount_++;
  return (getNum() < A.getNum());
}

bool ISBN::operator>(const ISBN& A) {
  cmpCount_++;
  return (getNum() > A.getNum());
}
