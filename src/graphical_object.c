#include "graphical_object.h"

// Méta objet unique pour la classe d'objets graphiques
meta_graphical_object_t _META_GRAPHICAL_OBJECT;

/**
 * Accesseur de l'abscisse (get)
 * @param self Pointeur de l'objet courant
 * @return L'abscisse du point
 */
int get_x(graphical_object_t* self) {
    return self->_x;
}

/**
 * Accesseur de l'ordonnée (get)
 * @param self Pointeur de l'objet courant
 * @return L'ordonnée du point
 */
int get_y(graphical_object_t* self) {
    return self->_y;
}

/**
 * Accesseur de l'abscisse (set)
 * @param self Pointeur de l'objet courant
 * @param x La nouvelle valeur de l'abscisse
 */
void set_x(graphical_object_t* self, int x) {
    self->_x = x;
}

/**
 * Accesseur de l'ordonnée
 * @param self Pointeur de l'objet courant
 * @param y La nouvelle valeur de l'ordonnée
 */
void set_y(graphical_object_t* self, int y) {
    self->_y = y;
}

/**
 * Méthode de classe pour le nombre d'instance
 * @return Le nombre d'instances d'objets graphiques
 * crées
 */
int graphical_object_get_instance_count() {
    return _META_GRAPHICAL_OBJECT._instance_count;
}

/**
 * Initialisation de l'unique méta-objet graphique
 */
void construct_meta_graphical_object() {
    _META_GRAPHICAL_OBJECT.get_x = &get_x;
    _META_GRAPHICAL_OBJECT.get_y = &get_y;
    _META_GRAPHICAL_OBJECT.set_x = &set_x;
    _META_GRAPHICAL_OBJECT.set_y = &set_y;
    _META_GRAPHICAL_OBJECT.constructor = &graphical_object_constructor;
    _META_GRAPHICAL_OBJECT.get_instance_count = &graphical_object_get_instance_count;
    _META_GRAPHICAL_OBJECT._instance_count = 0;
}

/**
 * Initialise un nouvel objet graphique.
 * @param self Pointeur vers l'objet courant
 */
void graphical_object_constructor(graphical_object_t* self) {
    if (_META_GRAPHICAL_OBJECT.constructor == NULL) {
        // Initialisation de l'unique méta objet
        construct_meta_graphical_object();
    }
    _META_GRAPHICAL_OBJECT._instance_count++;
    self->_x = 0;
    self->_y = 0;
    self->my_class = &_META_GRAPHICAL_OBJECT;
}
