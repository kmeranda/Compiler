#ifndef SCOPE_H
#define SCOPE_H

#include <stdio.h>
#include <stdlib.h>
#include "hash_table.h"
#include "symbol.h"

struct hash_table * h;
void scope_enter();
void scope_exit();
int scope_level();
void scope_bind(char * name, struct symbol * sym);
struct symbol * scope_lookup(const char * name);
struct symbol * scope_lookup_single(const char * name);
int scope_increment_local();

#endif
