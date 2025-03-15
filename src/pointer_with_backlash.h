#ifndef BACKLASHED_POINTER
#define BACKLASHED_POINTER

#include "range_pointer.h"

typedef struct {
    pointer_s *p;
    int max_backlash;
    int backlash;
} pointer_with_backlash_s;

void pointer_with_backlash_init(pointer_with_backlash_s *self, pointer_s *pointer, int max_backlash);
// int move_by_with_backlash(pointer_with_backlash_s *self, int value);
int move_by_counteract_backlash(pointer_with_backlash_s *self, int value);
// int move_to_with_backlash(pointer_with_backlash_s *self, int value);
int move_to_counteract_backlash(pointer_with_backlash_s *self, int value);
int pointer_with_backlash_get_value(pointer_with_backlash_s *self);

#endif