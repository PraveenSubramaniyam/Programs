#define MAXLEN 1024
typedef struct {
  char digits[MAXLEN];
  int noOfDigits;
}myInteger;

void memsetMyIntegertoZero(myInteger *myInt);
void leftshift(myInteger *a, int b);
void stripZero(myInteger *num);
void add(myInteger num1,int aCounter, myInteger num2,int bCounter, myInteger *result,int cCounter,int carry);
void divide(myInteger *a , myInteger *b, myInteger *c,myInteger *m);
int ComparemyInteger(myInteger int1, myInteger int2);
int  subtract(myInteger *a, int aCounter , myInteger *b, int bCounter,myInteger *c, int cCounter , int borrow);
