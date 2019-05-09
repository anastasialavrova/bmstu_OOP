#ifndef INIT_FREE_BACKGROUND_H
#define INIT_FREE_BACKGROUND_H

st_figure_data init_background(void);
void delete_dyn_mem(void *dyn_mas);
void delete_dyn_figure_data(st_figure_data *figure_data);
ERRORS delete_background(st_figure_data *figure_data, st_scene *window);

#endif // INIT_FREE_BACKGROUND_H
