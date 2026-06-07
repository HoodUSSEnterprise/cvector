#ifndef OPERATOR_SET_H
#define OPERATOR_SET_H

#include "set/base_set.h"
#include <stdbool.h>

int set_size(Set *set);
bool set_is_empty(Set *set);
int set_min(Set *set);
int set_max(Set *set);
void set_print(Set *set);

#endif
