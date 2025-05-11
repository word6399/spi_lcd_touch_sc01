#ifndef EEZ_LVGL_UI_SCREENS_H
#define EEZ_LVGL_UI_SCREENS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _objects_t {
    lv_obj_t *main;
    lv_obj_t *page_programm;
    lv_obj_t *page_setting;
    lv_obj_t *page_inform;
    lv_obj_t *sidebar1;
    lv_obj_t *sidebar1__obj0;
    lv_obj_t *button_interface;
    lv_obj_t *button_files;
    lv_obj_t *button_inform;
    lv_obj_t *obj0;
    lv_obj_t *obj1;
    lv_obj_t *obj2;
    lv_obj_t *obj3;
    lv_obj_t *main_label;
    lv_obj_t *folder;
    lv_obj_t *chart;
    lv_obj_t *slider1;
    lv_obj_t *obj4;
} objects_t;

extern objects_t objects;

enum ScreensEnum {
    SCREEN_ID_MAIN = 1,
    SCREEN_ID_PAGE_PROGRAMM = 2,
    SCREEN_ID_PAGE_SETTING = 3,
    SCREEN_ID_PAGE_INFORM = 4,
};

void create_screen_main();
void tick_screen_main();

void create_screen_page_programm();
void tick_screen_page_programm();

void create_screen_page_setting();
void tick_screen_page_setting();

void create_screen_page_inform();
void tick_screen_page_inform();

void create_user_widget_wiget1(lv_obj_t *parent_obj, void *flowState, int startWidgetIndex);
void tick_user_widget_wiget1(void *flowState, int startWidgetIndex);

void create_user_widget_sidebar(lv_obj_t *parent_obj, void *flowState, int startWidgetIndex);
void tick_user_widget_sidebar(void *flowState, int startWidgetIndex);

void create_user_widget_sadf(lv_obj_t *parent_obj, void *flowState, int startWidgetIndex);
void tick_user_widget_sadf(void *flowState, int startWidgetIndex);

void create_user_widget_button_folder(lv_obj_t *parent_obj, void *flowState, int startWidgetIndex);
void tick_user_widget_button_folder(void *flowState, int startWidgetIndex);

void create_user_widget_button_file(lv_obj_t *parent_obj, void *flowState, int startWidgetIndex);
void tick_user_widget_button_file(void *flowState, int startWidgetIndex);

void tick_screen_by_id(enum ScreensEnum screenId);
void tick_screen(int screen_index);

void create_screens();


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_SCREENS_H*/