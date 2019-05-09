#include "libraries_and_enum.h"
#include "pre_move_scale_turn.h"

ERRORS move_points(st_figure_data *obj, ui_information *connector)
{
    ERRORS err = check_data(connector, MOVE);
    if (err == OK)
        for (int i = 0; i < obj->points.len_points_mas; i++)
        {
            obj->points.mas_points[i].x += connector->move.x;
            obj->points.mas_points[i].y += connector->move.y;
            obj->points.mas_points[i].z += connector->move.z;
        }

    return err;
}

ERRORS skale_points(st_figure_data *obj, ui_information *connector)
{
    ERRORS err = check_data(connector, SKALE);
    if (err == OK)
    {
        double xc = connector->skale.xc;
        double yc = connector->skale.yc;
        double zc = connector->skale.zc;

        double kx = connector->skale.kx;
        double ky = connector->skale.ky;
        double kz = connector->skale.kz;

        for (int i = 0; i < obj->points.len_points_mas; i++)
        {
            obj->points.mas_points[i].x = (obj->points.mas_points[i].x - xc) * kx + xc;
            obj->points.mas_points[i].y = (obj->points.mas_points[i].y - yc) * ky + yc;
            obj->points.mas_points[i].z = (obj->points.mas_points[i].z - zc) * kz + zc;
        }
    }

    return err;
}

ERRORS turn_points(st_figure_data *obj, ui_information *connector)
{
    ERRORS err = check_data(connector, TURN);
    if (err == OK)
    {
        char axis = connector->turn.axis;

        switch (axis)
        {
            case 'x':
                err = turn_points_via_axis(&obj->points, connector, x_turn_point);
                break;

            case 'y':
                err = turn_points_via_axis(&obj->points, connector, y_turn_point);
                break;

            case 'z':
                err = turn_points_via_axis(&obj->points, connector, z_turn_point);
                break;

            default:
                err = INVALID_ENTRY_UI;
        }
    }

    return err;
}
