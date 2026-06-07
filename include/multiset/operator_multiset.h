#ifndef OPERATOR_MULTISET_H
#define OPERATOR_MULTISET_H

#include "multiset/base_multiset.h"

int multiset_size(MultiSet *set);
int multiset_is_empty(MultiSet *set);
int multiset_min(MultiSet *set);
int multiset_max(MultiSet *set);

#endif
