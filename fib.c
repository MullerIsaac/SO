#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int fib(int n) {
    if(n == 1) {
        return 0;
    } else if(n == 2) {
        return 1;
    } else {
        return fib(n-1) + fib(n-2);
    }
}

int main(int narg, char *argc[]) {

  if(narg < 3){
    printf("Poucos argumentos! ");
    exit(0);
  }

  int x = atoi(argc[1]);
  int y = atoi(argc[2]);
  int i; 

  for(i=x;x<=y; x++){
    printf("%d ", fib(x));
  }

  return 0;
}
