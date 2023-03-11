#include "../lvgl.h"
#if LV_BUILD_EXAMPLES && LV_USE_BTN

static void btn_event_cb(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * btn = lv_event_get_target(e);
    if(code == LV_EVENT_CLICKED) {
        static uint8_t cnt = 0;
        cnt++;
        /*Get the first child of the button which is the label and change its text*/
        lv_obj_t * label = lv_obj_get_child(btn, 0);
        lv_label_set_text_fmt(label, "abrieron el refrigerador: %d veces", cnt);
        LV_LOG_USER("ABRIERON EL REFRI");
    }
}

/**
 * Create a button with a label and react on click event.
 * crea un boton con la etiquera y reacciona al evento picale wey
 */
void lv_example_get_started_1(void)
{
    lv_obj_t * btn = lv_btn_create(lv_scr_act());     /*Add a button the current screen*/
    lv_obj_set_pos(btn, 300, 200);                            /*le damos posicion*/
    lv_obj_set_size(btn, 250, 100);                          /*Set le damos tamaño*/
    lv_obj_add_event_cb(btn, btn_event_cb, LV_EVENT_ALL, NULL);  /*le asigna una interrupcion al boton*/

    lv_obj_t * label = lv_label_create(btn);          /*Add a label to the button*/
    lv_label_set_text(label, "Puerta de refrigerador");   /*Se le coloca una primer etiquete o nombre*/
    lv_obj_center(label);
}

#endif

