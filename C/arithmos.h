/*
    Module : [ Arithmos ]
    AUTHOR : [ MD. Shifat Hasan ]
    Email  : [ shifathasangns@gmail.com ]
*/

#pragma once
#ifndef _CMATHLIB__ARITHMOS_
#define _CMATHLIB__ARITHMOS_

// ---------------------------------------------------------------- //
//                      H E A D E R -- F I L E s                    //
// ---------------------------------------------------------------- //

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>

// ---------------------------------------------------------------- //
//                            M A C R O s                           //
// ---------------------------------------------------------------- //

#define DONE printf("Done...\n")
#define $(_real_, _img_) new_number(_real_, _img_)
#define $$ (f80[])
#define loop while (1)

// Time Stamp for Stop-Watch:
#define TIME(_TIME_STAMP_) clock_gettime(CLOCK_MONOTONIC, &_TIME_STAMP_)

// To Free a Pointer from memory:
#define FREE_PTR(_pointer_) \
    free(_pointer_);        \
    _pointer_ = NULL

#define newline(number_of_new_lines)                             \
    for (i64 temp_i = 0; temp_i < number_of_new_lines; temp_i++) \
    printf("\n")

#define PHI_0 (f80)1.61803398874989484820458683436563811772030917980576    // [1 + sqrt(5)] / 2
#define PHI_1 (f80)(-0.61803398874989484820458683436563811772030917980576) // [1 - sqrt(5)] / 2

#define E (f80)2.71828182845904523536028747135266249775724709369995 // e --> Euler's Constant

#define TAU (f80)6.28318530717958647692528676655900576839433879875021       // TAU = 2 * PI
#define PI (f80)3.14159265358979323846264338327950288419716939937510        // PI
#define PI_over_2 (f80)1.57079632679489661923132169163975144209858469968755 // PI / 2
#define PI_over_3 (f80)1.04719755119659774615421446109316762806572313312503 // PI / 3
#define PI_over_4 (f80)0.78539816339744830961566084581987572104929234984377 // PI / 4
#define PI_over_5 (f80)0.62831853071795864769252867665590057683943387987502 // PI / 5
#define PI_over_6 (f80)0.52359877559829887307710723054658381403286156656251 // PI / 6

#define EulerGamma (f80)0.57721566490153286060651209008240243104215933593992 // gamma

#define SquareRootOf2 (f80)1.41421356237309504880168872420969807856967187537695 // sqrt(2)
#define SquareRootOf3 (f80)1.73205080756887729352744634150587236694280525381038 // sqrt(3)
#define SquareRootOf5 (f80)2.23606797749978969640917366873127623544061835961153 // sqrt(5)

#define One_over_SquareRootOf2 (f80)0.70710678118654752440084436210484903928483593768847 // 1 / sqrt(2)
#define One_over_SquareRootOf3 (f80)0.57735026918962576450914878050195745564760175127013 // 1 / sqrt(3)
#define One_over_SquareRootOf5 (f80)0.44721359549995793928183473374625524708812367192231 // 1 / sqrt(5)

#define Half (f80)0.5                                                                            // 1 / 2
#define OneForth (f80)0.25                                                                       // 1 / 4
#define OneThird (f80)0.3333333333333333                                                         // 1 / 3
#define TwoThird (f80)0.6666666666666667                                                         // 2 / 3
#define FourThird (f80)1.3333333333333333                                                        // 4 / 3
#define One_over_ThreeTimesCubeRootOf2 (f80)0.26456684199469991245861760654538471006524888798331 // 1 / (3 * 2^(1 / 3))
#define CubeRootOf2_over_Three (f80)0.41997368329829105492240353575940945019008382156717         // 2^(1 / 3) / 3

#define angle_mode(polar) polar.angle_mode // angle-mode of polar, where variable 'polar' is of type 'Polar2D/Polar'

#define Month_1 "January"
#define Month_2 "February"
#define Month_3 "March"
#define Month_4 "April"
#define Month_5 "May"
#define Month_6 "June"
#define Month_7 "July"
#define Month_8 "August"
#define Month_9 "September"
#define Month_10 "October"
#define Month_11 "November"
#define Month_12 "December"

#define W_DAY_1 "Saturday"
#define W_DAY_2 "Sunday"
#define W_DAY_3 "Monday"
#define W_DAY_4 "Tuesday"
#define W_DAY_5 "Wednesday"
#define W_DAY_6 "Thursday"
#define W_DAY_7 "Friday"

// ---------------------------------------------------------------- //
//                       E N U M E R A T O R s                      //
// ---------------------------------------------------------------- //

typedef enum
{
    nanosecond,
    microsecond,
    milisecond,
    second,
} time_unit;

typedef enum // text_style
{
    title, //  Title
    upper, //  UPPER
    lower  //  lower
} text_style;

typedef enum // angle_mode
{
    radian,
    degree
} angle_mode;

typedef enum // operation
{
    addition,       //  +
    subtraction,    //  -
    multiplication, //  *
} operation;

typedef enum // matrix_type
{
    row_matrix,         //  number of rows = 1
    column_matrix,      //  number of columns = 1
    horizontal_matrix,  //  number of columns > number of rows
    vertical_matrix,    //  number of rows > number of columns
    singleton_matrix,   //  a matrix that has only one element
    square_matrix,      //  number of rows = number of columns
    singular_matrix,    //  determinant of a matrix = 0
    nonsingular_matrix, //  determinant of a matrix not = 0
    diagonal_matrix,    //  a square-matrix whose all the entries outside the main diagonal are all 0
    scalar_matrix,      //  a diagonal-matrix whose all diagonal elements are equal
    identity_matrix,
    unit_matrix = identity_matrix, //  a diagonal-matrix whose all diagonal elements are 1
    null_matrix,
    zero_matrix = null_matrix, //  all elements are 0
    upper_triangular_matrix,   //  a square-matrix whose all the entries below the main diagonal are 0
    lower_triangular_matrix,   //  a square-matrix whose all the entries above the main diagonal are 0
    triangular_matrix,         //  a square-matrix whose all the entries above/below the main diagonal are 0
    involutory_matrix,         //  a square-matrix that is its own inverse; -->  A = inverse(A)
    symmetric_matrix,          //  a square-matrix that is equal to its transpose;  A = transpose(A)
    skew_symmetric_matrix,     //  a square-matrix whose transpose equals its negative;  transpose(A) = -A
    orthogonal_matrix,         //  A * transpose(A) = identity matrix = transpose(A) * A
    normal_matrix,             //  A * transpose(A) = transpose(A) * A
    idempotent_matrix,         //  a square-matrix which, when multiplied by itself, yields itself;  A x A = A
    periodic_matrix,           //  a matrix --> if A^(k+1) = A, then A has period of k, else k = 0
    nilpotent_matrix           //  a square-matrix N such that N^{k}=0, for some positive integer k. The smallest such k is called the index of N, sometimes the degree of N
} matrix_type;

// ---------------------------------------------------------------- //
//                        S T R U C T U R E s                       //
// ---------------------------------------------------------------- //

typedef char *String;        // %s
typedef unsigned char uchar; // %uc
typedef float f32;           // %f
typedef double f64;          // %lf
typedef long double f80;     // %Lf
typedef int16_t i16;         // %d
typedef int32_t i32;         // %ld
typedef int64_t i64;         // %lld
typedef uint16_t u16;        // %u
typedef uint32_t u32;        // %lu
typedef uint64_t u64;        // %llu

typedef struct timespec TimeStamp;

typedef struct
{
    i64 first;
    i64 second;
} Matrix_Index;

typedef struct
{
    f80 r;
    f80 theta;
    angle_mode angle_mode;
} Polar2D;

typedef struct
{
    f80 r;
    f80 theta_x;
    f80 theta_z;
    angle_mode angle_mode;
} Polar;

typedef struct
{
    f80 real;
    f80 img;
} Complex;

typedef struct
{
    i64 length;
    Complex *complex_numbers;
} Complex_Array;

typedef struct
{
    f80 X;
    f80 Y;
} Point2D, Vector2D;

typedef struct
{
    f80 X;
    f80 Y;
    f80 Z;
} Point, Vector;

typedef struct
{
    i64 len;
    f80 *nums;
} NumArray;

typedef struct
{
    i64 rows;
    i64 cols;
    f80 **data;
} Matrix;

typedef struct
{
    i64 n;
    Matrix *mat;
} Tensor;

typedef struct
{
    Complex z;
    f80 real;
    f80 img;
    f80 r;
    i64 r_i;
    f80 r_f;
    short sign_real;
    short sign_img;
    short sign_r;
} Number;

typedef struct
{
    i64 year;
    i64 month;
    i64 day; // monthly day
} Date;

typedef struct
{
    _Bool is_bc;
    _Bool is_leapyear;
    i64 year;
    i64 month;
    i64 day; // monthly day
    char *month_fullname;
    char *month_shortname;
    i64 weekly_day; // weekly day
    char *weekly_day_fullname;
    char *weekly_day_shortname;
    char *date_str;
} Date_Info;

// --------------------------------------------------------------- //
//                        F U N C T I O N s                        //
// --------------------------------------------------------------- //

f80 time_elapsed(TimeStamp before, TimeStamp after, time_unit unit) // returns elapsed time according to the time_unit.
{
    f80 before_nsec = before.tv_nsec;
    f80 after_nsec = after.tv_nsec;
    f80 unit_value = -1.0;
    switch (unit)
    {
    case nanosecond:
        unit_value = 1;
        break;
    case microsecond:
        unit_value = 1e3;
        break;
    case milisecond:
        unit_value = 1e6;
        break;
    case second:
        unit_value = 1e9;
        break;
    default:
        break;
    }
    f80 elapsed = (after_nsec - before_nsec) / (unit_value);
    return elapsed;
}

void print_elapsed_time(TimeStamp before, TimeStamp after, time_unit unit)
{
    char unit_str[13];
    switch (unit)
    {
    case nanosecond:
        strncpy(unit_str, "nanoseconds", 13);
        break;
    case microsecond:
        strncpy(unit_str, "microseconds", 13);
        break;
    case milisecond:
        strncpy(unit_str, "miliseconds", 13);
        break;
    case second:
        strncpy(unit_str, "seconds", 13);
        break;
    default:
        return;
    }
    printf("[ Time Elapsed : %Lf %s ]\n", time_elapsed(before, after, unit), unit_str);
}

char *str_from_char(char c, i64 number_of_copy)
{
    char *str = (char *)calloc(number_of_copy, sizeof(char));
    for (i64 i = 0; i < number_of_copy; i++)
        str[i] = c;
    str[number_of_copy] = '\0';
    return str;
}

char *slice_str(char *str, i64 start, i64 end)
{
    i64 len = end - start, r = 0;
    char *slice = (char *)calloc(len, sizeof(char));
    for (i64 i = start; i < end; i++)
        slice[r++] = str[i];
    slice[len] = '\0';
    return slice;
}

char *to_title(char *str)
{
    i64 len = strlen(str);
    char *str_title = (char *)calloc(len, sizeof(char));
    char x, c = str[0];

    if (c >= 'a' && c <= 'z')
        str_title[0] = c - 32;

    for (i64 i = 1; i < len; i++)
    {
        x = str[i - 1];
        c = str[i];
        if (x == ' ' && c >= 'a' && c <= 'z')
            str_title[i] = c - 32;
        else if (c >= 'A' && c <= 'Z')
            str_title[i] = c + 32;
        else
            str_title[i] = c;
    }
    str_title[len] = '\0';

    return str_title;
}

char *to_upper(char *str)
{
    i64 len = strlen(str);
    char *str_upper = (char *)calloc(len, sizeof(char));
    char c;

    for (i64 i = 0; i < len; i++)
    {
        c = str[i];
        if (c >= 'a' && c <= 'z')
            str_upper[i] = c - 32;
        else
            str_upper[i] = c;
    }
    str_upper[len] = '\0';

    return str_upper;
}

char *to_lower(char *str)
{
    i64 len = strlen(str);
    char *str_lower = (char *)calloc(len, sizeof(char));
    char c;

    for (i64 i = 0; i < len; i++)
    {
        c = str[i];
        if (c >= 'A' && c <= 'Z')
            str_lower[i] = c + 32;
        else
            str_lower[i] = c;
    }
    str_lower[len] = '\0';

    return str_lower;
}

i64 sign_int(i64 number)
{
    return ((number < 0) ? -1 : 1);
}

i64 sign_double(f80 number)
{
    return ((number < 0) ? -1 : 1);
}

_Bool is_negative(f80 number)
{
    return (number < 0);
}

_Bool is_positive(f80 number)
{
    return (number >= 0);
}

_Bool is_odd(i64 number)
{
    return (number & 1);
}

_Bool is_even(i64 number)
{
    return (!(number & 1));
}

i64 ceil_num(f80 number)
{
    i64 whole_number_part = (i64)number;
    f80 fraction_part = number - whole_number_part;
    if (fraction_part > 0)
        return (whole_number_part + 1);
    return whole_number_part;
}

i64 floor_num(f80 number)
{
    return (i64)number;
}

i64 round_num(f80 number)
{
    i64 whole_number_part = (i64)number;
    f80 fraction_part = number - whole_number_part;
    _Bool x = (fraction_part > 0.5);
    return (whole_number_part + x);
}

f80 to_radian(f80 angle_in_degree)
{
    return ((angle_in_degree * PI) / 180);
}

f80 to_degree(f80 angle_in_radian)
{
    return ((angle_in_radian * 180) / PI);
}

i64 abs_int(i64 number)
{
    return (sign_int(number) * number);
}

f80 abs_double(f80 number)
{
    return (sign_double(number) * number);
}

i64 max_int(i64 number_1, i64 number_2)
{
    return (number_1 > number_2) ? number_1 : number_2;
}

f80 max_double(f80 number_1, f80 number_2)
{
    return (number_1 > number_2) ? number_1 : number_2;
}

i64 min_int(i64 number_1, i64 number_2)
{
    return (number_1 < number_2) ? number_1 : number_2;
}

f80 min_double(f80 number_1, f80 number_2)
{
    return (number_1 < number_2) ? number_1 : number_2;
}

f80 trim_double(f80 num, i64 number_of_digits_after_the_radix_dot)
{
    i64 number = (i64)(num * pow(10, number_of_digits_after_the_radix_dot + 1));
    i64 last_digit = number - (i64)(number / 10);
    number = (i64)(number / 10);
    if (last_digit > 4)
        number++;
    return (number / pow(10, number_of_digits_after_the_radix_dot));
}

f80 fast_inverse(f80 n) // 1/n
{
    union
    {
        f80 f;
        uint64_t u;
    } x = {n};

    x.u = 0x7fde8f165f9c4a37 - x.u; // 9213959213902744119_10 = 7fde8f165f9c4a37_16

    for (i64 i = 0; i < 4; i++)
        x.f = x.f * (2 - (n * x.f));

    return x.f;
}

f80 fast_inverse_sqrt(f80 n) // 1 / sqrt(n)
{
    f80 r = 0.5 * n;
    union
    {
        f80 f;
        uint64_t u;
    } x = {n};

    x.u = 0x5fe6eb50c7b537a9 - (x.u >> 1); // 6910469410427058089_10 = 5fe6eb50c7b537a9_16

    for (i64 i = 0; i < 4; i++)
        x.f = x.f * (1.5F - (r * x.f * x.f));

    return x.f;
}

i64 mod(i64 a, i64 m)
{
    if (a < m)
        return a;
    else if (a == m)
        return 0;
    else
        return a % m;
}

i64 mod_nonzero(i64 a, i64 m)
{
    i64 result = mod(a, m);
    if (result == 0)
        return m;
    return result;
}

i64 bigmod(i64 a, i64 b, i64 m)
{
    if (b == 0)
        return mod(1, m);
    i64 result = bigmod(a, b / 2, m);
    result = mod(result * result, m);
    if (b & 1)
        result = mod(result * a, m);
    return result;
}

i64 bigmod_str(char *num, i64 m)
{
    i64 result = 0, len = strlen(num);
    for (i64 i = 0; i < len; i++)
        result = (result * 10 + (i64)num[i] - '0') % m;
    return result;
}

i64 gcd(i64 a, i64 b)
{
    i64 min = (a < b) ? a : b;
    i64 max = (a > b) ? a : b;
    i64 r = mod(max, min);
    if (r == 0)
        return min;
    return gcd(min, r);
}

i64 lcm(i64 a, i64 b)
{
    return ((a * b) / gcd(a, b));
}

i64 power_int(i64 base, i64 n)
{
    if (n == 0)
        return 1;
    else if (n == 1)
        return base;
    i64 result = 1;
    while (n > 0)
    {
        if (n & 1)
            result *= base;
        base *= base;
        n /= 2;
    }
    return result;
}

f80 power_double(f80 base, f80 n)
{
    if (n == 0.0)
        return 1;
    else if (n == 1.0)
        return base;
    else if (n == 0.5 || n == 1.0 / 2.0)
        return sqrt(base);
    else if (n == 0.3333333333333333 || n == 1.0 / 3.0)
        return cbrt(base);
    else
    {
        i64 r = 1, sign_of_base = sign_double(base), sign_of_n = sign_double(n);
        base = abs_double(base);
        n = abs_double(n);
        f80 remaining_power = trim_double(n - floor(n), 15), result = 1.0;
        i64 p = floor(n);
        if (sign_of_n == -1)
            base = 1.0 / base;
        f80 b = base;
        if (remaining_power == 0.0 && sign_of_base == -1)
        {
            if (p & 1)
                r = -1;
            else
            {
                i64 lower_part = pow(10.0, 15.0);
                i64 upper_part = remaining_power * lower_part;
                i64 h = gcd(upper_part, lower_part);
                upper_part /= h;
                lower_part /= h;
                if (!(lower_part & 1))
                    return 0;
                else
                {
                    if (!(upper_part & 1))
                        r = 1;
                    else
                        r = -1;
                }
            }
        }
        while (p > 0)
        {
            if (p & 1)
                result *= base;
            base *= base;
            p /= 2;
        }
        if (remaining_power != 0.0)
        {
            if (remaining_power == 1.0)
                result *= 1;
            else if (remaining_power == 0.5 || remaining_power == 1.0 / 2.0)
                result *= sqrt(b);
            else if (remaining_power == 0.3333333333333333 || remaining_power == 1.0 / 3.0)
                result *= cbrt(b);
            else
                result *= pow(b, remaining_power);
        }
        return (r * result);
    }
}

i64 int_num_len(i64 number)
{
    i64 sign = sign_int(number);
    i64 abs_num = sign * number;
    i64 len = (sign < 1) + 1 + floor_num(log10(abs_num));
    return len;
}

i64 last_digit_int(i64 number, i64 power)
{
    if (power == 0)
        return 1;
    if (number == 0)
        return 0;
    if (number < 1 || power < 1)
        return -1;
    i64 n = number - floor(number / 10) * 10;
    if (power == 1)
        return n;
    if (n == 0 || n == 1 || n == 5 || n == 6)
        return n;
    else if (n == 4 || n == 9)
    {
        return (power & 1) ? n : (10 - n);
    }
    else
    {
        i64 m = mod(power, 4);
        if (m == 1)
            return n;
        else if (m == 2)
            return (n == 2 || n == 8) ? 4 : 9;
        else if (m == 3)
            return (10 - n);
        else if (m == 0)
            return (n == 2 || n == 8) ? 6 : 1;
    }
    return -1;
}

i64 last_digit_uint(i64 number, i64 power)
{
    if (power == 0)
        return 1;
    if (number == 0)
        return 0;
    number = abs_double(number);
    power = abs_double(power);
    i64 n = number - floor(number / 10) * 10;
    if (power == 1)
        return n;
    if (n == 0 || n == 1 || n == 5 || n == 6)
        return n;
    else if (n == 4 || n == 9)
    {
        return (power & 1) ? n : (10 - n);
    }
    else
    {
        char *str = (char *)calloc(floor(log10(power) + 1), sizeof(char));
        sprintf(str, "%lld", power);
        i64 m = bigmod_str(str, 4);
        FREE_PTR(str);
        if (m == 1)
            return n;
        else if (m == 2)
            return (n == 2 || n == 8) ? 4 : 9;
        else if (m == 3)
            return (10 - n);
        else if (m == 0)
            return (n == 2 || n == 8) ? 6 : 1;
    }
    return -1;
}

f80 ln(f80 x)
{
    if (x > 0)
        return log(x);
    return -INFINITY;
}

f80 log_double(f80 base, f80 x)
{
    if (x > 0)
        return (ln(x) / ln(base));
    return -INFINITY;
}

i64 fibonacci(i64 n_th)
{
    return (One_over_SquareRootOf5 * (power_double(PHI_0, n_th) - power_double(PHI_1, n_th)));
}

i64 factorial(i64 n) // MAX --> n = 20
{
    if (n < 0)
        return 0;
    else if (n == 0)
        return 1;
    i64 N = 1;
    for (i64 i = 1; i <= n; i++)
        N *= i;
    return N;
}

f80 sum(char *expression, char *interval)
{
    char *lower_bound = (char *)calloc(128, sizeof(char));
    char *upper_bound = (char *)calloc(128, sizeof(char));
    sscanf(interval, "%s %s", lower_bound, upper_bound);

    char *format = "%0.15Lf";
    i64 a, b; // MAX = 9223372036854775807
    f80 answer = 0;

    if (strcmp(lower_bound, "-inf") == 0)
    {
        a = -10000000;
        sscanf(upper_bound, "%lld", &b);
    }

    if (strcmp(upper_bound, "inf") == 0)
    {
        sscanf(lower_bound, "%lld", &a);
        b = 10000000;
    }

    else
    {
        sscanf(lower_bound, "%lld", &a);
        sscanf(upper_bound, "%lld", &b);
    }

    if (b < a)
        return 0;

    FILE *fp;
    fp = fopen("temp_sum.c", "w");

    fprintf(fp, "#include \"arithmos.h\"\n\n");
    fprintf(fp, "f80 f(f80 x)\n{\n\treturn (%s);\n}\n\n", expression);
    fprintf(fp, "int main()\n{\n");
    fprintf(fp, "\tfloat sum = 0;\n");
    fprintf(fp, "\tfor (i64 x = %lld; x <= %lld; x++)\n", a, b);
    fprintf(fp, "\t\tsum += f(x);\n");
    fprintf(fp, "\tFILE *fp;\n");
    fprintf(fp, "\tfp = fopen(\"temp_answer_sum.txt\", \"w\");\n");
    fprintf(fp, "\tfprintf(fp, \"%s\", sum);\n", format);
    fprintf(fp, "\tfclose(fp);\n");
    fprintf(fp, "\treturn 0;\n}");

    fclose(fp);

    char *command = "gcc temp_sum.c -o temp_sum";
    system(command);
    command = "temp_sum";
    system(command);

    fp = fopen("temp_answer_sum.txt", "r");
    fscanf(fp, "%Lf", &answer);
    fclose(fp);

    remove("temp_sum");
    remove("temp_sum.c");
    remove("temp_answer_sum.txt");

    return answer;
}

f80 product(char *expression, char *interval)
{
    char *lower_bound = (char *)calloc(128, sizeof(char));
    char *upper_bound = (char *)calloc(128, sizeof(char));
    sscanf(interval, "%s %s", lower_bound, upper_bound);

    char *format = "%0.15Lf";
    i64 a, b; // MAX = 9223372036854775807
    f80 answer = 0;

    if (strcmp(lower_bound, "-inf") == 0)
    {
        a = -10000000;
        sscanf(upper_bound, "%lld", &b);
    }

    if (strcmp(upper_bound, "inf") == 0)
    {
        sscanf(lower_bound, "%lld", &a);
        b = 10000000;
    }

    else
    {
        sscanf(lower_bound, "%lld", &a);
        sscanf(upper_bound, "%lld", &b);
    }

    if (b < a)
        return 0;

    FILE *fp;
    fp = fopen("temp_sum.c", "w");

    fprintf(fp, "#include \"arithmos.h\"\n\n");
    fprintf(fp, "f80 f(f80 x)\n{\n\treturn (%s);\n}\n\n", expression);
    fprintf(fp, "int main()\n{\n");
    fprintf(fp, "\tfloat sum = 1;\n");
    fprintf(fp, "\tfor (i64 x = %lld; x <= %lld; x++)\n", a, b);
    fprintf(fp, "\t\tsum *= f(x);\n");
    fprintf(fp, "\tFILE *fp;\n");
    fprintf(fp, "\tfp = fopen(\"temp_answer_product.txt\", \"w\");\n");
    fprintf(fp, "\tfprintf(fp, \"%s\", sum);\n", format);
    fprintf(fp, "\tfclose(fp);\n");
    fprintf(fp, "\treturn 0;\n}");

    fclose(fp);

    char *command = "gcc temp_sum.c -o temp_sum";
    system(command);
    command = "temp_sum";
    system(command);

    fp = fopen("temp_answer_product.txt", "r");
    fscanf(fp, "%Lf", &answer);
    fclose(fp);

    remove("temp_sum");
    remove("temp_sum.c");
    remove("temp_answer_product.txt");

    return answer;
}

f80 differentiate(char *function, f80 x)
{
    f80 answer = 0;
    char *format = "%0.15Lf";

    FILE *fp;
    fp = fopen("temp_derivative.c", "w");

    fprintf(fp, "#include \"arithmos.h\"\n\n");
    fprintf(fp, "f80 f(f80 x)\n{\n\treturn (%s);\n}\n\n", function);
    fprintf(fp, "int main()\n{\n");
    fprintf(fp, "\tfloat dx = 0.000000000000001, a = 0, b = 0, x = %0.15Lf, result = 0;\n\n", x);
    fprintf(fp, "\ta = f(x+dx);\n\tb = f(x-dx);\n");
    fprintf(fp, "\tresult = (a - b)/(2 * dx);\n\n");
    fprintf(fp, "\tFILE *fp;\n");
    fprintf(fp, "\tfp = fopen(\"temp_answer_derivative.txt\", \"w\");\n");
    fprintf(fp, "\tfprintf(fp, \"%s\", result);\n", format);
    fprintf(fp, "\tfclose(fp);\n");
    fprintf(fp, "\treturn 0;\n}");

    fclose(fp);

    char *command = "gcc temp_derivative.c -o temp_derivative";
    system(command);
    command = "temp_derivative";
    system(command);

    fp = fopen("temp_answer_derivative.txt", "r");
    fscanf(fp, "%Lf", &answer);
    fclose(fp);

    remove("temp_derivative");
    remove("temp_derivative.c");
    remove("temp_answer_derivative.txt");

    return answer;
}

f80 integrate(char *integrand, char *interval)
{
    char *lower_bound = (char *)calloc(128, sizeof(char));
    char *upper_bound = (char *)calloc(128, sizeof(char));
    sscanf(interval, "%s %s", lower_bound, upper_bound);

    if (strcmp(lower_bound, upper_bound) == 0)
        return 0;

    f80 a, b, A, B, C, dx = 0.0000001, answer = 0;
    char *format = "%0.15Lf";
    i64 sign = 1;
    _Bool m = 0;

    if (strcmp(lower_bound, "-inf") == 0)
    {
        m = 1;
        A = -PI_over_2;
        if (strcmp(lower_bound, "inf") == 0)
        {
            B = PI_over_2;
        }
        else
        {
            sscanf(upper_bound, "%Lf", &b);
            B = atan(b);
        }
    }

    else if (strcmp(lower_bound, "inf") == 0)
    {
        m = 1;
        sign = -1;
        B = PI_over_2;
        if (strcmp(upper_bound, "-inf") == 0)
        {
            A = -PI_over_2;
        }
        else
        {
            sscanf(upper_bound, "%Lf", &b);
            A = atan(b);
        }
    }

    else
    {
        sscanf(lower_bound, "%Lf", &a);
        if (strcmp(upper_bound, "inf") == 0)
        {
            m = 1;
            A = atan(a);
            B = PI_over_2;
        }
        else if (strcmp(upper_bound, "-inf") == 0)
        {
            m = 1;
            sign = -1;
            B = atan(a);
            A = -PI_over_2;
        }
        else
        {
            sscanf(upper_bound, "%Lf", &b);
            A = a;
            B = b;
            if (b < a)
            {
                sign = -1;
                B = a;
                A = b;
            }
        }
    }

    C = B - A;

    FILE *fp;
    fp = fopen("temp_integral.c", "w");

    fprintf(fp, "#include \"arithmos.h\"\n\n");
    fprintf(fp, "f80 f(f80 x)\n{\n\treturn (%s);\n}\n\n", integrand);
    fprintf(fp, "int main()\n{\n");
    fprintf(fp, "\tfloat sum = 0, x = 0, result = 0;\n");
    fprintf(fp, "\tfor (i64 i = 1; i <= 10000000; i++)\n");
    fprintf(fp, "\t{\n");
    fprintf(fp, "\t\tx = %0.15Lf + (%0.15Lf * (i - 0.5) * %0.15Lf);\n", A, C, dx);
    if (m)
    {
        fprintf(fp, "\t\tx = tan(x);\n");
        fprintf(fp, "\t\tsum += f(x)*(1 + x*x);\n");
    }
    else
        fprintf(fp, "\t\tsum += f(x);\n");
    fprintf(fp, "\t}\n\n");
    fprintf(fp, "\tresult = %lld * %0.15Lf * sum * %0.15Lf;\n\n", sign, C, dx);
    fprintf(fp, "\tFILE *fp;\n");
    fprintf(fp, "\tfp = fopen(\"temp_answer_integral.txt\", \"w\");\n");
    fprintf(fp, "\tfprintf(fp, \"%s\", result);\n", format);
    fprintf(fp, "\tfclose(fp);\n");
    fprintf(fp, "\treturn 0;\n}");

    fclose(fp);

    char *command = "gcc temp_integral.c -o temp_integral";
    system(command);
    command = "temp_integral";
    system(command);

    fp = fopen("temp_answer_integral.txt", "r");
    fscanf(fp, "%Lf", &answer);
    fclose(fp);

    remove("temp_integral");
    remove("temp_integral.c");
    remove("temp_answer_integral.txt");

    return answer;
}

_Bool is_null_matrix(Matrix matrix)
{
    return (matrix.rows == 0 && matrix.cols == 0);
}

_Bool is_square_matrix(Matrix matrix)
{
    return (matrix.rows == matrix.cols);
}

_Bool are_perfect_matrix(Matrix matrix_1, Matrix matrix_2, operation operation)
{
    if (operation == addition || operation == subtraction)
        return ((matrix_1.rows == matrix_2.rows) && (matrix_1.cols == matrix_2.cols));
    else if (operation == multiplication)
        return (matrix_1.cols == matrix_2.rows);
    return 0;
}

_Bool are_identical_matrix(Matrix matrix_1, Matrix matrix_2)
{
    if (matrix_1.rows == matrix_2.rows && matrix_1.cols == matrix_2.cols)
    {
        i64 count = 0;
        for (i64 r = 0; r < matrix_1.rows; r++)
        {
            for (i64 c = 0; c < matrix_1.cols; c++)
                if (matrix_1.data[r][c] == matrix_2.data[r][c])
                    count++;
        }
        if (count == (matrix_1.rows * matrix_1.cols))
            return 1;
        return 0;
    }
    return 0;
}

Matrix_Index new_matrix_index(i64 first, i64 second)
{
    Matrix_Index p;
    p.first = first;
    p.first = second;
    return p;
}

Polar2D new_polar2D(f80 r, f80 theta, angle_mode angle_mode)
{
    Polar2D p;
    p.r = r;
    p.theta = theta;
    p.angle_mode = angle_mode;
    return p;
}

Polar new_polar(f80 r, f80 theta_x, f80 theta_z, angle_mode angle_mode)
{
    Polar p;
    p.r = r;
    p.theta_x = theta_x;
    p.theta_z = theta_z;
    p.angle_mode = angle_mode;
    return p;
}

Point2D new_point2D(f80 X, f80 Y)
{
    Point2D p;
    p.X = X;
    p.Y = Y;
    return p;
}

Vector2D new_vector2D(f80 X, f80 Y)
{
    Vector2D v;
    v.X = X;
    v.Y = Y;
    return v;
}

Point new_point(f80 X, f80 Y, f80 Z)
{
    Point p;
    p.X = X;
    p.Y = Y;
    p.Z = Z;
    return p;
}

Vector new_vector(f80 X, f80 Y, f80 Z)
{
    Vector v;
    v.X = X;
    v.Y = Y;
    v.Z = Z;
    return v;
}

NumArray new_num_array(i64 number_of_elements)
{
    NumArray na;
    na.len = number_of_elements;
    f80 *nums = (f80 *)calloc(number_of_elements, sizeof(f80));
    na.nums = nums;
    return na;
}

NumArray new_num_array_(i64 number_of_elements, f80 nums[])
{
    NumArray na;
    na.len = number_of_elements;
    na.nums = nums;
    return na;
}

Matrix new_matrix(i64 rows, i64 cols)
{
    Matrix matrix;
    matrix.rows = rows;
    matrix.cols = cols;
    f80 **data = (f80 **)calloc(rows, sizeof(f80 *));
    for (i64 x = 0; x < rows; x++)
        data[x] = (f80 *)calloc(cols, sizeof(f80));
    matrix.data = data;
    return matrix;
}

Tensor new_tensor(i64 number_of_mats, i64 rows, i64 cols)
{
    Tensor tensor;
    tensor.n = number_of_mats;
    Matrix *mat = (Matrix *)calloc(number_of_mats, sizeof(Matrix));
    for (i64 x = 0; x < number_of_mats; x++)
        mat[x] = new_matrix(rows, cols);
    tensor.mat = mat;
    return tensor;
}

Matrix new_column_matrix(i64 rows)
{
    return new_matrix(rows, 1);
}

Matrix new_row_matrix(i64 cols)
{
    return new_matrix(1, cols);
}

Matrix new_identity_matrix(i64 order)
{
    Matrix matrix = new_matrix(order, order);
    for (i64 r = 0; r < order; r++)
        matrix.data[r][r] = 1;
    return matrix;
}

Matrix new_scalar_matrix(i64 order, f80 scalar_number)
{
    Matrix matrix = new_matrix(order, order);
    for (i64 r = 0; r < order; r++)
        matrix.data[r][r] = scalar_number;
    return matrix;
}

Matrix new_primary_diagonal_matrix(i64 order, Matrix row_matrix)
{
    Matrix matrix = new_matrix(order, order);
    for (i64 r = 0; r < order; r++)
        matrix.data[r][r] = row_matrix.data[0][r];
    return matrix;
}

Matrix new_secondary_diagonal_matrix(i64 order, Matrix row_matrix)
{
    Matrix matrix = new_matrix(order, order);
    for (i64 r = 0; r < order; r++)
        matrix.data[r][order - r - 1] = row_matrix.data[0][r];
    return matrix;
}

Complex new_complex(f80 real_part, f80 imaginary_part)
{
    Complex complex_number;
    complex_number.real = real_part;
    complex_number.img = imaginary_part;
    return complex_number;
}

Complex_Array new_complex_array(i64 length)
{
    Complex_Array complex_array;
    complex_array.length = length;
    complex_array.complex_numbers = (Complex *)calloc(length, sizeof(Complex));
    return complex_array;
}

Number new_number(f80 real_part, f80 imaginary_part)
{
    Number n;
    n.z = new_complex(real_part, imaginary_part);
    n.real = real_part;
    n.img = imaginary_part;
    f80 R = (real_part * real_part) + (imaginary_part * imaginary_part);
    n.r = sqrt(R);
    n.r_i = (i64)n.r;
    n.r_f = (f80)(n.r - n.r_i);
    n.sign_real = (real_part < 0.0) ? -1 : 1;
    n.sign_img = (imaginary_part < 0.0) ? -1 : 1;
    n.sign_r = (n.r < 0.0) ? -1 : 1;
    return n;
}

NumArray random_num_array(i64 number_of_elements, i64 rounding_number, f80 scalar)
{
    srand(time(0));
    NumArray na = new_num_array(number_of_elements);
    for (i64 i = 0; i < number_of_elements; i++)
        na.nums[i] = scalar * ((rand() % rounding_number) + 1);
    return na;
}

NumArray random_num_array_(i64 number_of_elements, i64 rounding_number, f80 scalar, f80 seed)
{
    srand(seed);
    NumArray na = new_num_array(number_of_elements);
    for (i64 i = 0; i < number_of_elements; i++)
        na.nums[i] = scalar * ((rand() % rounding_number) + 1);
    return na;
}

NumArray scale_num_array(NumArray array, f80 scalar)
{
    NumArray na = new_num_array(array.len);
    for (i64 i = 0; i < array.len; i++)
        na.nums[i] = scalar * array.nums[i];
    return na;
}

NumArray copy_num_array(NumArray array)
{
    return new_num_array_(array.len, array.nums);
}

Matrix_Index copy_matrix_index(Matrix_Index p)
{
    return new_matrix_index(p.first, p.second);
}

Polar2D copy_polar2D(Polar2D p)
{
    return new_polar2D(p.r, p.theta, p.angle_mode);
}

Polar copy_polar(Polar p)
{
    return new_polar(p.r, p.theta_x, p.theta_z, p.angle_mode);
}

Complex copy_complex(Complex z)
{
    return new_complex(z.real, z.img);
}

Complex_Array copy_complex_array(Complex_Array complex_array)
{
    i64 len = complex_array.length;
    Complex_Array copy_of_complex_array = new_complex_array(len);
    for (i64 i = 0; i < len; i++)
        copy_of_complex_array.complex_numbers[i] = complex_array.complex_numbers[i];
    return copy_of_complex_array;
}

Point2D copy_point2D(Point2D p)
{
    return new_point2D(p.X, p.Y);
}

Vector2D copy_vector2D(Vector2D v)
{
    return new_vector2D(v.X, v.Y);
}

Point copy_point(Point p)
{
    return new_point(p.X, p.Y, p.Z);
}

Vector copy_vector(Vector v)
{
    return new_vector(v.X, v.Y, v.Z);
}

Matrix null()
{
    return new_matrix(0, 0);
}

Point2D origin_point2D()
{
    return new_point2D(0, 0);
}

Point origin_point()
{
    return new_point(0, 0, 0);
}

Vector2D zero_vector2D()
{
    return new_vector2D(0, 0);
}

Vector zero_vector()
{
    return new_vector(0, 0, 0);
}

Complex complex_from_real(f80 number)
{
    return new_complex(number, 0);
}

Complex complex_from_imaginary(f80 imaginary_number)
{
    return new_complex(0, imaginary_number);
}

f80 real_part(Complex z)
{
    return z.real;
}

f80 imaginary_part(Complex z)
{
    return z.img;
}

Complex conjugate(Complex z)
{
    Complex c_number;
    c_number.real = z.real;
    c_number.img = -z.img;
    return c_number;
}

f80 value_of_complex(Complex z)
{
    return sqrt((z.real * z.real) + (z.img * z.img));
}

Complex scale_complex(Complex z, f80 scalar)
{
    return new_complex(scalar * z.real, scalar * z.img);
}

i64 quadrent_for_complex(Complex z)
{
    f80 real = z.real;
    f80 imaginary = z.img;
    if (real >= 0 && imaginary >= 0)
        return 1;
    if (real < 0 && imaginary >= 0)
        return 2;
    if (real < 0 && imaginary < 0)
        return 3;
    if (real >= 0 && imaginary < 0)
        return 4;
    return -1;
}

f80 argument(Complex z, angle_mode angle_mode)
{
    f80 real = z.real;
    f80 imaginary = z.img;

    if (real == 0)
    {
        f80 arg = 90 * sign_double(imaginary);
        if (angle_mode == radian)
            return to_radian(arg);
        else if (angle_mode == degree)
            return arg;
    }
    else if (imaginary == 0)
    {
        if (real >= 0)
            return 0;
        else
        {
            if (angle_mode == radian)
                return PI;
            else if (angle_mode == degree)
                return 180;
        }
    }
    else
    {
        f80 arg = atan(abs_double(imaginary / real));
        if (real > 0 && imaginary > 0)
        {
            if (angle_mode == radian)
                return arg;
            else if (angle_mode == degree)
                return to_degree(arg);
        }
        if (real < 0 && imaginary > 0)
        {
            if (angle_mode == radian)
                return (PI - arg);
            else if (angle_mode == degree)
                return (180 - to_degree(arg));
        }
        if (real < 0 && imaginary < 0)
        {
            if (angle_mode == radian)
                return (arg - PI);
            else if (angle_mode == degree)
                return (to_degree(arg) - 180);
        }
        if (real > 0 && imaginary < 0)
        {
            if (angle_mode == radian)
                return (-arg);
            else if (angle_mode == degree)
                return (-to_degree(arg));
        }
    }
    return NAN;
}

f80 angle_for_complex(Complex z, angle_mode angle_mode)
{
    f80 real = z.real;
    f80 imaginary = z.img;

    if (real == 0)
    {
        f80 arg = 90 * sign_double(imaginary);
        if (angle_mode == radian)
            return to_radian(arg);
        else if (angle_mode == degree)
            return arg;
    }
    else if (imaginary == 0)
    {
        if (real >= 0)
            return 0;
        else
        {
            if (angle_mode == radian)
                return PI;
            else if (angle_mode == degree)
                return 180;
        }
    }
    else
    {
        f80 arg = atan(abs_double(imaginary / real));
        if (real > 0 && imaginary > 0)
        {
            if (angle_mode == radian)
                return arg;
            else if (angle_mode == degree)
                return to_degree(arg);
        }
        if (real < 0 && imaginary > 0)
        {
            if (angle_mode == radian)
                return (PI - arg);
            else if (angle_mode == degree)
                return (180 - to_degree(arg));
        }
        if (real < 0 && imaginary < 0)
        {
            if (angle_mode == radian)
                return (PI + arg);
            else if (angle_mode == degree)
                return (180 + to_degree(arg));
        }
        if (real > 0 && imaginary < 0)
        {
            if (angle_mode == radian)
                return (TAU - arg);
            else if (angle_mode == degree)
                return (360 - to_degree(arg));
        }
        return NAN;
    }
    return NAN;
}

i64 quadrent_for_angle(f80 angle, angle_mode angle_mode)
{
    f80 theta = remainder(abs_double(angle), TAU), pi_1 = PI / 2, pi_2 = (3 * PI) / 2;
    i64 quadrent = -1;
    if (angle_mode == radian)
    {
        if (theta >= 0 && theta <= pi_1)
            quadrent = 1;
        if (theta > pi_1 && theta <= PI)
            quadrent = 2;
        if (theta > PI && theta <= pi_2)
            quadrent = 3;
        if (theta > pi_2 && theta < TAU)
            quadrent = 4;
    }
    else if (angle_mode == degree)
    {
        if (theta >= 0 && theta <= 90)
            quadrent = 1;
        if (theta > 90 && theta <= 180)
            quadrent = 2;
        if (theta > 180 && theta <= 270)
            quadrent = 3;
        if (theta > 270 && theta < 360)
            quadrent = 4;
    }
    if (angle < 0)
    {
        if (quadrent == 1)
            quadrent = 4;
        if (quadrent == 2)
            quadrent = 3;
        if (quadrent == 3)
            quadrent = 2;
        if (quadrent == 4)
            quadrent = 1;
    }
    return quadrent;
}

Complex add_complex(Complex z1, Complex z2)
{
    return new_complex((z1.real + z2.real), (z1.img + z2.img));
}

Complex subtract_complex(Complex z1, Complex z2)
{
    return new_complex((z1.real - z2.real), (z1.img - z2.img));
}

Complex multiply_complex(Complex z1, Complex z2) // (x1 + iy1) * (x2 + iy2) = (x1*x2 - y1*y2) + i(x1*y2 + x2*y1)
{
    return new_complex(((z1.real * z2.real) - (z1.img * z2.img)), ((z1.real * z2.img) + (z2.real * z1.img)));
}

Complex divide_complex(Complex z1, Complex z2) // (x1 + iy1) / (x2 + iy2) = ((x1 + iy1) * (x2 - iy2)) / (x2*x2 + y2*y2)
{
    return scale_complex(multiply_complex(z1, conjugate(z2)), (1 / value_of_complex(z2)));
}

Complex power_complex(Complex base, Complex n)
{
    f80 r = value_of_complex(base);
    f80 t = argument(base, radian);
    f80 x = n.real, y = n.img;
    f80 p = (x * log(r)) - (y * t);
    f80 R = power_double(E, p);
    f80 T = (y * log(r)) + (x * t);
    f80 real = R * cos(T), img = R * sin(T);
    return new_complex(real, img);
}

Complex complex_ln(Complex z)
{
    f80 r = value_of_complex(z);
    f80 t = argument(z, radian);
    if (r < 0)
        return new_complex(log(abs_double(r)), (t + PI));
    else if (r > 0)
        return new_complex(log(r), t);
    return new_complex(-INFINITY, 0);
}

Complex complex_log10(Complex z)
{
    f80 r = value_of_complex(z);
    f80 t = argument(z, radian);
    if (r < 0)
        return new_complex(log(abs_double(r)) / log(10), (t + PI) / log(10));
    else if (r > 0)
        return new_complex(log(r) / log(10), t / log(10));
    return new_complex(-INFINITY, 0);
}

Complex complex_log(Complex base, Complex z)
{
    return divide_complex(complex_ln(z), complex_ln(base));
}

_Bool is_number(char *string)
{
    if (string == NULL || *string == '\0')
        return 0;                                       // Checking if the string is Empty...
    i64 count_dot = 0, count_plus = 0, count_minus = 0; // Initializing...
    // Checking if the string is a number...
    while (*string)
    {
        char c = *string;
        switch (c)
        {
        case '.':
            if (++count_dot > 1)
                return 0;
            break;
        case '+':
            if (++count_plus > 1)
                return 0;
            break;
        case '-':
            if (++count_minus > 1)
                return 0;
            break;
        default:
            if (c < '0' || c > '9')
                return 0;
            break;
        }
        string++; // Point to the next character...
    }
    // If it's a number then return True...
    return 1;
}

char *remove_char(char *str, char c)
{
    char *new_str = (char *)calloc(strlen(str), sizeof(char));
    i64 count = 0;
    for (i64 i = 0; new_str[i]; i++)
        if (new_str[i] != c)
            new_str[count++] = new_str[i];
    new_str[count] = '\0';
    return new_str;
}

char **split(char *str, i64 str_len, char delimiter_char)
{
    i64 len = (str_len + 2), number_of_tokens = 0;
    i64 n = (len >> 1);
    char *string = (char *)calloc(len, sizeof(char));
    sprintf(string, "%s ", str);

    // initialize the 'list_of_tokens'
    char **list_of_tokens = (char **)calloc(n, sizeof(char *));
    for (i64 i = 0; i < n; i++)
        list_of_tokens[i] = (char *)calloc(64, sizeof(char));

    // Split
    char delimiter_str[2] = {delimiter_char, '\0'};
    char *token, *rest_string = string;
    while ((token = strtok_r(rest_string, delimiter_str, &rest_string)))
        list_of_tokens[number_of_tokens++] = token;

    return list_of_tokens;
}

f80 *parse_number(char *string, i64 number_of_numbers)
{
    i64 count = 0, c = 0, i, string_len = number_of_numbers << 6;
    f80 temp_num;
    // Get the splitted_String as a 2D_Character_Array...
    char **splitted_string = split(string, string_len, ' ');
    // Initialize the 1D_Number_Array...
    while (splitted_string[count][0])
        count++;
    f80 *list_of_nums = (f80 *)calloc(count, sizeof(f80));
    // Parse the numbers...
    for (i = 0; i < count; i++)
    {
        if (is_number(splitted_string[i]))
        {
            sscanf(splitted_string[i], "%Lf", &temp_num);
            list_of_nums[c++] = temp_num;
            if (number_of_numbers != -1 && c == number_of_numbers)
                break;
        }
    }
    // Return the list as a f80 type 1D_Number_Array...
    return list_of_nums;
}

Matrix input_matrix(i64 rows, i64 cols)
{
    i64 r, c, len = 64 * cols;
    // Temporary Variables...
    f80 *temp_row = (f80 *)calloc(cols, sizeof(f80));
    char *temp_str = (char *)calloc(len, sizeof(char));

    i64 temp_len = 0;
    // Creating the Matrix...
    Matrix matrix = new_matrix(rows, cols);
    // Getting the Matrix_Input...
    for (r = 0; r < rows; r++)
    {
        *temp_str = '\0';
        fgets(temp_str, len, stdin);
        temp_len = strlen(temp_str);
        temp_str[temp_len - 1] = '\0';

        temp_row = parse_number(temp_str, cols);

        for (c = 0; c < cols; c++)
        {
            matrix.data[r][c] = temp_row[c];
            temp_row[c] = 0;
        }
    }
    return matrix;
}

Matrix input_row_matrix(i64 cols)
{
    return input_matrix(1, cols);
}

Matrix input_column_matrix(i64 rows)
{
    return input_matrix(rows, 1);
}

Matrix input_square_matrix(i64 order)
{
    return input_matrix(order, order);
}

Matrix matrix_from_array(i64 rows, i64 cols, NumArray array)
{
    if ((rows * cols) == array.len)
    {
        Matrix matrix = new_matrix(rows, cols);
        for (i64 r = 0; r < rows; r++)
        {
            for (i64 c = 0; c < cols; c++)
                matrix.data[r][c] = array.nums[cols * r + c];
        }
        return matrix;
    }
    return new_matrix(0, 0);
}

Matrix matrix_from_array_(i64 rows, i64 cols, f80 nums[])
{
    return matrix_from_array(rows, cols, new_num_array_(rows * cols, nums));
}

Matrix column_matrix_from_array(NumArray array)
{
    return matrix_from_array(array.len, 1, array);
}

Matrix column_matrix_from_array_(i64 len, f80 array[])
{
    NumArray narray = new_num_array_(len, array);
    return matrix_from_array(len, 1, narray);
}

Matrix row_matrix_from_array(NumArray array)
{
    return matrix_from_array(1, array.len, array);
}

Matrix row_matrix_from_array_(i64 len, f80 array[])
{
    NumArray narray = new_num_array_(len, array);
    return matrix_from_array(1, len, narray);
}

NumArray array_from_matrix(Matrix matrix)
{
    if (!is_null_matrix(matrix))
    {
        NumArray array = new_num_array(matrix.rows * matrix.cols);
        i64 i = 0;
        for (i64 r = 0; r < matrix.rows; r++)
        {
            for (i64 c = 0; c < matrix.cols; c++)
                array.nums[i++] = matrix.data[r][c];
        }
        return array;
    }
    return new_num_array(0);
}

Matrix random_matrix(i64 rows, i64 cols, i64 rounding_number, f80 scalar)
{
    srand(time(0));
    Matrix r_matrix = new_matrix(rows, cols);
    for (i64 r = 0; r < rows; r++)
    {
        for (i64 c = 0; c < cols; c++)
            r_matrix.data[r][c] = scalar * ((rand() % rounding_number) + 1);
    }
    return r_matrix;
}

Matrix random_matrix_(i64 rows, i64 cols, i64 rounding_number, f80 scalar, f80 seed)
{
    srand(seed);
    Matrix r_matrix = new_matrix(rows, cols);
    for (i64 r = 0; r < rows; r++)
    {
        for (i64 c = 0; c < cols; c++)
            r_matrix.data[r][c] = scalar * ((rand() % rounding_number) + 1);
    }
    return r_matrix;
}

Matrix copy_matrix(Matrix matrix)
{
    Matrix c_matrix = new_matrix(matrix.rows, matrix.cols);
    for (i64 r = 0; r < matrix.rows; r++)
    {
        for (i64 c = 0; c < matrix.cols; c++)
            c_matrix.data[r][c] = matrix.data[r][c];
    }
    return c_matrix;
}

Matrix row_matrix_from_vector2D(Vector2D vector)
{
    Matrix colMatrix = new_matrix(1, 2);
    colMatrix.data[0][0] = vector.X;
    colMatrix.data[0][1] = vector.Y;
    return colMatrix;
}

Matrix row_matrix_from_vector(Vector vector)
{
    Matrix colMatrix = new_matrix(1, 3);
    colMatrix.data[0][0] = vector.X;
    colMatrix.data[0][1] = vector.Y;
    colMatrix.data[0][2] = vector.Z;
    return colMatrix;
}

Matrix column_matrix_from_vector2D(Vector2D vector)
{
    Matrix colMatrix = new_matrix(2, 1);
    colMatrix.data[0][0] = vector.X;
    colMatrix.data[1][0] = vector.Y;
    return colMatrix;
}

Matrix column_matrix_from_vector(Vector vector)
{
    Matrix colMatrix = new_matrix(3, 1);
    colMatrix.data[0][0] = vector.X;
    colMatrix.data[1][0] = vector.Y;
    colMatrix.data[2][0] = vector.Z;
    return colMatrix;
}

Vector2D vector2D_from_matrix(Matrix matrix)
{
    if (matrix.cols == 1)
    {
        if (matrix.rows == 1)
            return new_vector2D(matrix.data[0][0], 0);
        else if (matrix.rows == 2)
            return new_vector2D(matrix.data[0][0], matrix.data[1][0]);
    }
    else if (matrix.rows == 1)
    {
        if (matrix.cols == 1)
            return new_vector2D(matrix.data[0][0], 0);
        else if (matrix.cols == 2)
            return new_vector2D(matrix.data[0][0], matrix.data[0][1]);
    }
    return new_vector2D(0, 0);
}

Vector vector_from_matrix(Matrix matrix)
{
    if (matrix.cols == 1)
    {
        if (matrix.rows == 1)
            return new_vector(matrix.data[0][0], 0, 0);
        else if (matrix.rows == 2)
            return new_vector(matrix.data[0][0], matrix.data[1][0], 0);
        else if (matrix.rows == 3)
            return new_vector(matrix.data[0][0], matrix.data[1][0], matrix.data[2][0]);
    }
    else if (matrix.rows == 1)
    {
        if (matrix.cols == 1)
            return new_vector(matrix.data[0][0], 0, 0);
        else if (matrix.cols == 2)
            return new_vector(matrix.data[0][0], matrix.data[0][1], 0);
        else if (matrix.cols == 3)
            return new_vector(matrix.data[0][0], matrix.data[0][1], matrix.data[0][2]);
    }
    return new_vector(0, 0, 0);
}

Polar2D polar2D_from_complex(Complex z, angle_mode angle_mode) // z = (x + iy) --> r * e^(i * theta)
{
    return new_polar2D(value_of_complex(z), argument(z, angle_mode), angle_mode);
}

Complex complex_from_polar2D(Polar2D number) // r * e^(i * theta) --> (x + iy) = z
{
    if (number.angle_mode == radian)
    {
        return scale_complex(new_complex(cos(number.theta), sin(number.theta)), number.r);
    }
    else if (number.angle_mode == degree)
    {
        f80 angle = to_radian(number.theta);
        return scale_complex(new_complex(cos(angle), sin(angle)), number.r);
    }
    return new_complex(0, 0);
}

Complex complex_from_point2D(Point2D point)
{
    return new_complex(point.X, point.Y);
}

Polar2D polar2D_from_point2D(Point2D point, angle_mode angle_mode)
{
    return polar2D_from_complex(complex_from_point2D(point), angle_mode);
}

Point2D point2D_from_complex(Complex z)
{
    return new_point2D(z.real, z.img);
}

Point2D point2D_from_polar2D(Polar2D point)
{
    return point2D_from_complex(complex_from_polar2D(point));
}

Point point_from_polar(Polar point)
{
    f80 t1 = point.theta_x, t2 = point.theta_z;
    if (point.angle_mode == degree)
    {
        t1 = to_radian(point.theta_x);
        t2 = to_radian(point.theta_z);
    }
    f80 x = point.r * sin(t2) * cos(t1);
    f80 y = point.r * sin(t2) * sin(t1);
    f80 z = point.r * cos(t2);
    return new_point(x, y, z);
}

Polar polar_from_point(Point point, angle_mode angle_mode)
{
    f80 x = point.X, y = point.Y, z = point.Z;
    f80 r = sqrt(x * x + y + y + z * z);
    f80 t1 = acos(x / sqrt(x * x + y * y));
    f80 t2 = acos(z / r);
    if (angle_mode == degree)
    {
        t1 = to_degree(t1);
        t2 = to_degree(t2);
    }
    return new_polar(r, t1, t2, angle_mode);
}

Complex complex_from_vector2D(Vector2D vector)
{
    return new_complex(vector.X, vector.Y);
}

Vector2D vector2D_from_complex(Complex z)
{
    return new_vector2D(z.real, z.img);
}

Vector vector_from_vector2D(Vector2D vector)
{
    return new_vector(vector.X, vector.Y, 0);
}

Vector2D vector2D_from_vector(Vector vector)
{
    return new_vector2D(vector.X, vector.Y);
}

Point point_from_point2D(Point2D p)
{
    return new_point(p.X, p.Y, 0);
}

Point2D point2D_from_point(Point point)
{
    return new_point2D(point.X, point.Y);
}

Point2D point2D_from_vector2D(Vector2D vector)
{
    return new_point2D(vector.X, vector.Y);
}

Vector2D vector2D_from_point2D(Point2D point)
{
    return new_vector2D(point.X, point.Y);
}

Point point_from_vector(Vector vector)
{
    return new_point(vector.X, vector.Y, vector.Z);
}

Vector vector_from_point(Point point)
{
    return new_vector(point.X, point.Y, point.Z);
}

Point point_from_vector2D(Vector2D vector)
{
    return new_point(vector.X, vector.Y, 0);
}

Vector2D vector2D_from_point(Point point)
{
    return new_vector2D(point.X, point.Y);
}

Point2D point2D_from_vector(Vector vector)
{
    return new_point2D(vector.X, vector.Y);
}

Vector vector_from_point2D(Point2D point)
{
    return new_vector(point.X, point.Y, 0);
}

Point2D input_point2D()
{
    return point2D_from_vector2D(vector2D_from_matrix(input_matrix(1, 2)));
}

Point input_point()
{
    return point_from_vector(vector_from_matrix(input_matrix(1, 3)));
}

Vector2D input_vector2D()
{
    return vector2D_from_matrix(input_matrix(1, 2));
}

Vector input_vector()
{
    return vector_from_matrix(input_matrix(1, 3));
}

Matrix generate_magic_square(i64 n)
{
    n = n - !(n & 1);
    i64 r = 0, c = n >> 1;

    Matrix magic_square = new_matrix(n, n);
    magic_square.data[r][c] = 1;

    for (i64 count = 2; count <= (n * n); count++)
    {
        if (r == 0 && c < (n - 1)) // x . | . x .
        {                          // . . | . . .
            r = n - 1;
            c = c + 1;
        }
        else if (r > 0 && c == (n - 1)) // . .
        {                               // . x
            r = r - 1;                  // . .
            c = 0;
        }
        else if (r == 0 && c == (n - 1)) // . x
        {                                // . .
            r = 1;
        }
        else if (r == (n - 1) && c < (n - 1)) // . . | . . .
        {                                     // x . | . x .
            r = n - 2;
            c = c + 1;
        }
        else if (r > 0 && r < (n - 1) && c < (n - 1))
        {
            if (magic_square.data[r - 1][c + 1] == 0)
            {
                r = r - 1;
                c = c + 1;
            }
            else
                r = r + 1;
        }
        magic_square.data[r][c] = count;
    }
    return magic_square;
}

Matrix transpose(Matrix matrix)
{
    Matrix transposed_matrix = new_matrix(matrix.cols, matrix.rows);
    for (i64 r = 0; r < matrix.cols; r++)
    {
        for (i64 c = 0; c < matrix.rows; c++)
            transposed_matrix.data[r][c] = matrix.data[c][r];
    }
    return transposed_matrix;
}

Matrix reshape(Matrix matrix, i64 rows, i64 cols)
{
    if (!is_null_matrix(matrix) && (rows * cols) == (matrix.rows * matrix.cols))
        return matrix_from_array(rows, cols, array_from_matrix(matrix));
    return matrix;
}

Matrix resize(Matrix matrix, i64 rows, i64 cols)
{
    Matrix m = new_matrix(rows, cols);
    for (i64 r = 0; r < matrix.rows; r++)
    {
        for (i64 c = 0; c < matrix.rows; c++)
            m.data[r][c] = matrix.data[r][c];
    }
    return m;
}

NumArray nth_row_data(Matrix matrix, i64 nth_row) // First Column = 0
{
    NumArray row_data = new_num_array(matrix.cols);
    for (i64 c = 0; c < matrix.cols; c++)
        row_data.nums[c] = matrix.data[nth_row][c];
    return row_data;
}

Matrix append_row_matrix(Matrix base_matrix, Matrix row_matrix)
{
    if (row_matrix.rows == 1)
    {
        Matrix new_matrix = resize(base_matrix, base_matrix.rows + 1, base_matrix.cols);
        for (i64 c = 0; c < base_matrix.cols; c++)
            new_matrix.data[base_matrix.rows][c] = row_matrix.data[0][c];
        return new_matrix;
    }
    return base_matrix;
}

Matrix append_column_matrix(Matrix base_matrix, Matrix column_matrix)
{
    if (column_matrix.cols == 1)
    {
        Matrix new_matrix = resize(base_matrix, base_matrix.rows, base_matrix.cols + 1);
        for (i64 r = 0; r < base_matrix.rows; r++)
            new_matrix.data[r][base_matrix.cols] = column_matrix.data[r][0];
        return new_matrix;
    }
    return base_matrix;
}

Matrix insert_row_matrix(Matrix base_matrix, i64 index_of_row, Matrix row_matrix)
{
    if (row_matrix.rows == 1)
    {
        if (index_of_row >= 0 && index_of_row < base_matrix.rows)
        {
            Matrix m = new_matrix(base_matrix.rows + 1, base_matrix.cols);
            for (i64 r = 0; r < base_matrix.rows + 1; r++)
            {
                for (i64 c = 0; c < base_matrix.cols; c++)
                {
                    if (r < index_of_row)
                        m.data[r][c] = base_matrix.data[r][c];
                    else if (r > index_of_row)
                        m.data[r][c] = base_matrix.data[r - 1][c];
                    else
                        m.data[r][c] = row_matrix.data[0][c];
                }
            }
            return m;
        }
        else if (index_of_row == base_matrix.rows)
            return append_row_matrix(base_matrix, row_matrix);
        else
            return base_matrix;
    }
    return base_matrix;
}

Matrix insert_column_matrix(Matrix base_matrix, i64 index_of_col, Matrix column_matrix)
{
    if (column_matrix.cols == 1)
    {
        if (index_of_col >= 0 && index_of_col < base_matrix.cols)
        {
            Matrix m = new_matrix(base_matrix.rows, base_matrix.cols + 1);
            for (i64 r = 0; r < base_matrix.rows; r++)
            {
                for (i64 c = 0; c < base_matrix.cols + 1; c++)
                {
                    if (c < index_of_col)
                        m.data[r][c] = base_matrix.data[r][c];
                    else if (c > index_of_col)
                        m.data[r][c] = base_matrix.data[r][c - 1];
                    else
                        m.data[r][c] = column_matrix.data[r][0];
                }
            }
            return m;
        }
        else if (index_of_col == base_matrix.rows)
            return append_column_matrix(base_matrix, column_matrix);
        return base_matrix;
    }
    return base_matrix;
}

Matrix del_row_matrix(Matrix base_matrix, i64 index_of_row)
{
    if (index_of_row >= 0 && index_of_row < base_matrix.rows)
    {
        Matrix m = new_matrix(base_matrix.rows - 1, base_matrix.cols);
        for (i64 r = 0; r < base_matrix.rows; r++)
        {
            if (r == index_of_row)
                continue;
            for (i64 c = 0; c < base_matrix.cols; c++)
            {
                if (r < index_of_row)
                    m.data[r][c] = base_matrix.data[r][c];
                else if (r > index_of_row)
                    m.data[r - 1][c] = base_matrix.data[r][c];
            }
        }
        return m;
    }
    return base_matrix;
}

Matrix del_column_matrix(Matrix base_matrix, i64 index_of_col)
{
    if (index_of_col >= 0 && index_of_col < base_matrix.cols)
    {
        Matrix m = new_matrix(base_matrix.rows, base_matrix.cols - 1);
        for (i64 r = 0; r < base_matrix.rows; r++)
        {
            for (i64 c = 0; c < base_matrix.cols; c++)
            {
                if (c < index_of_col)
                    m.data[r][c] = base_matrix.data[r][c];
                else if (c > index_of_col)
                    m.data[r][c - 1] = base_matrix.data[r][c];
                else
                    continue;
            }
        }
        return m;
    }
    return base_matrix;
}

Matrix replace_row_matrix(Matrix base_matrix, i64 index_of_row, Matrix row_matrix)
{
    if (row_matrix.rows == 1 && index_of_row >= 0 && index_of_row < base_matrix.rows)
    {
        Matrix m = new_matrix(base_matrix.rows, base_matrix.cols);
        for (i64 r = 0; r < base_matrix.rows; r++)
        {
            for (i64 c = 0; c < base_matrix.cols; c++)
            {
                if (r == index_of_row)
                    m.data[r][c] = row_matrix.data[0][c];
                else
                    m.data[r][c] = base_matrix.data[r][c];
            }
        }
        return m;
    }
    return base_matrix;
}

Matrix replace_column_matrix(Matrix base_matrix, i64 index_of_col, Matrix column_matrix)
{
    if (column_matrix.cols == 1 && index_of_col >= 0 && index_of_col < base_matrix.cols)
    {
        Matrix m = new_matrix(base_matrix.rows, base_matrix.cols);
        for (i64 r = 0; r < base_matrix.rows; r++)
        {
            for (i64 c = 0; c < base_matrix.cols; c++)
            {
                if (c == index_of_col)
                    m.data[r][c] = column_matrix.data[r][0];
                else
                    m.data[r][c] = base_matrix.data[r][c];
            }
        }
        return m;
    }
    return base_matrix;
}

Matrix pop_row_matrix(Matrix base_matrix)
{
    if (base_matrix.rows > 0)
        return del_row_matrix(base_matrix, base_matrix.rows - 1);
    return base_matrix;
}

Matrix pop_column_matrix(Matrix base_matrix)
{
    if (base_matrix.cols > 0)
        return del_column_matrix(base_matrix, base_matrix.cols - 1);
    return base_matrix;
}

Matrix swap_index(Matrix base_matrix, Matrix_Index first_index, Matrix_Index second_index)
{
    if (first_index.first < base_matrix.rows && first_index.second < base_matrix.cols && second_index.first < base_matrix.rows && second_index.second < base_matrix.cols && first_index.first != second_index.first && first_index.second != second_index.second)
    {
        Matrix mat = copy_matrix(base_matrix);
        mat.data[first_index.first][first_index.second] = base_matrix.data[second_index.first][second_index.second];
        mat.data[second_index.first][second_index.second] = base_matrix.data[first_index.first][first_index.second];
        return mat;
    }
    return base_matrix;
}

Matrix swap_row(Matrix base_matrix, i64 first_row, i64 second_row)
{
    if (first_row < base_matrix.rows && second_row < base_matrix.rows && first_row != second_row)
    {
        Matrix mat = copy_matrix(base_matrix);
        for (i64 c = 0; c < base_matrix.cols; c++)
        {
            mat.data[first_row][c] = base_matrix.data[second_row][c];
            mat.data[second_row][c] = base_matrix.data[first_row][c];
        }
        return mat;
    }
    return base_matrix;
}

Matrix swap_column(Matrix base_matrix, i64 first_col, i64 second_col)
{
    if (first_col < base_matrix.cols && second_col < base_matrix.cols && first_col != second_col)
    {
        Matrix mat = copy_matrix(base_matrix);
        for (i64 r = 0; r < base_matrix.cols; r++)
        {
            mat.data[r][first_col] = base_matrix.data[r][second_col];
            mat.data[r][second_col] = base_matrix.data[r][first_col];
        }
        return mat;
    }
    return base_matrix;
}

Matrix get_row_matrix(Matrix base_matrix, i64 index_of_row)
{
    if (index_of_row >= 0 && index_of_row < base_matrix.rows)
    {
        Matrix m = new_matrix(1, base_matrix.cols);
        for (i64 c = 0; c < base_matrix.cols; c++)
            m.data[0][c] = base_matrix.data[index_of_row][c];
        return m;
    }
    return new_matrix(0, 0);
}

Matrix get_column_matrix(Matrix base_matrix, i64 index_of_col)
{
    if (index_of_col >= 0 && index_of_col < base_matrix.rows)
    {
        Matrix m = new_matrix(base_matrix.rows, 1);
        for (i64 r = 0; r < base_matrix.rows; r++)
            m.data[r][0] = base_matrix.data[r][index_of_col];
        return m;
    }
    return new_matrix(0, 0);
}

Matrix_Index matrix_shape(Matrix matrix)
{
    return new_matrix_index(matrix.rows, matrix.cols);
}

_Bool are_similar_num_array(NumArray array_1, NumArray array_2)
{
    return (array_1.len == array_2.len);
}

_Bool are_similar_matrix(Matrix matrix_1, Matrix matrix_2)
{
    return (matrix_1.rows == matrix_2.rows && matrix_1.cols == matrix_2.cols);
}

i64 clip_int(i64 number, i64 min, i64 max)
{
    if (number <= min)
        return min;
    else if (number >= max)
        return max;
    return number;
}

f80 clip_double(f80 number, f80 min, f80 max)
{
    if (number < min)
        return min;
    else if (number > max)
        return max;
    return number;
}

NumArray clip_number_array(NumArray array, f80 min, f80 max)
{
    NumArray clipped_array = new_num_array(array.len);
    for (i64 i = 0; i < array.len; i++)
    {
        if (array.nums[i] >= min && array.nums[i] <= max)
            clipped_array.nums[i] = array.nums[i];
        else if (array.nums[i] < min)
            clipped_array.nums[i] = min;
        else if (array.nums[i] > max)
            clipped_array.nums[i] = max;
    }
    return clipped_array;
}

Matrix clip_matrix(Matrix matrix, f80 min, f80 max)
{
    Matrix clipped_matrix = new_matrix(matrix.rows, matrix.cols);
    for (i64 r = 0; r < matrix.rows; r++)
    {
        for (i64 c = 0; c < matrix.cols; c++)
        {
            if (matrix.data[r][c] >= min && matrix.data[r][c] <= max)
                clipped_matrix.data[r][c] = matrix.data[r][c];
            else if (matrix.data[r][c] < min)
                clipped_matrix.data[r][c] = min;
            else if (matrix.data[r][c] > max)
                clipped_matrix.data[r][c] = max;
        }
    }
    return clipped_matrix;
}

i64 argmax_num_array_index(NumArray array)
{
    i64 arg = 0;
    for (i64 i = 1; i < array.len; i++)
        arg = (array.nums[arg] > array.nums[i]) ? arg : i;
    return arg;
}

i64 argmin_num_array_index(NumArray array)
{
    i64 arg = 0;
    for (i64 i = 1; i < array.len; i++)
        arg = (array.nums[arg] < array.nums[i]) ? arg : i;
    return arg;
}

NumArray argmax_matrix_row_indices(Matrix matrix)
{
    NumArray arg_array = new_num_array(matrix.rows * matrix.cols);
    for (i64 r = 0; r < matrix.rows; r++)
    {
        i64 arg_c = 0;
        for (i64 c = 1; c < matrix.cols; c++)
            arg_c = (matrix.data[r][arg_c] > matrix.data[r][c]) ? arg_c : c;
        arg_array.nums[r] = arg_c;
    }
    return arg_array;
}

NumArray argmax_matrix_column_indices(Matrix matrix)
{
    NumArray arg_array = new_num_array(matrix.rows * matrix.cols);
    for (i64 c = 0; c < matrix.cols; c++)
    {
        i64 arg_r = 0;
        for (i64 r = 1; r < matrix.rows; r++)
            arg_r = (matrix.data[arg_r][c] > matrix.data[r][c]) ? arg_r : r;
        arg_array.nums[c] = arg_r;
    }
    return arg_array;
}

NumArray argmin_matrix_row_indices(Matrix matrix)
{
    NumArray arg_array = new_num_array(matrix.rows * matrix.cols);
    for (i64 r = 0; r < matrix.rows; r++)
    {
        i64 arg_c = 0;
        for (i64 c = 1; c < matrix.cols; c++)
            arg_c = (matrix.data[r][arg_c] < matrix.data[r][c]) ? arg_c : c;
        arg_array.nums[r] = arg_c;
    }
    return arg_array;
}

NumArray argmin_matrix_column_indices(Matrix matrix)
{
    NumArray arg_array = new_num_array(matrix.rows * matrix.cols);
    for (i64 c = 0; c < matrix.cols; c++)
    {
        i64 arg_r = 0;
        for (i64 r = 1; r < matrix.rows; r++)
            arg_r = (matrix.data[arg_r][c] < matrix.data[r][c]) ? arg_r : r;
        arg_array.nums[c] = arg_r;
    }
    return arg_array;
}

f80 sum_num_array(NumArray array)
{
    f80 sum = 0;
    for (i64 i = 0; i < array.len; i++)
        sum += array.nums[i];
    return sum;
}

f80 mean_num_array(NumArray array)
{
    return (sum_num_array(array) / (array.len));
}

f80 product_num_array(NumArray array)
{
    f80 product = 0;
    for (i64 i = 0; i < array.len; i++)
        product *= array.nums[i];
    return product;
}

f80 max_num_array_element(NumArray array)
{
    f80 max = array.nums[0];
    for (i64 i = 1; i < array.len; i++)
        max = (max > array.nums[i]) ? max : array.nums[i];
    return max;
}

f80 min_num_array_element(NumArray array)
{
    f80 min = array.nums[0];
    for (i64 i = 1; i < array.len; i++)
        min = (min < array.nums[i]) ? min : array.nums[i];
    return min;
}

Matrix sum_matrix_row_elements(Matrix matrix)
{
    Matrix sum_matrix = new_matrix(matrix.rows, 1);
    for (i64 r = 0; r < matrix.rows; r++)
    {
        f80 sum = 0;
        for (i64 c = 0; c < matrix.cols; c++)
            sum += matrix.data[r][c];
        sum_matrix.data[r][0] = sum;
    }
    return sum_matrix;
}

Matrix sum_matrix_column_elements(Matrix matrix)
{
    Matrix sum_matrix = new_matrix(1, matrix.cols);
    for (i64 c = 0; c < matrix.cols; c++)
    {
        f80 sum = 0;
        for (i64 r = 0; r < matrix.rows; r++)
            sum += matrix.data[r][c];
        sum_matrix.data[0][c] = sum;
    }
    return sum_matrix;
}

Matrix product_matrix_row_elements(Matrix matrix)
{
    Matrix product_matrix = new_matrix(matrix.rows, 1);
    for (i64 r = 0; r < matrix.rows; r++)
    {
        f80 product = 0;
        for (i64 c = 0; c < matrix.cols; c++)
            product *= matrix.data[r][c];
        product_matrix.data[r][0] = product;
    }
    return product_matrix;
}

Matrix product_matrix_column_elements(Matrix matrix)
{
    Matrix product_matrix = new_matrix(1, matrix.cols);
    for (i64 c = 0; c < matrix.cols; c++)
    {
        f80 product = 0;
        for (i64 r = 0; r < matrix.rows; r++)
            product *= matrix.data[r][c];
        product_matrix.data[0][c] = product;
    }
    return product_matrix;
}

Matrix max_matrix_row_elements(Matrix matrix)
{
    Matrix max_matrix = new_matrix(matrix.rows, 1);
    for (i64 r = 0; r < matrix.rows; r++)
    {
        f80 max = matrix.data[r][0];
        for (i64 c = 1; c < matrix.cols; c++)
            max = (max > matrix.data[r][c]) ? max : matrix.data[r][c];
        max_matrix.data[r][0] = max;
    }
    return max_matrix;
}

Matrix max_matrix_column_elements(Matrix matrix)
{
    Matrix max_matrix = new_matrix(1, matrix.cols);
    for (i64 c = 0; c < matrix.cols; c++)
    {
        f80 max = matrix.data[0][c];
        for (i64 r = 1; r < matrix.rows; r++)
            max = (max > matrix.data[r][c]) ? max : matrix.data[r][c];
        max_matrix.data[0][c] = max;
    }
    return max_matrix;
}

Matrix min_matrix_row_elements(Matrix matrix)
{
    Matrix min_matrix = new_matrix(matrix.rows, 1);
    for (i64 r = 0; r < matrix.rows; r++)
    {
        f80 min = matrix.data[r][0];
        for (i64 c = 1; c < matrix.cols; c++)
            min = (min < matrix.data[r][c]) ? min : matrix.data[r][c];
        min_matrix.data[r][0] = min;
    }
    return min_matrix;
}

Matrix min_matrix_column_elements(Matrix matrix)
{
    Matrix min_matrix = new_matrix(1, matrix.cols);
    for (i64 c = 0; c < matrix.cols; c++)
    {
        f80 min = matrix.data[0][c];
        for (i64 r = 1; r < matrix.rows; r++)
            min = (min < matrix.data[r][c]) ? min : matrix.data[r][c];
        min_matrix.data[0][c] = min;
    }
    return min_matrix;
}

Matrix max_matrix_elements(Matrix matrix_1, Matrix matrix_2)
{
    if (are_similar_matrix(matrix_1, matrix_2))
    {
        Matrix max_matrix = new_matrix(matrix_1.rows, matrix_1.cols);
        for (i64 r = 0; r < matrix_1.rows; r++)
        {
            for (i64 c = 0; c < matrix_1.cols; c++)
                max_matrix.data[r][c] = max_double(matrix_1.data[r][c], matrix_2.data[r][c]);
        }
        return max_matrix;
    }
    else
        return new_matrix(0, 0);
}

Matrix min_matrix_elements(Matrix matrix_1, Matrix matrix_2)
{
    if (are_similar_matrix(matrix_1, matrix_2))
    {
        Matrix min_matrix = new_matrix(matrix_1.rows, matrix_1.cols);
        for (i64 r = 0; r < matrix_1.rows; r++)
        {
            for (i64 c = 0; c < matrix_1.cols; c++)
                min_matrix.data[r][c] = min_double(matrix_1.data[r][c], matrix_2.data[r][c]);
        }
        return min_matrix;
    }
    else
        return new_matrix(0, 0);
}

Matrix exp_matrix(Matrix matrix)
{
    Matrix exped_matrix = new_matrix(matrix.rows, matrix.cols);
    for (i64 r = 0; r < matrix.rows; r++)
    {
        for (i64 c = 0; c < matrix.cols; c++)
            exped_matrix.data[r][c] = exp(matrix.data[r][c]);
    }
    return exped_matrix;
}

Matrix exp_matrix_(Matrix matrix, f80 base)
{
    Matrix exped_matrix = new_matrix(matrix.rows, matrix.cols);
    for (i64 r = 0; r < matrix.rows; r++)
    {
        for (i64 c = 0; c < matrix.cols; c++)
            exped_matrix.data[r][c] = power_double(base, matrix.data[r][c]);
    }
    return exped_matrix;
}

NumArray compare_num_array_elements(NumArray array_1, char *comparator, NumArray array_2)
{
    if (are_similar_num_array(array_1, array_2))
    {
        NumArray new_array = new_num_array(array_1.len);

        if (strcmp(comparator, "==") == 0)
        {
            for (i64 i = 0; i < array_1.len; i++)
                new_array.nums[i] = (array_1.nums[i] == array_2.nums[i]);
            return new_array;
        }
        else if (strcmp(comparator, "!=") == 0)
        {
            for (i64 i = 0; i < array_1.len; i++)
                new_array.nums[i] = (array_1.nums[i] != array_2.nums[i]);
            return new_array;
        }
        else if (strcmp(comparator, "<") == 0)
        {
            for (i64 i = 0; i < array_1.len; i++)
                new_array.nums[i] = (array_1.nums[i] < array_2.nums[i]);
            return new_array;
        }
        else if (strcmp(comparator, "<=") == 0)
        {
            for (i64 i = 0; i < array_1.len; i++)
                new_array.nums[i] = (array_1.nums[i] <= array_2.nums[i]);
            return new_array;
        }
        else if (strcmp(comparator, ">") == 0)
        {
            for (i64 i = 0; i < array_1.len; i++)
                new_array.nums[i] = (array_1.nums[i] > array_2.nums[i]);
            return new_array;
        }
        else if (strcmp(comparator, ">=") == 0)
        {
            for (i64 i = 0; i < array_1.len; i++)
                new_array.nums[i] = (array_1.nums[i] >= array_2.nums[i]);
            return new_array;
        }
        return new_array;
    }
    return new_num_array(array_1.len);
}

Matrix compare_matrix_elements(Matrix matrix_1, char *comparator, Matrix matrix_2)
{
    if (are_similar_matrix(matrix_1, matrix_2))
    {
        Matrix new_mat = new_matrix(matrix_1.rows, matrix_1.cols);
        if (strcmp(comparator, "==") == 0)
        {
            for (i64 r = 0; r < matrix_1.rows; r++)
            {
                for (i64 c = 0; c < matrix_1.cols; c++)
                    new_mat.data[r][c] = (matrix_1.data[r][c] == matrix_2.data[r][c]);
            }
            return new_mat;
        }
        else if (strcmp(comparator, "!=") == 0)
        {
            for (i64 r = 0; r < matrix_1.rows; r++)
            {
                for (i64 c = 0; c < matrix_1.cols; c++)
                    new_mat.data[r][c] = (matrix_1.data[r][c] != matrix_2.data[r][c]);
            }
            return new_mat;
        }
        else if (strcmp(comparator, "<") == 0)
        {
            for (i64 r = 0; r < matrix_1.rows; r++)
            {
                for (i64 c = 0; c < matrix_1.cols; c++)
                    new_mat.data[r][c] = (matrix_1.data[r][c] < matrix_2.data[r][c]);
            }
            return new_mat;
        }
        else if (strcmp(comparator, "<=") == 0)
        {
            for (i64 r = 0; r < matrix_1.rows; r++)
            {
                for (i64 c = 0; c < matrix_1.cols; c++)
                    new_mat.data[r][c] = (matrix_1.data[r][c] <= matrix_2.data[r][c]);
            }
            return new_mat;
        }
        else if (strcmp(comparator, ">") == 0)
        {
            for (i64 r = 0; r < matrix_1.rows; r++)
            {
                for (i64 c = 0; c < matrix_1.cols; c++)
                    new_mat.data[r][c] = (matrix_1.data[r][c] > matrix_2.data[r][c]);
            }
            return new_mat;
        }
        else if (strcmp(comparator, ">=") == 0)
        {
            for (i64 r = 0; r < matrix_1.rows; r++)
            {
                for (i64 c = 0; c < matrix_1.cols; c++)
                    new_mat.data[r][c] = (matrix_1.data[r][c] >= matrix_2.data[r][c]);
            }
            return new_mat;
        }
        return new_mat;
    }
    else
        return new_matrix(matrix_1.rows, matrix_1.cols);
}

Matrix principal_diagonal(Matrix matrix)
{
    if (matrix.rows == matrix.cols)
    {
        Matrix diagonal_matrix = new_matrix(1, matrix.cols);
        for (i64 r = 0; r < matrix.rows; r++)
            diagonal_matrix.data[0][r] = matrix.data[r][r];
        return diagonal_matrix;
    }
    return new_matrix(0, 0);
}

Matrix principal_diagonal_matrix(Matrix matrix)
{
    if (matrix.rows == matrix.cols)
    {
        Matrix diagonal_matrix = new_matrix(matrix.rows, matrix.cols);
        for (i64 r = 0; r < matrix.rows; r++)
            diagonal_matrix.data[r][r] = matrix.data[r][r];
        return diagonal_matrix;
    }
    return new_matrix(0, 0);
}

f80 trace(Matrix matrix)
{
    if (matrix.rows == matrix.cols)
    {
        f80 sum = 0;
        for (i64 r = 0; r < matrix.rows; r++)
            sum += matrix.data[r][r];
        return sum;
    }
    return 0;
}

Matrix secondary_diagonal(Matrix matrix)
{
    if (matrix.rows == matrix.cols)
    {
        Matrix diagonal_matrix = new_matrix(1, matrix.cols);
        for (i64 r = 0; r < matrix.rows; r++)
            diagonal_matrix.data[0][r] = matrix.data[r][matrix.cols - r - 1];
        return diagonal_matrix;
    }
    return new_matrix(0, 0);
}

Matrix secondary_diagonal_matrix(Matrix matrix)
{
    if (matrix.rows == matrix.cols)
    {
        Matrix diagonal_matrix = new_matrix(matrix.rows, matrix.cols);
        for (i64 r = 0; r < matrix.rows; r++)
            diagonal_matrix.data[r][matrix.cols - r - 1] = matrix.data[r][matrix.cols - r - 1];
        return diagonal_matrix;
    }
    return new_matrix(0, 0);
}

f80 secondary_trace(Matrix matrix)
{
    if (matrix.rows == matrix.cols)
    {
        f80 sum = 0;
        for (i64 r = 0; r < matrix.rows; r++)
            sum += matrix.data[r][matrix.cols - r - 1];
        return sum;
    }
    return 0;
}

Matrix scale_matrix(Matrix matrix, f80 scalar_number)
{
    Matrix scaled_matrix = new_matrix(matrix.rows, matrix.cols);
    for (i64 r = 0; r < matrix.rows; r++)
    {
        for (i64 c = 0; c < matrix.cols; c++)
            scaled_matrix.data[r][c] = scalar_number * matrix.data[r][c];
    }
    return scaled_matrix;
}

Matrix mean_matrix_row_elements(Matrix matrix)
{
    return scale_matrix(sum_matrix_row_elements(matrix), 1 / (matrix.cols));
}

Matrix mean_matrix_column_elements(Matrix matrix)
{
    return scale_matrix(sum_matrix_column_elements(matrix), 1 / (matrix.rows));
}

Matrix add_matrix(Matrix matrix_1, Matrix matrix_2)
{
    if (are_perfect_matrix(matrix_1, matrix_2, addition))
    {
        Matrix result = new_matrix(matrix_1.rows, matrix_1.cols);
        for (i64 r = 0; r < matrix_1.rows; r++)
        {
            for (i64 c = 0; c < matrix_1.cols; c++)
                result.data[r][c] = matrix_1.data[r][c] + matrix_2.data[r][c];
        }
        return result;
    }
    return new_matrix(0, 0);
}

Matrix subtract_matrix(Matrix matrix_1, Matrix matrix_2)
{
    if (are_perfect_matrix(matrix_1, matrix_2, subtraction))
    {
        Matrix result = new_matrix(matrix_1.rows, matrix_1.cols);
        for (i64 r = 0; r < matrix_1.rows; r++)
        {
            for (i64 c = 0; c < matrix_1.cols; c++)
                result.data[r][c] = matrix_1.data[r][c] - matrix_2.data[r][c];
        }
        return result;
    }
    return new_matrix(0, 0);
}

Matrix add_row_matrix(Matrix base_matrix, Matrix row_matrix)
{
    if (base_matrix.cols == row_matrix.cols)
    {
        Matrix result = new_matrix(base_matrix.rows, base_matrix.cols);
        for (i64 r = 0; r < base_matrix.rows; r++)
        {
            for (i64 c = 0; c < base_matrix.cols; c++)
                result.data[r][c] = base_matrix.data[r][c] + row_matrix.data[0][c];
        }
        return result;
    }
    return new_matrix(0, 0);
}

Matrix add_column_matrix(Matrix base_matrix, Matrix column_matrix)
{
    if (base_matrix.rows == column_matrix.rows)
    {
        Matrix result = new_matrix(base_matrix.rows, base_matrix.cols);
        for (i64 r = 0; r < base_matrix.rows; r++)
        {
            for (i64 c = 0; c < base_matrix.cols; c++)
                result.data[r][c] = base_matrix.data[r][c] + column_matrix.data[r][0];
        }
        return result;
    }
    return new_matrix(0, 0);
}

Matrix subtract_row_matrix(Matrix base_matrix, Matrix row_matrix)
{
    if (base_matrix.cols == row_matrix.cols)
    {
        Matrix result = new_matrix(base_matrix.rows, base_matrix.cols);
        for (i64 r = 0; r < base_matrix.rows; r++)
        {
            for (i64 c = 0; c < base_matrix.cols; c++)
                result.data[r][c] = base_matrix.data[r][c] - row_matrix.data[0][c];
        }
        return result;
    }
    return new_matrix(0, 0);
}

Matrix subtract_column_matrix(Matrix base_matrix, Matrix column_matrix)
{
    if (base_matrix.rows == column_matrix.rows)
    {
        Matrix result = new_matrix(base_matrix.rows, base_matrix.cols);
        for (i64 r = 0; r < base_matrix.rows; r++)
        {
            for (i64 c = 0; c < base_matrix.cols; c++)
                result.data[r][c] = base_matrix.data[r][c] - column_matrix.data[r][0];
        }
        return result;
    }
    return new_matrix(0, 0);
}

Matrix divide_row_matrix(Matrix base_matrix, Matrix row_matrix)
{
    if (base_matrix.cols == row_matrix.cols)
    {
        Matrix result = new_matrix(base_matrix.rows, base_matrix.cols);
        for (i64 r = 0; r < base_matrix.rows; r++)
        {
            for (i64 c = 0; c < base_matrix.cols; c++)
                result.data[r][c] = base_matrix.data[r][c] / row_matrix.data[0][c];
        }
        return result;
    }
    return new_matrix(0, 0);
}

Matrix divide_column_matrix(Matrix base_matrix, Matrix column_matrix)
{
    if (base_matrix.rows == column_matrix.rows)
    {
        Matrix result = new_matrix(base_matrix.rows, base_matrix.cols);
        for (i64 r = 0; r < base_matrix.rows; r++)
        {
            for (i64 c = 0; c < base_matrix.cols; c++)
                result.data[r][c] = base_matrix.data[r][c] / column_matrix.data[r][0];
        }
        return result;
    }
    return new_matrix(0, 0);
}

Matrix mod_row_matrix(Matrix base_matrix, Matrix row_matrix)
{
    if (base_matrix.cols == row_matrix.cols)
    {
        Matrix result = new_matrix(base_matrix.rows, base_matrix.cols);
        for (i64 r = 0; r < base_matrix.rows; r++)
        {
            for (i64 c = 0; c < base_matrix.cols; c++)
                result.data[r][c] = (i64)base_matrix.data[r][c] % (i64)row_matrix.data[0][c];
        }
        return result;
    }
    return new_matrix(0, 0);
}

Matrix mod_column_matrix(Matrix base_matrix, Matrix column_matrix)
{
    if (base_matrix.rows == column_matrix.rows)
    {
        Matrix result = new_matrix(base_matrix.rows, base_matrix.cols);
        for (i64 r = 0; r < base_matrix.rows; r++)
        {
            for (i64 c = 0; c < base_matrix.cols; c++)
                result.data[r][c] = (i64)base_matrix.data[r][c] % (i64)column_matrix.data[r][0];
        }
        return result;
    }
    return new_matrix(0, 0);
}

Matrix multiply_matrix(Matrix matrix_1, Matrix matrix_2)
{
    if (are_perfect_matrix(matrix_1, matrix_2, multiplication))
    {
        Matrix result = new_matrix(matrix_1.rows, matrix_2.cols);
        for (i64 i = 0; i < matrix_1.rows; i++)
        {
            for (i64 j = 0; j < matrix_2.cols; j++)
            {
                result.data[i][j] = 0;
                for (i64 k = 0; k < matrix_2.rows; k++)
                    result.data[i][j] += matrix_1.data[i][k] * matrix_2.data[k][j];
            }
        }
        return result;
    }
    return new_matrix(0, 0);
}

Matrix power_matrix(Matrix matrix, i64 n)
{
    if (matrix.rows == matrix.cols)
    {
        if (n == 0)
            return new_identity_matrix(matrix.rows);
        else if (n == 1)
            return matrix;
        else if (n > 1)
        {
            Matrix result = new_identity_matrix(matrix.rows);
            Matrix m = copy_matrix(matrix);
            while (n > 0)
            {
                if (n & 1)
                    result = multiply_matrix(result, m);
                m = multiply_matrix(m, m);
                n /= 2;
            }
            return result;
        }
        else
            return matrix;
    }
    return matrix;
}

Matrix minor_matrix(Matrix matrix, i64 index_row, i64 index_col)
{
    if (is_square_matrix(matrix))
    {
        Matrix minor = new_matrix(matrix.rows - 1, matrix.cols - 1);
        i64 r = 0, c = 0;
        for (i64 row = 0; row < matrix.rows; row++)
        {
            if (row != index_row)
            {
                for (i64 col = 0; col < matrix.rows; col++)
                {
                    if (col != index_col)
                        minor.data[r][c++] = matrix.data[row][col];
                }
                c = 0;
                r++;
            }
        }
        return minor;
    }
    return new_matrix(0, 0);
}

f80 determinant(Matrix matrix)
{
    if (is_square_matrix(matrix))
    {
        if (matrix.rows == 1 && matrix.cols == 1)
            return matrix.data[0][0];
        Matrix temp_minor_matrix = new_matrix(matrix.rows - 1, matrix.cols - 1);
        i64 sign = 1;
        f80 det = 0;
        for (i64 c = 0; c < matrix.rows; c++)
        {
            temp_minor_matrix = minor_matrix(matrix, 0, c);
            det += sign * matrix.data[0][c] * determinant(temp_minor_matrix);
            sign = -sign;
        }
        return det;
    }
    return 0;
}

f80 minor(Matrix matrix, i64 index_row, i64 index_col)
{
    if (is_square_matrix(matrix))
        return determinant(minor_matrix(matrix, index_row, index_col));
    return 0;
}

f80 co_factor(Matrix matrix, i64 index_row, i64 index_col)
{
    if (is_square_matrix(matrix))
    {
        i64 sign = (index_row + index_col) % 2 == 0 ? 1 : -1;
        return (f80)sign * determinant(minor_matrix(matrix, index_row, index_col));
    }
    return 0;
}

Matrix adjoint(Matrix matrix)
{
    if (is_square_matrix(matrix))
    {
        Matrix adjoint_matrix = new_matrix(matrix.rows, matrix.cols);
        for (i64 r = 0; r < matrix.cols; r++)
        {
            for (i64 c = 0; c < matrix.rows; c++)
                adjoint_matrix.data[r][c] = co_factor(matrix, r, c);
        }
        return transpose(adjoint_matrix);
    }
    return new_matrix(0, 0);
}

Matrix inverse(Matrix matrix)
{
    if (is_square_matrix(matrix))
        return scale_matrix(adjoint(matrix), 1.0 / determinant(matrix));
    return new_matrix(0, 0);
}

Vector2D add_vector2D(Vector2D vector_1, Vector2D vector_2)
{
    return new_vector2D((vector_1.X + vector_2.X), (vector_1.Y + vector_2.Y));
}

Vector add_vector(Vector vector_1, Vector vector_2)
{
    return new_vector((vector_1.X + vector_2.X), (vector_1.Y + vector_2.Y), (vector_1.Z + vector_2.Z));
}

Vector2D subtract_vector2D(Vector2D vector_1, Vector2D vector_2)
{
    return new_vector2D((vector_1.X - vector_2.X), (vector_1.Y - vector_2.Y));
}

Vector subtract_vector(Vector vector_1, Vector vector_2)
{
    return new_vector((vector_1.X - vector_2.X), (vector_1.Y - vector_2.Y), (vector_1.Z - vector_2.Z));
}

Vector2D scale_vector2D(Vector2D vector, f80 scalar_number)
{
    return new_vector2D((scalar_number * vector.X), (scalar_number * vector.Y));
}

Vector scale_vector(Vector vector, f80 scalar_number)
{
    return new_vector((scalar_number * vector.X), (scalar_number * vector.Y), (scalar_number * vector.Z));
}

f80 dot2D(Vector2D vector_1, Vector2D vector_2)
{
    return ((vector_1.X * vector_2.X) + (vector_1.Y * vector_2.Y));
}

f80 dot(Vector vector_1, Vector vector_2)
{
    return ((vector_1.X * vector_2.X) + (vector_1.Y * vector_2.Y) + (vector_1.Z * vector_2.Z));
}

Vector cross2D(Vector2D vector_1, Vector2D vector_2)
{
    Vector vector = new_vector(0, 0, 0);
    vector.X = 0;
    vector.Y = 0;
    vector.Z = (vector_1.X * vector_2.Y) - (vector_1.Y * vector_2.X);
    return vector;
}

Vector cross(Vector vector_1, Vector vector_2)
{
    Vector vector = new_vector(0, 0, 0);
    vector.X = (vector_1.Y * vector_2.Z) - (vector_1.Z * vector_2.Y);
    vector.Y = (vector_1.Z * vector_2.X) - (vector_1.X * vector_2.Z);
    vector.Z = (vector_1.X * vector_2.Y) - (vector_1.Y * vector_2.X);
    return vector;
}

f80 value_of_vector2D(Vector2D vector)
{
    return (f80)sqrt(vector.X * vector.X + vector.Y * vector.Y);
}

f80 value_of_vector(Vector vector)
{
    return (f80)sqrt(vector.X * vector.X + vector.Y * vector.Y + vector.Z * vector.Z);
}

Vector2D unit_vector2D(Vector2D vector)
{
    return scale_vector2D(vector, 1 / value_of_vector2D(vector));
}

Vector unit_vector(Vector vector)
{
    return scale_vector(vector, 1 / value_of_vector(vector));
}

f80 angle_between_vectors2D(Vector2D vector_1, Vector2D vector_2, angle_mode angle_mode)
{
    f80 angle = acos(dot2D(vector_1, vector_2) / (value_of_vector2D(vector_1) * value_of_vector2D(vector_2)));
    return ((angle_mode == radian) ? angle : to_degree(angle));
}

f80 angle_between_vectors(Vector vector_1, Vector vector_2, angle_mode angle_mode)
{
    f80 angle = acos(dot(vector_1, vector_2) / (value_of_vector(vector_1) * value_of_vector(vector_2)));
    return ((angle_mode == radian) ? angle : to_degree(angle));
}

Matrix translate_row_vector_matrix(Matrix matrix, Matrix translate_by_row_matrix)
{
    if (!is_null_matrix(matrix))
        return add_row_matrix(matrix, translate_by_row_matrix);
    return matrix;
}

Matrix translate_column_vector_matrix(Matrix matrix, Matrix translate_by_column_matrix)
{
    if (!is_null_matrix(matrix))
        return add_column_matrix(matrix, translate_by_column_matrix);
    return matrix;
}

Matrix scale_row_vector_matrix(Matrix matrix, Matrix scale_by_row_matrix)
{
    if (scale_by_row_matrix.cols == matrix.cols)
    {
        Matrix scalar_matrix = new_primary_diagonal_matrix(matrix.cols, scale_by_row_matrix);
        return multiply_matrix(matrix, scalar_matrix);
    }
    return matrix;
}

Matrix scale_column_vector_matrix(Matrix matrix, Matrix scale_by_column_matrix)
{
    if (scale_by_column_matrix.cols == matrix.rows)
    {
        Matrix scalar_matrix = new_primary_diagonal_matrix(matrix.cols, transpose(scale_by_column_matrix));
        return transpose(multiply_matrix(scalar_matrix, matrix));
    }
    return matrix;
}

Matrix dot_t1(Matrix matrix_1, Matrix matrix_2)
{
    return (multiply_matrix(transpose(matrix_1), matrix_2));
}

Matrix dot_t2(Matrix matrix_1, Matrix matrix_2)
{
    return (multiply_matrix(matrix_1, transpose(matrix_2)));
}

f80 dot_array(NumArray array_1, NumArray array_2)
{
    return (multiply_matrix(row_matrix_from_array(array_1), column_matrix_from_array(array_2))).data[0][0];
}

Matrix rotation_matrix_in_2D(f80 angle, angle_mode angle_mode)
{
    if (angle_mode == degree)
        angle = to_radian(angle);
    Matrix r_matrix = new_matrix(2, 2);
    r_matrix.data[0][0] = cos(angle);
    r_matrix.data[1][0] = sin(angle);
    r_matrix.data[0][1] = -sin(angle);
    r_matrix.data[1][1] = cos(angle);
    return r_matrix;
}

Matrix rotation_matrix_in_3D(Vector rotation_axis_vector, f80 angle, angle_mode angle_mode)
{
    if (angle_mode == degree)
        angle = to_radian(angle);
    angle = angle / 2;
    Vector v = unit_vector(rotation_axis_vector);
    f80 vr = cos(angle), vi = (sin(angle) * v.X), vj = (sin(angle) * v.Y), vk = (sin(angle) * v.Z);
    Matrix r_matrix = new_matrix(3, 3);
    r_matrix.data[0][0] = 1 - (2 * (vj * vj + vk * vk));
    r_matrix.data[1][0] = 2 * (vi * vj + vk * vr);
    r_matrix.data[2][0] = 2 * (vi * vk - vj * vr);
    r_matrix.data[0][1] = 2 * (vi * vj - vk * vr);
    r_matrix.data[1][1] = 1 - (2 * (vi * vi + vk * vk));
    r_matrix.data[2][1] = 2 * (vj * vk + vi * vr);
    r_matrix.data[0][2] = 2 * (vi * vk + vj * vr);
    r_matrix.data[1][2] = 2 * (vj * vk - vi * vr);
    r_matrix.data[2][2] = 1 - (2 * (vi * vi + vj * vj));
    return r_matrix;
}

Point2D rotate_point_in_2D(Point2D point, Point2D reference_point_origin, f80 angle, angle_mode angle_mode)
{
    Matrix p_matrix = column_matrix_from_vector2D(vector2D_from_point2D(point));
    Matrix rp_matrix = column_matrix_from_vector2D(vector2D_from_point2D(reference_point_origin));
    Matrix rotation_matrix = rotation_matrix_in_2D(angle, angle_mode);
    return point2D_from_vector2D(vector2D_from_matrix(add_matrix(multiply_matrix(rotation_matrix, subtract_matrix(p_matrix, rp_matrix)), rp_matrix)));
}

Point rotate_point_in_3D(Point point, Point reference_point_origin, Vector rotation_axis_vector, f80 angle, angle_mode angle_mode)
{
    Matrix p_matrix = column_matrix_from_vector(vector_from_point(point));
    Matrix rp_matrix = column_matrix_from_vector(vector_from_point(reference_point_origin));
    Matrix rotation_matrix = rotation_matrix_in_3D(rotation_axis_vector, angle, angle_mode);
    return point_from_vector(vector_from_matrix(add_matrix(multiply_matrix(rotation_matrix, subtract_matrix(p_matrix, rp_matrix)), rp_matrix)));
}

Vector2D rotate_vector_in_2D(Vector2D vector, Vector2D reference_vector_origin, f80 angle, angle_mode angle_mode)
{
    Matrix v_matrix = column_matrix_from_vector2D(vector);
    Matrix rv_matrix = column_matrix_from_vector2D(reference_vector_origin);
    Matrix rotation_matrix = rotation_matrix_in_2D(angle, angle_mode);
    return vector2D_from_matrix(add_matrix(multiply_matrix(rotation_matrix, subtract_matrix(v_matrix, rv_matrix)), rv_matrix));
}

Vector rotate_vector_in_3D(Vector vector, Vector reference_vector_origin, Vector rotation_axis_vector, f80 angle, angle_mode angle_mode)
{
    Matrix v_matrix = column_matrix_from_vector(vector);
    Matrix rv_matrix = column_matrix_from_vector(reference_vector_origin);
    Matrix rotation_matrix = rotation_matrix_in_3D(rotation_axis_vector, angle, angle_mode);
    return vector_from_matrix(add_matrix(multiply_matrix(rotation_matrix, subtract_matrix(v_matrix, rv_matrix)), rv_matrix));
}

Matrix rotate_matrix_in_2D(Matrix column_vector2D_matrix, Vector2D reference_vector_origin, f80 angle, angle_mode angle_mode)
{
    Matrix rv_matrix = column_matrix_from_vector2D(reference_vector_origin);
    Matrix rotation_matrix = rotation_matrix_in_2D(angle, angle_mode);
    return add_matrix(multiply_matrix(rotation_matrix, subtract_matrix(column_vector2D_matrix, rv_matrix)), rv_matrix);
}

Matrix rotate_matrix_in_3D(Matrix column_vector_matrix, Vector reference_vector_origin, Vector rotation_axis_vector, f80 angle, angle_mode angle_mode)
{
    Matrix rv_matrix = column_matrix_from_vector(reference_vector_origin);
    Matrix rotation_matrix = rotation_matrix_in_3D(rotation_axis_vector, angle, angle_mode);
    return add_matrix(multiply_matrix(rotation_matrix, subtract_matrix(column_vector_matrix, rv_matrix)), rv_matrix);
}

Matrix solve_xy(Matrix coefficients_square_matrix, Matrix constants_column_matrix)
{
    Matrix result_column_matrix = new_matrix(coefficients_square_matrix.cols, 1);
    if (is_square_matrix(coefficients_square_matrix) && constants_column_matrix.rows == coefficients_square_matrix.cols && constants_column_matrix.cols == 1)
    {
        f80 scaling_factor = 1 / determinant(coefficients_square_matrix);
        for (i64 i = 0; i < coefficients_square_matrix.cols; i++)
            result_column_matrix.data[i][0] = scaling_factor * determinant(replace_column_matrix(coefficients_square_matrix, i, constants_column_matrix));
    }
    return result_column_matrix;
}

f80 solve_x(f80 a, f80 b)
{
    return -(b / a);
}

Complex_Array solve_x2(f80 a, f80 b, f80 c)
{
    Complex_Array complex_array = new_complex_array(2);
    f80 m = (b * b) - (4 * a * c);
    if (m >= 0)
    {
        f80 sqrt_m = sqrt(m);
        complex_array.complex_numbers[0] = new_complex((-b - sqrt_m) / 2, 0);
        complex_array.complex_numbers[1] = new_complex((-b + sqrt_m) / 2, 0);
        return complex_array;
    }
    Complex csqrt_m = power_complex(new_complex(m, 0), new_complex(0.5, 0));
    csqrt_m.real /= 2;
    csqrt_m.img /= 2;
    Complex cb = new_complex(-b / 2, 0);
    complex_array.complex_numbers[0] = add_complex(cb, csqrt_m);
    complex_array.complex_numbers[1] = subtract_complex(cb, csqrt_m);
    return complex_array;
}

Complex_Array solve_x3(f80 a, f80 b, f80 c, f80 d)
{
    f80 p, q, m, N, n, t, a0 = a;
    // y = 0 + 0*i
    Complex y = new_complex(0, 0);
    Complex_Array complex_array_2 = new_complex_array(2);
    Complex_Array complex_array_3 = new_complex_array(3);
    a = b / a0;
    b = c / a0;
    c = d / a0;
    d = 0;
    // p = b - (a^2 / 3)
    p = b - (0.3333333333333333 * a * a);
    // q = (2 a^3 / 27) - (a^2 / 3) + c
    q = (0.0740740740740741 * a * a * a) - (0.3333333333333333 * a * b) + c;
    // m = -q / 2
    m = -q / 2;
    // N = (q^2 / 4) + (p^3 / 27)
    N = (0.25 * (q * q)) + (0.037037037037037 * p * p * p);
    // n = |N|^(1/2)
    n = sqrt(abs_double(N));

    if (N >= 0)
        // t = (m + n)^(1/3) + (m - n)^(1/3)
        t = cbrt(m + n) + cbrt(m - n);
    else
    {
        // z = m + n*i
        Complex z = new_complex(m, n);
        // r = (m^2 + |N|)^(1/2)
        f80 r = sqrt((m * m) + abs_double(N));
        // theta = arg(r) / 3
        f80 theta = argument(z, radian) / 3;
        // t = 2 * r^(1/3) * cos(theta)
        t = 2 * cbrt(r) * cos(theta);
    }
    // u = a/3 + 0*i
    Complex u = new_complex(0.3333333333333333 * a, 0);
    y.real = t;
    // Solve [x^2 + t x + (t^2 p) x = 0], for x
    complex_array_2 = solve_x2(1, t, (t * t) + p);
    // Preparing Result...
    complex_array_3.complex_numbers[0] = subtract_complex(y, u);
    complex_array_3.complex_numbers[1] = subtract_complex(complex_array_2.complex_numbers[0], u);
    complex_array_3.complex_numbers[2] = subtract_complex(complex_array_2.complex_numbers[1], u);
    return complex_array_3;
}

_Bool is_type_of(Matrix matrix, matrix_type type)
{
    if (type == row_matrix)
    {
        if (matrix.rows == 1 && matrix.cols > 1)
            return 1;
        return 0;
    }

    else if (type == column_matrix)
    {
        if (matrix.rows > 1 && matrix.cols == 1)
            return 1;
        return 0;
    }

    else if (type == horizontal_matrix)
    {
        if (matrix.rows < matrix.cols)
            return 1;
        return 0;
    }

    else if (type == vertical_matrix)
    {
        if (matrix.rows > matrix.cols)
            return 1;
        return 0;
    }

    else if (type == singleton_matrix)
    {
        if (matrix.rows == 1 && matrix.cols == 1)
            return 1;
        return 0;
    }

    else if (type == square_matrix)
    {
        if (matrix.rows == matrix.cols)
            return 1;
        return 0;
    }

    else if (type == singular_matrix)
    {
        if (determinant(matrix) == 0)
            return 1;
        return 0;
    }

    else if (type == nonsingular_matrix)
    {
        if (determinant(matrix) != 0)
            return 1;
        return 0;
    }

    else if (type == diagonal_matrix)
    {
        if (matrix.rows == matrix.cols)
        {
            i64 n = matrix.rows, count_zeros = 0, count_non_zeros = 0;
            for (i64 r = 0; r < n; r++)
            {
                for (i64 c = 0; c < n; c++)
                {
                    if (c != r && matrix.data[r][c] == 0)
                        count_zeros++;
                    if (c == r && matrix.data[r][c] != 0)
                        count_non_zeros++;
                }
            }
            if (count_non_zeros == n && count_zeros == n * (n - 1))
                return 1;
            return 0;
        }
        return 0;
    }

    else if (type == scalar_matrix)
    {
        if (matrix.rows == matrix.cols)
        {
            i64 n = matrix.rows, constant = matrix.data[0][0], count_zeros = 0, count_consts = 0;
            for (i64 r = 0; r < n; r++)
            {
                for (i64 c = 0; c < n; c++)
                {
                    if (c != r && matrix.data[r][c] == 0)
                        count_zeros++;
                    if (c == r && matrix.data[r][c] == constant)
                        count_consts++;
                }
            }
            if (count_consts == n && count_zeros == n * (n - 1))
                return 1;
            return 0;
        }
        return 0;
    }

    else if (type == identity_matrix || type == unit_matrix)
    {
        if (matrix.rows == matrix.cols)
        {
            i64 n = matrix.rows, count_zeros = 0, count_unit = 0;
            for (i64 r = 0; r < n; r++)
            {
                for (i64 c = 0; c < n; c++)
                {
                    if (c != r && matrix.data[r][c] == 0)
                        count_zeros++;
                    if (c == r && matrix.data[r][c] == 1)
                        count_unit++;
                }
            }
            if (count_unit == n && count_zeros == n * (n - 1))
                return 1;
            return 0;
        }
        return 0;
    }

    else if (type == null_matrix || type == zero_matrix)
    {
        if (matrix.rows == matrix.cols)
        {
            i64 n = matrix.rows, count_zeros = 0;
            for (i64 r = 0; r < n; r++)
            {
                for (i64 c = 0; c < n; c++)
                {
                    if (matrix.data[r][c] == 0)
                        count_zeros++;
                }
            }
            if (count_zeros == n * n)
                return 1;
            return 0;
        }
        return 0;
    }

    else if (type == upper_triangular_matrix)
    {
        if (matrix.rows == matrix.cols)
        {
            i64 n = matrix.rows, m = (n * (n - 1)) / 2, count_zeros = 0;
            for (i64 r = 0; r < n; r++)
            {
                for (i64 c = 0; c < n; c++)
                {
                    if (c < r && matrix.data[r][c] == 0)
                        count_zeros++;
                }
            }
            if (count_zeros == m)
                return 1;
            return 0;
        }
        return 0;
    }

    else if (type == lower_triangular_matrix)
    {
        if (matrix.rows == matrix.cols)
        {
            i64 n = matrix.rows, m = (n * (n - 1)) / 2, count_zeros = 0;
            for (i64 r = 0; r < n; r++)
            {
                for (i64 c = 0; c < n; c++)
                {
                    if (c > r && matrix.data[r][c] == 0)
                        count_zeros++;
                }
            }
            if (count_zeros == m)
                return 1;
            return 0;
        }
        return 0;
    }

    else if (type == triangular_matrix)
    {
        if (is_type_of(matrix, upper_triangular_matrix) || is_type_of(matrix, lower_triangular_matrix))
            return 1;
        return 0;
    }

    else if (type == involutory_matrix)
    {
        if (matrix.rows == matrix.cols)
            return is_type_of(multiply_matrix(matrix, matrix), identity_matrix);
        return 0;
    }

    else if (type == symmetric_matrix)
    {
        if (matrix.rows == matrix.cols)
            return are_identical_matrix(matrix, transpose(matrix));
        return 0;
    }

    else if (type == skew_symmetric_matrix)
    {
        if (matrix.rows == matrix.cols)
            return are_identical_matrix(scale_matrix(matrix, -1), transpose(matrix));
        return 0;
    }

    else if (type == orthogonal_matrix)
    {
        if (matrix.rows == matrix.cols)
            return are_identical_matrix(multiply_matrix(matrix, transpose(matrix)), new_identity_matrix(matrix.rows));
        return 0;
    }

    else if (type == normal_matrix)
    {
        if (matrix.rows == matrix.cols)
            return are_identical_matrix(multiply_matrix(matrix, transpose(matrix)), multiply_matrix(transpose(matrix), matrix));
        return 0;
    }

    else if (type == idempotent_matrix)
    {
        if (matrix.rows == matrix.cols)
            return are_identical_matrix(matrix, multiply_matrix(matrix, matrix));
        return 0;
    }

    else if (type == periodic_matrix) // It is seriously very complicated to check...
    {
        if (matrix.rows == matrix.cols)
        {
            if (is_type_of(matrix, null_matrix))
                return 1;
            else if (is_type_of(matrix, identity_matrix))
                return 1;
            i64 trial = 0;
            Matrix temp_matrix = new_matrix(matrix.rows, matrix.cols);
            temp_matrix = copy_matrix(matrix);
            while (trial != 1024)
            {
                temp_matrix = multiply_matrix(temp_matrix, matrix);
                if (are_identical_matrix(matrix, temp_matrix))
                    return 1;
                trial++;
            }
            return 0;
        }
        return 0;
    }

    else if (type == nilpotent_matrix) // It is seriously very complicated to check as well...
    {
        if (matrix.rows == matrix.cols)
        {
            if (is_type_of(matrix, null_matrix))
                return 1;
            i64 trial = 0;
            Matrix temp_matrix = new_matrix(matrix.rows, matrix.cols);
            temp_matrix = copy_matrix(matrix);
            while (trial != 1024)
            {
                temp_matrix = multiply_matrix(temp_matrix, matrix);
                if (is_type_of(temp_matrix, null_matrix))
                    return 1;
                trial++;
            }
            return 0;
        }
        return 0;
    }

    else
        return 0;
}

char **types_of_matrix(Matrix matrix, text_style text_style)
{
    char **list_of_types = (char **)calloc(23, sizeof(char *));
    for (i64 i = 0; i < 22; i++)
        list_of_types[i] = (char *)calloc(32, sizeof(char));

    i64 count = 0;

    if (is_type_of(matrix, row_matrix))
    {
        if (text_style == upper)
            list_of_types[count] = "ROW-MATRIX";
        else if (text_style == lower)
            list_of_types[count] = "row-matrix";
        else
            list_of_types[count] = "Row-Matrix";
        count++;
    }

    if (is_type_of(matrix, column_matrix))
    {
        if (text_style == upper)
            list_of_types[count] = "COLUMN-MATRIX";
        else if (text_style == lower)
            list_of_types[count] = "column-matrix";
        else
            list_of_types[count] = "Column-Matrix";
        count++;
    }

    if (is_type_of(matrix, horizontal_matrix))
    {
        if (text_style == upper)
            list_of_types[count] = "HORIZONTAL-MATRIX";
        else if (text_style == lower)
            list_of_types[count] = "horizontal-matrix";
        else
            list_of_types[count] = "Horizontal-Matrix";
        return list_of_types;
    }

    if (is_type_of(matrix, vertical_matrix))
    {
        if (text_style == upper)
            list_of_types[count] = "VERTICAL-MATRIX";
        else if (text_style == lower)
            list_of_types[count] = "vertical-matrix";
        else
            list_of_types[count] = "Vertical-Matrix";
        return list_of_types;
    }

    if (is_type_of(matrix, singleton_matrix))
    {
        if (text_style == upper)
            list_of_types[count] = "SINGLETON-MATRIX";
        else if (text_style == lower)
            list_of_types[count] = "singleton-matrix";
        else
            list_of_types[count] = "Singleton-Matrix";
        count++;
    }

    if (is_type_of(matrix, square_matrix))
    {
        if (text_style == upper)
            list_of_types[count] = "SQUARE-MATRIX";
        else if (text_style == lower)
            list_of_types[count] = "square-matrix";
        else
            list_of_types[count] = "Square-Matrix";
        count++;
    }

    if (is_type_of(matrix, singular_matrix))
    {
        if (text_style == upper)
            list_of_types[count] = "SINGULAR-MATRIX";
        else if (text_style == lower)
            list_of_types[count] = "singular-matrix";
        else
            list_of_types[count] = "Singular-Matrix";
        count++;
    }

    if (is_type_of(matrix, nonsingular_matrix))
    {
        if (text_style == upper)
            list_of_types[count] = "NONSINGULAR-MATRIX";
        else if (text_style == lower)
            list_of_types[count] = "nonsingular-matrix";
        else
            list_of_types[count] = "Nonsingular-Matrix";
        count++;
    }

    if (is_type_of(matrix, diagonal_matrix))
    {
        if (text_style == upper)
            list_of_types[count] = "DIAGONAL-MATRIX";
        else if (text_style == lower)
            list_of_types[count] = "diagonal-matrix";
        else
            list_of_types[count] = "Diagonal-Matrix";
        count++;
    }

    if (is_type_of(matrix, scalar_matrix))
    {
        if (text_style == upper)
            list_of_types[count] = "SCALAR-MATRIX";
        else if (text_style == lower)
            list_of_types[count] = "scalar-matrix";
        else
            list_of_types[count] = "Scalar-Matrix";
        count++;
    }

    if (is_type_of(matrix, identity_matrix))
    {
        if (text_style == upper)
            list_of_types[count] = "IDENTITY-MATRIX / UNIT-MATRIX";
        else if (text_style == lower)
            list_of_types[count] = "identity-matrix / unit-matrix";
        else
            list_of_types[count] = "Identity-Matrix / Unit-Matrix";
        count++;
    }

    if (is_type_of(matrix, null_matrix))
    {
        if (text_style == upper)
            list_of_types[count] = "NULL-MATRIX / ZERO-MATRIX";
        else if (text_style == lower)
            list_of_types[count] = "null-matrix / zero-matrix";
        else
            list_of_types[count] = "Null-Matrix / Zero-Matrix";
        count++;
    }

    if (is_type_of(matrix, triangular_matrix))
    {
        if (text_style == upper)
            list_of_types[count] = "TRIANGULAR-MATRIX";
        else if (text_style == lower)
            list_of_types[count] = "triangular-matrix";
        else
            list_of_types[count] = "Triangular-Matrix";
        count++;
    }

    if (is_type_of(matrix, upper_triangular_matrix))
    {
        if (text_style == upper)
            list_of_types[count] = "upper-TRIANGULAR-MATRIX";
        else if (text_style == lower)
            list_of_types[count] = "upper-triangular-matrix";
        else
            list_of_types[count] = "Upper-Triangular-Matrix";
        count++;
    }

    if (is_type_of(matrix, lower_triangular_matrix))
    {
        if (text_style == upper)
            list_of_types[count] = "lower-TRIANGULAR-MATRIX";
        else if (text_style == lower)
            list_of_types[count] = "lower-triangular-matrix";
        else
            list_of_types[count] = "Lower-Triangular-Matrix";
        count++;
    }

    if (is_type_of(matrix, involutory_matrix))
    {
        if (text_style == upper)
            list_of_types[count] = "INVOLUTORY-MATRIX";
        else if (text_style == lower)
            list_of_types[count] = "involutory-matrix";
        else
            list_of_types[count] = "Involutory-Matrix";
        count++;
    }

    if (is_type_of(matrix, symmetric_matrix))
    {
        if (text_style == upper)
            list_of_types[count] = "SYMMETRIC-MATRIX";
        else if (text_style == lower)
            list_of_types[count] = "symmetric-matrix";
        else
            list_of_types[count] = "Symmetric-Matrix";
        count++;
    }

    if (is_type_of(matrix, skew_symmetric_matrix))
    {
        if (text_style == upper)
            list_of_types[count] = "SKEW-SYMMETRIC-MATRIX";
        else if (text_style == lower)
            list_of_types[count] = "skew-symmetric-matrix";
        else
            list_of_types[count] = "Skew-Symmetric-Matrix";
        count++;
    }

    if (is_type_of(matrix, orthogonal_matrix))
    {
        if (text_style == upper)
            list_of_types[count] = "ORTHOGONAL-MATRIX";
        else if (text_style == lower)
            list_of_types[count] = "orthogonal-matrix";
        else
            list_of_types[count] = "Orthogonal-Matrix";
        count++;
    }

    if (is_type_of(matrix, normal_matrix))
    {
        if (text_style == upper)
            list_of_types[count] = "NORMAL-MATRIX";
        else if (text_style == lower)
            list_of_types[count] = "normal-matrix";
        else
            list_of_types[count] = "Normal-Matrix";
        count++;
    }

    if (is_type_of(matrix, idempotent_matrix))
    {
        if (text_style == upper)
            list_of_types[count] = "IDEMPOTENT-MATRIX";
        else if (text_style == lower)
            list_of_types[count] = "idempotent-matrix";
        else
            list_of_types[count] = "Idempotent-Matrix";
        count++;
    }

    if (is_type_of(matrix, periodic_matrix))
    {
        if (text_style == upper)
            list_of_types[count] = "PERIODIC-MATRIX";
        else if (text_style == lower)
            list_of_types[count] = "periodic-matrix";
        else
            list_of_types[count] = "Periodic-Matrix";
        count++;
    }

    if (is_type_of(matrix, nilpotent_matrix))
    {
        if (text_style == upper)
            list_of_types[count] = "NILPOTENT-MATRIX";
        else if (text_style == lower)
            list_of_types[count] = "nilpotent-matrix";
        else
            list_of_types[count] = "Nilpotent-Matrix";
    }

    return list_of_types;
}

void print_matrix_index(Matrix_Index index)
{
    printf("(%lld, %lld)", index.first, index.second);
}

void print_matrix_index_(Matrix_Index index)
{
    print_matrix_index(index);
    newline(1);
}

void print_polar2D(Polar2D point)
{
    if (point.r == 0.0 && point.theta == 0.0)
        printf("(0, 0)");
    else if (point.r != 0.0 && point.theta == 0.0)
        printf("(%0.15Lf, 0)", point.r);
    else if (point.r == 0.0 && point.theta != 0.0)
        printf("(0, %0.15Lf)", point.theta);
    else
        printf("(%0.15Lf, %0.15Lf)", point.r, point.theta);
}

void print_polar2D_(Polar2D point)
{
    print_polar2D(point);
    newline(1);
}

void print_polar(Polar point)
{
    if (point.r == 0.0 && point.theta_x == 0.0 && point.theta_z == 0.0)
        printf("(0, 0, 0)");
    else if (point.r != 0.0 && point.theta_x == 0.0 && point.theta_z == 0.0)
        printf("(%0.15Lf, 0, 0)", point.r);
    else if (point.r == 0.0 && point.theta_x != 0.0 && point.theta_z == 0.0)
        printf("(0, %0.15Lf, 0)", point.theta_x);
    else if (point.r != 0.0 && point.theta_x != 0.0 && point.theta_z == 0.0)
        printf("(%0.15Lf, %0.15Lf, 0)", point.r, point.theta_x);
    else if (point.r == 0.0 && point.theta_x == 0.0 && point.theta_z != 0.0)
        printf("(0, 0, %0.15Lf)", point.theta_z);
    else if (point.r == 0.0 && point.theta_x != 0.0 && point.theta_z != 0.0)
        printf("(0, %0.15Lf, %0.15Lf)", point.theta_x, point.theta_z);
    else if (point.r != 0.0 && point.theta_x == 0.0 && point.theta_z != 0.0)
        printf("(%0.15Lf, 0, %0.15Lf)", point.r, point.theta_z);
    else
        printf("(%0.15Lf, %0.15Lf, %0.15Lf)", point.r, point.theta_x, point.theta_z);
}

void print_polar_(Polar point)
{
    print_polar(point);
    newline(1);
}

void print_point2D(Point2D point)
{
    if (point.X == 0.0 && point.Y == 0.0)
        printf("(0, 0)");
    else if (point.X != 0.0 && point.Y == 0.0)
        printf("(%0.15Lf, 0)", point.X);
    else if (point.X == 0.0 && point.Y != 0.0)
        printf("(0, %0.15Lf)", point.Y);
    else
        printf("(%0.15Lf, %0.15Lf)", point.X, point.Y);
}

void print_point2D_(Point2D point)
{
    print_point2D(point);
    newline(1);
}

void print_point(Point point)
{
    if (point.X == 0.0 && point.Y == 0.0 && point.Z == 0.0)
        printf("(0, 0, 0)");
    else if (point.X != 0.0 && point.Y == 0.0 && point.Z == 0.0)
        printf("(%0.15Lf, 0, 0)", point.X);
    else if (point.X == 0.0 && point.Y != 0.0 && point.Z == 0.0)
        printf("(0, %0.15Lf, 0)", point.Y);
    else if (point.X == 0.0 && point.Y == 0.0 && point.Z != 0.0)
        printf("(0, 0, %0.15Lf)", point.Z);
    else if (point.X != 0.0 && point.Y != 0.0 && point.Z == 0.0)
        printf("(%0.15Lf, %0.15Lf, 0)", point.X, point.Y);
    else if (point.X != 0.0 && point.Y == 0.0 && point.Z != 0.0)
        printf("(%0.15Lf, 0, %0.15Lf)", point.X, point.Z);
    else if (point.X == 0.0 && point.Y != 0.0 && point.Z != 0.0)
        printf("(0, %0.15Lf, %0.15Lf)", point.Y, point.Z);
    else
        printf("(%0.15Lf, %0.15Lf, %0.15Lf)", point.X, point.Y, point.Z);
}

void print_point_(Point point)
{
    print_point(point);
    newline(1);
}

void print_complex(Complex number)
{
    if (number.real == 0.0 && number.img == 0.0)
        printf("(0)");
    else if (number.real != 0.0 && number.img == 0.0)
        printf("(%0.15Lf)", number.real);
    else if (number.real == 0.0 && number.img != 0.0)
        printf("(%0.15Lfi)", number.img);
    else
    {
        if (number.img < 0.0)
            printf("(%0.15Lf - %0.15Lfi)", number.real, abs_double(number.img));
        else
            printf("(%0.15Lf + %0.15Lfi)", number.real, number.img);
    }
}

void print_complex_(Complex number)
{
    print_complex(number);
    newline(1);
}

void print_complex_array(Complex_Array complex_array)
{
    if (complex_array.length == 1)
    {
        printf("[");
        print_complex(complex_array.complex_numbers[0]);
        printf("]\n");
    }
    else if (complex_array.length > 1)
    {
        printf("[");
        print_complex(complex_array.complex_numbers[0]);
        for (i64 i = 1; i < complex_array.length; i++)
        {
            printf(", ");
            print_complex(complex_array.complex_numbers[i]);
        }
        printf("]\n");
    }
}

void print_complex_array_(Complex_Array complex_array)
{
    print_complex_array(complex_array);
    newline(1);
}

void print_vector2D(Vector2D vector)
{
    if (vector.X == 0.0 && vector.Y == 0.0)
        printf("<0>");
    else if (vector.X != 0.0 && vector.Y == 0.0)
        printf("<%0.15Lfi>", vector.X);
    else if (vector.X == 0.0 && vector.Y != 0.0)
        printf("<%0.15Lfj>", vector.Y);
    else
    {
        if (vector.Y < 0.0)
            printf("<%0.15Lfi - %0.15Lfj>", vector.X, abs_double(vector.Y));
        else
            printf("<%0.15Lfi + %0.15Lfj>", vector.X, vector.Y);
    }
}

void print_vector2D_(Vector2D vector)
{
    print_vector2D(vector);
    newline(1);
}

void print_vector(Vector vector)
{
    if (vector.X == 0.0 && vector.Y == 0.0 && vector.Z == 0.0)
        printf("<0>");
    else if (vector.X != 0.0 && vector.Y == 0.0 && vector.Z == 0.0)
        printf("<%0.15Lfi>", vector.X);
    else if (vector.X == 0.0 && vector.Y != 0.0 && vector.Z == 0.0)
        printf("<%0.15Lfj>", vector.Y);
    else if (vector.X == 0.0 && vector.Y == 0.0 && vector.Z != 0.0)
        printf("<%0.15Lfk>", vector.Z);
    else if (vector.X != 0.0 && vector.Y != 0.0 && vector.Z == 0.0)
    {
        if (vector.Y < 0.0)
            printf("<%0.15Lfi - %0.15Lfj>", vector.X, abs_double(vector.Y));
        else
            printf("<%0.15Lfi + %0.15Lfj>", vector.X, vector.Y);
    }
    else if (vector.X != 0.0 && vector.Y == 0.0 && vector.Z != 0.0)
    {
        if (vector.Z < 0.0)
            printf("<%0.15Lfi - %0.15Lfk>", vector.X, abs_double(vector.Z));
        else
            printf("<%0.15Lfi + %0.15Lfk>", vector.X, vector.Z);
    }
    else if (vector.X == 0.0 && vector.Y != 0.0 && vector.Z != 0.0)
    {
        if (vector.Z < 0.0)
            printf("<%0.15Lfj - %0.15Lfk>", vector.Y, abs_double(vector.Z));
        else
            printf("<%0.15Lfj + %0.15Lfk>", vector.Y, vector.Z);
    }
    else
    {
        if (vector.Y < 0.0 && vector.Z < 0.0)
            printf("<%0.15Lfi - %0.15Lfj - %0.15Lfk>", vector.X, (f80)sqrt(vector.Y * vector.Y), (f80)sqrt(vector.Z * vector.Z));
        else if (vector.Y < 0.0 && vector.Z > 0.0)
            printf("<%0.15Lfi - %0.15Lfj + %0.15Lfk>", vector.X, (f80)sqrt(vector.Y * vector.Y), vector.Z);
        else if (vector.Y > 0.0 && vector.Z < 0.0)
            printf("<%0.15Lfi + %0.15Lfj - %0.15Lfk>", vector.X, vector.Y, (f80)sqrt(vector.Z * vector.Z));
        else
            printf("<%0.15Lfi + %0.15Lfj + %0.15Lfk>", vector.X, vector.Y, vector.Z);
    }
}

void print_vector_(Vector vector)
{
    print_vector(vector);
    newline(1);
}

void print_num_array(NumArray num_array)
{
    printf("[");
    for (i64 i = 0; i < num_array.len; i++)
    {
        printf("%0.15Lf", num_array.nums[i]);
        if ((i + 1) != num_array.len)
            printf(", ");
    }
    printf("]");
}

void print_num_array_(NumArray num_array)
{
    print_num_array(num_array);
    newline(1);
}

i64 num_len(f80 number, i64 number_of_digits_after_the_radix_dot)
{
    i64 length = (number < 0.0);
    length += (number_of_digits_after_the_radix_dot == 0) ? 0 : (number_of_digits_after_the_radix_dot + 1);
    i64 abs_int_num = (i64)abs_double(number);
    i64 count = 0;
    if (abs_int_num == 0)
        return (length + 1);
    while (abs_int_num != 0)
    {
        abs_int_num /= 10;
        count++;
    }
    length += count;
    return length;
}

i64 max_num_len(NumArray numbers, i64 number_of_digits_after_the_radix_dot)
{
    if (numbers.len == 0)
        return 0;
    i64 max_len = num_len(numbers.nums[0], number_of_digits_after_the_radix_dot);
    i64 next_num_len = 0;
    if (numbers.len == 1)
        return max_len;
    for (i64 i = 1; i < numbers.len; i++)
    {
        next_num_len = num_len(numbers.nums[i], number_of_digits_after_the_radix_dot);
        if (next_num_len > max_len)
            max_len = next_num_len;
    }
    return max_len;
}

NumArray nth_column_data(Matrix matrix, i64 nth_column) // First Row = 0
{
    NumArray col_data = new_num_array(matrix.rows);
    for (i64 r = 0; r < matrix.rows; r++)
        col_data.nums[r] = matrix.data[r][nth_column];
    return col_data;
}

i64 *max_num_len_array(Matrix matrix, i64 number_of_digits_after_the_radix_dot)
{
    i64 *max_number_length_array = (i64 *)calloc(matrix.cols, sizeof(i64));
    for (i64 c = 0; c < matrix.cols; c++)
    {
        NumArray matrix_column_data = nth_column_data(matrix, c);
        max_number_length_array[c] = max_num_len(matrix_column_data, number_of_digits_after_the_radix_dot);
    }
    return max_number_length_array;
}

char *pre_space(f80 number, i64 max_number_length, i64 number_of_digits_after_the_radix_dot)
{
    i64 extra_space_number = max_number_length - num_len(number, number_of_digits_after_the_radix_dot);
    char *spaces = (char *)calloc(extra_space_number, sizeof(char));
    for (i64 i = 0; i < extra_space_number; i++)
        spaces[i] = ' ';
    spaces[extra_space_number] = '\0';
    return spaces;
}

void print_matrix(Matrix matrix, i64 number_of_digits_after_the_radix_dot)
{
    char *format = (char *)calloc(128, sizeof(char));
    sprintf(format, " %%s%%0.%lldlf ", number_of_digits_after_the_radix_dot);
    i64 *max_number_length_array = max_num_len_array(matrix, number_of_digits_after_the_radix_dot);

    printf("[[");
    for (i64 r = 0; r < matrix.rows; r++)
    {
        if (r > 0)
            printf(" [");
        for (i64 c = 0; c < matrix.cols; c++)
            printf((const char *)format, pre_space(matrix.data[r][c], max_number_length_array[c], number_of_digits_after_the_radix_dot), matrix.data[r][c]);
        if (r < (matrix.rows - 1))
            printf("]\n");
        else
            printf("]]");
    }
}

void print_matrix_(Matrix matrix, i64 number_of_digits_after_the_radix_dot)
{
    print_matrix(matrix, number_of_digits_after_the_radix_dot);
    newline(1);
}

void print_tensor(Tensor tensor, i64 number_of_digits_after_the_radix_dot)
{
    char *format = (char *)calloc(128, sizeof(char));
    sprintf(format, " %%s%%0.%lldlf ", number_of_digits_after_the_radix_dot);
    printf("[[[");
    for (i64 n = 0; n < tensor.n; n++)
    {
        if (n > 0)
            printf(" [[");

        i64 *max_number_length_array = max_num_len_array(tensor.mat[n], number_of_digits_after_the_radix_dot);
        for (i64 r = 0; r < tensor.mat[n].rows; r++)
        {
            if (r > 0)
                printf("  [");
            for (i64 c = 0; c < tensor.mat[n].cols; c++)
                printf(format, pre_space(tensor.mat[n].data[r][c], max_number_length_array[c], number_of_digits_after_the_radix_dot), tensor.mat[n].data[r][c]);
            if (r < (tensor.mat[n].rows - 1))
                printf("]\n");
            else
                printf("]");
        }

        if (n < (tensor.n - 1))
            printf("]\n\n");
        else
            printf("]]");
    }
}

void print_tensor_(Tensor tensor, i64 number_of_digits_after_the_radix_dot)
{
    print_tensor(tensor, number_of_digits_after_the_radix_dot);
    newline(1);
}

void print_matrix_types(Matrix matrix, text_style text_style)
{
    char **types = types_of_matrix(matrix, text_style);
    i64 count = 0;
    while (types[count][0])
        count++;
    if (count == 0)
        return;
    printf("[");
    printf("'%s'", types[0]);
    for (i64 i = 1; i < count; i++)
        printf(", '%s'", types[i]);
    printf("]");
}

void print_matrix_types_(Matrix matrix, text_style text_style)
{
    print_matrix_types(matrix, text_style);
    newline(1);
}

// NOTE : Calendar Stuffs

char *month_fullname_for(i64 month)
{
    char *month_fullname = (char *)calloc(10, sizeof(char));
    switch (month)
    {
    case 1:
        strncpy(month_fullname, "January", 8);
        break;
    case 2:
        strncpy(month_fullname, "February", 9);
        break;
    case 3:
        strncpy(month_fullname, "March", 6);
        break;
    case 4:
        strncpy(month_fullname, "April", 6);
        break;
    case 5:
        strncpy(month_fullname, "May", 4);
        break;
    case 6:
        strncpy(month_fullname, "June", 5);
        break;
    case 7:
        strncpy(month_fullname, "July", 5);
        break;
    case 8:
        strncpy(month_fullname, "August", 7);
        break;
    case 9:
        strncpy(month_fullname, "September", 10);
        break;
    case 10:
        strncpy(month_fullname, "October", 8);
        break;
    case 11:
        strncpy(month_fullname, "November", 9);
        break;
    case 12:
        strncpy(month_fullname, "December", 9);
        break;
    default:
        break;
    }
    return month_fullname;
}

char *month_shortname_for(i64 month)
{
    char *month_shortname = (char *)calloc(4, sizeof(char));
    switch (month)
    {
    case 1:
        strncpy(month_shortname, "Jan", 4);
        break;
    case 2:
        strncpy(month_shortname, "Feb", 4);
        break;
    case 3:
        strncpy(month_shortname, "Mar", 4);
        break;
    case 4:
        strncpy(month_shortname, "Apr", 4);
        break;
    case 5:
        strncpy(month_shortname, "May", 4);
        break;
    case 6:
        strncpy(month_shortname, "Jun", 4);
        break;
    case 7:
        strncpy(month_shortname, "Jul", 4);
        break;
    case 8:
        strncpy(month_shortname, "Aug", 4);
        break;
    case 9:
        strncpy(month_shortname, "Sep", 4);
        break;
    case 10:
        strncpy(month_shortname, "Oct", 4);
        break;
    case 11:
        strncpy(month_shortname, "Nov", 4);
        break;
    case 12:
        strncpy(month_shortname, "Dec", 4);
        break;
    default:
        break;
    }
    return month_shortname;
}

char *weekly_day_fullname_for(i64 weekly_day)
{
    char *weekly_day_fullname = (char *)calloc(10, sizeof(char));
    switch (weekly_day)
    {
    case 1:
        strncpy(weekly_day_fullname, "Saturday", 9);
        break;
    case 2:
        strncpy(weekly_day_fullname, "Sunday", 7);
        break;
    case 3:
        strncpy(weekly_day_fullname, "Monday", 7);
        break;
    case 4:
        strncpy(weekly_day_fullname, "Tuesday", 8);
        break;
    case 5:
        strncpy(weekly_day_fullname, "Wednesday", 10);
        break;
    case 6:
        strncpy(weekly_day_fullname, "Thursday", 9);
        break;
    case 7:
        strncpy(weekly_day_fullname, "Friday", 7);
        break;
    default:
        break;
    }
    return weekly_day_fullname;
}

char *weekly_day_shortname_for(i64 weekly_day)
{
    char *weekly_day_shortname = (char *)calloc(4, sizeof(char));
    switch (weekly_day)
    {
    case 1:
        strncpy(weekly_day_shortname, "Sat", 4);
        break;
    case 2:
        strncpy(weekly_day_shortname, "Sun", 4);
        break;
    case 3:
        strncpy(weekly_day_shortname, "Mon", 4);
        break;
    case 4:
        strncpy(weekly_day_shortname, "Tue", 4);
        break;
    case 5:
        strncpy(weekly_day_shortname, "Wed", 4);
        break;
    case 6:
        strncpy(weekly_day_shortname, "Thu", 4);
        break;
    case 7:
        strncpy(weekly_day_shortname, "Fri", 4);
        break;
    default:
        break;
    }
    return weekly_day_shortname;
}

i64 delta_m_for(i64 month)
{
    switch (month)
    {
    case 5:
        return 0;
    case 8:
        return 1;
    case 2:
    case 3:
    case 11:
        return 2;
    case 6:
        return 3;
    case 9:
    case 12:
        return 4;
    case 4:
    case 7:
        return 5;
    case 1:
    case 10:
        return 6;
    default:
        return -1;
    }
}

_Bool is_leapyear(i64 year)
{
    return (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0));
}

i64 weekly_day_for(Date date)
{
    _Bool lambda = is_leapyear(date.year) && (date.month > 2);
    _Bool is_bc = (date.year < 0);
    i64 days = ceil_num(1.25 * date.year) + date.day + delta_m_for(date.month) + lambda - is_bc;
    i64 weekly_day = days % 7;
    if (weekly_day == 0)
        return 7;
    return weekly_day;
}

i64 last_day_for(i64 year, i64 month)
{
    month = clip_int(month, 1, 12);

    if (month == 2 && is_leapyear(year))
        return 28;

    switch (month)
    {
    case 2:
        return 29;
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    default:
        return 31;
    }
}

i64 clip_day(Date date)
{
    i64 last_day = last_day_for(date.year, date.month);
    return clip_int(date.day, 1, last_day);
}

char *refine_date_str(char *date_str)
{
    i64 len = strlen(date_str);
    if (len < 3)
        return NULL;

    _Bool is_minus_checked = 0;
    i64 count = 3, i = 0, r = 0;
    char *refined_date_str = (char *)calloc(len, sizeof(char));

    while (i < len && count > 0)
    {
        if (date_str[i] == '-' && is_minus_checked == 0)
        {
            is_minus_checked = 1;
            refined_date_str[r++] = '-';
        }
        else if (date_str[i] == '/' && (refined_date_str[r - 1] >= '0' && refined_date_str[r - 1] <= '9'))
        {
            is_minus_checked = 1;
            if (--count > 0)
                refined_date_str[r++] = '/';
        }
        else if (date_str[i] >= '0' && date_str[i] <= '9')
            refined_date_str[r++] = date_str[i];
        i++;
    }
    refined_date_str[r] = '\0';

    return refined_date_str;
}

Date new_date_from(char *date_str) // Format for 'date_str': year/month/day | Example: date_str = "2022/11/2"
{
    Date date;
    date_str = refine_date_str(date_str);
    sscanf(date_str, "%lld/%lld/%lld", &date.year, &date.month, &date.day);
    date.month = clip_int(date.month, 1, 12);
    date.day = clip_day(date);
    return date;
}

Date new_date(i64 year, i64 month, i64 day)
{
    Date date;
    date.year = year;
    date.month = clip_int(month, 1, 12);
    date.day = day;
    date.day = clip_day(date);
    return date;
}

Date_Info new_date_info_from(char *date_str) // Format for 'date_str': year/month/day | Example: date_str = "2022/11/2"
{
    Date_Info date_info;
    date_str = refine_date_str(date_str);
    sscanf(date_str, "%lld/%lld/%lld", &date_info.year, &date_info.month, &date_info.day);
    date_info.is_bc = (date_info.year < 0);
    date_info.is_leapyear = is_leapyear(date_info.year);
    date_info.month = clip_int(date_info.month, 1, 12);
    Date date = new_date(date_info.year, date_info.month, date_info.day);
    date_info.day = clip_day(date);
    date.day = date_info.day;
    date_info.month_fullname = month_fullname_for(date_info.month);
    date_info.month_shortname = month_shortname_for(date_info.month);
    date_info.weekly_day = weekly_day_for(date);
    date_info.weekly_day_fullname = weekly_day_fullname_for(date_info.weekly_day);
    date_info.weekly_day_shortname = weekly_day_shortname_for(date_info.weekly_day);
    sprintf(date_info.date_str, "%lld/%lld/%lld", date_info.year, date_info.month, date_info.day);
    return date_info;
}

Date_Info new_date_info(Date date)
{
    Date_Info date_info;
    date_info.is_bc = (date.year < 0);
    date_info.is_leapyear = is_leapyear(date.year);
    date_info.year = date.year;
    date_info.month = clip_int(date.month, 1, 12);
    date = new_date(date_info.year, date_info.month, date.day);
    date_info.day = clip_day(date);
    date.day = date_info.day;
    date_info.month_fullname = month_fullname_for(date_info.month);
    date_info.month_shortname = month_shortname_for(date_info.month);
    date_info.weekly_day = weekly_day_for(date);
    date_info.weekly_day_fullname = weekly_day_fullname_for(date_info.weekly_day);
    date_info.weekly_day_shortname = weekly_day_shortname_for(date_info.weekly_day);
    i64 len = int_num_len(date_info.year) + int_num_len(date_info.month) + int_num_len(date_info.day) + 3;
    date_info.date_str = (char *)calloc(len, sizeof(char));
    sprintf(date_info.date_str, "%lld/%lld/%lld", date_info.year, date_info.month, date_info.day);
    return date_info;
}

void print_date_str(Date date, _Bool is_month_as_name)
{
    printf("%lld/", date.year);
    if (is_month_as_name)
    {
        printf("%s/", month_fullname_for(date.month));
    }
    else
    {
        if (date.month < 10)
            printf("0");
        printf("%lld/", date.month);
    }
    if (date.day < 10)
        printf("0");
    printf("%lld", date.day);
}

void print_date_str_(Date date, _Bool is_month_as_name)
{
    print_date_str(date, is_month_as_name);
    printf("\n");
}

void print_date_info(Date date)
{
    Date_Info date_info = new_date_info(date);
    char *bc_or_ad = (char *)calloc(3, sizeof(char));
    if (date_info.is_bc)
        strncpy(bc_or_ad, "BC", 3);
    else
        strncpy(bc_or_ad, "AD", 3);

    char *leapyear_or_not = (char *)calloc(13, sizeof(char));
    if (is_leapyear(date.year))
        strncpy(leapyear_or_not, "Leapyear", 9);
    else
        strncpy(leapyear_or_not, "not Leapyear", 13);

    printf("%lld (%s, %s) / %lld (%s) / %lld (%s)", date_info.year, bc_or_ad, leapyear_or_not, date_info.month, date_info.month_fullname, date_info.day, weekly_day_fullname_for(date_info.weekly_day));
}

void print_date_info_(Date date)
{
    print_date_info(date);
    printf("\n");
}

void print_calendar_month(i64 year, i64 month)
{
    month = clip_int(month, 1, 12);
    char *month_name = month_fullname_for(month);

    i64 title_padding = (22 - (int_num_len(year) + strlen(month_name))) >> 1;
    if (title_padding < 1)
        title_padding = 0;
    printf("%s[ %s, %lld ]\n", str_from_char(' ', title_padding), month_name, year);

    printf("SAT SUN MON TUE WED THU FRI\n");

    Date date = new_date(year, month, 1);
    i64 weekly_day = weekly_day_for(date);

    i64 padding_for_first_day = (weekly_day << 2) - 3 + (weekly_day < 10);
    printf("%s1", str_from_char(' ', padding_for_first_day));

    for (i64 i = 2; i <= last_day_for(year, month); i++)
    {
        weekly_day = mod_nonzero((weekly_day + 1), 7);
        if (weekly_day == 1)
            printf("\n ");
        else
            printf("  ");

        printf("%s%lld", str_from_char(' ', (i < 10)), i);
    }
}

void print_calendar_year(i64 year)
{
    for (i64 month = 1; month < 12; month++)
    {
        print_calendar_month(year, month);
        printf("\n\n");
    }
    print_calendar_month(year, 12);
    printf("\n");
}

#endif // _CMATHLIB__ARITHMOS_