#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "task_manager.h"
#include "mainwindow_buttons_and_errs.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    init_ui(&ui, &window, &connector, this);

    task_manager(INIT, connector, window);
    task_manager(UPDATE_SCENE, connector, window);
}

MainWindow::~MainWindow()
{
    task_manager(DELETE_BACKGROUND, connector, window);
    delete connector;
    delete ui;
}

void MainWindow::on_radio_x_clicked()
{
    ui->first_point->setText("yc");
    ui->second_point->setText("zc");
}

void MainWindow::on_radio_y_clicked()
{
    ui->first_point->setText("xc");
    ui->second_point->setText("zc");
}

void MainWindow::on_radio_z_clicked()
{
    ui->first_point->setText("xc");
    ui->second_point->setText("yc");
}

void MainWindow::on_Button_save_points_clicked()
{
    strcpy(connector->name_file, QFileDialog::getOpenFileName(this, "", "", "Text Files (*.txt)").toUtf8().constData());
    ERRORS err = task_manager(SAVE_POINTS, connector, window);
    show_message(err, this);
}

void MainWindow::on_Button_import_from_file_clicked()
{
    strcpy(connector->name_file, QFileDialog::getOpenFileName(this, "", "", "Text Files (*.txt)").toUtf8().constData());
    ERRORS err = task_manager(IMPORT_POINTS_FROM_FILE, connector, window);
    show_message(err, this);

    if (err == SUCCES_TO_IMPORT_POINTS)
        task_manager(UPDATE_SCENE, connector, window);
}

void MainWindow::on_horizontalSlider_valueChanged()
{
    window->size_window->len_z = ui->horizontalSlider->value();
    ERRORS err = task_manager(UPDATE_SCENE, connector, window);
    show_message(err, this);
}

void MainWindow::on_Button_move_clicked()
{
    button_clicked(MOVE, connector, ui, window, this);
}

void MainWindow::on_Button_skale_clicked()
{
    button_clicked(SKALE, connector, ui, window, this);
}

void MainWindow::on_Button_turn_clicked()
{
    button_clicked(TURN, connector, ui, window, this);
}


void set_size_window(st_scene *scene, Ui::MainWindow *ui)
{
    scene->size_window = new st_size_window;
    scene->size_window->len_x = ui->graphicsView->size().width() - 5;
    scene->size_window->len_y = ui->graphicsView->size().height() - 5;
    scene->size_window->len_z = DEPTH;
}

void init_ui(Ui::MainWindow **ui, st_scene **window, ui_information **connector, QMainWindow *parent)
{
    *window = new st_scene;
    (*connector) = new ui_information;
    (*window)->scene = new QGraphicsScene(parent);

    (*ui)->setupUi(parent);
    (*ui)->graphicsView->centerOn(0, 0);
    (*ui)->graphicsView->setScene((*window)->scene);

    set_size_window(*window, *ui);
    (*window)->scene->setSceneRect(0, 0, (*window)->size_window->len_x, (*window)->size_window->len_y);
}

void show_message(ERRORS err, QWidget *parent)
{
    switch(err)
    {
        case ERR_OPEN_FILE:
            QMessageBox::critical(parent, "", "Ошибка открытия файла!");
            break;
        case SUCCES_TO_SAVE_POINTS:
            QMessageBox::information(parent, "", "Точки успешно сохранены");
            break;
        case INPUT_DATA_ERROR_IN_FILE:
            QMessageBox::critical(parent, "", "Неверные данные в файле!");
            break;
        case INVALID_ENTRY_UI:
            QMessageBox::critical(parent, "", "Ошибка!\nВведены неверные данные");
            break;
        case SUCCES_TO_IMPORT_POINTS:
            QMessageBox::information(parent, "", "Точки успешно загружены");
            break;
        case ERROR_NEW_MEM:
            QMessageBox::critical(parent, "", "Ошибка выделения памяти!");
            break;
        case ERROR_NOT_FOUND:
            QMessageBox::critical(parent, "", "Неизвестный код ошибки!");
            break;

        default:
            break;
    }
}

void import_data_from_skale_line(Ui::MainWindow *ui, ui_information *connector)
{
    bool err1, err2, err3, err4, err5, err6;
    double kx = ui->kx_entry->text().toDouble(&err1);
    double ky = ui->ky_entry->text().toDouble(&err2);
    double kz = ui->kz_entry->text().toDouble(&err3);

    double xc = ui->xc_entry->text().toDouble(&err4);
    double yc = ui->yc_entry->text().toDouble(&err5);
    double zc = ui->zc_entry->text().toDouble(&err6);

    connector->skale.kx = kx;
    connector->skale.ky = ky;
    connector->skale.kz = kz;
    connector->skale.xc = xc;
    connector->skale.yc = yc;
    connector->skale.zc = zc;
    connector->skale.err = err1 * err2 * err3 * err4 * err5 * err6;
}

void import_data_from_move_line(Ui::MainWindow *ui, ui_information *connector)
{
    bool err1, err2, err3;
    double x = ui->x_entry->text().toDouble(&err1);
    double y = ui->y_entry->text().toDouble(&err2);
    double z = ui->z_entry->text().toDouble(&err3);

    connector->move.x = x;
    connector->move.y = y;
    connector->move.z = z;
    connector->move.err = err1 * err2 * err3;
}

void import_data_from_turn_line(Ui::MainWindow *ui, ui_information *connector)
{
    bool err1, err2, err3;
    double point1 = ui->point1_entry->text().toDouble(&err1);
    double point2 = ui->point2_entry->text().toDouble(&err2);
    double angle = ui->angle_entry->text().toDouble(&err3);

    if (ui->radio_x->isChecked())
        connector->turn.axis = 'x';
    else if (ui->radio_y->isChecked())
        connector->turn.axis = 'y';
    else
        connector->turn.axis = 'z';

    connector->turn.angle = angle;
    connector->turn.point1 = point1;
    connector->turn.point2 = point2;
    connector->turn.err = err1 * err2 * err3;
}

ERRORS data_from_ui(ACTIONS action, ui_information *connector, Ui::MainWindow *ui)
{
    ERRORS err = OK;
    switch(action)
    {
        case MOVE:
            import_data_from_move_line(ui, connector);
            break;

        case SKALE:
            import_data_from_skale_line(ui, connector);
            break;

        case TURN:
            import_data_from_turn_line(ui, connector);
            break;

        default:
            err = INVALID_ENTRY_UI;
            break;
     }

    return err;
}

void button_clicked(ACTIONS action, ui_information *connector, Ui::MainWindow *ui, st_scene *window, QMainWindow *parent)
{
    ERRORS err = data_from_ui(action, connector, ui);
    if (err == OK)
        err = task_manager(action, connector, window);

    if (err != OK)
        show_message(err, parent);
    else
        task_manager(UPDATE_SCENE, connector, window);
}
