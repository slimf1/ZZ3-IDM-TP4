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
 * Initialisation de l'unique méta-objet graphique
 */
void construct_meta_circle() {
    _META_CIRCLE.get_radius = &get_radius;
    _META_CIRCLE.set_radius = &set_radius;
    _META_CIRCLE.constructor = &circle_constructor;
    _META_CIRCLE.super_meta_class = &_META_GRAPHICAL_OBJECT;
}

/**
 * Initialise un nouveau cercle
 * @param self Pointeur de l'objet courant
 */
void circle_constructor(circle_t* self) {
    if (_META_GRAPHICAL_OBJECT.constructor == NULL) {
        construct_meta_graphical_object();
    }
    if (_META_CIRCLE.constructor == NULL) {
        construct_meta_circle();
    }

    self->_radius = 0;
    self->my_class = &_META_CIRCLE;
    _META_GRAPHICAL_OBJECT.constructor(&self->super);
}
