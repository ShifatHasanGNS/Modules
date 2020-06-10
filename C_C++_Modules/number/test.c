#include "number.h"

int main(int argc, char const *argv[])
{
    /* code */
    Vector v1 = new_vector(2, 3, 5);
    Vector v2 = new_vector(2, 5, 1);
    printf("\nValue of v1 = %lf\nValue of v2 = %lf\nangle between v1 and v2 = %lf\n\n", value_of_vector(v1), value_of_vector(v2), angle_between_vectors(v1, v2, DEG));
    return 0;
}