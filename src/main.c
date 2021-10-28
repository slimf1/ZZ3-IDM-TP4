#include <stdlib.h>
#include <stdio.h>
#include "graphical_object.h"
#include "circle.h"
#include "rectangle.h"

int main() {
    graphical_object_t graph;
    circle_t circle;
    rectangle_t rect;

#if DEBUG
    printf("is debug\n");
#endif

    graphical_object_constructor(&graph);
    circle_constructor(&circle);
    rectangle_constructor(&rect);
    graph.my_class->set_x(&graph, 4);
    circle.my_class->set_radius(&circle, 14);
    circle.super.my_class->set_x(&circle.super, 33);
    rect.my_class->set_height(&rect, 5);

    printf("x=%d\n", graph.my_class->get_x(&graph));
    printf("y=%d\n", graph.my_class->get_y(&graph));
    printf("radius=%d\n", circle.my_class->get_radius(&circle));
    printf("x circle=%d\n", circle.my_class->super_meta_class->get_x(&circle.super));
    printf("height=%d\n", rect.my_class->get_height(&rect));
    printf("instnb=%d\n", graph.my_class->get_instance_count());

    circle.super.my_class->display((graphical_object_t*)&circle, stdout);
    rect.super.my_class->display((graphical_object_t*)&rect, stdout);
    
    return EXIT_SUCCESS;
}
