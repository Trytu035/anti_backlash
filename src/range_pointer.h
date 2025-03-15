#ifndef MAIN2
#define MAIN2

typedef struct{
    int min;
    int max;
} range_s;

typedef struct{
    int value;
    range_s *range;
} pointer_s;

void range_init(range_s *self, int min, int max);
int move_by(pointer_s *self, int x);
int move_to(pointer_s *self, int x);
void pointer_init(pointer_s *self, range_s *range);
int pointer_get_value(pointer_s *self);

#endif