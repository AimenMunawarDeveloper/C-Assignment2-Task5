#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
// task 5
// Improvements in my program
/* Improvements:k
 * 1.Text color & background color added using system function.
 * 2.Studied and implemented custom functions
 * 3.Learn how to play audio in C and play beep sound when user gives invalid input*/

int addition_subtraction();

int multiplication_division();

int brackets_accessing_integer_operands();

char inputExpression[100];
int index = 0;

int brackets_accessing_integer_operands() {
    int num = 0;//to reset the value of n each time the function is called
// at start of brackets start calculations and return the answer of that calculation when brackets end
    if (inputExpression[index] == '(') {
        index++;// to move to next character in brackets
        num = addition_subtraction();

        if (inputExpression[index] == ')') {
            index++;//to move to next position or to next character in string
            return num;
        }
    } else {
        while ('0' <= inputExpression[index] && inputExpression[index] <= '9') {
            num = num * 10 + (inputExpression[index] - '0');
            //(inputExpression[i] - '0') is used to convert character to numeric value i.e '9' to 9
            index++;
        }
    }
    return num;
}

int multiplication_division() {
    int first_number, second_number;

    first_number = brackets_accessing_integer_operands();
    for (;;) {
        // infinite loop for multiplication and division
        if (inputExpression[index] == '*') {
            index++;
            second_number = brackets_accessing_integer_operands();
            // to check last character should not be an operator
            if(second_number==0){
                Beep(1000, 1000);
                printf("Enter one more operand");
                exit (0);
            }
            first_number *= second_number;
        } else if (inputExpression[index] == '/') {
            index++;
            second_number = brackets_accessing_integer_operands();
            // to check last character should not be an operator and division with zero
            if(second_number==0){
                Beep(1000, 1000);
                printf("Enter one more operand or second operand entered is invalid");
                exit (0);
            }
            first_number /= second_number;
        } else {
            return first_number;
        }
    }
}

int addition_subtraction() {
    int first_number, second_number;

    first_number = multiplication_division();

    // loop for addition,subtraction
    for (;;) {
        if (inputExpression[index] == '+') {
            index++;
            second_number = multiplication_division();
            // to check last character should not be an operator
            if(second_number==0){
                Beep(1000, 1000);
                printf("Enter one more operand");
                exit (0);
            }
            first_number += second_number;
        } else if (inputExpression[index] == '-') {
            index++;
            second_number = multiplication_division();
            // to check last character should not be an operator
            if(second_number==0){
                Beep(1000, 1000);
                printf("Enter one more operand");
                printf("\a");
                exit (0);
            }
            first_number -= second_number;
        } else {
            // final answer
            return first_number;
        }
    }

}

int main() {
    int n, i, j;
    _Bool c;
    system("cls");
    system("COLOR D0");
    // check whether user wants to enter first expression
    printf("Enter 1 to input expression and 0 to exit:\n");
    scanf(" %d",&c);
    while(c!=0){
        // input expression as string
        printf("Input an expression using (+, -, *, /) operators:\n");
        scanf("%s", inputExpression);
        printf("%d\n", addition_subtraction());// calling add,sub function
        // check whether user wants to enter more expressions or not
        printf("Enter 1 to input expression and 0 to exit:\n");
        scanf(" %d",&c);
    }

    return 0;
}


