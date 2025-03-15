#include <math.h>
#include <assert.h>

void hilbertCurve(int *ret, int ret_size, int *ret_i, int n, int x, int y, int xi, int xj, int yi, int yj)   
{  
    assert(ret_size >= pow(2, n * 2) * 2);   //assert that ret_size can fit all element
    if (n <= 0)  
    {
        ret[*ret_i * 2] = x;
        ret[*ret_i * 2 + 1] = y;
        (*ret_i)++;

        return;  
    }  
hilbertCurve(ret, ret_size, ret_i, n - 1, x + xi * pow(2, n - 1), y + yi * pow(2, n - 1), xi, xj, yi, yj);  
hilbertCurve(ret, ret_size, ret_i, n - 1, x + xj * pow(2, n - 1), y + yj * pow(2, n - 1), xi, xj, yi, yj);  
hilbertCurve(ret, ret_size, ret_i, n - 1, x + xj * pow(2, n - 1) + xi, y + yj * pow(2, n - 1) + yi, xi, xj, yi, yj);  
hilbertCurve(ret, ret_size, ret_i, n - 1, x + xi * pow(2, n - 1) - xj, y + yi * pow(2, n - 1) - yj, -xi, -xj, -yi, -yj);  
}  

// int main()  
// {  
//     int n = 3; // Order of the curve  
// // printf("Enter the order of Hilbert Curve: ");  
// // scanf("%d", &n);  
//     int numPoints = pow(2, n * 2);
//     // int *ret_arr = malloc(numPoints * 2 * sizeof(int)); //num of entries times vector(2) of int
//     int *ret_arr = calloc(numPoints * 2, sizeof(int)); //num of entries times vector(2) of int
//     // int sideLength = pow(2, n);  
//     int i = 0;
//     printf("Points on the Hilbert Curve:\n");  
//     hilbertCurve(ret_arr, numPoints * 2, &i, n, 0, 0, 1, 0, 0, 1);  
//     printf("ret_arr[%d]\n", i);
//     printf("numPoints %d\n", numPoints * 2);

//     for (int i = 0; i < 10; i++) {
//         printf("(%d, %d)\n", ret_arr[i*2], ret_arr[i*2 + 1]);
//     }

//     free(ret_arr);
//     return 0;  
// }  