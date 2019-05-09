#include "libraries_and_enum.h"

ERRORS check_data(ui_information *connector, ACTIONS action)
{
    ERRORS err = OK;
    switch (action)
    {
        case MOVE:
            if (!connector->move.err)
                err = INVALID_ENTRY_UI;
            break;
        case SKALE:
            if (!connector->skale.err)
                err = INVALID_ENTRY_UI;
            break;
        case TURN:
            if (!connector->turn.err)
                err = INVALID_ENTRY_UI;
            break;
        default:
            err = INVALID_ENTRY_UI;
    }

    return err;
}

double d_cos(double angle)
{
    return cos(angle * M_PI / 180);
}

double d_sin(double angle)
{
    return sin(angle * M_PI / 180);
}

point x_turn_point(point point, double point1, double point2, double angle)
{
    double new_point1 = point1 + (point.y - point1) * d_cos(angle) + (point.z - point2) * d_sin(angle);
    double new_point2 = point2 - (point.y - point1) * d_sin(angle) + (point.z - point2) * d_cos(angle);

    point.y = new_point1;
    point.z = new_point2;

    return point;
}

point y_turn_point(point point, double point1, double point2, double angle)
{
    double new_point1 = point1 + (point.x - point1) * d_cos(angle) + (point.z - point2) * d_sin(angle);
    double new_point2 = point2 - (point.x - point1) * d_sin(angle) + (point.z - point2) * d_cos(angle);

    point.x = new_point1;
    point.z = new_point2;

    return point;
}

point z_turn_point(point point, double point1, double point2, double angle)
{
    double new_point1 = point1 + (point.x - point1) * d_cos(angle) + (point.y - point2) * d_sin(angle);
    double new_point2 = point2 - (point.x - point1) * d_sin(angle) + (point.y - point2) * d_cos(angle);

    point.x = new_point1;
    point.y = new_point2;

    return point;
}

ERRORS turn_points_via_axis(st_points *pts, ui_information *connector, point (*func_turn_point)(point, double, double, double))
{
    ERRORS err = OK;
    double point1 = connector->turn.point1;
    double point2 = connector->turn.point2;
    double angle = connector->turn.angle;

    for (int i = 0; i < pts->len_points_mas && err == OK; i++)
        pts->mas_points[i] = func_turn_point(pts->mas_points[i], point1, point2, angle);

    return err;
}
