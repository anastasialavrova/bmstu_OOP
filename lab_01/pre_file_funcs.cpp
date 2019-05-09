#include "libraries_and_enum.h"
#include "init_free_background.h"

void write_points_to_file(st_points points_data, FILE *file)
{
    fprintf(file, "%d\n", points_data.len_points_mas);
    for (int i = 0; i < points_data.len_points_mas; i++)
        fprintf(file, "%f %f %f\n", points_data.mas_points[i].x,
                                    points_data.mas_points[i].y,
                                    points_data.mas_points[i].z);
}

void write_connections_to_file(st_connections connections_data, FILE *file)
{
    fprintf(file, "%d\n", connections_data.len_connections_mas);
    for (int i = 0; i < connections_data.len_connections_mas; i++)
        fprintf(file, "%d %d\n", connections_data.mas_connections[i].first_point,
                                 connections_data.mas_connections[i].second_point);
}

ERRORS read_len_points_from_file(int *len_points_mas, FILE *file)
{
    ERRORS err = SUCCES_TO_IMPORT_POINTS;
    int rc = fscanf(file, "%d", len_points_mas);
    if (rc != 1|| *len_points_mas <= 0)
        err = INPUT_DATA_ERROR_IN_FILE;

    return err;
}

ERRORS read_point_from_file(point *point, FILE *file)
{
    ERRORS err = SUCCES_TO_IMPORT_POINTS;

    int rc = fscanf(file, "%lf %lf %lf", &(point->x), &(point->y), &(point->z));
    if (rc != 3)
        err = INPUT_DATA_ERROR_IN_FILE;

    return  err;
}

point* init_mas_points(point *mas_points, int len)
{
    mas_points = new point [len];
    return mas_points;
}

ERRORS read_points_from_file(st_points *points_from_file, FILE *file)
{
    ERRORS err = SUCCES_TO_IMPORT_POINTS;

    for (int i = 0; i < points_from_file->len_points_mas && err == SUCCES_TO_IMPORT_POINTS; i++)
        err = read_point_from_file(&(points_from_file->mas_points[i]), file);

    return err;
}

ERRORS read_data_for_points_from_file(st_points *points_from_file, FILE *file)
{
    ERRORS err = read_len_points_from_file(&(points_from_file->len_points_mas), file);
    if (err == SUCCES_TO_IMPORT_POINTS)
    {
        points_from_file->mas_points = init_mas_points(points_from_file->mas_points,
                                                       points_from_file->len_points_mas);
        if ((err = read_points_from_file(points_from_file, file)) == INPUT_DATA_ERROR_IN_FILE)
            delete_dyn_mem(&points_from_file->mas_points);
    }
    return err;
}

ERRORS read_len_connections_from_file(int *len_connections_mas, FILE *file)
{
    ERRORS err = SUCCES_TO_IMPORT_POINTS;
    int rc = fscanf(file, "%d", len_connections_mas);
    if (rc != 1|| *len_connections_mas <= 0)
        err = INPUT_DATA_ERROR_IN_FILE;

    return err;
}

ERRORS read_connection_from_file(connection *connections, FILE *file)
{
    ERRORS err = SUCCES_TO_IMPORT_POINTS;

    int rc = fscanf(file, "%d %d", &(connections->first_point), &(connections->second_point));
    if (rc != 2)
        err = INPUT_DATA_ERROR_IN_FILE;

    return  err;
}

connection* init_mas_connections(connection *mas_connections, int len)
{
    mas_connections = new connection [len];
    return mas_connections;
}

ERRORS read_connections_from_file(st_connections *connections_from_file, FILE *file)
{
    ERRORS err = SUCCES_TO_IMPORT_POINTS;

    for (int i = 0; i < connections_from_file->len_connections_mas && err == SUCCES_TO_IMPORT_POINTS; i++)
        err = read_connection_from_file(&(connections_from_file->mas_connections[i]), file);

    return err;
}

ERRORS read_data_for_connections_from_file(st_connections *connections_from_file, FILE *file)
{
    ERRORS err = read_len_connections_from_file(&(connections_from_file->len_connections_mas), file);
    if (err == SUCCES_TO_IMPORT_POINTS)
    {
        connections_from_file->mas_connections = init_mas_connections(connections_from_file->mas_connections,
                                                                      connections_from_file->len_connections_mas);
        if ((err = read_connections_from_file(connections_from_file, file)) == INPUT_DATA_ERROR_IN_FILE)
            delete_dyn_mem(&connections_from_file->mas_connections);
    }
    return err;
}

void copy_ptrs_from_data_file(st_figure_data *figure_data, st_figure_data *data_from_file)
{
    figure_data->points.mas_points = data_from_file->points.mas_points;
    figure_data->points.len_points_mas = data_from_file->points.len_points_mas;

    figure_data->connections.mas_connections = data_from_file->connections.mas_connections;
    figure_data->connections.len_connections_mas = data_from_file->connections.len_connections_mas;
}
