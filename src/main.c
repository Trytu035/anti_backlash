// #define TESTING
#ifdef TESTING
#include "test.c"
#endif
#ifndef TESTING
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "range_pointer.h"
#include "pointer_with_backlash.h"
#include "hilbert.h"

void print_pointer_pos(pointer_s *p){
    printf("pointer position is <%d>\n", pointer_get_value(p));
}
void print_pointer_in_grid_pos(pointer_s *p1, pointer_s *p2){
    printf("pointer (%d, %d)\n", pointer_get_value(p1), pointer_get_value(p2));
}

void print_pointer_with_backlash_pos(pointer_with_backlash_s *p){
    printf("pointer backlash position is <%d>\n", pointer_with_backlash_get_value(p));
}
void print_pointer_with_backlash_in_grid_pos(pointer_with_backlash_s *p1, pointer_with_backlash_s *p2){
    printf("pointer backlash (%d, %d)\n", pointer_with_backlash_get_value(p1), pointer_with_backlash_get_value(p2));
}

// int main(int argc, char **args){
int main(void){
    range_s range_x = {};
    range_s range_y = {};
    pointer_s pointer_x = {};
    pointer_s pointer_y = {};
    pointer_s pointer_x2 = {};
    pointer_s pointer_y2 = {};
    pointer_with_backlash_s backlash_pointer_x = {};
    pointer_with_backlash_s backlash_pointer_y = {};
    int ret = 0;
    
    range_init(&range_x, -100, 100);
    range_init(&range_y, -100, 100);
    pointer_init(&pointer_x, &range_x);
    pointer_init(&pointer_y, &range_y);
    pointer_init(&pointer_x2, &range_x);
    pointer_init(&pointer_y2, &range_y);
    pointer_with_backlash_init(&backlash_pointer_x, &pointer_x, 0);
    pointer_with_backlash_init(&backlash_pointer_y, &pointer_y, 10);

    print_pointer_pos(&pointer_x);
    
    //spirala archimedesa
    printf("spirala archimedesa\n");
    int x = 0;
    int y = 0;
    for (float i = 0; i < 40; i++){
        x = i * cos(i/3);
        y = i * sin(i/3);
        ret = move_to(&pointer_x2, x);
        ret = move_to_counteract_backlash(&backlash_pointer_x, x);
        if (ret){ printf("blad\n"); return ret; }
        ret = move_to(&pointer_y2, y);
        ret = move_to_counteract_backlash(&backlash_pointer_y, y);
        if (ret){ printf("blad\n"); return ret; }
        print_pointer_in_grid_pos(&pointer_x2, &pointer_y2);
        print_pointer_with_backlash_in_grid_pos(&backlash_pointer_x, &backlash_pointer_y);
        // printf("backlash: (%d, %d)\n", backlash_pointer_x.backlash, backlash_pointer_y.backlash);
    }

    x = 0;
    y = 0;
    printf("krzywa hilberta\n");
    int n = 3;
    int number_of_element = pow(2, n*2);
    int sideLength = pow(2, n);
    int *ret_array = calloc(number_of_element*2, sizeof(int));
    int hilbert_iterator = 0;
    // (x1, xj) oraz (yi, yj) to wektory jednostkowe przestrzeni na której się rozciąga ta krzywa.
    hilbertCurve(ret_array, number_of_element*2, &hilbert_iterator, n, -sideLength/2, -sideLength/2, 2, 0, 0, 2);

    // move_to(&pointer_x2, 0);
    // move_to(&pointer_y2, 0);
    move_to_counteract_backlash(&backlash_pointer_x, 0);
    move_to_counteract_backlash(&backlash_pointer_y, 0);
    for (int i = 0; i < number_of_element; i++){
        // move_to(&pointer_x2, ret_array[i*2]);
        // move_to(&pointer_y2, ret_array[i*2 + 1]);
        // print_pointer_in_grid_pos(&pointer_x2, &pointer_y2);
        move_to_counteract_backlash(&backlash_pointer_x, ret_array[i*2]);
        move_to_counteract_backlash(&backlash_pointer_y, ret_array[i*2 + 1]);
        print_pointer_with_backlash_in_grid_pos(&backlash_pointer_x, &backlash_pointer_y);
    }

    free(ret_array);
    return 0;
}

#endif