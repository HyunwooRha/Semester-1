/* This C program demonstrates the switch statement without using breaks.*/
#include <stdio.h>
void main(){
    char ch = '+';
    int a = 10, b = 20;
    float f;
    printf("ch = %c\n", ch);
    switch (ch) {
        case '+': f = a + b; printf("f = %f\n", f); break;
        case '-': f = a - b; printf("f = %f\n", f); break;
        case '*': f = a * b; printf("f = %f\n", f); break;
        case '/': f = a / b; printf("f = %f\n", f); break;
        default: printf("invalid operator\n"); break;
    }
    ch = '-';
    printf("ch = %c\n", ch);
    switch (ch) {
        case '+': f = a + b; printf("f = %f\n", f); break;
        case '-': f = a - b; printf("f = %f\n", f); break;
        case '*': f = a * b; printf("f = %f\n", f); break;
        case '/': f = a / b; printf("f = %f\n", f); break;
        default: printf("invalid operator\n"); break;
    }
    ch = '*';
    printf("ch = %c\n", ch);
    switch (ch) {
        case '+': f = a + b; printf("f = %f\n", f); break;
        case '-': f = a - b; printf("f = %f\n", f); break;
        case '*': f = a * b; printf("f = %f\n", f); break;
        case '/': f = a / b; printf("f = %f\n", f); break;
        default: printf("invalid operator\n"); break;
    }
    ch = '/';
    printf("ch = %c\n", ch);
    switch (ch) {
        case '+': f = a + b; printf("f = %f\n", f); break;
        case '-': f = a - b; printf("f = %f\n", f); break;
        case '*': f = a * b; printf("f = %f\n", f); break;
        case '/': f = a / b; printf("f = %f\n", f); break;
        default: printf("invalid operator\n"); break;
    }
    ch = '%';
    printf("ch = %c\n", ch);
    switch (ch) {
        case '+': f = a + b; printf("f = %f\n", f); break;
        case '-': f = a - b; printf("f = %f\n", f); break;
        case '*': f = a * b; printf("f = %f\n", f); break;
        case '/': f = a / b; printf("f = %f\n", f); break;
        default: printf("invalid operator\n"); break;
    }

}