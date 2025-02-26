#include <stdio.h>
#include <stdlib.h>

typedef int (*operation_ptr)(int x, int y);

int calculator(int x, int y, operation_ptr operation);

int sum(int x, int y);

int sub(int x, int y);

int mul(int x, int y);

int divider(int x, int y);

int main() {
    int x = 0;
    int y = 0;
    char op = '\0';
    scanf("%d %c %d", &x, &op, &y);

    switch(op){
        case'+':
        printf("%d", calculator(x, y, sum));
        case '-':
        printf("%d", calculator(x, y, sub));
        case '*':
       printf("%d", calculator(x, y, mul));
       case '/':
       printf("%d", calculator(x, y, divider));
    }
    printf("\n");
    return 0;
}

int sum(int x, int y) { return x + y; }

int sub(int x, int y) { return x - y; }

int mul(int x, int y) { return x * y; }

int divider(int x, int y) { return x / y; }

int calculator(int x, int y, operation_ptr operation) {
  return operation(x, y);
}
