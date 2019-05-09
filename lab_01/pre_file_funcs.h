#ifndef PRE_FILE_FUNCS_H
#define PRE_FILE_FUNCS_H

void write_points_to_file(st_points points_data, FILE *file);
void write_connections_to_file(st_connections connections_data, FILE *file);
ERRORS read_data_for_connections_from_file(st_connections *connections_from_file, FILE *file);
ERRORS read_data_for_points_from_file(st_points *points_from_file, FILE *file);
void copy_ptrs_from_data_file(st_figure_data *figure_data, st_figure_data *data_from_file);

#endif // PRE_FILE_FUNCS_H
