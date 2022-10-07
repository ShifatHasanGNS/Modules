#ifndef TEMPLATE_H
#define TEMPLATE_H

// necessary libraries / header-files
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "string.h"

// define types
typedef char *String;
typedef unsigned char uchar; // %c
typedef double float64; // %Lf
typedef long double float80; // %Lf

// boolian values
#define False 0
#define No 0
#define Off 0
#define True 1
#define Yes 1
#define On 1
// conditional operators
#define or ||
#define and &&
#define not !

// start = main(),  stop = return 0
#define _start_ void main(int argc, char const *argv[])
#define start int main(int argc, char const *argv[])
#define Exit return 0
#define exit_success return 0
#define exit_failed return 1
#define exit0 return 0
#define exit1 return 1
#define Exit_(x) return x
#define stop break
#define skip continue
#define eif else if

// input
#define input(prompt_text, format_spesifier_string, var) \
    printf(prompt_text);                                 \
    scanf(format_spesifier_string, &var)
#define input_char(prompt_text, char_var) \
    printf(prompt_text);                  \
    scanf("%c", &char_var)
#define input_str(prompt_text, string_var) \
    printf(prompt_text);                   \
    gets(string_var)
#define input_int(prompt_text, int_var) \
    printf(prompt_text);                \
    scanf("%d", &int_var)
#define input_float(prompt_text, float_var) \
    printf(prompt_text);                    \
    scanf("%f", &float_var)
#define input_double(prompt_text, double_var) \
    printf(prompt_text);                      \
    scanf("%lf", &double_var)
//scan
#define scan scanf
#define scan_char(char_var) scanf("%c", &char_var)
#define scan_str(string_var) gets(string_var)

#define scan_int8(int8_var) scanf("%hi", &int8_var)
#define scan_int32(int32_var) scanf("%li", &int32_var)
#define scan_int64(int64_var) scanf("%lli", &int64_var)
#define scan_uint8(uint8_var) scanf("%hu", &uint8_var)
#define scan_uint32(uint32_var) scanf("%lu", &uint32_var)
#define scan_uint64(uint64_var) scanf("%llu", &uint64_var)

#define scan_float32(float32_var) scanf("%f", &float32_var)
#define scan_float64(float64_var) scanf("%lf", &float64_var)
#define scan_float80(float80_var) scanf("%Lf", &float80_var)
// print
#define print printf
#define print_(text) printf(text"\n")
#define print_char(char_var) printf("%c", char_var)
#define print_char_(char_var) printf("%c\n", char_var)
#define print_str(string_var) printf("%s", string_var)
#define print_str_(string_var) printf("%s\n", string_var)
#define print_int8(int8_var) printf("%hi", int8_var)
#define print_int8_(int8_var) printf("%hi\n", int8_var)
#define print_int32(int32_var) printf("%li", int32_var)
#define print_int32_(int32_var) printf("%li\n", int32_var)
#define print_int64(int64_var) printf("%lli", int64_var)
#define print_int64_(int64_var) printf("%lli\n", int64_var)
#define print_uint8(uint8_var) printf("%hu", uint8_var)
#define print_uint8_(uint8_var) printf("%hu\n", uint8_var)
#define print_uint32(uint32_var) printf("%lu", uint32_var)
#define print_uint32_(uint32_var) printf("%lu\n", uint32_var)
#define print_uint64(uint64_var) printf("%llu", uint64_var)
#define print_uint64_(uint64_var) printf("%llu\n", uint64_var)
#define print_float32(float32_var) printf("%f", float32_var)
#define print_float32_(float32_var) printf("%f\n", float32_var)
#define print_float64(float64_var) printf("%lf", float64_var)
#define print_float64_(float64_var) printf("%lf\n", float64_var)
#define print_float80(float80_var) printf("%Lf", float80_var)
#define print_float80_(float80_var) printf("%Lf\n", float80_var)
// new_line
#define newline printf("\n")
#define newline_(number_of_new_lines)                            \
    for (int temp_i = 0; temp_i < number_of_new_lines; temp_i++) \
    printf("\n")

// #define make1(type, m) (type *)malloc(m*sizeof(type))
#define make1(type, m) malloc(sizeof(type[m]))
// #define make2(type, m, n) (type **)malloc(m*sizeof(type *) + m*n*sizeof(type))
#define make2(type, m, n) malloc(sizeof(type[m][n]))
// #define make3(type, m, n, p) (type ***)malloc(m*sizeof(type **) + m*n*sizeof(type *) + m*n*p*sizeof(type))
#define make3(type, m, n, p) malloc(sizeof(type[m][n][p]))

// for loop
#define For(i, start, end, step) for (int i = (start); i < (end); i += (step))
#define For_(type, i, start, end, step) for (type i = (start); i < (end); i += (step))

// memory size of a variable
#define size(var) sizeof(var)
// swap values of two variables
#define swap(type, x, y) type temp = x; x = y; y = temp
// show ---> variable = value
#define show(format_spesifier_string, variable)                  \
    char *temp = (char *)malloc(100);                            \
    sprintf(temp, #variable " = %s\n", format_spesifier_string); \
    printf(temp, variable);                                      \
    free(temp)

#endif
