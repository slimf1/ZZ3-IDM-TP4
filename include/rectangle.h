#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "graphical_object.h"

/**
 * Rectangle
 */
typedef struct rectangle {
    graphical_object_t super;
    struct meta_rectangle* my_class;
    int _width;
    int _height;
} rectangle_t;

/**
 * Méta rectangle
 */
typedef struct meta_rectangle {
    meta_graphical_object_t* super_meta_class;
    
    void (*set_width)(rectangle_t* self, int width);
    int (*get_width)(rectangle_t* self);
    void (*set_height)(rectangle_t* self, int height);
    int (*get_height)(rectangle_t* self);

    void (*constructor)(rectangle_t* self);
} meta_rectangle_t;

extern meta_rectangle_t _META_RECTANGLE; 

void construct_meta_rectangle();
void rectangle_constructor(rectangle_t* self);

#endif // RECTANGLE_H
