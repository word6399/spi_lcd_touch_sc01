#ifndef EEZ_LVGL_UI_IMAGES_H
#define EEZ_LVGL_UI_IMAGES_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

extern const lv_img_dsc_t img_logo_lvgl;
extern const lv_img_dsc_t img_logo_eez;
extern const lv_img_dsc_t img_file_upload;
extern const lv_img_dsc_t img_inform;
extern const lv_img_dsc_t img_setting;
extern const lv_img_dsc_t img_folder;
extern const lv_img_dsc_t img_file;

#ifndef EXT_IMG_DESC_T
#define EXT_IMG_DESC_T
typedef struct _ext_img_desc_t {
    const char *name;
    const lv_img_dsc_t *img_dsc;
} ext_img_desc_t;
#endif

extern const ext_img_desc_t images[7];


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_IMAGES_H*/