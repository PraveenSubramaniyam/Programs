#define MAXLEN 1024
typedef struct {
  char digits[MAXLEN];
  int noOfDigits;
}myInteger;


void trimSlash(char *source);
void memsetMyIntegertoZero(myInteger *myInt);
void generateMyInteger(myInteger *num, char *str);
void leftshift(myInteger *num, int count);
void stripZero(myInteger *num);
void add(myInteger num1,int aCounter, myInteger num2,int bCounter, myInteger *result,int cCounter,int carry);
void divide(myInteger *a , myInteger *b, myInteger *c,myInteger *m);
int ComparemyInteger(myInteger int1, myInteger int2);
void subtract(myInteger *num1, int num1Count, myInteger *num2, int num2Count, myInteger *result, int resCount, int borrow);
