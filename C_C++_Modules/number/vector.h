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
#include "parser.h"

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