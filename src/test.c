#ifdef TESTING
#include <stdio.h>
#include <math.h>
#include "main2.h"
#include "pointer_with_backlash.h"

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
    pointer_s pointer_x = {};
    pointer_with_backlash_s backlash_pointer_x = {};
    int ret = 0;
    
    range_init(&range_x, -100, 100);
    pointer_init(&pointer_x, &range_x);
    pointer_with_backlash_init(&backlash_pointer_x, &pointer_x, 10);

    int x = 0;
    for (float i = 0; i < 20; i++){
        x = i;
        // ret = move_to(&pointer_x2, x);
        ret = move_to_counteract_backlash(&backlash_pointer_x, x);
        if (ret){ printf("blad\n"); return ret; }
        print_pointer_with_backlash_pos(&backlash_pointer_x);
        // printf("backlash: <%d>\n", backlash_pointer_x.backlash);
    }
    for (float i = 0; i < 20; i++){
        x = 20 - i;
        // ret = move_to(&pointer_x2, x);
        ret = move_to_counteract_backlash(&backlash_pointer_x, x);
        if (ret){ printf("blad\n"); return ret; }
        print_pointer_with_backlash_pos(&backlash_pointer_x);
        // printf("backlash: <%d>\n", backlash_pointer_x.backlash);
    }

    return 0;
}
#endif