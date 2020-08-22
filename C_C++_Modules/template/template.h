// necessary libraries / header-files
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "string.h"

// start = main(),  stop = return 0
#define start int main(int argc, char const *argv[])
#define stop return 0

// input
#define input(prompt_text, format_spesifier_string, var) printf(prompt_text); scanf(format_spesifier_string, &var)
#define input_char(prompt_text, char_var) printf(prompt_text); scanf("%c", &char_var)
#define input_str(prompt_text, string_var) printf(prompt_text); scanf("%s", &string_var)
#define input_int(prompt_text, int_var) printf(prompt_text); scanf("%d", &int_var)
#define input_float(prompt_text, float_var) printf(prompt_text); scanf("%f", &float_var)
#define input_double(prompt_text, double_var) printf(prompt_text); scanf("%lf", &double_var)
//scan
#define scan scanf
#define scan_char(char_var) scanf("%c", &char_var)
#define scan_str(string_var) scanf("%s", &string_var)
#define scan_int(int_var) scanf("%d", &int_var)
#define scan_float(float_var) scanf("%f", &float_var)
#define scan_double(double_var) scanf("%lf", &double_var)
// print
#define print printf
#define print_char(char_var) printf("%c", char_var)
#define print_str(string_var) printf("%s", string_var)
#define print_int(int_var) printf("%d", int_var)
#define print_float(float_var) printf("%f", float_var)
#define print_double(double_var) printf("%lf", double_var)
// new_line
#define newline printf("\n")
#define new_line(number_of_new_lines) for(int temp_i=0;temp_i<number_of_new_lines;temp_i++) printf("\n")

// #define new(type, m) (type *)malloc(m*sizeof(type))
#define new1(type, m) malloc(sizeof(type[m]))
// #define new2(type, m, n) (type **)malloc(m*sizeof(type *) + m*n*sizeof(type))
#define new2(type, m, n) malloc(sizeof(type[m][n]))
// #define new3(type, m, n, p) (type ***)malloc(m*sizeof(type **) + m*n*sizeof(type *) + m*n*p*sizeof(type))
#define new3(type, m, n, p) malloc(sizeof(type[m][n][p]))

// for loop
#define For(i, start, end, step) for(int i=(start); i<(end); i += (step))
#define For_(type, i, start, end, step) for(type i=(start); i<(end); i += (step))

// memory size of a variable
#define size(var) sizeof(var)
// swap values of two variables
#define swap(type, x, y) type temp=x; x=y, y=temp;
// show ---> variable = value
#define show(format_spesifier_string, variable)\
char *temp=(char *)malloc(100);\
sprintf(temp, #variable" = %s\n", format_spesifier_string);\
printf(temp, variable);\
free(temp)

// boolian values
#define False 0
#define No 0
#define Off 0
#define True 1
#define Yes 1
#define On 1
// binary operators
#define OR |
#define AND &
#define NOT ~
#define XOR ^
// conditional operators
#define or ||
#define and &&
#define not !

// define types

typedef char* String;
/*
    u  ---> unsigned
    s ---> short
    l  ---> long
    ll ---> long long
*/
// ... char ---> %c
typedef unsigned char uchar;
// ... short ---> %hd
typedef unsigned short ushort;
// ... int ---> 
typedef unsigned int uint;
// ... short int
typedef signed short int sint;
typedef unsigned short int usint;
// ... long int
typedef signed long int lint;
typedef unsigned long int ulint;
// ... long long int
typedef signed long long int llint;
typedef unsigned long long int ullint;
// ... double
typedef long double ldouble;