/*
	Module :: [ number.h ]

	AUTHOR  : MD. Shifat Hasan
	Email   : shifathasangns@gmail.com
*/

// ---------------------------------------------------------------- //
//     N E C E S S A R Y    <----->    H E A D E R -- F I L E S     //
// ---------------------------------------------------------------- //

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// ---------------------------------------------------------------- //
//          I M P O R T A N T S    <----->    M A C R O S           //
// ---------------------------------------------------------------- //

/*
    PI = 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679...
*/

#define PI 3.14159265358979323846264338327950288419716939937510

/*
    #define OPERATION <int::VALUE>            
*/

#define ADDITION 0
#define SUBTRACTION 1
#define MULTIPLICATION 2

/*
    #define TYPE_OF_MATRIX <int::VALUE>
*/

#define ROW_MATRIX 3
#define COLUMN_MATRIX 4
#define SQUARE_MATRIX 5
#define DIAGONAL_MATRIX 6
#define SCALAR_MATRIX 7
#define IDENTITY_MATRIX 8
#define UNIT_MATRIX 8
#define NULL_MATRIX 9
#define ZERO_MATRIX 9
#define UPPER_TRIANGULAR_MATRIX 10
#define LOWER_TRIANGULAR_MATRIX 11
#define TRIANGULAR_MATRIX 12
#define INVOLUTORY_MATRIX 13
#define IDEMPOTENT_MATRIX 14
#define SYMMETRIC_MATRIX 15
#define SKEW_SYMMETRIC_MATRIX 16
#define NILPOTENT_MATRIX 17

/*
    #define TEXT_STYLE <int::VALUE>
*/

#define UPPER 18
#define LOWER 19
#define TITLE 20

/*
    #define ANGLE <int::VALUE>
*/

#define DEG 21
#define RAD 22

/*
    #define ROW_COL <int::VALUE>
*/

#define ROW 23
#define COL 24

// --------------------------------------------------------------- //
//             P A I R    <----->    S T R U C T U R E           //
// --------------------------------------------------------------- //

struct Index
{
    int row;
    int col;
};

typedef struct Index* Pair;

// --------------------------------------------------------------- //
//           V E C T O R    <----->    S T R U C T U R E           //
// --------------------------------------------------------------- //

struct vector
{
    double X;
    double Y;
    double Z;
};

typedef struct vector* Vector;
typedef struct vector* Point;

// --------------------------------------------------------------- //
//           M A T R I X    <----->    S T R U C T U R E           //
// --------------------------------------------------------------- //

struct matrix
{
    int rows;
    int cols;
    double **data;
};

typedef struct matrix* Matrix;

// --------------------------------------------------------------- //
//                        F U N C T I O N S                        //
// --------------------------------------------------------------- //


double radian(double angle_in_degree)
{
    return ((angle_in_degree * PI) / 180);
}


double degree(double angle_in_radian)
{
    return ((angle_in_radian * 180) / PI);
}


bool is_null(Matrix matrix)
{
    return (matrix->rows == 0 && matrix->cols == 0) ? true : false;
}


bool is_square_matrix(Matrix matrix)
{
    return (matrix->rows == matrix->cols);
}


bool are_perfect(Matrix matrix_1, Matrix matrix_2, int OPERATION)
{
    if(OPERATION == ADDITION || OPERATION == SUBTRACTION)
        return (matrix_1->rows == matrix_2->rows && matrix_1->cols == matrix_2->cols);
    else if(OPERATION == MULTIPLICATION)
        return (matrix_1->cols == matrix_2->rows);
    return false;
}


bool are_identical(Matrix matrix_1, Matrix matrix_2)
{
    if(matrix_1->rows == matrix_2->rows && matrix_1->cols == matrix_2->cols)
    {
        int count = 0;
        for(int r = 0; r < matrix_1->rows; r++)
        {
            for(int c = 0; c < matrix_1->cols; c++)
                if(matrix_1->data[r][c] == matrix_2->data[r][c]) count++;
        }
        if(count == (matrix_1->rows * matrix_1->cols)) return true;
        return false;
    }
}


Pair pair(int row, int column)
{
    Pair i = (Pair)malloc(sizeof(Pair));
    i->row = row;
    i->col = column;
    return i;
}


Point point(double X, double Y, double Z)
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
    double **data = (double **)malloc(sizeof(double*) * rows); 
    for(int x = 0; x < rows; x++)
        data[x] = (double *)calloc(cols, sizeof(double));
    matrix->data = data;
    return matrix;
}


Matrix null()
{
    return new_matrix(0, 0);
}


Vector zero_vector()
{
    return new_vector(0, 0, 0);
}


Matrix new_identity_matrix(int order)
{
    Matrix matrix = new_matrix(order, order);
    for(int r = 0; r < order; r++)
    {
        for(int c = 0; c < order; c++)
            if(r == c) matrix->data[r][c] = 1;
    }
    return matrix;
}


bool is_number(char *string)
{
    if(string == NULL || *string == '\0') return false; // Checking if the string is Empty...
    int count_dot = 0, count_plus = 0, count_minus = 0; // Initializing...
    // Checking if the string is a number...
    while(*string)
    {
        char c = *string;
        switch(c)
        {
            case '.':
                if(++count_dot > 1) return false;
                break;
            case '+':
                if(++count_plus > 1) return false;
                break;
            case '-':
                if(++count_minus > 1) return false;
                break;
            default:
                if(c < '0' || c > '9') return false;
                break;
        }
        string++;
    }
    // If it's a number then return True...
    return true;
}


char **split(char *string, char c)
{  
    // Initialize...
    sprintf(string, "%s ", string);
    int len = strlen(string), count_c = 0, number_of_tokens = 0;
    char str_c[1], **list_of_tokens = malloc(sizeof(char)*(len-count_c) + sizeof(char *)*(len-count_c-2));
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
    while(splitted_string[count]) count++;
    double *list_of_nums = (double *)malloc(count * sizeof(double));
    // Parse the numbers...
    for(i=0; i<count; i++)
    {
        if(is_number(splitted_string[i]))
        {
            sscanf(splitted_string[i], "%lf", &temp_num); 
            list_of_nums[c++] = temp_num;
            if(num != -1 && c == num) break;
        }
    }
    // Return the list as a double type Number_Array...
    return list_of_nums;
}


Matrix input_matrix(int rows, int cols)
{
    int r, c, count;
    // Temporary Variables...
    double *temp_row = (double *)malloc(cols*sizeof(double));
    char *temp_str = (char *)malloc(100 * cols * sizeof(char));
    // Creating the Matrix...
    Matrix matrix = new_matrix(rows, cols);
    // Getting the Matrix_Input...
    for(r=0; r<rows; r++)
    {
        *temp_str = '\0';
        gets(temp_str);
        for(c=0; c<cols; c++) temp_row[c] = 0;
        temp_row = parse_number(temp_str, cols);
        for(c = 0; c < cols; c++) matrix->data[r][c] = temp_row[c];
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
    while(*array)
    {
        count++;
        array++;
    }
    if(count == (rows*cols)) return true;
    return false;
}


Matrix make_matrix_from_array(double *data, int rows, int cols)
{
    if(is_convertable(data, rows, cols))
    {
        Matrix matrix = new_matrix(rows, cols);
        for(int r = 0; r < rows; r++)
        {
            for(int c = 0; c < cols; c++)
                matrix->data[r][c] = data[cols*r+c];
        }
        return matrix;
    }
    return new_matrix(0, 0);
}


double *make_array_from_matrix(Matrix matrix)
{
    if(!is_null(matrix))
    {
        double *array = (double *)malloc(matrix->rows * matrix->cols * sizeof(double));
        int i = 0;
        for(int r = 0; r < matrix->rows; r++)
        {
            for(int c = 0; c < matrix->cols; c++)
                array[i++] = matrix->data[r][c];
        }
        return array;
    }
    return NULL;
}


Matrix to_row_matrix(Vector vector)
{
    Matrix colMatrix = new_matrix(1, 3);
    colMatrix->data[0][0] = vector->X;
    colMatrix->data[0][1] = vector->Y;
    colMatrix->data[0][2] = vector->Z;
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


Vector vectorize(Matrix matrix)
{
    if(matrix->cols == 1)
    {
        if(matrix->rows == 1) return new_vector(matrix->data[0][0], 0, 0);
        else if(matrix->rows == 2) return new_vector(matrix->data[0][0], matrix->data[1][0], 0);
        else if(matrix->rows == 3) return new_vector(matrix->data[0][0], matrix->data[1][0], matrix->data[2][0]);
    }
    else if(matrix->rows== 1)
    {
        if(matrix->cols == 1) return new_vector(matrix->data[0][0], 0, 0);
        else if(matrix->cols == 2) return new_vector(matrix->data[0][0], matrix->data[0][1], 0);
        else if(matrix->cols == 3) return new_vector(matrix->data[0][0], matrix->data[0][1], matrix->data[0][2]);
    }
    else return new_vector(0, 0, 0);
}


Vector to_point(Vector vector)
{
    return point(vector->X, vector->Y, vector->Z);
}


Vector to_vector(Point point)
{
    return new_vector(point->X, point->Y, point->Z);
}


Vector input_point(int dimention)
{
    return to_point(vectorize(input_matrix(1, dimention)));
}


Vector input_vector(int dimention, int IN_ROW_OR_COLUMN)
{
    if(IN_ROW_OR_COLUMN == ROW) return vectorize(input_matrix(1, dimention));
    if(IN_ROW_OR_COLUMN == COL) return vectorize(input_matrix(dimention, 1));
}


Matrix transpose(Matrix matrix)
{
    Matrix transposed_matrix = new_matrix(matrix->cols, matrix->rows);
    for(int r=0; r<matrix->cols; r++)
    {
        for(int c=0; c<matrix->rows; c++)
            transposed_matrix->data[r][c] = matrix->data[c][r];
    }
    return transposed_matrix;
}


Matrix reform(Matrix matrix, int rows, int cols)
{
    if(!is_null(matrix) && (rows*cols) == (matrix->rows*matrix->cols))
        return make_matrix_from_array(make_array_from_matrix(matrix), rows, cols);
    return matrix;
}


Matrix reshape(Matrix matrix, int rows, int cols)
{
    Matrix m = new_matrix(rows, cols);
    for(int r = 0; r < matrix->rows; r++)
    {
        for(int c = 0; c < matrix->rows; c++)
            m->data[r][c] = matrix->data[r][c];
    }
    return m;
}


Matrix append_row_matrix(Matrix base_matrix, Matrix row_matrix)
{
    if(row_matrix->rows == 1)
    {
        Matrix new_matrix = reshape(base_matrix, base_matrix->rows+1, base_matrix->cols);
        for(int c = 0; c < base_matrix->cols; c++)
            new_matrix->data[base_matrix->rows][c] = row_matrix->data[0][c];
        return new_matrix;
    }
    return base_matrix;
}


Matrix append_column_matrix(Matrix base_matrix, Matrix column_matrix)
{
    if(column_matrix->cols == 1)
    {
        Matrix new_matrix = reshape(base_matrix, base_matrix->rows, base_matrix->cols+1);
        for(int r = 0; r < base_matrix->rows; r++)
            new_matrix->data[r][base_matrix->cols] = column_matrix->data[r][0];
        return new_matrix;
    }
    return base_matrix;
}
    

Matrix insert_row_matrix(Matrix base_matrix, int index_of_row, Matrix row_matrix)
{
    if(row_matrix->rows == 1)
    {
        if(index_of_row >= 0 && index_of_row < base_matrix->rows)
        {
            Matrix m = new_matrix(base_matrix->rows+1, base_matrix->cols);
            for(int r = 0; r < base_matrix->rows+1; r++)
            {
                for(int c = 0; c < base_matrix->cols; c++)
                {
                    if(r < index_of_row) m->data[r][c] = base_matrix->data[r][c];
                    else if(r > index_of_row) m->data[r][c] = base_matrix->data[r-1][c];
                    else m->data[r][c] = row_matrix->data[0][c];
                }
            }
            return m;
        }
        else if(index_of_row == base_matrix->rows) return append_row_matrix(base_matrix, row_matrix);
        else return base_matrix;
    }
    return base_matrix;
}


Matrix insert_column_matrix(Matrix base_matrix, int index_of_col, Matrix column_matrix)
{
    if(column_matrix->cols == 1)
    {
        if(index_of_col >= 0 && index_of_col < base_matrix->cols)
        {
            Matrix m = new_matrix(base_matrix->rows, base_matrix->cols+1);
            for(int r = 0; r < base_matrix->rows; r++)
            {
                for(int c = 0; c < base_matrix->cols+1; c++)
                {
                    if(c < index_of_col) m->data[r][c] = base_matrix->data[r][c];
                    else if(c > index_of_col) m->data[r][c] = base_matrix->data[r][c-1];
                    else m->data[r][c] = column_matrix->data[r][0];
                }
            }
            return m;
        }
        else if(index_of_col == base_matrix->rows) return append_column_matrix(base_matrix, column_matrix);
        return base_matrix;
    }
    return base_matrix;
}


Matrix del_row_matrix(Matrix base_matrix, int index_of_row)
{
    if(index_of_row >= 0 && index_of_row < base_matrix->rows)
    {
        Matrix m = new_matrix(base_matrix->rows-1, base_matrix->cols);
        for(int r = 0; r < base_matrix->rows; r++)
        {
            if(r == index_of_row) continue;
            for(int c = 0; c < base_matrix->cols; c++)
            {
                if(r < index_of_row) m->data[r][c] = base_matrix->data[r][c];
                else if(r > index_of_row) m->data[r-1][c] = base_matrix->data[r][c];
            }
        }
        return m;
    }
    return base_matrix;
}


Matrix del_column_matrix(Matrix base_matrix, int index_of_col)
{
    if(index_of_col >= 0 && index_of_col < base_matrix->cols)
    {
        Matrix m = new_matrix(base_matrix->rows, base_matrix->cols-1);
        for(int r = 0; r < base_matrix->rows; r++)
        {
            for(int c = 0; c < base_matrix->cols; c++)
            {
                if(c < index_of_col) m->data[r][c] = base_matrix->data[r][c];
                else if(c > index_of_col) m->data[r][c-1] = base_matrix->data[r][c];
                else continue;
            }
        }
        return m;
    }
    return base_matrix;
}


Matrix replace_row_matrix(Matrix base_matrix, int index_of_row, Matrix row_matrix)
{
    if(row_matrix->rows == 1 && index_of_row >= 0 && index_of_row < base_matrix->rows)
    {
        Matrix m = new_matrix(base_matrix->rows, base_matrix->cols);
        for(int r = 0; r < base_matrix->rows; r++)
        {
            for(int c = 0; c < base_matrix->cols; c++)
            {
                if(r == index_of_row) m->data[r][c] = row_matrix->data[0][c];
                else m->data[r][c] = base_matrix->data[r][c];
            }
        }
        return m;
    }
    return base_matrix;
}


Matrix replace_column_matrix(Matrix base_matrix, int index_of_col, Matrix column_matrix)
{
    if(column_matrix->cols == 1 && index_of_col >= 0 && index_of_col < base_matrix->cols)
    {
        Matrix m = new_matrix(base_matrix->rows, base_matrix->cols);
        for(int r = 0; r < base_matrix->rows; r++)
        {
            for(int c = 0; c < base_matrix->cols; c++)
            {
                if(c == index_of_col) m->data[r][c] = column_matrix->data[r][0];
                else m->data[r][c] = base_matrix->data[r][c];
            }
        }
        return m;
    }
    return base_matrix;
}


Matrix pop_row_matrix(Matrix base_matrix)
{
    if(base_matrix->rows > 0) return del_row_matrix(base_matrix, base_matrix->rows-1);
    return base_matrix;
}


Matrix pop_column_matrix(Matrix base_matrix)
{
    if(base_matrix->cols > 0) return del_column_matrix(base_matrix, base_matrix->cols-1);
    return base_matrix;
}


void swap_index(Matrix base_matrix, Pair first_index, Pair second_index)
{
    if(first_index->row < base_matrix->rows && first_index->col < base_matrix->cols && second_index->row < base_matrix->rows && second_index->col < base_matrix->cols && first_index->row != second_index->row && first_index->col != second_index->col)
    {
        double temp_index = base_matrix->data[first_index->row][first_index->col];
        base_matrix->data[first_index->row][first_index->col] = base_matrix->data[second_index->row][second_index->col];
        base_matrix->data[second_index->row][second_index->col] = temp_index;
    }
}


void swap_row(Matrix base_matrix, int first_row, int second_row)
{
    if(first_row < base_matrix->rows && second_row < base_matrix->rows && first_row != second_row)
    {
        double temp;
        for(int c = 0; c < base_matrix->cols; c++)
        {
            temp = base_matrix->data[first_row][c];
            base_matrix->data[first_row][c] = base_matrix->data[second_row][c];
            base_matrix->data[second_row][c] = temp;
        }
    }
}


void swap_column(Matrix base_matrix, int first_col, int second_col)
{
    if(first_col < base_matrix->cols && second_col < base_matrix->cols && first_col != second_col)
    {
        double temp;
        for(int r = 0; r < base_matrix->cols; r++)
        {
            temp = base_matrix->data[r][first_col];
            base_matrix->data[r][first_col] = base_matrix->data[r][second_col];
            base_matrix->data[r][second_col] = temp;
        }
    }
}


Matrix get_row_matrix(Matrix base_matrix, int index_of_row)
{
    if(index_of_row >= 0 && index_of_row < base_matrix->rows)
    {
        Matrix m = new_matrix(1, base_matrix->cols);
        for(int c = 0; c < base_matrix->cols; c++)
            m->data[0][c] = base_matrix->data[index_of_row][c];
        return m;
    }
    return new_matrix(0, 0);
}


Matrix get_column_matrix(Matrix base_matrix, int index_of_col)
{
    if(index_of_col >= 0 && index_of_col < base_matrix->rows)
    {
        Matrix m = new_matrix(base_matrix->rows, 1);
        for(int r = 0; r < base_matrix->rows; r++)
            m->data[r][0] = base_matrix->data[r][index_of_col];
        return m;
    }
    return new_matrix(0, 0);
}


void print_index(Pair index)
{
    printf("(%d, %d)", index->row, index->col);
}


void print_point(Point point)
{
    if(point->X == 0 && point->Y == 0 && point->Z == 0)
        printf("(0, 0, 0)");
    else if(point->X != 0 && point->Y == 0 && point->Z == 0)
        printf("(%lf)", point->X);
    else if(point->X == 0 && point->Y != 0 && point->Z == 0)
        printf("(0, %lf)", point->Y);
    else if(point->X == 0 && point->Y == 0 && point->Z != 0)
        printf("(0, 0, %lf)", point->Z);
    else if(point->X != 0 && point->Y != 0 && point->Z == 0)
        printf("(%lf, %lf)", point->X, point->Y);
    else if(point->X != 0 && point->Y == 0 && point->Z != 0)
        printf("(%lf, 0, %lf)", point->X, point->Z);
    else if(point->X == 0 && point->Y != 0 && point->Z != 0)
        printf("(0, %lf, %lf)", point->Y, point->Z);
    else printf("(%lf, %lf, %lf)", point->X, point->Y, point->Z);
}


void print_vector(Vector vector)
{
    if(vector->X == 0 && vector->Y == 0 && vector->Z == 0)
        printf("(0)");
    else if(vector->X != 0 && vector->Y == 0 && vector->Z == 0)
        printf("(%lfi)", vector->X);
    else if(vector->X == 0 && vector->Y != 0 && vector->Z == 0)
        printf("(%lfj)", vector->Y);
    else if(vector->X == 0 && vector->Y == 0 && vector->Z != 0)
        printf("(%lfk)", vector->Z);
    else if(vector->X != 0 && vector->Y != 0 && vector->Z == 0)
    {
        if(vector->Y < 0) printf("(%lfi - %lfj)", vector->X, sqrt(vector->Y * vector->Y));
        else printf("(%lfi + %lfj)", vector->X, vector->Y);
    }
    else if(vector->X != 0 && vector->Y == 0 && vector->Z != 0)
    {
        if(vector->Z < 0) printf("(%lfi - %lfk)", vector->X, sqrt(vector->Z * vector->Z));
        else printf("(%lfi + %lfj)", vector->X, vector->Z);
    }
    else if(vector->X == 0 && vector->Y != 0 && vector->Z != 0)
    {
        if(vector->Z < 0) printf("(%lfj - %lfk)", vector->Y, sqrt(vector->Z * vector->Z));
        else printf("(%lfj + %lfj)", vector->Y, vector->Z);
    }
    else
    {
        if(vector->Y < 0 && vector->Z < 0) printf("(%lfi - %lfj - %lfk)", vector->X, sqrt(vector->Y * vector->Y), sqrt(vector->Z * vector->Z));
        else if(vector->Y < 0 && vector->Z > 0) printf("(%lfi - %lfj + %lfk)", vector->X, sqrt(vector->Y * vector->Y), vector->Z);
        else if(vector->Y > 0 && vector->Z < 0) printf("(%lfi + %lfj - %lfk)", vector->X, vector->Y, sqrt(vector->Z * vector->Z));
        else printf("(%lfi + %lfj + %lfj)", vector->X, vector->Y, vector->Z);
    }
}


void print_matrix(Matrix matrix)
{
    for(int r = 0; r < matrix->rows; r++)
    {
        printf("[");
        for(int c = 0; c < matrix->cols; c++)
            printf("%lf\t", matrix->data[r][c]);
        printf("]\n");
    }
}


void print_types(char **types)
{
    int count = 0;
    while(types[count]) count++;
    if(count == 0) return;
    printf("[");
    printf("'%s'", types[0]);
    for(int i = 1; i < count; i++)
        printf(", '%s'", types[i]);
    printf("]");
}


Matrix principal_diagonal(Matrix matrix)
{
    if(matrix->rows == matrix->cols)
    {
        Matrix diagonal_matrix = new_matrix(1, matrix->cols);
        for(int r = 0; r < matrix->rows; r++)
            diagonal_matrix->data[0][r] = matrix->data[r][r];
        return diagonal_matrix;
    }
    return new_matrix(0, 0);
}


Matrix principal_diagonal_matrix(Matrix matrix)
{
    if(matrix->rows == matrix->cols)
    {
        Matrix diagonal_matrix = new_matrix(matrix->rows, matrix->cols);
        for(int r = 0; r < matrix->rows; r++)
            diagonal_matrix->data[r][r] = matrix->data[r][r];
        return diagonal_matrix;
    }
    return new_matrix(0, 0);
}


double trace(Matrix matrix)
{
    if(matrix->rows == matrix->cols)
    {
        double sum = 0;
        for(int r = 0; r < matrix->rows; r++)
            sum += matrix->data[r][r];
        return sum;
    }
    return 0;
}


Matrix secondary_diagonal(Matrix matrix)
{
    if(matrix->rows == matrix->cols)
    {
        Matrix diagonal_matrix = new_matrix(1, matrix->cols);
        for(int r = 0; r < matrix->rows; r++)
            diagonal_matrix->data[0][r] = matrix->data[r][matrix->cols-r-1];
        return diagonal_matrix;
    }
    return new_matrix(0, 0);
}


Matrix secondary_diagonal_matrix(Matrix matrix)
{
    if(matrix->rows == matrix->cols)
    {
        Matrix diagonal_matrix = new_matrix(matrix->rows, matrix->cols);
        for(int r = 0; r < matrix->rows; r++)
            diagonal_matrix->data[r][matrix->cols-r-1] = matrix->data[r][matrix->cols-r-1];
        return diagonal_matrix;
    }
    return new_matrix(0, 0);
}


double secondary_trace(Matrix matrix)
{
    if(matrix->rows == matrix->cols)
    {
        double sum = 0;
        for(int r = 0; r < matrix->rows; r++)
            sum += matrix->data[r][matrix->cols-r-1];
        return sum;
    }
    return 0;
}


Matrix add_matrix(Matrix matrix_1, Matrix matrix_2)
{
    if(are_perfect(matrix_1, matrix_2, ADDITION))
    {
        Matrix result = new_matrix(matrix_1->rows, matrix_1->cols);
        for(int r = 0; r < matrix_1->rows; r++)
        {
            for(int c = 0; c < matrix_1->cols; c++)
                result->data[r][c] = matrix_1->data[r][c] + matrix_2->data[r][c];
        }
        return result;
    }
    return new_matrix(0, 0);
}


Matrix add_row_matrix(Matrix base_matrix, Matrix row_matrix)
{
    if(base_matrix->cols == row_matrix->cols)
    {
        Matrix result = new_matrix(base_matrix->rows, base_matrix->cols);
        for(int r = 0; r < base_matrix->rows; r++)
        {
            for(int c = 0; c < base_matrix->cols; c++)
                result->data[r][c] = base_matrix->data[r][c] + row_matrix->data[0][c];
        }
        return result;
    }
    return new_matrix(0, 0);
}


Matrix add_column_matrix(Matrix base_matrix, Matrix column_matrix)
{
    if(base_matrix->rows == column_matrix->rows)
    {
        Matrix result = new_matrix(base_matrix->rows, base_matrix->cols);
        for(int r = 0; r < base_matrix->rows; r++)
        {
            for(int c = 0; c < base_matrix->cols; c++)
                result->data[r][c] = base_matrix->data[r][c] + column_matrix->data[r][0];
        }
        return result;
    }
    return new_matrix(0, 0);
}


Matrix subtract_matrix(Matrix matrix_1, Matrix matrix_2)
{
    if(are_perfect(matrix_1, matrix_2, SUBTRACTION))
    {
        Matrix result = new_matrix(matrix_1->rows, matrix_1->cols);
        for(int r = 0; r < matrix_1->rows; r++)
        {
            for(int c = 0; c < matrix_1->cols; c++)
                result->data[r][c] = matrix_1->data[r][c] - matrix_2->data[r][c];
        }
        return result;
    }
    return new_matrix(0, 0);
}


Matrix subtract_row_matrix(Matrix base_matrix, Matrix row_matrix)
{
    if(base_matrix->cols == row_matrix->cols)
    {
        Matrix result = new_matrix(base_matrix->rows, base_matrix->cols);
        for(int r = 0; r < base_matrix->rows; r++)
        {
            for(int c = 0; c < base_matrix->cols; c++)
                result->data[r][c] = base_matrix->data[r][c] - row_matrix->data[0][c];
        }
        return result;
    }
    return new_matrix(0, 0);
}


Matrix subtract_column_matrix(Matrix base_matrix, Matrix column_matrix)
{
    if(base_matrix->rows == column_matrix->rows)
    {
        Matrix result = new_matrix(base_matrix->rows, base_matrix->cols);
        for(int r = 0; r < base_matrix->rows; r++)
        {
            for(int c = 0; c < base_matrix->cols; c++)
                result->data[r][c] = base_matrix->data[r][c] - column_matrix->data[r][0];
        }
        return result;
    }
    return new_matrix(0, 0);
}


Matrix translate_row_vector_matrix(Matrix matrix, Point changed_point_of_origin)
{
    if(matrix->rows > 0 && matrix->cols == 3)
    {
        Matrix row_matrix = to_row_matrix(to_vector(changed_point_of_origin));
        return subtract_row_matrix(matrix, row_matrix);
    }
}


Matrix translate_column_vector_matrix(Matrix matrix, Point changed_point_of_origin)
{
    if(matrix->rows == 3 && matrix->cols > 3)
    {
        Matrix col_matrix = to_column_matrix(to_vector(changed_point_of_origin));
        return subtract_column_matrix(matrix, col_matrix);
    }
}


Matrix scale_matrix(Matrix matrix, double scalar_number)
{
    Matrix scaled_matrix = new_matrix(matrix->rows, matrix->cols);
    for(int r = 0; r < matrix->rows; r++)
    {
        for(int c = 0; c < matrix->cols; c++)
            scaled_matrix->data[r][c] = scalar_number * matrix->data[r][c];
    }
    return scaled_matrix;
}


Matrix multiply(Matrix matrix_1, Matrix matrix_2)
{
    if(are_perfect(matrix_1, matrix_2, MULTIPLICATION))
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


Matrix power(Matrix matrix, int n)
{
    if(matrix->rows == matrix->cols)
    {
        if(n == 0) return new_identity_matrix(matrix->rows);
        else if(n == 1) return matrix;
        else if(n > 1)
        {
            Matrix m = new_matrix(matrix->rows, matrix->cols);
            m = matrix;
            for(int p = 1; p < n; p++)
            {
                m = multiply(m, matrix);
            }
            return m;
        }
        else return matrix;
    }
    return matrix;
}


Matrix minor_matrix(Matrix matrix, int index_row, int index_col) 
{ 
    if(is_square_matrix(matrix))
    {
        Matrix minor = new_matrix(matrix->rows-1, matrix->cols-1);
        int r = 0, c = 0;
        for(int row = 0; row < matrix->rows; row++) 
        { 
            if(row != index_row)
            {
                for(int col = 0; col < matrix->rows; col++) 
                { 
                    if(col != index_col) 
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
    if(is_square_matrix(matrix))
    {
        if(matrix->rows == 1 && matrix->cols == 1) return matrix->data[0][0];
        Matrix temp_minor_matrix = new_matrix(matrix->rows-1, matrix->cols-1);
        int sign = 1, det = 0;
        for(int c = 0; c < matrix->rows; c++)
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
    if(is_square_matrix(matrix))
        return determinant(minor_matrix(matrix, index_row, index_col));
    return 0;
}


double co_factor(Matrix matrix, int index_row, int index_col)
{
    if(is_square_matrix(matrix))
    {
        int sign = (index_row+index_col)%2 == 0 ? 1 : -1;
        return (double)sign*determinant(minor_matrix(matrix, index_row, index_col));
    }
    return 0;
}


Matrix adjoint(Matrix matrix)
{
    if(is_square_matrix(matrix))
    {
        Matrix adjoint_matrix = new_matrix(matrix->rows, matrix->cols);
        for(int r=0; r<matrix->cols; r++)
        {
            for(int c=0; c<matrix->rows; c++)
                adjoint_matrix->data[r][c] = co_factor(matrix, r, c);
        }
        return transpose(adjoint_matrix);
    }
    return new_matrix(0, 0);
}


Matrix inverse(Matrix matrix)
{
    if(is_square_matrix(matrix))
        return scale_matrix(adjoint(matrix), 1/determinant(matrix));
    return new_matrix(0, 0);
}


Vector add_vector(Vector vector_1, Vector vector_2)
{
    return new_vector((vector_1->X + vector_2->X), (vector_1->Y + vector_2->Y), (vector_1->Z + vector_2->Z));
}


Vector subtract_vector(Vector vector_1, Vector vector_2)
{
    return new_vector((vector_1->X - vector_2->X), (vector_1->Y - vector_2->Y), (vector_1->Z - vector_2->Z));
}


Vector scale_vector(Vector vector, double scalar_number)
{
    return new_vector((scalar_number * vector->X), (scalar_number * vector->Y), (scalar_number * vector->Z));
}


double dot(Vector vector_1, Vector vector_2)
{
    return ((vector_1->X * vector_2->X) + (vector_1->Y * vector_2->Y) + (vector_1->Z * vector_2->Z));
}


Vector cross(Vector vector_1, Vector vector_2)
{
    Vector vector = new_vector(0, 0, 0);
    vector->X = (vector_1->Y * vector_2->Z) - (vector_1->Z * vector_2->Y);
    vector->Y = (vector_1->Z * vector_2->X) - (vector_1->X * vector_2->Z);
    vector->Z = (vector_1->X * vector_2->Y) - (vector_1->Y * vector_2->X);
    return vector;
}


double value_of_vector(Vector vector)
{
    return sqrt(vector->X*vector->X + vector->Y*vector->Y + vector->Z*vector->Z);
}


Vector unit_vector(Vector vector)
{
    return scale_vector(vector, 1/value_of_vector(vector));
}


double angle_between_vectors(Vector vector_1, Vector vector_2, int OUTPUT_ANGLE)
{
    double angle = acos(dot(vector_1, vector_2) / (value_of_vector(vector_1) * value_of_vector(vector_2)));
    return (OUTPUT_ANGLE == RAD) ? angle : degree(angle);
}


Matrix rotation_matrix_in_2D_space(double angle, int ANGLE)
{
    if(ANGLE == DEG) angle = radian(angle);
    Matrix r_matrix = new_matrix(2, 2);
    r_matrix->data[0][0] = cos(angle);
    r_matrix->data[1][0] = sin(angle);
    r_matrix->data[0][1] = -sin(angle);
    r_matrix->data[1][1] = cos(angle);
    return r_matrix;
}


Matrix rotation_matrix_in_3D_space(Vector rotation_axis_vector, float angle, int ANGLE)
{
    if(ANGLE == DEG) angle = radian(angle);
    angle = angle / 2;
    Vector v = unit_vector(rotation_axis_vector);
    double vr = cos(angle), vi = (sin(angle)*v->X), vj = (sin(angle)*v->Y), vk = (sin(angle)*v->Z);
    Matrix r_matrix = new_matrix(3, 3);
    r_matrix->data[0][0] = 1 - (2 * (vj*vj + vk*vk));
    r_matrix->data[1][0] = 2 * (vi*vj + vk*vr);
    r_matrix->data[2][0] = 2 * (vi*vk - vj*vr);
    r_matrix->data[0][1] = 2 * (vi*vj - vk*vr);
    r_matrix->data[1][1] = 1 - (2 * (vi*vi + vk*vk));
    r_matrix->data[2][1] = 2 * (vj*vk + vi*vr);
    r_matrix->data[0][2] = 2 * (vi*vk + vj*vr);
    r_matrix->data[1][2] = 2 * (vj*vk - vi*vr);
    r_matrix->data[2][2] = 1 - (2 * (vi*vi + vj*vj));
    return r_matrix;
}


Point rotate_point_in_2D_space(Point point, double angle, int ANGLE)
{
    return to_point(vectorize(multiply(rotation_matrix_in_2D_space(angle, ANGLE), pop_row_matrix(to_column_matrix(to_vector(point))))));
}


Point rotate_point_in_3D_space(Point point, Vector rotation_axis_vector, double angle, int ANGLE)
{
    return to_point(vectorize(multiply(rotation_matrix_in_3D_space(rotation_axis_vector, angle, ANGLE), to_column_matrix(to_vector(point)))));
}


Vector rotate_vector_in_2D_space(Vector vector, double angle, int ANGLE)
{
    return vectorize(multiply(rotation_matrix_in_2D_space(angle, ANGLE), pop_row_matrix(to_column_matrix(vector))));
}


Vector rotate_vector_in_3D_space(Vector vector, Vector rotation_axis_vector, double angle, int ANGLE)
{
    return vectorize(multiply(rotation_matrix_in_3D_space(rotation_axis_vector, angle, ANGLE), to_column_matrix(vector)));
}


Matrix rotate_matrix_in_2D_space(Matrix matrix, double angle, int ANGLE)
{
    if(matrix->rows == 2 && matrix->cols > 0) return multiply(rotation_matrix_in_2D_space(angle, ANGLE), matrix);
    else if(matrix->rows > 0 && matrix->cols == 2) return multiply(rotation_matrix_in_2D_space(angle, ANGLE), transpose(matrix));
    else return matrix;
}


Matrix rotate_matrix_in_3D_space(Matrix matrix, Vector rotation_axis_vector, double angle, int ANGLE)
{
    if(matrix->rows == 2 && matrix->cols > 0) return multiply(rotation_matrix_in_3D_space(rotation_axis_vector, angle, ANGLE), matrix);
    else if(matrix->rows > 0 && matrix->cols == 2) return multiply(rotation_matrix_in_3D_space(rotation_axis_vector, angle, ANGLE), transpose(matrix));
    else return matrix;
}


Matrix solve(Matrix coefficients_square_matrix, Matrix constants_column_matrix)
{
    Matrix result_column_matrix = new_matrix(coefficients_square_matrix->cols, 1);
    if(is_square_matrix(coefficients_square_matrix) && constants_column_matrix->rows == coefficients_square_matrix->cols && constants_column_matrix->cols == 1)
    {
        double scaling_factor = 1/determinant(coefficients_square_matrix);
        for(int i = 0; i < coefficients_square_matrix->cols; i++)
            result_column_matrix->data[i][0] = scaling_factor*determinant(replace_column_matrix(coefficients_square_matrix, i, constants_column_matrix));
    }
    return result_column_matrix;
}


bool is_type_of(Matrix matrix, int TYPE)
{
    if(TYPE == ROW_MATRIX)
    {
        if(matrix->rows == 1 && matrix->cols > 1) return true;
        return false;
    }

    else if(TYPE == COLUMN_MATRIX)
    {
        if(matrix->rows > 1 && matrix->cols == 1) return true;
        return false;
    }

    else if(TYPE == SQUARE_MATRIX)
    {
        if(matrix->rows == matrix->cols) return true;
        return false;
    }

    else if(TYPE == DIAGONAL_MATRIX)
    {
        if(matrix->rows == matrix->cols)
        {
            int n = matrix->rows, count_zeros = 0, count_non_zeros = 0;
            for(int r = 0; r < n; r++)
            {
                for(int c = 0; c < n; c++)
                {
                    if(c != r && matrix->data[r][c] == 0) count_zeros++;
                    if(c == r && matrix->data[r][c] != 0) count_non_zeros++;
                }
            }
            if(count_non_zeros == n && count_zeros == n*(n-1)) return true;
            return false;
        }
        return false;
    }

    else if(TYPE == SCALAR_MATRIX)
    {
        if(matrix->rows == matrix->cols)
        {
            int n = matrix->rows, constant = matrix->data[0][0], count_zeros = 0, count_consts = 0;
            for(int r = 0; r < n; r++)
            {
                for(int c = 0; c < n; c++)
                {
                    if(c != r && matrix->data[r][c] == 0) count_zeros++;
                    if(c == r && matrix->data[r][c] == constant) count_consts++;
                }
            }
            if(count_consts == n && count_zeros == n*(n-1)) return true;
            return false;
        }
        return false;
    }

    else if(TYPE == IDENTITY_MATRIX || TYPE == UNIT_MATRIX)
    {
        if(matrix->rows == matrix->cols)
        {
            int n = matrix->rows, count_zeros = 0, count_unit = 0;
            for(int r = 0; r < n; r++)
            {
                for(int c = 0; c < n; c++)
                {
                    if(c != r && matrix->data[r][c] == 0) count_zeros++;
                    if(c == r && matrix->data[r][c] == 1) count_unit++;
                }
            }
            if(count_unit == n && count_zeros == n*(n-1)) return true;
            return false;
        }
        return false;
    }

    else if(TYPE == NULL_MATRIX || TYPE == ZERO_MATRIX)
    {
        if(matrix->rows == matrix->cols)
        {
            int n = matrix->rows, count_zeros = 0;
            for(int r = 0; r < n; r++)
            {
                for(int c = 0; c < n; c++)
                {
                    if(matrix->data[r][c] == 0) count_zeros++;
                }
            }
            if(count_zeros == n*n) return true;
            return false;
        }
        return false;
    }

    else if(TYPE == UPPER_TRIANGULAR_MATRIX)
    {
        if(matrix->rows == matrix->cols)
        {
            int n = matrix->rows, m = (n*(n-1))/2, count_zeros = 0;
            for(int r = 0; r < n; r++)
            {
                for(int c = 0; c < n; c++)
                {
                    if(c < r && matrix->data[r][c] == 0) count_zeros++;
                }
            }
            if(count_zeros == m) return true;
            return false;
        }
        return false;
    }

    else if(TYPE == LOWER_TRIANGULAR_MATRIX)
    {
        if(matrix->rows == matrix->cols)
        {
            int n = matrix->rows, m = (n*(n-1))/2, count_zeros = 0;
            for(int r = 0; r < n; r++)
            {
                for(int c = 0; c < n; c++)
                {
                    if(c > r && matrix->data[r][c] == 0) count_zeros++;
                }
            }
            if(count_zeros == m) return true;
            return false;
        }
        return false;
    }

    else if(TYPE == TRIANGULAR_MATRIX)
    {
        if(is_type_of(matrix, UPPER_TRIANGULAR_MATRIX) || is_type_of(matrix, LOWER_TRIANGULAR_MATRIX)) return true;
        return false;
    }

    else if(TYPE == INVOLUTORY_MATRIX)
    {
        if(matrix->rows == matrix->cols)
        {
            return is_type_of(multiply(matrix, matrix), IDENTITY_MATRIX);
        }
        return false;
    }

    else if(TYPE == IDEMPOTENT_MATRIX)
    {
        if(matrix->rows == matrix->cols)
        {
            return are_identical(matrix, multiply(matrix, matrix));
        }
        return false;
    }

    else if(TYPE == SYMMETRIC_MATRIX)
    {
        if(matrix->rows == matrix->cols)
        {
            return are_identical(matrix, transpose(matrix));
        }
        return false;
    }

    else if(TYPE == SKEW_SYMMETRIC_MATRIX)
    {
        if(matrix->rows == matrix->cols)
        {
            return are_identical(scale_matrix(matrix, -1), transpose(matrix));
        }
        return false;
    }

    else if(TYPE == NILPOTENT_MATRIX) // It is seriously very complicated to check...
    {
        if(matrix->rows == matrix->cols)
        {
            if(is_type_of(matrix, NULL_MATRIX)) return true;
            int trial = 0;
            Matrix temp_matrix = new_matrix(matrix->rows, matrix->cols);
            temp_matrix = matrix;
            while(trial != 100)
            {
                temp_matrix = multiply(temp_matrix, matrix);
                if(is_type_of(temp_matrix, NULL_MATRIX)) return true;
                trial++;
            }
            return false;
        }
        return false;
    }

    else return false;
}


char **types(Matrix matrix, int TEXT_STYLE)
{
    char **list_of_types = (char **)malloc(375*sizeof(char) + 15*sizeof(char *));
    int count = 0;

    if(is_type_of(matrix, ROW_MATRIX))
    {
        if(TEXT_STYLE == UPPER) list_of_types[count] = "ROW-MATRIX";
        else if(TEXT_STYLE == LOWER) list_of_types[count] = "row-matrix";
        else list_of_types[count] = "Row-Matrix";
        return list_of_types;
    }

    if(is_type_of(matrix, COLUMN_MATRIX))
    {
        if(TEXT_STYLE == UPPER) list_of_types[count] = "COLUMN-MATRIX";
        else if(TEXT_STYLE == LOWER) list_of_types[count] = "column-matrix";
        else list_of_types[count] = "Column-Matrix";
        return list_of_types;
    }

    if(is_type_of(matrix, SQUARE_MATRIX))
    {
        if(TEXT_STYLE == UPPER) list_of_types[count] = "SQUARE-MATRIX";
        else if(TEXT_STYLE == LOWER) list_of_types[count] = "square-matrix";
        else list_of_types[count] = "Square-Matrix";
        count++;
    }

    if(is_type_of(matrix, DIAGONAL_MATRIX))
    {
        if(TEXT_STYLE == UPPER) list_of_types[count] = "DIAGONAL-MATRIX";
        else if(TEXT_STYLE == LOWER) list_of_types[count] = "diagonal-matrix";
        else list_of_types[count] = "Diagonal-Matrix";
        count++;
    }

    if(is_type_of(matrix, SCALAR_MATRIX))
    {
        if(TEXT_STYLE == UPPER) list_of_types[count] = "SCALAR-MATRIX";
        else if(TEXT_STYLE == LOWER) list_of_types[count] = "scalar-matrix";
        else list_of_types[count] = "Scalar-Matrix";
        count++;
    }

    if(is_type_of(matrix, IDENTITY_MATRIX))
    {
        if(TEXT_STYLE == UPPER) list_of_types[count] = "IDENTITY-MATRIX / UNIT-MATRIX";
        else if(TEXT_STYLE == LOWER) list_of_types[count] = "identity-matrix / unit-matrix";
        else list_of_types[count] = "Identity-Matrix / Unit-Matrix";
        count++;
    }

    if(is_type_of(matrix, NULL_MATRIX))
    {
        if(TEXT_STYLE == UPPER) list_of_types[count] = "NULL-MATRIX / ZERO-MATRIX";
        else if(TEXT_STYLE == LOWER) list_of_types[count] = "null-matrix / zero-matrix";
        else list_of_types[count] = "Null-Matrix / Zero-Matrix";
        count++;
    }

    if(is_type_of(matrix, TRIANGULAR_MATRIX))
    {
        if(TEXT_STYLE == UPPER) list_of_types[count] = "TRIANGULAR-MATRIX";
        else if(TEXT_STYLE == LOWER) list_of_types[count] = "triangular-matrix";
        else list_of_types[count] = "Triangular-Matrix";
        count++;
    }

    if(is_type_of(matrix, UPPER_TRIANGULAR_MATRIX))
    {
        if(TEXT_STYLE == UPPER) list_of_types[count] = "UPPER-TRIANGULAR-MATRIX";
        else if(TEXT_STYLE == LOWER) list_of_types[count] = "upper-triangular-matrix";
        else list_of_types[count] = "Upper-Triangular-Matrix";
        count++;
    }

    if(is_type_of(matrix, LOWER_TRIANGULAR_MATRIX))
    {
        if(TEXT_STYLE == UPPER) list_of_types[count] = "LOWER-TRIANGULAR-MATRIX";
        else if(TEXT_STYLE == LOWER) list_of_types[count] = "lower-triangular-matrix";
        else list_of_types[count] = "Lower-Triangular-Matrix";
        count++;
    }

    if(is_type_of(matrix, INVOLUTORY_MATRIX))
    {
        if(TEXT_STYLE == UPPER) list_of_types[count] = "INVOLUTORY-MATRIX";
        else if(TEXT_STYLE == LOWER) list_of_types[count] = "involutory-matrix";
        else list_of_types[count] = "Involutory-Matrix";
        count++;
    }

    if(is_type_of(matrix, IDEMPOTENT_MATRIX))
    {
        if(TEXT_STYLE == UPPER) list_of_types[count] = "IDEMPOTENT-MATRIX";
        else if(TEXT_STYLE == LOWER) list_of_types[count] = "idempotent-matrix";
        else list_of_types[count] = "Idempotent-Matrix";
        count++;
    }

    if(is_type_of(matrix, SYMMETRIC_MATRIX))
    {
        if(TEXT_STYLE == UPPER) list_of_types[count] = "SYMMETRIC-MATRIX";
        else if(TEXT_STYLE == LOWER) list_of_types[count] = "symmetric-matrix";
        else list_of_types[count] = "Symmetric-Matrix";
        count++;
    }

    if(is_type_of(matrix, SKEW_SYMMETRIC_MATRIX))
    {
        if(TEXT_STYLE == UPPER) list_of_types[count] = "SKEW-SYMMETRIC-MATRIX";
        else if(TEXT_STYLE == LOWER) list_of_types[count] = "skew-symmetric-matrix";
        else list_of_types[count] = "Skew-Symmetric-Matrix";
        count++;
    }

    if(is_type_of(matrix, NILPOTENT_MATRIX))
    {
        if(TEXT_STYLE == UPPER) list_of_types[count] = "NILPOTENT-MATRIX";
        else if(TEXT_STYLE == LOWER) list_of_types[count] = "nilpotent-matrix";
        else list_of_types[count] = "Nilpotent-Matrix";
    }

    return list_of_types;
}
