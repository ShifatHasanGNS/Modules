/*
	Module :: [ number.h ]

	AUTHOR  : MD. Shifat Hasan
	Email   : shifathasangns@gmail.com
*/

// ---------------------------------------------------------------- //
//                      H E A D E R -- F I L E s                    //
// ---------------------------------------------------------------- //

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

// ---------------------------------------------------------------- //
//                            M A C R O s                           //
// ---------------------------------------------------------------- //

#define PHI_0 (double)1.61803398874989484820458683436563811772030917980576    // [1 + sqrt(5)] / 2
#define PHI_1 (double)(-0.61803398874989484820458683436563811772030917980576) // [1 - sqrt(5)] / 2

#define E (double)2.71828182845904523536028747135266249775724709369995 // e ---> Euler's Constant

#define TAU (double)6.28318530717958647692528676655900576839433879875021     // TAU = 2 * PI
#define PI (double)3.14159265358979323846264338327950288419716939937510      // PI
#define PI_BY_2 (double)1.57079632679489661923132169163975144209858469968755 // PI / 2
#define PI_BY_3 (double)1.04719755119659774615421446109316762806572313312503 // PI / 3
#define PI_BY_4 (double)0.78539816339744830961566084581987572104929234984377 // PI / 4
#define PI_BY_5 (double)0.62831853071795864769252867665590057683943387987502 // PI / 5
#define PI_BY_6 (double)0.52359877559829887307710723054658381403286156656251 // PI / 6

#define EulerGamma (double)0.57721566490153286060651209008240243104215933593992 // gamma

#define SQRT_2 (double)1.41421356237309504880168872420969807856967187537695 // sqrt(2)
#define SQRT_3 (double)1.73205080756887729352744634150587236694280525381038 // sqrt(3)
#define SQRT_5 (double)2.23606797749978969640917366873127623544061835961153 // sqrt(5)

#define ONE_OVER_SQRT_2 (double)0.70710678118654752440084436210484903928483593768847 // 1 / sqrt(2)
#define ONE_OVER_SQRT_3 (double)0.57735026918962576450914878050195745564760175127013 // 1 / sqrt(3)
#define ONE_OVER_SQRT_5 (double)0.44721359549995793928183473374625524708812367192231 // 1 / sqrt(5)

#define angle_mode(polar) polar->angle_mode // angle-mode of polar, where variable 'polar' is of type 'Polar2D/Polar'

// ---------------------------------------------------------------- //
//                       E N U M E R A T O R s                      //
// ---------------------------------------------------------------- //

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
    multiplication, //  x or, *
    divition        //  /
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
    involutory_matrix,         //  a square-matrix that is its own inverse; --->  A = inverse(A)
    symmetric_matrix,          //  a square-matrix that is equal to its transpose;  A = transpose(A)
    skew_symmetric_matrix,     //  a square-matrix whose transpose equals its negative;  transpose(A) = -A
    orthogonal_matrix,         //  A * transpose(A) = identity matrix = transpose(A) * A
    idempotent_matrix,         //  a square-matrix which, when multiplied by itself, yields itself;  A x A = A
    periodic_matrix,           //  a matrix --> if A^(k+1) = A, then A has period of k, else k = 0
    nilpotent_matrix           //  a square-matrix N such that N^{k}=0, for some positive integer k. The smallest such k is called the index of N, sometimes the degree of N
} matrix_type;

// ---------------------------------------------------------------- //
//                        S T R U C T U R E s                       //
// ---------------------------------------------------------------- //

typedef char *String;

struct pair_struct //  pair
{
    int first;
    int second;
};
typedef struct pair_struct *Pair;

struct polar2D_struct //  polar
{
    double r;
    double theta;
    angle_mode angle_mode;
};
typedef struct polar2D_struct *Polar2D;

struct polar_struct //  polar
{
    double r;
    double theta_x;
    double theta_z;
    angle_mode angle_mode;
};
typedef struct polar_struct *Polar;

struct complex_struct //  complex
{
    double real;
    double imaginary;
};
typedef struct complex_struct *Complex;

struct complex_array_struct //  complex_Array
{
    int length;
    Complex *complex_numbers;
};
typedef struct complex_array_struct *Complex_Array;

struct vector2D_struct //  vector2D
{
    double X;
    double Y;
};
typedef struct vector2D_struct *Point2D;
typedef struct vector2D_struct *Vector2D;

struct vector_struct //  vector
{
    double X;
    double Y;
    double Z;
};
typedef struct vector_struct *Point;
typedef struct vector_struct *Vector;

struct matrix_struct //  matrix
{
    int rows;
    int cols;
    double **data;
};
typedef struct matrix_struct *Matrix;

typedef Matrix* Tensor;

// --------------------------------------------------------------- //
//                        F U N C T I O N s                        //
// --------------------------------------------------------------- //

int sign_int(int number)
{
    return ((number < 0) ? -1 : 1);
}

int sign(double number)
{
    return ((number < 0) ? -1 : 1);
}

int sign_ldouble(long double number)
{
    return ((number < 0) ? -1 : 1);
}

bool is_negative(double number)
{
    return (number < 0);
}

bool is_positive(double number)
{
    return (number >= 0);
}

bool is_odd(int number)
{
    return (number & 1);
}

bool is_even(int number)
{
    return (!(number & 1));
}

double to_radian(double angle_in_degree)
{
    return ((angle_in_degree * PI) / 180);
}

double to_degree(double angle_in_radian)
{
    return ((angle_in_radian * 180) / PI);
}

int absolute_int(int number)
{
    return (sign(number) * number);
}

double absolute(double number)
{
    return (sign(number) * number);
}

long double absolute_ldouble(long double number)
{
    return (sign_ldouble(number) * number);
}

double trim(double num)
{
    int number = (int)(num * pow(10, 9));
    int last_digit = number - (int)(number / 10);
    number = (int)(number / 10);
    if (last_digit > 4)
        number++;
    return (number / pow(10, 8));
}

double trim_ldouble(long double num)
{
    int number = (int)(num * pow(10, 9));
    int last_digit = number - (int)(number / 10);
    number = (int)(number / 10);
    if (last_digit > 4)
        number++;
    return (number / pow(10, 8));
}

int mod(int a, int m)
{
    if (absolute(a) < absolute(m))
        return a;
    else if (absolute(a) == absolute(m))
        return 1;
    else
        return a % m;
}

int bigmod(int a, unsigned int b, int m)
{
    if (b == 0)
        return mod(1, m);
    int result = bigmod(a, b / 2, m);
    result = mod(result * result, m);
    if (b & 1)
        result = mod(result * a, m);
    return result;
}

int bigmod_str(char *num, int m)
{
    int result = 0, len = strlen(num);
    for (int i = 0; i < len; i++)
        result = (result * 10 + (int)num[i] - '0') % m;
    return result;
}

int gcd_int(int a, int b)
{
    a = absolute_int(a);
    b = absolute_int(b);
    int min = (a < b) ? a : b;
    int max = (a > b) ? a : b;
    int r = mod(max, min);
    if (r == 0)
        return min;
    return gcd_int(min, r);
}

unsigned int gcd_uint(unsigned int a, unsigned int b)
{
    unsigned int min = (a < b) ? a : b;
    unsigned int max = (a > b) ? a : b;
    unsigned int r = mod(max, min);
    if (r == 0)
        return min;
    return gcd_uint(min, r);
}

unsigned long int gcd_ulint(unsigned long int a, unsigned long int b)
{
    unsigned long int min = (a < b) ? a : b;
    unsigned long int max = (a > b) ? a : b;
    unsigned long int r = mod(max, min);
    if (r == 0)
        return min;
    return gcd_ulint(min, r);
}

unsigned long long int gcd_ullint(unsigned long long int a, unsigned long long int b)
{
    unsigned long long int min = (a < b) ? a : b;
    unsigned long long int max = (a > b) ? a : b;
    unsigned long long int r = mod(max, min);
    if (r == 0)
        return min;
    return gcd_ullint(min, r);
}

int lcm_int(int a, int b)
{
    a = absolute_int(a);
    b = absolute_int(b);
    return ((a * b) / gcd_int(a, b));
}

unsigned int lcm_uint(unsigned int a, unsigned int b)
{
    return ((a * b) / gcd_uint(a, b));
}

unsigned long int lcm_ulint(unsigned long int a, unsigned long int b)
{
    return ((a * b) / gcd_ulint(a, b));
}

unsigned long long int lcm_ullint(unsigned long long int a, unsigned long long int b)
{
    return ((a * b) / gcd_ullint(a, b));
}

int power_int(int base, int n)
{
    if (n == 0)
        return 1;
    else if (n == 1)
        return base;
    int result = 1;
    while (n > 0)
    {
        if (n & 1)
            result *= base;
        base *= base;
        n /= 2;
    }
    return result;
}

unsigned int power_uint(unsigned int base, unsigned int n)
{
    if (n == 0)
        return 1;
    else if (n == 1)
        return base;
    unsigned int result = 1;
    while (n > 0)
    {
        if (n & 1)
            result *= base;
        base *= base;
        n /= 2;
    }
    return result;
}

unsigned long int power_ulint(unsigned long int base, unsigned long int n)
{
    if (n == 0)
        return 1;
    else if (n == 1)
        return base;
    unsigned long int result = 1;
    while (n > 0)
    {
        if (n & 1)
            result *= base;
        base *= base;
        n /= 2;
    }
    return result;
}

unsigned long long int power_ullint(unsigned long long int base, unsigned long long int n)
{
    if (n == 0)
        return 1;
    else if (n == 1)
        return base;
    unsigned long long int result = 1;
    while (n > 0)
    {
        if (n & 1)
            result *= base;
        base *= base;
        n /= 2;
    }
    return result;
}

double power_double(double base, double n)
{
    if (n == 0)
        return 1;
    else if (n == 1)
        return base;
    else if (n == 0.5 || n == 1 / 2)
        return sqrt(base);
    else if (n == 0.333333 || n == 1 / 3)
        return cbrt(base);
    else
    {
        int r = 1, sign_of_base = sign(base), sign_of_n = sign(n);
        base = absolute(base);
        n = absolute(n);
        double remaining_power = n - floor(n), result = 1;
        int p = floor(n);
        if (sign_of_n == -1)
            base = 1 / base;
        double b = base;
        if (sign_of_base == -1)
        {
            remaining_power = trim(remaining_power);
            if (remaining_power == 0)
            {
                if (p & 1)
                    r = -1;
                else
                {
                    unsigned int lower_part = pow(10, 8);
                    unsigned int upper_part = remaining_power * lower_part;
                    unsigned int h = gcd_uint(upper_part, lower_part);
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
        }
        while (p > 0)
        {
            if (p & 1)
                result *= base;
            base *= base;
            p /= 2;
        }
        if (remaining_power != 0)
        {
            if (remaining_power == 1)
                result *= 1;
            else if (remaining_power == 0.5 || remaining_power == 1 / 2)
                result *= sqrt(b);
            else if (remaining_power == 0.333333 || remaining_power == 1 / 3)
                result *= cbrt(b);
            else
                result *= pow(b, remaining_power);
        }
        return (r * result);
    }
}

long double power_ldouble(long double base, long double n)
{
    if (n == 0)
        return 1;
    else if (n == 1)
        return base;
    else if (n == 0.5 || n == 1 / 2)
        return sqrt(base);
    else if (n == 0.333333 || n == 1 / 3)
        return cbrt(base);
    else
    {
        int r = 1, sign_of_base = sign(base), sign_of_n = sign(n);
        base = absolute(base);
        n = absolute(n);
        long double remaining_power = n - floor(n), result = 1;
        int p = floor(n);
        if (sign_of_n == -1)
            base = 1 / base;
        long double b = base;
        if (sign_of_base == -1)
        {
            remaining_power = trim(remaining_power);
            if (remaining_power == 0)
            {
                if (p & 1)
                    r = -1;
                else
                {
                    unsigned int lower_part = pow(10, 8);
                    unsigned int upper_part = remaining_power * lower_part;
                    unsigned int h = gcd_uint(upper_part, lower_part);
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
        }
        while (p > 0)
        {
            if (p & 1)
                result *= base;
            base *= base;
            p /= 2;
        }
        if (remaining_power != 0)
        {
            if (remaining_power == 1)
                result *= 1;
            else if (remaining_power == 0.5 || remaining_power == 1 / 2)
                result *= sqrt(b);
            else if (remaining_power == 0.333333 || remaining_power == 1 / 3)
                result *= cbrt(b);
            else
                result *= pow(b, remaining_power);
        }
        return (r * result);
    }
}

int last_digit_int(int number, int power) // number, power >= 0
{
    if (power == 0)
        return 1;
    if (number == 0)
        return 0;
    if (number < 1 || power < 1)
        return -1;
    int n = number - floor(number / 10) * 10;
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
        int m = mod(power, 4);
        if (m == 1)
            return n;
        else if (m == 2)
            return (n == 2 || n == 8) ? 4 : 9;
        else if (m == 3)
            return (10 - n);
        else if (m == 0)
            return (n == 2 || n == 8) ? 6 : 1;
    }
}

int last_digit_uint(unsigned int number, unsigned int power) // number, power >= 0
{
    if (power == 0)
        return 1;
    if (number == 0)
        return 0;
    number = absolute(number);
    power = absolute(power);
    int n = number - floor(number / 10) * 10;
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
        char *str = (char *)malloc(floor(log10(power) + 1) * sizeof(char));
        sprintf(str, "%u", power);
        int m = bigmod_str(str, 4);
        free(str);
        if (m == 1)
            return n;
        else if (m == 2)
            return (n == 2 || n == 8) ? 4 : 9;
        else if (m == 3)
            return (10 - n);
        else if (m == 0)
            return (n == 2 || n == 8) ? 6 : 1;
    }
}

int last_digit_ulint(unsigned long int number, unsigned long int power) // number, power >= 0
{
    if (power == 0)
        return 1;
    if (number == 0)
        return 0;
    number = absolute(number);
    power = absolute(power);
    int n = number - floor(number / 10) * 10;
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
        char *str = (char *)malloc(floor(log10(power) + 1) * sizeof(char));
        sprintf(str, "%lu", power);
        int m = bigmod_str(str, 4);
        free(str);
        if (m == 1)
            return n;
        else if (m == 2)
            return (n == 2 || n == 8) ? 4 : 9;
        else if (m == 3)
            return (10 - n);
        else if (m == 0)
            return (n == 2 || n == 8) ? 6 : 1;
    }
}

int last_digit_ullint(unsigned long long int number, unsigned long long int power) // number, power >= 0
{
    if (power == 0)
        return 1;
    if (number == 0)
        return 0;
    number = absolute(number);
    power = absolute(power);
    int n = number - floor(number / 10) * 10;
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
        char *str = (char *)malloc(floor(log10(power) + 1) * sizeof(char));
        sprintf(str, "%llu", power);
        int m = bigmod_str(str, 4);
        free(str);
        if (m == 1)
            return n;
        else if (m == 2)
            return (n == 2 || n == 8) ? 4 : 9;
        else if (m == 3)
            return (10 - n);
        else if (m == 0)
            return (n == 2 || n == 8) ? 6 : 1;
    }
}

double ln(double x)
{
    if (x > 0)
        return log(x);
}

double log_double(double base, double x)
{
    if (x > 0)
        return (ln(x) / ln(base));
}

long double log_ldouble(long double base, long double x)
{
    if (x > 0)
        return (ln(x) / ln(base));
}

int fibonacci(int n_th)
{
    return (ONE_OVER_SQRT_5 * (power_double(PHI_0, n_th) - power_double(PHI_1, n_th)));
}

int factorial(int n) // MAX --> n = 12
{
    if (n < 0)
        return 0;
    else if (n == 0)
        return 1;
    int N = 1;
    for (int i=1; i<=n; i++)
        N *= i;
    return N;
}

int multiply_for_factorial_str(int x, int res[], int res_size)
{
    int carry = 0;
    for (int i=0; i<res_size; i++)
    {
        int prod = res[i] * x + carry;
        res[i] = prod % 10; 
        carry = prod/10;   
    }
    while (carry)
    {
        res[res_size] = carry%10;
        carry = carry/10;
        res_size++;
    }
    return res_size;
}

char *factorial_str(int n)
{
    int res[1024];
    char *N = (char *)malloc(1024 * sizeof(char));
    res[0] = 1;
    int res_size = 1;
    for (int x=2; x<=n; x++)
        res_size = multiply_for_factorial_str(x, res, res_size);
    sprintf(N, "%d", res[res_size-1]);
    for (int i=res_size-2; i>=0; i--)
        sprintf(N, "%s%d", N, res[i]);
    return N;
}

double sum(char *expression, char *interval)
{
    char *lower_bound = (char *)malloc(128 * sizeof(char));
    char *upper_bound = (char *)malloc(128 * sizeof(char));
    sscanf(interval, "%s %s", lower_bound, upper_bound);

    char *format = "%0.15lf";
    int a, b; // MAX = 2147483647
    double answer = 0;

    if (!strcmp(lower_bound, "-inf"))
    {
        a = -10000000;
        sscanf(upper_bound, "%d", &b);
    }
    
    if (!strcmp(upper_bound, "inf"))
    {
        sscanf(lower_bound, "%d", &a);
        b = 10000000;
    }

    else
    {
        sscanf(lower_bound, "%d", &a);
        sscanf(upper_bound, "%d", &b);
    }

    if (b < a) return 0;

    FILE *fp;
    fp = fopen("temp_sum.c", "w");

    fprintf(fp, "#include \"number.h\"\n\n");
    fprintf(fp, "double f(double x)\n{\n\treturn (%s);\n}\n\n", expression);
    fprintf(fp, "void main()\n{\n");
    fprintf(fp, "\tdouble sum = 0;\n");
    fprintf(fp, "\tfor (int x = %d; x <= %d; x++)\n", a, b);
    fprintf(fp, "\t\tsum += f(x);\n");
    fprintf(fp, "\tFILE *fp;\n");
    fprintf(fp, "\tfp = fopen(\"temp_answer_sum.txt\", \"w\");\n");
    fprintf(fp, "\tfprintf(fp, \"%s\", sum);\n", format);
    fprintf(fp, "\tfclose(fp);\n");
    fprintf(fp, "}");

    fclose(fp);

    char *command = "gcc temp_sum.c -o temp_sum.exe";
    system(command);
    command = "temp_sum.exe";
    system(command);

    fp = fopen("temp_answer_sum.txt", "r");
    fscanf(fp, "%lf", &answer);
    fclose(fp);

    remove("temp_sum.exe");
    remove("temp_sum.c");
    remove("temp_answer_sum.txt");

    return answer;
}

double product(char *expression, char *interval)
{
    char *lower_bound = (char *)malloc(128 * sizeof(char));
    char *upper_bound = (char *)malloc(128 * sizeof(char));
    sscanf(interval, "%s %s", lower_bound, upper_bound);
    
    char *format = "%0.15lf";
    int a, b; // MAX = 2147483647
    double answer = 0;

    if (!strcmp(lower_bound, "-inf"))
    {
        a = -10000000;
        sscanf(upper_bound, "%d", &b);
    }
    
    if (!strcmp(upper_bound, "inf"))
    {
        sscanf(lower_bound, "%d", &a);
        b = 10000000;
    }

    else
    {
        sscanf(lower_bound, "%d", &a);
        sscanf(upper_bound, "%d", &b);
    }

    if (b < a) return 0;

    FILE *fp;
    fp = fopen("temp_sum.c", "w");

    fprintf(fp, "#include \"number.h\"\n\n");
    fprintf(fp, "double f(double x)\n{\n\treturn (%s);\n}\n\n", expression);
    fprintf(fp, "void main()\n{\n");
    fprintf(fp, "\tdouble sum = 1;\n");
    fprintf(fp, "\tfor (int x = %d; x <= %d; x++)\n", a, b);
    fprintf(fp, "\t\tsum *= f(x);\n");
    fprintf(fp, "\tFILE *fp;\n");
    fprintf(fp, "\tfp = fopen(\"temp_answer_product.txt\", \"w\");\n");
    fprintf(fp, "\tfprintf(fp, \"%s\", sum);\n", format);
    fprintf(fp, "\tfclose(fp);\n");
    fprintf(fp, "}");

    fclose(fp);

    char *command = "gcc temp_sum.c -o temp_sum.exe";
    system(command);
    command = "temp_sum.exe";
    system(command);

    fp = fopen("temp_answer_product.txt", "r");
    fscanf(fp, "%lf", &answer);
    fclose(fp);

    remove("temp_sum.exe");
    remove("temp_sum.c");
    remove("temp_answer_product.txt");

    return answer;
}

double differentiate(char *function, double x)
{
    double answer = 0;
    char *format = "%0.15lf";

    FILE *fp;
    fp = fopen("temp_derivative.c", "w");

    fprintf(fp, "#include \"number.h\"\n\n");
    fprintf(fp, "double f(double x)\n{\n\treturn (%s);\n}\n\n", function);
    fprintf(fp, "void main()\n{\n");
    fprintf(fp, "\tdouble dx = 0.000000000000001, a = 0, b = 0, x = %lf, result = 0;\n\n", x);
    fprintf(fp, "\ta = f(x+dx);\n\tb = f(x-dx);\n");
    fprintf(fp, "\tresult = (a - b)/(2 * dx);\n\n");
    fprintf(fp, "\tFILE *fp;\n");
    fprintf(fp, "\tfp = fopen(\"temp_answer_derivative.txt\", \"w\");\n");
    fprintf(fp, "\tfprintf(fp, \"%s\", result);\n", format);
    fprintf(fp, "\tfclose(fp);\n");
    fprintf(fp, "}");

    fclose(fp);

    char *command = "gcc temp_derivative.c -o temp_derivative.exe";
    system(command);
    command = "temp_derivative.exe";
    system(command);

    fp = fopen("temp_answer_derivative.txt", "r");
    fscanf(fp, "%lf", &answer);
    fclose(fp);

    remove("temp_derivative.exe");
    remove("temp_derivative.c");
    remove("temp_answer_derivative.txt");

    return answer;
}

double integrate(char *integrand, char *interval)
{
    char *lower_bound = (char *)malloc(128 * sizeof(char));
    char *upper_bound = (char *)malloc(128 * sizeof(char));
    sscanf(interval, "%s %s", lower_bound, upper_bound);

    if (!strcmp(lower_bound, upper_bound))
        return 0;

    double temp, a, b, A, B, C, dx = 0.0000001, answer = 0;
    char *format = "%0.15lf";
    int sign = 1;
    bool m = false;

    if (!strcmp(lower_bound, "-inf"))
    {
        m = true;
        A = -PI_BY_2;
        if (!strcmp(lower_bound, "inf"))
        {
            B = PI_BY_2;
        }
        else
        {
            sscanf(upper_bound, "%lf", &b);
            B = atan(b);
        }
    }

    else if (!strcmp(lower_bound, "inf"))
    {
        m = true;
        sign = -1;
        B = PI_BY_2;
        if (!strcmp(upper_bound, "-inf"))
        {
            A = -PI_BY_2;
        }
        else
        {
            sscanf(upper_bound, "%lf", &b);
            A = atan(b);
        }
    }

    else
    {
        sscanf(lower_bound, "%lf", &a);
        if (!strcmp(upper_bound, "inf"))
        {
            m = true;
            A = atan(a);
            B = PI_BY_2;
        }
        else if (!strcmp(upper_bound, "-inf"))
        {
            m = true;
            sign = -1;
            B = atan(a);
            A = -PI_BY_2;
        }
        else
        {
            sscanf(upper_bound, "%lf", &b);
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

    fprintf(fp, "#include \"number.h\"\n\n");
    fprintf(fp, "double f(double x)\n{\n\treturn (%s);\n}\n\n", integrand);
    fprintf(fp, "void main()\n{\n");
    fprintf(fp, "\tdouble sum = 0, x = 0, t = 0, result = 0;\n");
    fprintf(fp, "\tfor (int i = 1; i <= 10000000; i++)\n");
    fprintf(fp, "\t{\n");
    fprintf(fp, "\t\tx = %0.15lf + (%0.15lf * (i - 0.5) * %0.15lf);\n", A, C, dx);
    if (m)
    {
        fprintf(fp, "\t\tx = tan(x);\n");
        fprintf(fp, "\t\tsum += f(x)*(1 + x*x);\n");
    }
    else
        fprintf(fp, "\t\tsum += f(x);\n");
    fprintf(fp, "\t}\n\n");
    fprintf(fp, "\tresult = %d * %0.15lf * sum * %0.15lf;\n\n", sign, C, dx);
    fprintf(fp, "\tFILE *fp;\n");
    fprintf(fp, "\tfp = fopen(\"temp_answer_integral.txt\", \"w\");\n");
    fprintf(fp, "\tfprintf(fp, \"%s\", result);\n", format);
    fprintf(fp, "\tfclose(fp);\n");
    fprintf(fp, "}");

    fclose(fp);

    char *command = "gcc temp_integral.c -o temp_integral.exe";
    system(command);
    command = "temp_integral.exe";
    system(command);

    fp = fopen("temp_answer_integral.txt", "r");
    fscanf(fp, "%lf", &answer);
    fclose(fp);

    remove("temp_integral.exe");
    remove("temp_integral.c");
    remove("temp_answer_integral.txt");

    return answer;
}

bool is_null(Matrix matrix)
{
    return (matrix->rows == 0 && matrix->cols == 0) ? true : false;
}

bool is_square_matrix(Matrix matrix)
{
    return (matrix->rows == matrix->cols);
}

bool are_perfect(Matrix matrix_1, Matrix matrix_2, operation operation)
{
    if (operation == addition || operation == subtraction)
        return (matrix_1->rows == matrix_2->rows && matrix_1->cols == matrix_2->cols);
    else if (operation == multiplication)
        return (matrix_1->cols == matrix_2->rows);
    return false;
}

bool are_identical(Matrix matrix_1, Matrix matrix_2)
{
    if (matrix_1->rows == matrix_2->rows && matrix_1->cols == matrix_2->cols)
    {
        int count = 0;
        for (int r = 0; r < matrix_1->rows; r++)
        {
            for (int c = 0; c < matrix_1->cols; c++)
                if (matrix_1->data[r][c] == matrix_2->data[r][c])
                    count++;
        }
        if (count == (matrix_1->rows * matrix_1->cols))
            return true;
        return false;
    }
}

Pair new_pair(int first, int second)
{
    Pair p = (Pair)malloc(sizeof(Pair));
    p->first = first;
    p->first = second;
    return p;
}

Polar2D new_polar2D(double r, double theta, angle_mode angle_mode)
{
    Polar2D p = (Polar2D)malloc(sizeof(Polar2D));
    p->r = r;
    p->theta = theta;
    p->angle_mode = angle_mode;
    return p;
}

Polar new_polar(double r, double theta_x, double theta_z, angle_mode angle_mode)
{
    Polar p = (Polar)malloc(sizeof(Polar));
    p->r = r;
    p->theta_x = theta_x;
    p->theta_z = theta_z;
    p->angle_mode = angle_mode;
    return p;
}

Point2D new_point2D(double X, double Y)
{
    Point2D p = (Point2D)malloc(sizeof(Point2D));
    p->X = X;
    p->Y = Y;
    return p;
}

Vector2D new_vector2D(double X, double Y)
{
    Vector2D v = (Vector2D)malloc(sizeof(Vector2D));
    v->X = X;
    v->Y = Y;
    return v;
}

Point new_point(double X, double Y, double Z)
{
    Point p = (Point)malloc(sizeof(Point));
    p->X = X;
    p->Y = Y;
    p->Z = Z;
    return p;
}

Vector new_vector(double X, double Y, double Z)
{
    Vector v = (Vector)malloc(sizeof(Vector));
    v->X = X;
    v->Y = Y;
    v->Z = Z;
    return v;
}

Matrix new_matrix(int rows, int cols)
{
    Matrix matrix = (Matrix)malloc(sizeof(Matrix));
    matrix->rows = rows;
    matrix->cols = cols;
    double **data = (double **)malloc(sizeof(double *) * rows);
    for (int x = 0; x < rows; x++)
        data[x] = (double *)calloc(cols, sizeof(double));
    matrix->data = data;
    return matrix;
}

Matrix new_identity_matrix(int order)
{
    Matrix matrix = new_matrix(order, order);
    for (int r = 0; r < order; r++)
        matrix->data[r][r] = 1;
    return matrix;
}

Matrix new_scalar_matrix(int order, double scalar_number)
{
    Matrix matrix = new_matrix(order, order);
    for (int r = 0; r < order; r++)
        matrix->data[r][r] = scalar_number;
    return matrix;
}

Matrix new_primary_diagonal_matrix(int order, Matrix row_matrix)
{
    Matrix matrix = new_matrix(order, order);
    for (int r = 0; r < order; r++)
        matrix->data[r][r] = row_matrix->data[0][r];
    return matrix;
}

Matrix new_secondary_diagonal_matrix(int order, Matrix row_matrix)
{
    Matrix matrix = new_matrix(order, order);
    for (int r = 0; r < order; r++)
        matrix->data[r][order - r - 1] = row_matrix->data[0][r];
    return matrix;
}

Complex new_complex(double real_part, double imaginary_part)
{
    Complex complex_number = (Complex)malloc(sizeof(Complex));
    complex_number->real = real_part;
    complex_number->imaginary = imaginary_part;
    return complex_number;
}

Complex_Array new_complex_array(int length)
{
    Complex_Array complex_array = (Complex_Array)malloc(sizeof(Complex_Array));
    complex_array->length = length;
    complex_array->complex_numbers = (Complex *)malloc(length * sizeof(Complex));
    return complex_array;
}

Pair copy_pair(Pair p)
{
    return new_pair(p->first, p->second);
}

Polar2D copy_polar2D(Polar2D p)
{
    return new_polar2D(p->r, p->theta, p->angle_mode);
}

Polar copy_polar(Polar p)
{
    return new_polar(p->r, p->theta_x, p->theta_z, p->angle_mode);
}

Complex copy_complex(Complex z)
{
    return new_complex(z->real, z->imaginary);
}

Complex_Array copy_complex_array(Complex_Array complex_array)
{
    int len = complex_array->length;
    Complex_Array copy_of_complex_array = new_complex_array(len);
    for (int i = 0; i < len; i++)
        copy_of_complex_array->complex_numbers[i] = complex_array->complex_numbers[i];
    return copy_of_complex_array;
}

Point2D copy_point2D(Point2D p)
{
    return new_point2D(p->X, p->Y);
}

Vector2D copy_vector2D(Vector2D v)
{
    return new_vector2D(v->X, v->Y);
}

Point copy_point(Point p)
{
    return new_point(p->X, p->Y, p->Z);
}

Vector copy_vector(Vector v)
{
    return new_vector(v->X, v->Y, v->Z);
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

Complex real_number_to_complex(double number)
{
    return new_complex(number, 0);
}

Complex imaginary_number_to_complex(double imaginary_number)
{
    return new_complex(0, imaginary_number);
}

double real_part(Complex z)
{
    return z->real;
}

double imaginary_part(Complex z)
{
    return z->imaginary;
}

Complex conjugate(Complex z)
{
    Complex c_number = (Complex)malloc(sizeof(Complex));
    c_number->real = z->real;
    c_number->imaginary = -z->imaginary;
    return c_number;
}

double value_of_complex(Complex z)
{
    return sqrt((z->real * z->real) + (z->imaginary * z->imaginary));
}

Complex scale_complex(Complex z, double scalar)
{
    return new_complex(scalar * z->real, scalar * z->imaginary);
}

int quadrent_for_complex(Complex z)
{
    double real = z->real;
    double imaginary = z->imaginary;
    if (real >= 0 && imaginary >= 0)
        return 1;
    if (real < 0 && imaginary >= 0)
        return 2;
    if (real < 0 && imaginary < 0)
        return 3;
    if (real >= 0 && imaginary < 0)
        return 4;
}

double argument(Complex z, angle_mode angle_mode)
{
    double real = z->real;
    double imaginary = z->imaginary;

    if (real == 0)
    {
        double arg = 90 * sign(imaginary);
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
        double arg = atan(absolute(imaginary / real));
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
}

double angle_for_complex(Complex z, angle_mode angle_mode)
{
    double real = z->real;
    double imaginary = z->imaginary;

    if (real == 0)
    {
        double arg = 90 * sign(imaginary);
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
        double arg = atan(absolute(imaginary / real));
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
    }
}

int quadrent_for_angle(double angle, angle_mode angle_mode)
{
    double theta = remainder(absolute(angle), TAU), pi_1 = PI / 2, pi_2 = (3 * PI) / 2;
    int quadrent = -1;
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
    return new_complex((z1->real + z2->real), (z1->imaginary + z2->imaginary));
}

Complex subtract_complex(Complex z1, Complex z2)
{
    return new_complex((z1->real - z2->real), (z1->imaginary - z2->imaginary));
}

Complex multiply_complex(Complex z1, Complex z2) // (x1 + iy1) * (x2 + iy2) = (x1*x2 - y1*y2) + i(x1*y2 + x2*y1)
{
    return new_complex(((z1->real * z2->real) - (z1->imaginary * z2->imaginary)), ((z1->real * z2->imaginary) + (z2->real * z1->imaginary)));
}

Complex divide_complex(Complex z1, Complex z2) // (x1 + iy1) / (x2 + iy2) = ((x1 + iy1) * (x2 - iy2)) / (x2*x2 + y2*y2)
{
    return scale_complex(multiply_complex(z1, conjugate(z2)), (1 / value_of_complex(z2)));
}

Complex power_complex(Complex base, Complex n)
{
    double r = value_of_complex(base);
    double t = argument(base, radian);
    double x = n->real, y = n->imaginary;
    double p = (x * log(r)) - (y * t);
    double R = power_double(E, p);
    double T = (y * log(r)) + (x * t);
    double real = R * cos(T), img = R * sin(T);
    return new_complex(real, img);
}

Complex complex_ln(Complex z)
{
    double r = value_of_complex(z);
    double t = argument(z, radian);
    if (r < 0)
        return new_complex(log(absolute(r)), (t + PI));
    if (r > 0)
        return new_complex(log(r), t);
}

Complex complex_log10(Complex z)
{
    double r = value_of_complex(z);
    double t = argument(z, radian);
    if (r < 0)
        return new_complex(log(absolute(r)) / log(10), (t + PI) / log(10));
    if (r > 0)
        return new_complex(log(r) / log(10), t / log(10));
}

Complex complex_log(Complex base, Complex z)
{
    return divide_complex(complex_ln(z), complex_ln(base));
}

bool is_number(char *string)
{
    if (string == NULL || *string == '\0')
        return false;                                   // Checking if the string is Empty...
    int count_dot = 0, count_plus = 0, count_minus = 0; // Initializing...
    // Checking if the string is a number...
    while (*string)
    {
        char c = *string;
        switch (c)
        {
        case '.':
            if (++count_dot > 1)
                return false;
            break;
        case '+':
            if (++count_plus > 1)
                return false;
            break;
        case '-':
            if (++count_minus > 1)
                return false;
            break;
        default:
            if (c < '0' || c > '9')
                return false;
            break;
        }
        string++;
    }
    // If it's a number then return True...
    return true;
}

char *remove_char(char *str, char c)
{
    char *new_str = (char *)malloc(strlen(str) * sizeof(char));
    strcpy(new_str, str);
    int count = 0;
    for (int i = 0; new_str[i]; i++)
        if (new_str[i] != c)
            new_str[count++] = new_str[i];
    new_str[count] = '\0';
    return new_str;
}

char **split(char *string, char c)
{
    // Initialize...
    sprintf(string, "%s ", string);
    int len = strlen(string), count_c = 0, number_of_tokens = 0;
    char str_c[1], **list_of_tokens = malloc(sizeof(char *) * (len - count_c - 2) + sizeof(char) * (len - count_c));
    sprintf(str_c, "%c", c);
    // Split...
    char *token = strtok(string, str_c);
    while (token != NULL)
    {
        list_of_tokens[number_of_tokens] = token;
        number_of_tokens++;
        token = strtok(NULL, str_c);
    }
    // Return the splited 2D-Array of character...
    return list_of_tokens;
}

double *parse_number(char *string, int num)
{
    int count = 0, c = 0, i;
    double temp_num;
    // Get the splitted_String as a 2D_Character_Array...
    char **splitted_string = split(string, ' ');
    // Initialize the Number_Array...
    while (splitted_string[count])
        count++;
    double *list_of_nums = (double *)malloc(count * sizeof(double));
    // Parse the numbers...
    for (i = 0; i < count; i++)
    {
        if (is_number(splitted_string[i]))
        {
            sscanf(splitted_string[i], "%lf", &temp_num);
            list_of_nums[c++] = temp_num;
            if (num != -1 && c == num)
                break;
        }
    }
    // Return the list as a double type Number_Array...
    return list_of_nums;
}

Matrix input_matrix(int rows, int cols)
{
    int r, c, count;
    // Temporary Variables...
    double *temp_row = (double *)malloc(cols * sizeof(double));
    char *temp_str = (char *)malloc(100 * cols * sizeof(char));
    // Creating the Matrix...
    Matrix matrix = new_matrix(rows, cols);
    // Getting the Matrix_Input...
    for (r = 0; r < rows; r++)
    {
        *temp_str = '\0';
        gets(temp_str);
        for (c = 0; c < cols; c++)
            temp_row[c] = 0;
        temp_row = parse_number(temp_str, cols);
        for (c = 0; c < cols; c++)
            matrix->data[r][c] = temp_row[c];
    }
    return matrix;
}

Matrix input_row_matrix(int cols)
{
    return input_matrix(1, cols);
}

Matrix input_column_matrix(int rows)
{
    return input_matrix(rows, 1);
}

Matrix input_square_matrix(int order)
{
    return input_matrix(order, order);
}

bool is_convertable(double *array, int rows, int cols)
{
    int count = 0;
    while (*array)
    {
        count++;
        array++;
    }
    if (count == (rows * cols))
        return true;
    return false;
}

Matrix array_to_matrix(double *data, int rows, int cols)
{
    if (is_convertable(data, rows, cols))
    {
        Matrix matrix = new_matrix(rows, cols);
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
                matrix->data[r][c] = data[cols * r + c];
        }
        return matrix;
    }
    return new_matrix(0, 0);
}

double *matrix_to_array(Matrix matrix)
{
    if (!is_null(matrix))
    {
        double *array = (double *)malloc(matrix->rows * matrix->cols * sizeof(double));
        int i = 0;
        for (int r = 0; r < matrix->rows; r++)
        {
            for (int c = 0; c < matrix->cols; c++)
                array[i++] = matrix->data[r][c];
        }
        return array;
    }
    return NULL;
}

Matrix copy_matrix(Matrix matrix)
{
    double *data = matrix_to_array(matrix);
    return array_to_matrix(data, matrix->rows, matrix->cols);
}

Matrix to_row_matrix2D(Vector2D vector)
{
    Matrix colMatrix = new_matrix(1, 2);
    colMatrix->data[0][0] = vector->X;
    colMatrix->data[0][1] = vector->Y;
    return colMatrix;
}

Matrix to_row_matrix(Vector vector)
{
    Matrix colMatrix = new_matrix(1, 3);
    colMatrix->data[0][0] = vector->X;
    colMatrix->data[0][1] = vector->Y;
    colMatrix->data[0][2] = vector->Z;
    return colMatrix;
}

Matrix to_column_matrix2D(Vector2D vector)
{
    Matrix colMatrix = new_matrix(2, 1);
    colMatrix->data[0][0] = vector->X;
    colMatrix->data[1][0] = vector->Y;
    return colMatrix;
}

Matrix to_column_matrix(Vector vector)
{
    Matrix colMatrix = new_matrix(3, 1);
    colMatrix->data[0][0] = vector->X;
    colMatrix->data[1][0] = vector->Y;
    colMatrix->data[2][0] = vector->Z;
    return colMatrix;
}

Vector2D vectorize2D(Matrix matrix)
{
    if (matrix->cols == 1)
    {
        if (matrix->rows == 1)
            return new_vector2D(matrix->data[0][0], 0);
        else if (matrix->rows == 2)
            return new_vector2D(matrix->data[0][0], matrix->data[1][0]);
    }
    else if (matrix->rows == 1)
    {
        if (matrix->cols == 1)
            return new_vector2D(matrix->data[0][0], 0);
        else if (matrix->cols == 2)
            return new_vector2D(matrix->data[0][0], matrix->data[0][1]);
    }
    else
        return new_vector2D(0, 0);
}

Vector vectorize(Matrix matrix)
{
    if (matrix->cols == 1)
    {
        if (matrix->rows == 1)
            return new_vector(matrix->data[0][0], 0, 0);
        else if (matrix->rows == 2)
            return new_vector(matrix->data[0][0], matrix->data[1][0], 0);
        else if (matrix->rows == 3)
            return new_vector(matrix->data[0][0], matrix->data[1][0], matrix->data[2][0]);
    }
    else if (matrix->rows == 1)
    {
        if (matrix->cols == 1)
            return new_vector(matrix->data[0][0], 0, 0);
        else if (matrix->cols == 2)
            return new_vector(matrix->data[0][0], matrix->data[0][1], 0);
        else if (matrix->cols == 3)
            return new_vector(matrix->data[0][0], matrix->data[0][1], matrix->data[0][2]);
    }
    else
        return new_vector(0, 0, 0);
}

Polar2D complex_to_polar2D(Complex z, angle_mode angle_mode) // z = (x + iy) ---> r * e^(i * theta)
{
    return new_polar2D(value_of_complex(z), argument(z, angle_mode), angle_mode);
}

Complex polar2D_to_complex(Polar2D number) // r * e^(i * theta) ---> (x + iy) = z
{
    if (number->angle_mode == radian)
    {
        return scale_complex(new_complex(cos(number->theta), sin(number->theta)), number->r);
    }
    else if (number->angle_mode == degree)
    {
        double angle = to_radian(number->theta);
        return scale_complex(new_complex(cos(angle), sin(angle)), number->r);
    }
}

Complex point2D_to_complex(Point2D point)
{
    return new_complex(point->X, point->Y);
}

Polar2D point2D_to_polar2D(Point2D point, angle_mode angle_mode)
{
    return complex_to_polar2D(point2D_to_complex(point), angle_mode);
}

Point2D complex_to_point2D(Complex z)
{
    return new_point2D(z->real, z->imaginary);
}

Point2D polar2D_to_point2D(Polar2D point)
{
    return complex_to_point2D(polar2D_to_complex(point));
}

Point polar_to_point(Polar point)
{
    double t1 = point->theta_x, t2 = point->theta_z;
    if (point->angle_mode == degree)
    {
        t1 = to_radian(point->theta_x);
        t2 = to_radian(point->theta_z);
    }
    double x = point->r * sin(t2) * cos(t1);
    double y = point->r * sin(t2) * sin(t1);
    double z = point->r * cos(t2);
    return new_point(x, y, z);
}

Polar point_to_polar(Point point, angle_mode angle_mode)
{
    double x = point->X, y = point->Y, z = point->Z;
    double r = sqrt(x * x + y + y + z * z);
    double t1 = acos(x / sqrt(x * x + y * y));
    double t2 = acos(z / r);
    if (angle_mode = degree)
    {
        t1 = to_degree(t1);
        t2 = to_degree(t2);
    }
    return new_polar(r, t1, t2, angle_mode);
}

Complex vector2D_to_complex(Vector2D vector)
{
    return new_complex(vector->X, vector->Y);
}

Vector2D complex_to_vector2D(Complex z)
{
    return new_vector2D(z->real, z->imaginary);
}

Vector vector2D_to_vector(Vector2D vector)
{
    return new_vector(vector->X, vector->Y, 0);
}

Vector2D vector_to_vector2D(Vector vector)
{
    return new_vector2D(vector->X, vector->Y);
}

Point point2D_to_point(Point2D p)
{
    return new_point(p->X, p->Y, 0);
}

Point2D point_to_point2D(Point point)
{
    return new_point2D(point->X, point->Y);
}

Point2D vector2D_to_point2D(Vector2D vector)
{
    return new_point2D(vector->X, vector->Y);
}

Vector2D point2D_to_vector2D(Point2D point)
{
    return new_vector2D(point->X, point->Y);
}

Point vector_to_point(Vector vector)
{
    return new_point(vector->X, vector->Y, vector->Z);
}

Vector point_to_vector(Point point)
{
    return new_vector(point->X, point->Y, point->Z);
}

Point vector2D_to_point(Vector2D vector)
{
    return new_point(vector->X, vector->Y, 0);
}

Vector2D point_to_vector2D(Point point)
{
    return new_vector2D(point->X, point->Y);
}

Point2D vector_to_point2D(Vector vector)
{
    return new_point2D(vector->X, vector->Y);
}

Vector point2D_to_vector(Point2D point)
{
    return new_vector(point->X, point->Y, 0);
}

Point2D input_point2D()
{
    return vector2D_to_point2D(vectorize2D(input_matrix(1, 2)));
}

Point input_point()
{
    return vector_to_point(vectorize(input_matrix(1, 3)));
}

Vector2D input_vector2D()
{
    return vectorize2D(input_matrix(1, 2));
}

Vector input_vector()
{
    return vectorize(input_matrix(1, 3));
}

Matrix transpose(Matrix matrix)
{
    Matrix transposed_matrix = new_matrix(matrix->cols, matrix->rows);
    for (int r = 0; r < matrix->cols; r++)
    {
        for (int c = 0; c < matrix->rows; c++)
            transposed_matrix->data[r][c] = matrix->data[c][r];
    }
    return transposed_matrix;
}

Matrix reform(Matrix matrix, int rows, int cols)
{
    if (!is_null(matrix) && (rows * cols) == (matrix->rows * matrix->cols))
        return array_to_matrix(matrix_to_array(matrix), rows, cols);
    return matrix;
}

Matrix reshape(Matrix matrix, int rows, int cols)
{
    Matrix m = new_matrix(rows, cols);
    for (int r = 0; r < matrix->rows; r++)
    {
        for (int c = 0; c < matrix->rows; c++)
            m->data[r][c] = matrix->data[r][c];
    }
    return m;
}

Matrix append_row_matrix(Matrix base_matrix, Matrix row_matrix)
{
    if (row_matrix->rows == 1)
    {
        Matrix new_matrix = reshape(base_matrix, base_matrix->rows + 1, base_matrix->cols);
        for (int c = 0; c < base_matrix->cols; c++)
            new_matrix->data[base_matrix->rows][c] = row_matrix->data[0][c];
        return new_matrix;
    }
    return base_matrix;
}

Matrix append_column_matrix(Matrix base_matrix, Matrix column_matrix)
{
    if (column_matrix->cols == 1)
    {
        Matrix new_matrix = reshape(base_matrix, base_matrix->rows, base_matrix->cols + 1);
        for (int r = 0; r < base_matrix->rows; r++)
            new_matrix->data[r][base_matrix->cols] = column_matrix->data[r][0];
        return new_matrix;
    }
    return base_matrix;
}

Matrix insert_row_matrix(Matrix base_matrix, int index_of_row, Matrix row_matrix)
{
    if (row_matrix->rows == 1)
    {
        if (index_of_row >= 0 && index_of_row < base_matrix->rows)
        {
            Matrix m = new_matrix(base_matrix->rows + 1, base_matrix->cols);
            for (int r = 0; r < base_matrix->rows + 1; r++)
            {
                for (int c = 0; c < base_matrix->cols; c++)
                {
                    if (r < index_of_row)
                        m->data[r][c] = base_matrix->data[r][c];
                    else if (r > index_of_row)
                        m->data[r][c] = base_matrix->data[r - 1][c];
                    else
                        m->data[r][c] = row_matrix->data[0][c];
                }
            }
            return m;
        }
        else if (index_of_row == base_matrix->rows)
            return append_row_matrix(base_matrix, row_matrix);
        else
            return base_matrix;
    }
    return base_matrix;
}

Matrix insert_column_matrix(Matrix base_matrix, int index_of_col, Matrix column_matrix)
{
    if (column_matrix->cols == 1)
    {
        if (index_of_col >= 0 && index_of_col < base_matrix->cols)
        {
            Matrix m = new_matrix(base_matrix->rows, base_matrix->cols + 1);
            for (int r = 0; r < base_matrix->rows; r++)
            {
                for (int c = 0; c < base_matrix->cols + 1; c++)
                {
                    if (c < index_of_col)
                        m->data[r][c] = base_matrix->data[r][c];
                    else if (c > index_of_col)
                        m->data[r][c] = base_matrix->data[r][c - 1];
                    else
                        m->data[r][c] = column_matrix->data[r][0];
                }
            }
            return m;
        }
        else if (index_of_col == base_matrix->rows)
            return append_column_matrix(base_matrix, column_matrix);
        return base_matrix;
    }
    return base_matrix;
}

Matrix del_row_matrix(Matrix base_matrix, int index_of_row)
{
    if (index_of_row >= 0 && index_of_row < base_matrix->rows)
    {
        Matrix m = new_matrix(base_matrix->rows - 1, base_matrix->cols);
        for (int r = 0; r < base_matrix->rows; r++)
        {
            if (r == index_of_row)
                continue;
            for (int c = 0; c < base_matrix->cols; c++)
            {
                if (r < index_of_row)
                    m->data[r][c] = base_matrix->data[r][c];
                else if (r > index_of_row)
                    m->data[r - 1][c] = base_matrix->data[r][c];
            }
        }
        return m;
    }
    return base_matrix;
}

Matrix del_column_matrix(Matrix base_matrix, int index_of_col)
{
    if (index_of_col >= 0 && index_of_col < base_matrix->cols)
    {
        Matrix m = new_matrix(base_matrix->rows, base_matrix->cols - 1);
        for (int r = 0; r < base_matrix->rows; r++)
        {
            for (int c = 0; c < base_matrix->cols; c++)
            {
                if (c < index_of_col)
                    m->data[r][c] = base_matrix->data[r][c];
                else if (c > index_of_col)
                    m->data[r][c - 1] = base_matrix->data[r][c];
                else
                    continue;
            }
        }
        return m;
    }
    return base_matrix;
}

Matrix replace_row_matrix(Matrix base_matrix, int index_of_row, Matrix row_matrix)
{
    if (row_matrix->rows == 1 && index_of_row >= 0 && index_of_row < base_matrix->rows)
    {
        Matrix m = new_matrix(base_matrix->rows, base_matrix->cols);
        for (int r = 0; r < base_matrix->rows; r++)
        {
            for (int c = 0; c < base_matrix->cols; c++)
            {
                if (r == index_of_row)
                    m->data[r][c] = row_matrix->data[0][c];
                else
                    m->data[r][c] = base_matrix->data[r][c];
            }
        }
        return m;
    }
    return base_matrix;
}

Matrix replace_column_matrix(Matrix base_matrix, int index_of_col, Matrix column_matrix)
{
    if (column_matrix->cols == 1 && index_of_col >= 0 && index_of_col < base_matrix->cols)
    {
        Matrix m = new_matrix(base_matrix->rows, base_matrix->cols);
        for (int r = 0; r < base_matrix->rows; r++)
        {
            for (int c = 0; c < base_matrix->cols; c++)
            {
                if (c == index_of_col)
                    m->data[r][c] = column_matrix->data[r][0];
                else
                    m->data[r][c] = base_matrix->data[r][c];
            }
        }
        return m;
    }
    return base_matrix;
}

Matrix pop_row_matrix(Matrix base_matrix)
{
    if (base_matrix->rows > 0)
        return del_row_matrix(base_matrix, base_matrix->rows - 1);
    return base_matrix;
}

Matrix pop_column_matrix(Matrix base_matrix)
{
    if (base_matrix->cols > 0)
        return del_column_matrix(base_matrix, base_matrix->cols - 1);
    return base_matrix;
}

void swap_index(Matrix base_matrix, Pair first_index, Pair second_index)
{
    if (first_index->first < base_matrix->rows && first_index->second < base_matrix->cols && second_index->first < base_matrix->rows && second_index->second < base_matrix->cols && first_index->first != second_index->first && first_index->second != second_index->second)
    {
        double temp_index = base_matrix->data[first_index->first][first_index->second];
        base_matrix->data[first_index->first][first_index->second] = base_matrix->data[second_index->first][second_index->second];
        base_matrix->data[second_index->first][second_index->second] = temp_index;
    }
}

void swap_row(Matrix base_matrix, int first_row, int second_row)
{
    if (first_row < base_matrix->rows && second_row < base_matrix->rows && first_row != second_row)
    {
        double temp;
        for (int c = 0; c < base_matrix->cols; c++)
        {
            temp = base_matrix->data[first_row][c];
            base_matrix->data[first_row][c] = base_matrix->data[second_row][c];
            base_matrix->data[second_row][c] = temp;
        }
    }
}

void swap_column(Matrix base_matrix, int first_col, int second_col)
{
    if (first_col < base_matrix->cols && second_col < base_matrix->cols && first_col != second_col)
    {
        double temp;
        for (int r = 0; r < base_matrix->cols; r++)
        {
            temp = base_matrix->data[r][first_col];
            base_matrix->data[r][first_col] = base_matrix->data[r][second_col];
            base_matrix->data[r][second_col] = temp;
        }
    }
}

Matrix get_row_matrix(Matrix base_matrix, int index_of_row)
{
    if (index_of_row >= 0 && index_of_row < base_matrix->rows)
    {
        Matrix m = new_matrix(1, base_matrix->cols);
        for (int c = 0; c < base_matrix->cols; c++)
            m->data[0][c] = base_matrix->data[index_of_row][c];
        return m;
    }
    return new_matrix(0, 0);
}

Matrix get_column_matrix(Matrix base_matrix, int index_of_col)
{
    if (index_of_col >= 0 && index_of_col < base_matrix->rows)
    {
        Matrix m = new_matrix(base_matrix->rows, 1);
        for (int r = 0; r < base_matrix->rows; r++)
            m->data[r][0] = base_matrix->data[r][index_of_col];
        return m;
    }
    return new_matrix(0, 0);
}

void print_pair(Pair pair)
{
    printf("(%d, %d)", pair->first, pair->second);
}

void print_polar2D(Polar2D point)
{
    if (point->r == 0 && point->theta == 0)
        printf("(0, 0)");
    else if (point->r != 0 && point->theta == 0)
        printf("(%lf, 0)", point->r);
    else if (point->r == 0 && point->theta != 0)
        printf("(0, %lf)", point->theta);
    else
        printf("(%lf, %lf)", point->r, point->theta);
}

void print_polar(Polar point)
{
    if (point->r == 0 && point->theta_x == 0 && point->theta_z == 0)
        printf("(0, 0, 0)");
    else if (point->r != 0 && point->theta_x == 0 && point->theta_z == 0)
        printf("(%lf, 0, 0)", point->r);
    else if (point->r == 0 && point->theta_x != 0 && point->theta_z == 0)
        printf("(0, %lf, 0)", point->theta_x);
    else if (point->r != 0 && point->theta_x != 0 && point->theta_z == 0)
        printf("(%lf, %lf, 0)", point->r, point->theta_x);
    else if (point->r == 0 && point->theta_x == 0 && point->theta_z != 0)
        printf("(0, 0, %lf)", point->theta_z);
    else if (point->r == 0 && point->theta_x != 0 && point->theta_z != 0)
        printf("(0, %lf, %lf)", point->theta_x, point->theta_z);
    else if (point->r != 0 && point->theta_x == 0 && point->theta_z != 0)
        printf("(%lf, 0, %lf)", point->r, point->theta_z);
    else
        printf("(%lf, %lf, %lf)", point->r, point->theta_x, point->theta_z);
}

void print_point2D(Point2D point)
{
    if (point->X == 0 && point->Y == 0)
        printf("(0, 0)");
    else if (point->X != 0 && point->Y == 0)
        printf("(%lf, 0)", point->X);
    else if (point->X == 0 && point->Y != 0)
        printf("(0, %lf)", point->Y);
    else
        printf("(%lf, %lf)", point->X, point->Y);
}

void print_point(Point point)
{
    if (point->X == 0 && point->Y == 0 && point->Z == 0)
        printf("(0, 0, 0)");
    else if (point->X != 0 && point->Y == 0 && point->Z == 0)
        printf("(%lf, 0, 0)", point->X);
    else if (point->X == 0 && point->Y != 0 && point->Z == 0)
        printf("(0, %lf, 0)", point->Y);
    else if (point->X == 0 && point->Y == 0 && point->Z != 0)
        printf("(0, 0, %lf)", point->Z);
    else if (point->X != 0 && point->Y != 0 && point->Z == 0)
        printf("(%lf, %lf, 0)", point->X, point->Y);
    else if (point->X != 0 && point->Y == 0 && point->Z != 0)
        printf("(%lf, 0, %lf)", point->X, point->Z);
    else if (point->X == 0 && point->Y != 0 && point->Z != 0)
        printf("(0, %lf, %lf)", point->Y, point->Z);
    else
        printf("(%lf, %lf, %lf)", point->X, point->Y, point->Z);
}

void print_complex(Complex number)
{
    if (number->real == 0 && number->imaginary == 0)
        printf("(0)");
    else if (number->real != 0 && number->imaginary == 0)
        printf("(%lf)", number->real);
    else if (number->real == 0 && number->imaginary != 0)
        printf("(%lfi)", number->imaginary);
    else
    {
        if (number->imaginary < 0)
            printf("(%lf - %lfi)", number->real, absolute(number->imaginary));
        else
            printf("(%lf + %lfi)", number->real, number->imaginary);
    }
}

void print_complex_array(Complex_Array complex_array)
{
    if (complex_array->length == 1)
    {
        printf("[");
        print_complex(complex_array->complex_numbers[0]);
        printf("]\n");
    }
    else if (complex_array->length > 1)
    {
        printf("[");
        print_complex(complex_array->complex_numbers[0]);
        for (int i = 1; i < complex_array->length; i++)
        {
            printf(", ");
            print_complex(complex_array->complex_numbers[i]);
        }
        printf("]\n");
    }
}

void print_vector2D(Vector2D vector)
{
    if (vector->X == 0 && vector->Y == 0)
        printf("<0>");
    else if (vector->X != 0 && vector->Y == 0)
        printf("<%lfi>", vector->X);
    else if (vector->X == 0 && vector->Y != 0)
        printf("<%lfj>", vector->Y);
    else
    {
        if (vector->Y < 0)
            printf("<%lfi - %lfj>", vector->X, absolute(vector->Y));
        else
            printf("<%lfi + %lfj>", vector->X, vector->Y);
    }
}

void print_vector(Vector vector)
{
    if (vector->X == 0 && vector->Y == 0 && vector->Z == 0)
        printf("<0>");
    else if (vector->X != 0 && vector->Y == 0 && vector->Z == 0)
        printf("<%lfi>", vector->X);
    else if (vector->X == 0 && vector->Y != 0 && vector->Z == 0)
        printf("<%lfj>", vector->Y);
    else if (vector->X == 0 && vector->Y == 0 && vector->Z != 0)
        printf("<%lfk>", vector->Z);
    else if (vector->X != 0 && vector->Y != 0 && vector->Z == 0)
    {
        if (vector->Y < 0)
            printf("<%lfi - %lfj>", vector->X, absolute(vector->Y));
        else
            printf("<%lfi + %lfj>", vector->X, vector->Y);
    }
    else if (vector->X != 0 && vector->Y == 0 && vector->Z != 0)
    {
        if (vector->Z < 0)
            printf("<%lfi - %lfk>", vector->X, absolute(vector->Z));
        else
            printf("<%lfi + %lfk>", vector->X, vector->Z);
    }
    else if (vector->X == 0 && vector->Y != 0 && vector->Z != 0)
    {
        if (vector->Z < 0)
            printf("<%lfj - %lfk>", vector->Y, absolute(vector->Z));
        else
            printf("<%lfj + %lfk>", vector->Y, vector->Z);
    }
    else
    {
        if (vector->Y < 0 && vector->Z < 0)
            printf("<%lfi - %lfj - %lfk>", vector->X, sqrt(vector->Y * vector->Y), sqrt(vector->Z * vector->Z));
        else if (vector->Y < 0 && vector->Z > 0)
            printf("<%lfi - %lfj + %lfk>", vector->X, sqrt(vector->Y * vector->Y), vector->Z);
        else if (vector->Y > 0 && vector->Z < 0)
            printf("<%lfi + %lfj - %lfk>", vector->X, vector->Y, sqrt(vector->Z * vector->Z));
        else
            printf("<%lfi + %lfj + %lfk>", vector->X, vector->Y, vector->Z);
    }
}

void print_matrix(Matrix matrix)
{
    for (int r = 0; r < matrix->rows; r++)
    {
        printf("[");
        for (int c = 0; c < matrix->cols; c++)
            printf("%lf\t", matrix->data[r][c]);
        printf("]\n");
    }
}

void print_types_of_matrix(char **types)
{
    int count = 0;
    while (types[count])
        count++;
    if (count == 0)
        return;
    printf("[");
    printf("'%s'", types[0]);
    for (int i = 1; i < count; i++)
        printf(", '%s'", types[i]);
    printf("]");
}

Matrix principal_diagonal(Matrix matrix)
{
    if (matrix->rows == matrix->cols)
    {
        Matrix diagonal_matrix = new_matrix(1, matrix->cols);
        for (int r = 0; r < matrix->rows; r++)
            diagonal_matrix->data[0][r] = matrix->data[r][r];
        return diagonal_matrix;
    }
    return new_matrix(0, 0);
}

Matrix principal_diagonal_matrix(Matrix matrix)
{
    if (matrix->rows == matrix->cols)
    {
        Matrix diagonal_matrix = new_matrix(matrix->rows, matrix->cols);
        for (int r = 0; r < matrix->rows; r++)
            diagonal_matrix->data[r][r] = matrix->data[r][r];
        return diagonal_matrix;
    }
    return new_matrix(0, 0);
}

double trace(Matrix matrix)
{
    if (matrix->rows == matrix->cols)
    {
        double sum = 0;
        for (int r = 0; r < matrix->rows; r++)
            sum += matrix->data[r][r];
        return sum;
    }
    return 0;
}

Matrix secondary_diagonal(Matrix matrix)
{
    if (matrix->rows == matrix->cols)
    {
        Matrix diagonal_matrix = new_matrix(1, matrix->cols);
        for (int r = 0; r < matrix->rows; r++)
            diagonal_matrix->data[0][r] = matrix->data[r][matrix->cols - r - 1];
        return diagonal_matrix;
    }
    return new_matrix(0, 0);
}

Matrix secondary_diagonal_matrix(Matrix matrix)
{
    if (matrix->rows == matrix->cols)
    {
        Matrix diagonal_matrix = new_matrix(matrix->rows, matrix->cols);
        for (int r = 0; r < matrix->rows; r++)
            diagonal_matrix->data[r][matrix->cols - r - 1] = matrix->data[r][matrix->cols - r - 1];
        return diagonal_matrix;
    }
    return new_matrix(0, 0);
}

double secondary_trace(Matrix matrix)
{
    if (matrix->rows == matrix->cols)
    {
        double sum = 0;
        for (int r = 0; r < matrix->rows; r++)
            sum += matrix->data[r][matrix->cols - r - 1];
        return sum;
    }
    return 0;
}

Matrix scale_matrix(Matrix matrix, double scalar_number)
{
    Matrix scaled_matrix = new_matrix(matrix->rows, matrix->cols);
    for (int r = 0; r < matrix->rows; r++)
    {
        for (int c = 0; c < matrix->cols; c++)
            scaled_matrix->data[r][c] = scalar_number * matrix->data[r][c];
    }
    return scaled_matrix;
}

Matrix add_matrix(Matrix matrix_1, Matrix matrix_2)
{
    if (are_perfect(matrix_1, matrix_2, addition))
    {
        Matrix result = new_matrix(matrix_1->rows, matrix_1->cols);
        for (int r = 0; r < matrix_1->rows; r++)
        {
            for (int c = 0; c < matrix_1->cols; c++)
                result->data[r][c] = matrix_1->data[r][c] + matrix_2->data[r][c];
        }
        return result;
    }
    return new_matrix(0, 0);
}

Matrix add_row_matrix(Matrix base_matrix, Matrix row_matrix)
{
    if (base_matrix->cols == row_matrix->cols)
    {
        Matrix result = new_matrix(base_matrix->rows, base_matrix->cols);
        for (int r = 0; r < base_matrix->rows; r++)
        {
            for (int c = 0; c < base_matrix->cols; c++)
                result->data[r][c] = base_matrix->data[r][c] + row_matrix->data[0][c];
        }
        return result;
    }
    return new_matrix(0, 0);
}

Matrix add_column_matrix(Matrix base_matrix, Matrix column_matrix)
{
    if (base_matrix->rows == column_matrix->rows)
    {
        Matrix result = new_matrix(base_matrix->rows, base_matrix->cols);
        for (int r = 0; r < base_matrix->rows; r++)
        {
            for (int c = 0; c < base_matrix->cols; c++)
                result->data[r][c] = base_matrix->data[r][c] + column_matrix->data[r][0];
        }
        return result;
    }
    return new_matrix(0, 0);
}

Matrix subtract_matrix(Matrix matrix_1, Matrix matrix_2)
{
    if (are_perfect(matrix_1, matrix_2, subtraction))
    {
        Matrix result = new_matrix(matrix_1->rows, matrix_1->cols);
        for (int r = 0; r < matrix_1->rows; r++)
        {
            for (int c = 0; c < matrix_1->cols; c++)
                result->data[r][c] = matrix_1->data[r][c] - matrix_2->data[r][c];
        }
        return result;
    }
    return new_matrix(0, 0);
}

Matrix subtract_row_matrix(Matrix base_matrix, Matrix row_matrix)
{
    if (base_matrix->cols == row_matrix->cols)
    {
        Matrix result = new_matrix(base_matrix->rows, base_matrix->cols);
        for (int r = 0; r < base_matrix->rows; r++)
        {
            for (int c = 0; c < base_matrix->cols; c++)
                result->data[r][c] = base_matrix->data[r][c] - row_matrix->data[0][c];
        }
        return result;
    }
    return new_matrix(0, 0);
}

Matrix subtract_column_matrix(Matrix base_matrix, Matrix column_matrix)
{
    if (base_matrix->rows == column_matrix->rows)
    {
        Matrix result = new_matrix(base_matrix->rows, base_matrix->cols);
        for (int r = 0; r < base_matrix->rows; r++)
        {
            for (int c = 0; c < base_matrix->cols; c++)
                result->data[r][c] = base_matrix->data[r][c] - column_matrix->data[r][0];
        }
        return result;
    }
    return new_matrix(0, 0);
}

Matrix multiply_matrix(Matrix matrix_1, Matrix matrix_2)
{
    if (are_perfect(matrix_1, matrix_2, multiplication))
    {
        Matrix result = new_matrix(matrix_1->rows, matrix_2->cols);
        for (int i = 0; i < matrix_1->rows; i++)
        {
            for (int j = 0; j < matrix_2->cols; j++)
            {
                result->data[i][j] = 0;
                for (int k = 0; k < matrix_2->rows; k++)
                    result->data[i][j] += matrix_1->data[i][k] * matrix_2->data[k][j];
            }
        }
        return result;
    }
    return new_matrix(0, 0);
}

Matrix power_matrix(Matrix matrix, int n)
{
    if (matrix->rows == matrix->cols)
    {
        if (n == 0)
            return new_identity_matrix(matrix->rows);
        else if (n == 1)
            return matrix;
        else if (n > 1)
        {
            Matrix result = new_identity_matrix(matrix->rows);
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

Matrix minor_matrix(Matrix matrix, int index_row, int index_col)
{
    if (is_square_matrix(matrix))
    {
        Matrix minor = new_matrix(matrix->rows - 1, matrix->cols - 1);
        int r = 0, c = 0;
        for (int row = 0; row < matrix->rows; row++)
        {
            if (row != index_row)
            {
                for (int col = 0; col < matrix->rows; col++)
                {
                    if (col != index_col)
                        minor->data[r][c++] = matrix->data[row][col];
                }
                c = 0;
                r++;
            }
        }
        return minor;
    }
    return new_matrix(0, 0);
}

double determinant(Matrix matrix)
{
    if (is_square_matrix(matrix))
    {
        if (matrix->rows == 1 && matrix->cols == 1)
            return matrix->data[0][0];
        Matrix temp_minor_matrix = new_matrix(matrix->rows - 1, matrix->cols - 1);
        int sign = 1, det = 0;
        for (int c = 0; c < matrix->rows; c++)
        {
            temp_minor_matrix = minor_matrix(matrix, 0, c);
            det += sign * matrix->data[0][c] * determinant(temp_minor_matrix);
            sign = -sign;
        }
        return det;
    }
    return 0;
}

double minor(Matrix matrix, int index_row, int index_col)
{
    if (is_square_matrix(matrix))
        return determinant(minor_matrix(matrix, index_row, index_col));
    return 0;
}

double co_factor(Matrix matrix, int index_row, int index_col)
{
    if (is_square_matrix(matrix))
    {
        int sign = (index_row + index_col) % 2 == 0 ? 1 : -1;
        return (double)sign * determinant(minor_matrix(matrix, index_row, index_col));
    }
    return 0;
}

Matrix adjoint(Matrix matrix)
{
    if (is_square_matrix(matrix))
    {
        Matrix adjoint_matrix = new_matrix(matrix->rows, matrix->cols);
        for (int r = 0; r < matrix->cols; r++)
        {
            for (int c = 0; c < matrix->rows; c++)
                adjoint_matrix->data[r][c] = co_factor(matrix, r, c);
        }
        return transpose(adjoint_matrix);
    }
    return new_matrix(0, 0);
}

Matrix inverse(Matrix matrix)
{
    if (is_square_matrix(matrix))
        return scale_matrix(adjoint(matrix), 1 / determinant(matrix));
    return new_matrix(0, 0);
}

Vector2D add_vector2D(Vector2D vector_1, Vector2D vector_2)
{
    return new_vector2D((vector_1->X + vector_2->X), (vector_1->Y + vector_2->Y));
}

Vector add_vector(Vector vector_1, Vector vector_2)
{
    return new_vector((vector_1->X + vector_2->X), (vector_1->Y + vector_2->Y), (vector_1->Z + vector_2->Z));
}

Vector2D subtract_vector2D(Vector2D vector_1, Vector2D vector_2)
{
    return new_vector2D((vector_1->X - vector_2->X), (vector_1->Y - vector_2->Y));
}

Vector subtract_vector(Vector vector_1, Vector vector_2)
{
    return new_vector((vector_1->X - vector_2->X), (vector_1->Y - vector_2->Y), (vector_1->Z - vector_2->Z));
}

Vector2D scale_vector2D(Vector2D vector, double scalar_number)
{
    return new_vector2D((scalar_number * vector->X), (scalar_number * vector->Y));
}

Vector scale_vector(Vector vector, double scalar_number)
{
    return new_vector((scalar_number * vector->X), (scalar_number * vector->Y), (scalar_number * vector->Z));
}

double dot2D(Vector2D vector_1, Vector2D vector_2)
{
    return ((vector_1->X * vector_2->X) + (vector_1->Y * vector_2->Y));
}

double dot(Vector vector_1, Vector vector_2)
{
    return ((vector_1->X * vector_2->X) + (vector_1->Y * vector_2->Y) + (vector_1->Z * vector_2->Z));
}

Vector cross2D(Vector2D vector_1, Vector2D vector_2)
{
    Vector vector = new_vector(0, 0, 0);
    vector->X = 0;
    vector->Y = 0;
    vector->Z = (vector_1->X * vector_2->Y) - (vector_1->Y * vector_2->X);
    return vector;
}

Vector cross(Vector vector_1, Vector vector_2)
{
    Vector vector = new_vector(0, 0, 0);
    vector->X = (vector_1->Y * vector_2->Z) - (vector_1->Z * vector_2->Y);
    vector->Y = (vector_1->Z * vector_2->X) - (vector_1->X * vector_2->Z);
    vector->Z = (vector_1->X * vector_2->Y) - (vector_1->Y * vector_2->X);
    return vector;
}

double value_of_vector2D(Vector2D vector)
{
    return sqrt(vector->X * vector->X + vector->Y * vector->Y);
}

double value_of_vector(Vector vector)
{
    return sqrt(vector->X * vector->X + vector->Y * vector->Y + vector->Z * vector->Z);
}

Vector2D unit_vector2D(Vector2D vector)
{
    return scale_vector2D(vector, 1 / value_of_vector2D(vector));
}

Vector unit_vector(Vector vector)
{
    return scale_vector(vector, 1 / value_of_vector(vector));
}

double angle_between_vectors2D(Vector2D vector_1, Vector2D vector_2, angle_mode angle_mode)
{
    double angle = acos(dot2D(vector_1, vector_2) / (value_of_vector2D(vector_1) * value_of_vector2D(vector_2)));
    return ((angle_mode == radian) ? angle : to_degree(angle));
}

double angle_between_vectors(Vector vector_1, Vector vector_2, angle_mode angle_mode)
{
    double angle = acos(dot(vector_1, vector_2) / (value_of_vector(vector_1) * value_of_vector(vector_2)));
    return ((angle_mode == radian) ? angle : to_degree(angle));
}

Matrix translate_row_vector_matrix(Matrix matrix, Matrix translate_by_row_matrix)
{
    if (!is_null(matrix))
        return add_row_matrix(matrix, translate_by_row_matrix);
}

Matrix translate_column_vector_matrix(Matrix matrix, Matrix translate_by_column_matrix)
{
    if (!is_null(matrix))
        return add_column_matrix(matrix, translate_by_column_matrix);
}

Matrix scale_row_vector_matrix(Matrix matrix, Matrix scale_by_row_matrix)
{
    if (scale_by_row_matrix->cols == matrix->cols)
    {
        Matrix scalar_matrix = new_primary_diagonal_matrix(matrix->cols, scale_by_row_matrix);
        return multiply_matrix(matrix, scalar_matrix);
    }
}

Matrix scale_column_vector_matrix(Matrix matrix, Matrix scale_by_column_matrix)
{
    if (scale_by_column_matrix->cols == matrix->rows)
    {
        Matrix scalar_matrix = new_primary_diagonal_matrix(matrix->cols, transpose(scale_by_column_matrix));
        return transpose(multiply_matrix(scalar_matrix, matrix));
    }
}

Matrix rotation_matrix_in_2D(double angle, angle_mode angle_mode)
{
    if (angle_mode == degree)
        angle = to_radian(angle);
    Matrix r_matrix = new_matrix(2, 2);
    r_matrix->data[0][0] = cos(angle);
    r_matrix->data[1][0] = sin(angle);
    r_matrix->data[0][1] = -sin(angle);
    r_matrix->data[1][1] = cos(angle);
    return r_matrix;
}

Matrix rotation_matrix_in_3D(Vector rotation_axis_vector, float angle, angle_mode angle_mode)
{
    if (angle_mode == degree)
        angle = to_radian(angle);
    angle = angle / 2;
    Vector v = unit_vector(rotation_axis_vector);
    double vr = cos(angle), vi = (sin(angle) * v->X), vj = (sin(angle) * v->Y), vk = (sin(angle) * v->Z);
    Matrix r_matrix = new_matrix(3, 3);
    r_matrix->data[0][0] = 1 - (2 * (vj * vj + vk * vk));
    r_matrix->data[1][0] = 2 * (vi * vj + vk * vr);
    r_matrix->data[2][0] = 2 * (vi * vk - vj * vr);
    r_matrix->data[0][1] = 2 * (vi * vj - vk * vr);
    r_matrix->data[1][1] = 1 - (2 * (vi * vi + vk * vk));
    r_matrix->data[2][1] = 2 * (vj * vk + vi * vr);
    r_matrix->data[0][2] = 2 * (vi * vk + vj * vr);
    r_matrix->data[1][2] = 2 * (vj * vk - vi * vr);
    r_matrix->data[2][2] = 1 - (2 * (vi * vi + vj * vj));
    return r_matrix;
}

Point2D rotate_point_in_2D(Point2D point, Point2D reference_point_origin, double angle, angle_mode angle_mode)
{
    Matrix p_matrix = to_column_matrix2D(point2D_to_vector2D(point));
    Matrix rp_matrix = to_column_matrix2D(point2D_to_vector2D(reference_point_origin));
    Matrix rotation_matrix = rotation_matrix_in_2D(angle, angle_mode);
    return vector2D_to_point2D(vectorize2D(add_matrix(multiply_matrix(rotation_matrix, subtract_matrix(p_matrix, rp_matrix)), rp_matrix)));
}

Point rotate_point_in_3D(Point point, Point reference_point_origin, Vector rotation_axis_vector, double angle, angle_mode angle_mode)
{
    Matrix p_matrix = to_column_matrix(point_to_vector(point));
    Matrix rp_matrix = to_column_matrix(point_to_vector(reference_point_origin));
    Matrix rotation_matrix = rotation_matrix_in_3D(rotation_axis_vector, angle, angle_mode);
    return vector_to_point(vectorize(add_matrix(multiply_matrix(rotation_matrix, subtract_matrix(p_matrix, rp_matrix)), rp_matrix)));
}

Vector2D rotate_vector_in_2D(Vector2D vector, Vector2D reference_vector_origin, double angle, angle_mode angle_mode)
{
    Matrix v_matrix = to_column_matrix2D(vector);
    Matrix rv_matrix = to_column_matrix2D(reference_vector_origin);
    Matrix rotation_matrix = rotation_matrix_in_2D(angle, angle_mode);
    return vectorize2D(add_matrix(multiply_matrix(rotation_matrix, subtract_matrix(v_matrix, rv_matrix)), rv_matrix));
}

Vector rotate_vector_in_3D(Vector vector, Vector reference_vector_origin, Vector rotation_axis_vector, double angle, angle_mode angle_mode)
{
    Matrix v_matrix = to_column_matrix(vector);
    Matrix rv_matrix = to_column_matrix(reference_vector_origin);
    Matrix rotation_matrix = rotation_matrix_in_3D(rotation_axis_vector, angle, angle_mode);
    return vectorize(add_matrix(multiply_matrix(rotation_matrix, subtract_matrix(v_matrix, rv_matrix)), rv_matrix));
}

Matrix rotate_matrix_in_2D(Matrix column_vector2D_matrix, Vector2D reference_vector_origin, double angle, angle_mode angle_mode)
{
    Matrix rv_matrix = to_column_matrix2D(reference_vector_origin);
    Matrix rotation_matrix = rotation_matrix_in_2D(angle, angle_mode);
    return add_matrix(multiply_matrix(rotation_matrix, subtract_matrix(column_vector2D_matrix, rv_matrix)), rv_matrix);
}

Matrix rotate_matrix_in_3D(Matrix column_vector_matrix, Vector reference_vector_origin, Vector rotation_axis_vector, double angle, angle_mode angle_mode)
{
    Matrix rv_matrix = to_column_matrix(reference_vector_origin);
    Matrix rotation_matrix = rotation_matrix_in_3D(rotation_axis_vector, angle, angle_mode);
    return add_matrix(multiply_matrix(rotation_matrix, subtract_matrix(column_vector_matrix, rv_matrix)), rv_matrix);
}

Matrix solve_xy(Matrix coefficients_square_matrix, Matrix constants_column_matrix)
{
    Matrix result_column_matrix = new_matrix(coefficients_square_matrix->cols, 1);
    if (is_square_matrix(coefficients_square_matrix) && constants_column_matrix->rows == coefficients_square_matrix->cols && constants_column_matrix->cols == 1)
    {
        double scaling_factor = 1 / determinant(coefficients_square_matrix);
        for (int i = 0; i < coefficients_square_matrix->cols; i++)
            result_column_matrix->data[i][0] = scaling_factor * determinant(replace_column_matrix(coefficients_square_matrix, i, constants_column_matrix));
    }
    return result_column_matrix;
}

double solve_x(double a, double b)
{
    return -(b / a);
}

Complex_Array solve_x2(double a, double b, double c)
{
    Complex_Array complex_array = new_complex_array(2);
    double m = b * b - 4 * a * c;
    if (m >= 0)
    {
        double sqrt_m = sqrt(m);
        complex_array->complex_numbers[0] = new_complex((-b - sqrt_m) / 2, 0);
        complex_array->complex_numbers[1] = new_complex((-b + sqrt_m) / 2, 0);
        return complex_array;
    }
    Complex csqrt_m = power_complex(new_complex(m, 0), new_complex(0.5, 0));
    csqrt_m->real /= 2;
    csqrt_m->imaginary /= 2;
    Complex cb = new_complex(-b / 2, 0);
    complex_array->complex_numbers[0] = add_complex(cb, csqrt_m);
    complex_array->complex_numbers[1] = subtract_complex(cb, csqrt_m);
    return complex_array;
}

Complex_Array solve_x3(double a, double b, double c, double d)
{
    double p, q, m, N, n, t, a0 = a;
    Complex y = new_complex(0, 0);
    Complex_Array complex_array_2 = new_complex_array(2);
    Complex_Array complex_array_3 = new_complex_array(3);
    a = b / a0;
    b = c / a0;
    c = d / a0;
    d = 0;
    p = b - ((a * a) / 3);
    q = (2 * (a * a * a) / 27) - (a * b / 3) + c;
    m = -q / 2;
    N = ((q * q) / 4) + (p * p * p / 27);
    n = sqrt(absolute(N));

    if (N >= 0)
        t = cbrt(m + n) + cbrt(m - n);
    else
    {
        Complex z = new_complex(m, n);
        double r = sqrt((m * m) + absolute(N));
        double theta = argument(z, radian) / 3;
        t = 2 * cbrt(r) * cos(theta);
    }
    Complex u = new_complex(a / 3, 0);
    y->real = t;
    complex_array_2 = solve_x2(1, t, (t * t) + p);

    complex_array_3->complex_numbers[0] = subtract_complex(y, u);
    complex_array_3->complex_numbers[1] = subtract_complex(complex_array_2->complex_numbers[0], u);
    complex_array_3->complex_numbers[2] = subtract_complex(complex_array_2->complex_numbers[1], u);
    return complex_array_3;
}

bool is_type_of(Matrix matrix, matrix_type type)
{
    if (type == row_matrix)
    {
        if (matrix->rows == 1 && matrix->cols > 1)
            return true;
        return false;
    }

    else if (type == column_matrix)
    {
        if (matrix->rows > 1 && matrix->cols == 1)
            return true;
        return false;
    }

    else if (type == horizontal_matrix)
    {
        if (matrix->rows < matrix->cols)
            return true;
        return false;
    }

    else if (type == vertical_matrix)
    {
        if (matrix->rows > matrix->cols)
            return true;
        return false;
    }

    else if (type == singleton_matrix)
    {
        if (matrix->rows == 1 && matrix->cols == 1)
            return true;
        return false;
    }

    else if (type == square_matrix)
    {
        if (matrix->rows == matrix->cols)
            return true;
        return false;
    }

    else if (type == singular_matrix)
    {
        if (determinant(matrix) == 0)
            return true;
        return false;
    }

    else if (type == nonsingular_matrix)
    {
        if (determinant(matrix) != 0)
            return true;
        return false;
    }

    else if (type == diagonal_matrix)
    {
        if (matrix->rows == matrix->cols)
        {
            int n = matrix->rows, count_zeros = 0, count_non_zeros = 0;
            for (int r = 0; r < n; r++)
            {
                for (int c = 0; c < n; c++)
                {
                    if (c != r && matrix->data[r][c] == 0)
                        count_zeros++;
                    if (c == r && matrix->data[r][c] != 0)
                        count_non_zeros++;
                }
            }
            if (count_non_zeros == n && count_zeros == n * (n - 1))
                return true;
            return false;
        }
        return false;
    }

    else if (type == scalar_matrix)
    {
        if (matrix->rows == matrix->cols)
        {
            int n = matrix->rows, constant = matrix->data[0][0], count_zeros = 0, count_consts = 0;
            for (int r = 0; r < n; r++)
            {
                for (int c = 0; c < n; c++)
                {
                    if (c != r && matrix->data[r][c] == 0)
                        count_zeros++;
                    if (c == r && matrix->data[r][c] == constant)
                        count_consts++;
                }
            }
            if (count_consts == n && count_zeros == n * (n - 1))
                return true;
            return false;
        }
        return false;
    }

    else if (type == identity_matrix || type == unit_matrix)
    {
        if (matrix->rows == matrix->cols)
        {
            int n = matrix->rows, count_zeros = 0, count_unit = 0;
            for (int r = 0; r < n; r++)
            {
                for (int c = 0; c < n; c++)
                {
                    if (c != r && matrix->data[r][c] == 0)
                        count_zeros++;
                    if (c == r && matrix->data[r][c] == 1)
                        count_unit++;
                }
            }
            if (count_unit == n && count_zeros == n * (n - 1))
                return true;
            return false;
        }
        return false;
    }

    else if (type == null_matrix || type == zero_matrix)
    {
        if (matrix->rows == matrix->cols)
        {
            int n = matrix->rows, count_zeros = 0;
            for (int r = 0; r < n; r++)
            {
                for (int c = 0; c < n; c++)
                {
                    if (matrix->data[r][c] == 0)
                        count_zeros++;
                }
            }
            if (count_zeros == n * n)
                return true;
            return false;
        }
        return false;
    }

    else if (type == upper_triangular_matrix)
    {
        if (matrix->rows == matrix->cols)
        {
            int n = matrix->rows, m = (n * (n - 1)) / 2, count_zeros = 0;
            for (int r = 0; r < n; r++)
            {
                for (int c = 0; c < n; c++)
                {
                    if (c < r && matrix->data[r][c] == 0)
                        count_zeros++;
                }
            }
            if (count_zeros == m)
                return true;
            return false;
        }
        return false;
    }

    else if (type == lower_triangular_matrix)
    {
        if (matrix->rows == matrix->cols)
        {
            int n = matrix->rows, m = (n * (n - 1)) / 2, count_zeros = 0;
            for (int r = 0; r < n; r++)
            {
                for (int c = 0; c < n; c++)
                {
                    if (c > r && matrix->data[r][c] == 0)
                        count_zeros++;
                }
            }
            if (count_zeros == m)
                return true;
            return false;
        }
        return false;
    }

    else if (type == triangular_matrix)
    {
        if (is_type_of(matrix, upper_triangular_matrix) || is_type_of(matrix, lower_triangular_matrix))
            return true;
        return false;
    }

    else if (type == involutory_matrix)
    {
        if (matrix->rows == matrix->cols)
            return is_type_of(multiply_matrix(matrix, matrix), identity_matrix);
        return false;
    }

    else if (type == symmetric_matrix)
    {
        if (matrix->rows == matrix->cols)
            return are_identical(matrix, transpose(matrix));
        return false;
    }

    else if (type == skew_symmetric_matrix)
    {
        if (matrix->rows == matrix->cols)
            return are_identical(scale_matrix(matrix, -1), transpose(matrix));
        return false;
    }

    else if (type == orthogonal_matrix)
    {
        if (matrix->rows == matrix->cols)
            return are_identical(multiply_matrix(matrix, transpose(matrix)), new_identity_matrix(matrix->rows));
        return false;
    }

    else if (type == idempotent_matrix)
    {
        if (matrix->rows == matrix->cols)
            return are_identical(matrix, multiply_matrix(matrix, matrix));
        return false;
    }

    else if (type == periodic_matrix) // It is seriously very complicated to check...
    {
        if (matrix->rows == matrix->cols)
        {
            if (is_type_of(matrix, null_matrix))
                return true;
            else if (is_type_of(matrix, identity_matrix))
                return true;
            int trial = 0;
            Matrix temp_matrix = new_matrix(matrix->rows, matrix->cols);
            temp_matrix = copy_matrix(matrix);
            while (trial != 1024)
            {
                temp_matrix = multiply_matrix(temp_matrix, matrix);
                if (are_identical(matrix, temp_matrix))
                    return true;
                trial++;
            }
            return false;
        }
        return false;
    }

    else if (type == nilpotent_matrix) // It is seriously very complicated to check as well...
    {
        if (matrix->rows == matrix->cols)
        {
            if (is_type_of(matrix, null_matrix))
                return true;
            int trial = 0;
            Matrix temp_matrix = new_matrix(matrix->rows, matrix->cols);
            temp_matrix = copy_matrix(matrix);
            while (trial != 1024)
            {
                temp_matrix = multiply_matrix(temp_matrix, matrix);
                if (is_type_of(temp_matrix, null_matrix))
                    return true;
                trial++;
            }
            return false;
        }
        return false;
    }

    else
        return false;
}

char **types_of_matrix(Matrix matrix, text_style text_style)
{
    char **list_of_types = (char **)malloc(375 * sizeof(char) + 15 * sizeof(char *));
    int count = 0;

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