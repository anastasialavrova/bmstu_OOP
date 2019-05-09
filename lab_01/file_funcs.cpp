#include "libraries_and_enum.h"
#include "init_free_background.h"
#include "pre_file_funcs.h"
#include <fstream>
#include <cstdio>

ERRORS save_points(st_figure_data *figure_data, ui_information *connector)
{
    ERRORS err = SUCCES_TO_SAVE_POINTS;
    //FILE *file = fopen(connector->name_file, "w");
    FILE *file;
    fopen_s(&file, connector->name_file, "w");
    if (!file)
        return ERR_OPEN_FILE;

    write_points_to_file(figure_data->points, file);
    write_connections_to_file(figure_data->connections, file);

    fclose(file);

    return err;
}

ERRORS import_data_from_file(st_figure_data *figure_data, ui_information *connector)
{
    //FILE *file = fopen(connector->name_file, "r");
    FILE *file;
    fopen_s(&file, connector->name_file, "r");
    if (!file)
        return ERR_OPEN_FILE;

    ERRORS err = SUCCES_TO_IMPORT_POINTS;
    st_figure_data data_from_file = init_background();
    err = read_data_for_points_from_file(&(data_from_file.points), file);
    if (err == SUCCES_TO_IMPORT_POINTS)
    {
        if((err = read_data_for_connections_from_file(&(data_from_file.connections), file)) == INPUT_DATA_ERROR_IN_FILE)
            delete_dyn_mem(&data_from_file.points);
    }

    fclose(file);

    if (err != INPUT_DATA_ERROR_IN_FILE)
    {
        delete_dyn_figure_data(figure_data);
        copy_ptrs_from_data_file(figure_data, &data_from_file);
    }

    return err;
}
