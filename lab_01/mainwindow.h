#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "libraries_and_enum.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    Ui::MainWindow *ui;
    st_scene *window;
    ui_information *connector;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_radio_x_clicked();
    void on_radio_y_clicked();
    void on_radio_z_clicked();
    void on_Button_save_points_clicked();
    void on_Button_import_from_file_clicked();
    void on_horizontalSlider_valueChanged();
    void on_Button_move_clicked();
    void on_Button_skale_clicked();
    void on_Button_turn_clicked();
};

#endif // MAINWINDOW_H
