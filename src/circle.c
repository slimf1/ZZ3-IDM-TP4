#include <stdio.h>
#include "circle.h"

// Méta objet unique pour la classe des cercles
meta_circle_t _META_CIRCLE;

/**
 * Accesseur pour le rayon (get)
 * @param self Pointeur de l'objet courant
 * @return Le rayon du cercle
 */
int get_radius(circle_t* self) {
    return self->_radius;
}

/**
 * Accesseur pour le rayon
 * @param self Pointeur de l'objet courant
 * @param radius Nouvelle valeur du rayon
 */
void set_radius(circle_t* self, int radius) {
    self->_radius = radius;
}

/**
 * Affiche un cercle dans un flux
 * @param self Pointeur de l'objet courant
 * @param stream Flux dans lequel écrire
 */
void display_circle(graphical_object_t* self, FILE* stream) {
    circle_t* self_circle = (circle_t*)self;
    fprintf(stream, "<Circle r=%d>\n", self_circle->_radius);
}

/**
 * Initialisation de l'unique méta-objet graphique
 */
void construct_meta_circle() {
    _META_CIRCLE.get_radius = &get_radius;
    _META_CIRCLE.set_radius = &set_radius;
    _META_CIRCLE.constructor = &circle_constructor;
    _META_CIRCLE.super_meta_class = &_META_GRAPHICAL_OBJECT;
    _META_CIRCLE.super_meta_class->VTABLE_display[CIRCLE] = &display_circle;
}

/**
 * Initialise un nouveau cercle
 * @param self Pointeur de l'objet courant
 */
void circle_constructor(circle_t* self) {
    if (_META_GRAPHICAL_OBJECT.constructor == NULL) {
        construct_meta_graphical_object();
    }
    _META_GRAPHICAL_OBJECT.constructor(&self->super);
    if (_META_CIRCLE.constructor == NULL) {
        construct_meta_circle();
    }
    self->_radius = 0;
    self->my_class = &_META_CIRCLE;
    self->super.type = CIRCLE;
}
