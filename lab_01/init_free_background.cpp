#include "libraries_and_enum.h"

void delete_dyn_mem(void *dyn_mas)
{
    if (dyn_mas)
        free(dyn_mas);
}

st_figure_data init_background(void)
{
    st_figure_data arr_points;
    arr_points.points.mas_points = nullptr;
    arr_points.connections.mas_connections = nullptr;

    return arr_points;
}

void delete_dyn_figure_data(st_figure_data *figure_data)
{
    if (figure_data)
    {
        delete_dyn_mem(figure_data->points.mas_points);
        delete_dyn_mem(figure_data->connections.mas_connections);
    }
}

ERRORS delete_background(st_figure_data *figure_data, st_scene *window)
{
    ERRORS err = OK;
    delete window->scene;
    delete [] window;
    delete_dyn_figure_data(figure_data);

    return err;
}
