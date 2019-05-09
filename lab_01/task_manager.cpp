#include "libraries_and_enum.h"
#include "file_funcs.h"
#include "move_scale_turn_funcs.h"
#include "init_free_background.h"
#include "update_scene.h"

ERRORS task_manager(ACTIONS action, ui_information *connector, st_scene *scene)
{
    static st_figure_data figure_data = init_background();
    ERRORS err = OK;

    switch (action)
    {
        case INIT:
            break;

        case MOVE:
            err = move_points(&figure_data, connector);
            break;

        case SKALE:
            err = skale_points(&figure_data, connector);
            break;

        case TURN:
            err = turn_points(&figure_data, connector);
            break;

        case SAVE_POINTS:
            err = save_points(&figure_data, connector);
            break;

        case IMPORT_POINTS_FROM_FILE:
            err = import_data_from_file(&figure_data, connector);
            break;

        case UPDATE_SCENE:
            err = update_scene(&figure_data, scene);
            break;

        case DELETE_BACKGROUND:
            err = delete_background(&figure_data, scene);
            break;

        default:
            err = ERROR_NOT_FOUND1;
    }

    return err;
}
