#include "styles.h"
#include "images.h"
#include "fonts.h"

#include "ui.h"
#include "screens.h"

//
// Style: default_font
//

void init_style_default_font_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_text_font(style, &ui_font_nunito_14);
};

lv_style_t *get_style_default_font_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_default_font_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_default_font(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_default_font_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_default_font(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_default_font_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
//
//

void add_style(lv_obj_t *obj, int32_t styleIndex) {
    typedef void (*AddStyleFunc)(lv_obj_t *obj);
    static const AddStyleFunc add_style_funcs[] = {
        add_style_default_font,
    };
    add_style_funcs[styleIndex](obj);
}

void remove_style(lv_obj_t *obj, int32_t styleIndex) {
    typedef void (*RemoveStyleFunc)(lv_obj_t *obj);
    static const RemoveStyleFunc remove_style_funcs[] = {
        remove_style_default_font,
    };
    remove_style_funcs[styleIndex](obj);
}

