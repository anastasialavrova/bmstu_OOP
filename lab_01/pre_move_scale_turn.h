#ifndef PRE_MOVE_SKALE_TURN_H
#define PRE_MOVE_SKALE_TURN_H

ERRORS check_data(ui_information *connector, ACTIONS action);
double d_cos(double angle);
double d_sin(double angle);
point x_turn_point(point point, double point1, double point2, double angle);
point y_turn_point(point point, double point1, double point2, double angle);
point z_turn_point(point point, double point1, double point2, double angle);
ERRORS turn_points_via_axis(st_points *pts, ui_information *connector, point (*func_turn_point)(point, double, double, double));

#endif // PRE_MOVE_SKALE_TURN_H
