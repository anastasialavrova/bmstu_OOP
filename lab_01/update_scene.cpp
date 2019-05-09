#include "libraries_and_enum.h"
#include "pre_update_scene.h"
#include "init_free_background.h"

void addLine(st_scene *window, point point1, point point2)
{
    window->scene->addLine(QLine(int(point1.x), int(point1.y), int(point2.x), int(point2.y)));
}

void draw_figure(st_scene *window, st_points *points, st_connections *connections)
{
    point *inverted_points = invert_points(points, window);

    int len_connections_mas = connections->len_connections_mas;
    connection *mas_connections = connections->mas_connections;
    for (int i = 0; i < len_connections_mas; i++)
        addLine(window, inverted_points[mas_connections[i].first_point - 1],
                        inverted_points[mas_connections[i].second_point - 1]);

    delete_dyn_mem(inverted_points);
}

void clear_scene(st_scene *window)
{
    window->scene->clear();
}

ERRORS update_scene(st_figure_data *figure_data, st_scene *window)
{
    ERRORS err = OK;

    clear_scene(window);
    draw_axis(window);
    draw_figure(window, &figure_data->points, &figure_data->connections);

    return err;
}
