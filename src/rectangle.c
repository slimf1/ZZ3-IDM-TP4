#include <stdio.h>
#include "rectangle.h"

//  Méta objet unique pour la classe des rectangles
meta_rectangle_t _META_RECTANGLE;

/**
 * Accesseur de la largeur (get)
 * @param self Pointeur de l'objet courant
 * @return La largeur d'un rectangle
 */
int get_width(rectangle_t* self) {
    return self->_width;
}

/**
 * Accesseur de la hauteur (get)
 * @param self Pointeur de l'objet courant
 * @return La largeur de la hauteur
 */
int get_height(rectangle_t* self) {
    return self->_height;
}

/**
 * Accesseur de la largeur (set)
 * @param self Pointeur de l'objet courant
 * @param width La nouvelle valeur de la largeur
 */
void set_width(rectangle_t* self, int width) {
  self->_width = width;
}

/**
 * Accesseur de la hauteur (set)
 * @param self Pointeur de l'objet courant
 * @param height La nouvelle valeur de la hauteur
 */
void set_height(rectangle_t* self, int height) {
  self->_height = height;
}

/**
 * Affiche un rectangle dans un flux
 * @param self Pointeur de l'objet courant
 * @param stream Flux dans lequel écrire
 */
void display_rectangle(graphical_object_t* self, FILE* stream) {
    rectangle_t* self_rectangle = (rectangle_t*)self;
    fprintf(stream, "<Rectangle w=%d h=%d>\n", self_rectangle->_width,
                                               self_rectangle->_height);
}

/**
 * Initialisation de l'unique méta-objet des rectangles
 */
void construct_meta_rectangle() {
    _META_RECTANGLE.get_height = &get_height;
    _META_RECTANGLE.set_height = &set_height;
    _META_RECTANGLE.get_width = &get_width;
    _META_RECTANGLE.set_width = &set_width;
    _META_RECTANGLE.constructor = &rectangle_constructor;
    _META_RECTANGLE.super_meta_class = &_META_GRAPHICAL_OBJECT;
    _META_RECTANGLE.super_meta_class->VTABLE_display[RECTANGLE] = &display_rectangle;
}

/**
 * Initialise un nouveau rectangle
 * @param self Pointeur vers l'objet courant
 */
void rectangle_constructor(rectangle_t* self) {
    if (_META_GRAPHICAL_OBJECT.constructor == NULL) {
        construct_meta_graphical_object();
    }
    _META_GRAPHICAL_OBJECT.constructor(&self->super);
    if (_META_RECTANGLE.constructor == NULL) {
        construct_meta_rectangle();
    }
    self->_height = 0;
    self->_width = 0;
    self->my_class = &_META_RECTANGLE;
    self->super.type = RECTANGLE;
}
