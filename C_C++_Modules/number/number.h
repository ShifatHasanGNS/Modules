/*
	Module :: [ matrix.h ]
*/

/*
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

// ---------------------------------------------------------------- //
//          I M P O R T A N T S    <----->    M A C R O S           //
// ---------------------------------------------------------------- //


/*
    #define OPERATION <int::VALUE>            
*/

#define ADDITION 0
#define SUBTRACTION 1
#define MULTIPLICATION 2
#define DETERMINANT 3
#define MINOR 4
#define COFACTOR 5
#define TRANSPOSE 6
#define ADJOINT 7
#define INVERSE 8

/*
    #define TYPE_OF_MATRIX <int::VALUE>
*/

#define ROW_MATRIX 9
#define COLUMN_MATRIX 10
#define SQUARE_MATRIX 11
#define DIAGONAL_MATRIX 12
#define SCALAR_MATRIX 13
#define IDENTITY_MATRIX 14
#define UNIT_MATRIX 14
#define NULL_MATRIX 15
#define ZERO_MATRIX 15
#define UPPER_TRIANGULAR_MATRIX 16
#define LOWER_TRIANGULAR_MATRIX 17
#define TRIANGULAR_MATRIX 18
#define INVOLUTORY_MATRIX 19
#define IDEMPOTENT_MATRIX 20
#define SYMMETRIC_MATRIX 21
#define SKEW_SYMMETRIC_MATRIX 22
#define NILPOTENT_MATRIX 23

/*
    #define TEXT_STYLE <int::VALUE>
*/

#define UPPER 24
#define LOWER 25
#define TITLE 26 