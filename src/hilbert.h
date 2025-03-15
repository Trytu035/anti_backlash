#ifndef HILBERT
#define HILBERT

// https://www.tpointtech.com/hilbert-curve-program-in-c
// n: The level of the current recursion.
// (x,y): The location on the plane at the moment.
// (xi, xj): Unit vectors for the positive and negative directions along the x-axis are (xi, xj).
// (yi, yj): Unit vectors for the positive and negative directions along the y-axis are (yi, yj).
void hilbertCurve(int *ret, int ret_size, int *ret_i, int n, int x, int y, int xi, int xj, int yi, int yj);

#endif
