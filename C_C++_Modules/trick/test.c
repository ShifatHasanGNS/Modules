#include "trick.h"
#include "stdlib.h"
#include "stdio.h"

start{
    String str = "Hello World\n\n";
    print("%s", str);

    if (1==1 and 2==2 or 3!=5)
        print("hahaha\n\n");

    For_(float, num, 2.16, 10.58, 2.1)
        print("%0.2f  ", num);
    
    int *arr = new1(int, 10);

    For(i, 0, 10, 1) arr[i] = i+2;

    print("\n\n");

    For(j, 0, 10, 1)
        print("%d  ", j);
    stop;
}