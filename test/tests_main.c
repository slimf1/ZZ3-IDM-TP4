#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "teZZt.h"
#include "graphical_object.h"
#include "circle.h"
#include "rectangle.h"

BEGIN_TEST_GROUP(TP4)

TEST(GETTERS_SETTERS, "Test construction and setters logic") {
    graphical_object_t graph;
    circle_t circle;
    rectangle_t rect;

    graphical_object_constructor(&graph);
    circle_constructor(&circle);
    rectangle_constructor(&rect);
    graph.my_class->set_x(&graph, 4);
    circle.my_class->set_radius(&circle, 14);
    circle.super.my_class->set_x(&circle.super, 33);
    rect.my_class->set_height(&rect, 5);

    // Test du bon fonctionnement des getters
    CHECK(graph.my_class->get_x(&graph) == 4);
    CHECK(graph.my_class->get_y(&graph) == 0);
    CHECK(circle.my_class->get_radius(&circle) == 14);
    CHECK(circle.my_class->super_meta_class->get_x(&circle.super) == 33);
    CHECK(rect.my_class->get_height(&rect) == 5);

    // Test du bon nombre d'instances
    CHECK(graph.my_class->get_instance_count() == 3);
};

TEST(DISPLAY, "Test the display method") {
    circle_t circle;
    rectangle_t rect;
    char buffer[100];
    FILE* stream;

    circle_constructor(&circle);
    rectangle_constructor(&rect);
    circle.my_class->set_radius(&circle, 1);
    rect.my_class->set_height(&rect, 5);
    rect.my_class->set_width(&rect, 15);

    stream = fmemopen(buffer, sizeof(buffer), "w");
    rect.super.my_class->display((graphical_object_t*)&rect, stream);
    circle.super.my_class->display((graphical_object_t*)&circle, stream);
    fclose(stream);

    CHECK(strcmp(buffer, "<Rectangle w=15 h=5>\n<Circle r=1>\n") == 0);
};

END_TEST_GROUP(TP4)

int main() {
    RUN_TEST_GROUP(TP4);
    return EXIT_SUCCESS;
}
