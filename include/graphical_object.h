#ifndef GRAPHICAL_OBJECT_H
#define GRAPHICAL_OBJECT_H

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

#define NBCLASSES 2
typedef enum graphical_object_classes {
    CIRCLE = 0,
    RECTANGLE = 1,
    GRAPHICAL_OBJECT = 2
} graphical_object_classes_t;

/**
 * Objet graphique 
 */
typedef struct graphical_object {
    struct meta_graphical_object* my_class;
    int _x;
    int _y;
    graphical_object_classes_t type;
} graphical_object_t;

/**
 * Méta objet graphique 
 */
typedef struct meta_graphical_object {
    int (*get_x)(graphical_object_t* self);
    int (*get_y)(graphical_object_t* self);
    void (*set_x)(graphical_object_t* self, int x);
    void (*set_y)(graphical_object_t* self, int y);

    void (*VTABLE_display[NBCLASSES])(graphical_object_t* self, FILE* stream);
    // void (*VTABLE_move[NBCLASSES])(graphical_object_t* self);
    // void (*VTABLE_erase[NBCLASSES])(graphical_object_t* self);

    void (*display)(graphical_object_t* self, FILE* stream);
    // void (*move)(graphical_object_t* self);
    // void (*erase)(graphical_object_t* self);

    int _instance_count;
    int (*get_instance_count)(void);
    void (*constructor)(graphical_object_t* self);
} meta_graphical_object_t;

extern meta_graphical_object_t _META_GRAPHICAL_OBJECT; 

void construct_meta_graphical_object();
void graphical_object_constructor(graphical_object_t* self);

#endif // GRAPHICAL_OBJECT_H
