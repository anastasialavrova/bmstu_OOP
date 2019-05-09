#ifndef PRE_UPDATE_SCENE_H
#define PRE_UPDATE_SCENE_H

point new_point(point *point_3d, st_scene *win);
void draw_axis(st_scene *win);
point *invert_points(st_points *pts, st_scene *window);

#endif // PRE_UPDATE_SCENE_H
