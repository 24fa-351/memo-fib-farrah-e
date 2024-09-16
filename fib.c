#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long long int fi[100];
unsigned long long int printRecursionWrap(int n){
   unsigned long long int fibcur;
   if (fi[n] != 0){
    return fi[n];
   }
   if (n == 1){
      fibcur= 0;
   } else
   if (n == 2){
      fibcur = 1;
   }
   else{
      fibcur = (printRecursionWrap(n-1)+printRecursionWrap(n-2));
   }
   return fibcur;
}

unsigned long long int printIterationWrap(int n){
   if (fi[n] != 0){
    return fi[n];
   }
   if (n<=1){
      return 0;
   } else if(n==2){
      return 1;
   }
   unsigned long long int term1=0, term2=1, curfib;
   for (int i = 3; i <= n; i++){
      curfib = term1 + term2;
      term1 = term2;
      term2 = curfib;
   }
   return curfib;
}

// unsigned long long int fibWrapper(unsigned long long int n, (*fibFunc)(unsigned long long int)){
//    return fibFunc(n);
// }
unsigned long long int fibSequence(char s, int n){
   if (fi[n] != 0){
    return fi[n];
   }
      if(s == 'i'){
         fi[n] = printIterationWrap(n);
      } else{
         fi[n] = printRecursionWrap(n);
      }
   return fi[n];
}
int main(int argc, char *argv[]) {
   unsigned long long int fibN;
   int numInputted = atoi(argv[1]);
   char ir = argv[2][0];
   fibN = fibSequence(ir, numInputted);
   printf("%llu\n", fibN);
   return 0;
}