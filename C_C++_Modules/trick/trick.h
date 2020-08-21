typedef char* String;

// #define new(type, m) (type *)malloc(m*sizeof(type))
#define new1(type, m) malloc(sizeof(type[m]))
// #define new2(type, m, n) (type **)malloc(m*sizeof(type *) + m*n*sizeof(type))
#define new2(type, m, n) malloc(sizeof(type[m][n]))
// #define new3(type, m, n, p) (type ***)malloc(m*sizeof(type **) + m*n*sizeof(type *) + m*n*p*sizeof(type))
#define new3(type, m, n, p) malloc(sizeof(type[m][n][p]))

#define start int main(int argc, char const *argv[])
#define stop return 0

#define scan scanf
#define print printf

#define For(i, start, end, step) for(int i=(start); i<(end); i += (step))
#define For_(type, i, start, end, step) for(type i=(start); i<(end); i += (step))

#define size(x) sizeof(x)
#define swap(type, x, y) type temp=x; x=y, y=temp;

#define False 0
#define No 0
#define Off 0
#define True 1
#define Yes 1
#define On 1
#define or ||
#define and &&
#define not !
#define OR |
#define AND &
#define NOT ~
#define XOR ^

#define show(format_spesifier_string, variable)\
char *temp=(char *)malloc(100);\
sprintf(temp, #variable" = %s", format_spesifier_string);\
printf(temp, variable);\
free(temp)