#include <stdio.h>

int fibo(int num) {
    if (num == 0)
        return 0;
    else if (num == 1)
        return 1;
    return fibo(num - 1) + fibo(num - 2);
}

unsigned long long int fact(unsigned int n) {
    if (n == 1 || n == 0)
        return 1;
    return n * fact(n - 1);
}

int gcd(int a, int b) {
    if (b != 0)
        return gcd(b, a % b);
    return a;
}

void TOH(char src, char dest, char mid, int n) {
    if (n == 1) {
        printf("%c to %c \n", src, dest);
        return;
    }

    TOH(src, mid, dest, n - 1);
    printf("%c to %c\n", src, dest);
    TOH(mid, dest, src, n - 1);
}

int main() {
    int choice;
    printf("1. Fibonacci\n");
    printf("2. Factorial\n");
    printf("3. GCD\n");
    printf("4. Tower of Hanoi\n");
    printf("0. Exit\n");
    enter_choice:;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1: {
            int num;
            printf("Enter a number for Fibonacci: ");
            scanf("%d", &num);
            printf("Fibonacci(%d) = %d\n", num, fibo(num));
            break;
        }
        
        case 2:{
            unsigned int n;
            printf("Enter positive integer: ");
            scanf("%u", &n);
            printf("Factorial(%u) = %llu\n", n, fact(n));
            break;
        }
            
        
        case 3:{
            int a, b;
            printf("Enter two integers for GCD: ");
            scanf("%d %d", &a, &b);
            printf("GCD(%d, %d) = %d\n", a, b, gcd(a, b));
            break;
        }
            
        case 4:{
            int n;
            printf("Enter the number of discs : ");
            scanf("%d", &n);
            TOH('A', 'C', 'B', n);
            break;
        }
            
        
        case 0:{
            printf("Exiting the program.\n");
            return 0;
        }
            
    }
    goto enter_choice;
    
}
/*
1. Fibonacci
2. Factorial
3. GCD
4. Tower of Hanoi
0. Exit
Enter your choice: 1
Enter a number for Fibonacci: 6
Fibonacci(6) = 8
Enter your choice: 2 
Enter positive integer: 13
Factorial(13) = 6227020800
Enter your choice: 3
Enter two integers for GCD: 12 18
GCD(12, 18) = 6
Enter your choice: 4
Enter the number of discs : 3
A to C 
A to B
C to B 
A to C
B to A
B to C
A to C
Enter your choice: 0
Exiting the program.
*/