#ifndef CIRCLE_H
#define CIRCLE_H

#include "graphical_object.h"

/**
 * Cercle
 */
typedef struct circle {
    graphical_object_t super;
    struct meta_circle* my_class;
    int _radius;
} circle_t;

/**
 * Méta cercle
 */
typedef struct meta_circle {
    meta_graphical_object_t* super_meta_class;
    
    void (*set_radius)(circle_t* self, int radius);
    int (*get_radius)(circle_t* self);

    void (*constructor)(circle_t* self);
} meta_circle_t;

extern meta_circle_t _META_CIRCLE; 

void construct_meta_circle();
void circle_constructor(circle_t* self);

#endif // CIRCLE_H
