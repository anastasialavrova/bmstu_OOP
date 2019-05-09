#include "libraries_and_enum.h"

void draw_axis(st_scene *win)
{
    win->scene->addLine(win->size_window->len_x/2, 0, win->size_window->len_x/2, win->size_window->len_y);
    win->scene->addLine(0, win->size_window->len_y/2, win->size_window->len_x, win->size_window->len_y/2);

    win->scene->addPolygon(QPolygonF() << QPointF(win->size_window->len_x/2, 0)
                                       << QPointF(win->size_window->len_x/2 - 5, 15)
                                       << QPointF(win->size_window->len_x/2 + 5, 15),
                                          QPen(Qt::black), QBrush(Qt::black));

    win->scene->addPolygon(QPolygonF() << QPointF(win->size_window->len_x, win->size_window->len_y/2)
                                       << QPointF(win->size_window->len_x - 15, win->size_window->len_y/2 + 5)
                                       << QPointF(win->size_window->len_x - 15, win->size_window->len_y/2 - 5),
                                          QPen(Qt::black), QBrush(Qt::black));

    QGraphicsTextItem *textItem = new QGraphicsTextItem("OY");
    textItem->setPos(win->size_window->len_x/2 + 5, 0);
    win->scene->addItem(textItem);

    textItem = new QGraphicsTextItem("OX");
    textItem->setPos(win->size_window->len_x - 22, win->size_window->len_y / 2);
    win->scene->addItem(textItem);
}

point new_point(point *point_3d, st_scene *win)
{
    point new_point;
    new_point.x = win->size_window->len_x/2 + point_3d->x * win->size_window->len_z/(point_3d->z + win->size_window->len_z);
    new_point.y = win->size_window->len_y/2 - point_3d->y * win->size_window->len_z/(point_3d->z + win->size_window->len_z);

    return new_point;
}

point *invert_points(st_points *pts, st_scene *window)
{
    point *inverted_points = new point [pts->len_points_mas];
    for (int i = 0; i < pts->len_points_mas; i++)
            inverted_points[i] = new_point(&pts->mas_points[i], window);

    return inverted_points;
}
