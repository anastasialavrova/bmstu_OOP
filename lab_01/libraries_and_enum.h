#ifndef LIBRARIES_AND_ENUM_H
#define LIBRARIES_AND_ENUM_H

#include <QMainWindow>
#include <QGraphicsItem>
#include <QMessageBox>
#include <QtGui>
#include <QtCore>
#include <QDialog>
#include <QGraphicsView>
#include <QFileDialog>
#include <QString>
#include <QFile>

#include <iostream>
#include <math.h>
#include <fstream>

#define DEPTH 400
#define NUM_CONNECTIONS 2
#define NUM_POINTS 3
#define DEFAULT_FILE_NAME "default_points.txt"

enum ACTIONS {INIT, MOVE, SKALE, TURN, SAVE_POINTS,
              IMPORT_POINTS_FROM_FILE, UPDATE_SCENE, DELETE_BACKGROUND};
//enum ERRORS {OK, ERR_OPEN_FILE, SUCCES_TO_SAVE_POINTS, INPUT_DATA_ERROR_IN_FILE, INVALID_ENTRY_UI, SUCCES_TO_IMPORT_POINTS, ERROR_NOT_FOUND, ERROR_NEW_MEM};
enum ERRORS {OK, ERR_OPEN_FILE, SUCCES_TO_SAVE_POINTS, INPUT_DATA_ERROR_IN_FILE, INVALID_ENTRY_UI, SUCCES_TO_IMPORT_POINTS, ERROR_NOT_FOUND1, ERROR_NEW_MEM};

typedef struct {
    struct {
        double x;
        double y;
        double z;
        bool err;
    } move;

    struct {
        double kx;
        double ky;
        double kz;
        double xc;
        double yc;
        double zc;
        bool err;
    } skale;

    struct {
        char axis;
        double point1;
        double point2;
        double angle;
        bool err;
    } turn;

    char name_file[300];

} ui_information;

typedef struct {
    double x;
    double y;
    double z;
} point;

typedef struct {
    double len_x;
    double len_y;
    double len_z;
} st_size_window;

typedef struct {
    int first_point;
    int second_point;
} connection;

typedef struct {
    point *mas_points;
    int len_points_mas;
} st_points;

typedef struct {
    connection *mas_connections;
    int len_connections_mas;
} st_connections;

typedef struct {

    st_points points;
    st_connections connections;

} st_figure_data;

typedef struct {
    QGraphicsScene *scene;
    st_size_window *size_window;
} st_scene;

#endif // LIBRARIES_AND_ENUM_H
