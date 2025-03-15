#include "range_pointer.h"

void range_init(range_s *self, int min, int max){
    self->min = min;
    self->max = max;
}

void pointer_init(pointer_s *self, range_s *range){
    self->value = 0;
    self->range = range;
}

int move_by(pointer_s *self, int value){
    int new_val = self->value + value;

    if (new_val > self->range->min && new_val < self->range->max){
        self->value = new_val;
        return 0;
    }

    return -1;
}

int move_to(pointer_s *self, int value){
    if (value > self->range->min && value < self->range->max){
        self->value = value;
        return 0;
    }

    return -1;
}

int pointer_get_value(pointer_s *self){
    return self->value;
}