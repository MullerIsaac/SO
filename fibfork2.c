#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

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
  int i, j;

  if(x <0 || y <0){
    printf("Erro: Argumentos negativos!");
    exit(0);
  }

  i = x+(y-x)/2;
  j =i+1;

  pid_t pID = fork();

  if(pID == 0){
    pid_t pID2 = fork();
    if(pID2 == 0){
      for(x=x;x<=i; x++){
        printf("%d ", fib(x));
      }
      printf("\n");
    }else{
      sleep(5);
      wait(NULL);
      for(j=j;j<=y; j++){
        printf("%d ", fib(j));
      }
    }
  }else{
    sleep(5);
    wait(NULL);
  }

  return 0;
}
