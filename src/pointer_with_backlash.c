#include "range_pointer.h"
#include "pointer_with_backlash.h"

int clamp(int x, int min, int max){
    if (x < min){
        return min;
    } else if (x > max){
        return max;
    }else{
        return x;
    }
}

void pointer_with_backlash_init(pointer_with_backlash_s *self, pointer_s *pointer, int max_backlash){
    self->p = pointer;
    self->max_backlash = max_backlash;
    self->backlash = 0;
}


int move_by_with_backlash(pointer_with_backlash_s *self, int value){
    // TODO:
    // assert, that pointer is initialized (haven't done that yet)
    int ret = move_by(self->p, value);
    if (0 == ret){
        self->backlash = clamp(self->backlash + value, -self->max_backlash, self->max_backlash);
    }
    
    return ret;
}

int move_by_counteract_backlash(pointer_with_backlash_s *self, int value){
    if (value > 0){
        value += self->max_backlash - self->backlash;
    }else if (value < 0){
        value -= self->max_backlash + self->backlash;
    }
    
    return move_by_with_backlash(self, value);
}

int move_to_with_backlash(pointer_with_backlash_s *self, int value){
    // TODO:
    // assert, that pointer is initialized (haven't done that yet)
    int curr_val = self->p->value;
    int ret = move_to(self->p, value);

    if (0 == ret){
        self->backlash = clamp(self->backlash - curr_val + value, -self->max_backlash, self->max_backlash);
    }
    
    return ret;
}

int move_to_counteract_backlash(pointer_with_backlash_s *self, int value){
    int current_value = self->p->value - self->backlash;

    if (value - current_value > 0){
        value += self->max_backlash;
    }else if (value - current_value < 0){
        value -= self->max_backlash;
    }

    return move_to_with_backlash(self, value);
}

int pointer_with_backlash_get_value(pointer_with_backlash_s *self){
    return self->p->value - self->backlash;
}