#ifndef MAINWINDOW_BUTTONS_AND_ERRS_H
#define MAINWINDOW_BUTTONS_AND_ERRS_H

void init_ui(Ui::MainWindow **ui, st_scene **scene, ui_information **connector, QMainWindow *parent);
void show_message(ERRORS err, QWidget *parent);
void import_data_from_skale_line(Ui::MainWindow *ui, ui_information *connector);
void import_data_from_move_line(Ui::MainWindow *ui, ui_information *connector);
void import_data_from_turn_line(Ui::MainWindow *ui, ui_information *connector);
ERRORS data_from_ui(ACTIONS action, ui_information *connector, Ui::MainWindow *ui);
void button_clicked(ACTIONS action, ui_information *connector, Ui::MainWindow *ui, st_scene *window, QMainWindow *parent);


#endif // MAINWINDOW_BUTTONS_AND_ERRS_H
