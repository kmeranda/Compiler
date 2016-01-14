#include "scope.h"
#include "symbol.h"

extern struct hash_table * h;

void scope_enter() {
	struct hash_table *h_prev;	// pointer to the end of the linked list to link new hash table
	h_prev = h;
	hash_table_insert(h, "0next", hash_table_create(0,0));
	h = hash_table_lookup(h, "0next");
	hash_table_insert(h, "0prev", h_prev);
	if (scope_level()==2) {
		int * p_count = malloc(sizeof *p_count);
		int * l_count = malloc(sizeof *l_count);
		*p_count = 0;
		*l_count = 0;
		hash_table_insert(h, "0p_count", p_count);
		hash_table_insert(h, "0l_count", l_count);
	}
}

void scope_exit() {
	h = hash_table_lookup(h, "0prev");
	//hash_table_clear(hash_table_lookup(h,"0next"));
	hash_table_delete(hash_table_lookup(h,"0next"));
	hash_table_remove(h,"0next");
}

int scope_level() {
	int num_levels = 0;
	struct hash_table * current_level = h;
	while (current_level) {
		current_level = hash_table_lookup(current_level, "0prev");
		num_levels++;
	}
	return num_levels;
}

void scope_bind(char * name, struct symbol * sym) {
	hash_table_insert(h, name, sym);
}

struct symbol * scope_lookup(const char * name) {
	struct hash_table * cursor = h;
	while (cursor) {
		if (hash_table_lookup(cursor, name)) { 
			return hash_table_lookup(cursor, name); 
		}
		cursor = hash_table_lookup(cursor, "0prev");
	}
	return NULL;
}

struct symbol * scope_lookup_single(const char * name) {
	return hash_table_lookup(h, name);
}

int scope_increment_local() {
	struct hash_table * current_level = h;
	while (!hash_table_lookup(current_level, "0l_count")) {
		current_level = hash_table_lookup(current_level, "0prev");
	}
	int * temp = hash_table_lookup(current_level, "0l_count");
	(* temp)++;
	return ((*temp)-1);
}
