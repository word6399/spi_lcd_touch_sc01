#include "vars.h"
#include "actions.h"


#include <Arduino.h>
#include "Display.h"

#include "esp_console.h"

#include "ui/ui.h"
#include "screens.h"
#include "images.h"

#include "FFat.h"
#include <WiFi.h>
#include <ESPAsyncWebServer.h>


static const char *TAG = "example";

lv_chart_series_t *ser2;

void action_inc_counter(lv_event_t *e) {
    
}

void action_update_chart(lv_event_t *e) {
  int32_t val = lv_slider_get_value(objects.slider1);
  lv_chart_set_next_value(objects.chart, ser2, val);
  //Serial.println("update " + String(val));
}




int32_t test_val;

int32_t get_var_test_val() {
    return test_val;
}

void set_var_test_val(int32_t value) {
    test_val = value;
}


AsyncWebServer server(80);

void listDir(fs::FS &fs, const char *dirname, uint8_t levels = -1) {
  Serial.printf("Listing directory: %s\r\n", dirname);

  File root = fs.open(dirname);
  if (!root) {
    Serial.println("- failed to open directory");
    return;
  }
  if (!root.isDirectory()) {
    Serial.println(" - not a directory");
    return;
  }

  File file = root.openNextFile();
  while (file) {
    if (file.isDirectory()) {
      //Serial.print("  DIR : ");
      //Serial.println(file.name());
      if (levels) {
        listDir(fs, file.path(), levels - 1);
      }
    } else {
      Serial.print("  FILE: ");
      Serial.print(file.path());
      Serial.print("\tSIZE: ");
      Serial.println(file.size());
      server.serveStatic(file.path(), FFat, file.path());
    }
    file = root.openNextFile();
  }
}

void click_cb(lv_event_t *e)
{
  Serial.println("click");
  lv_obj_t *target = (lv_obj_t *)lv_event_get_target(e);

  lv_obj_t *child = lv_obj_get_child(target, 0);
  while(child) {
    if( lv_obj_check_type(child, &lv_label_class) ){
      Serial.println( lv_label_get_text(child));
    }
    
    child = lv_obj_get_child(target, lv_obj_get_index(child)+1);
  }
}

void setup()
{
    Serial.begin(115200);

    if( FFat.begin() ){
        Serial.println("file fs mounted size: " + String(FFat.totalBytes()));
        Serial.println("Used bytes: " + String( FFat.usedBytes()));
    }

    listDir(FFat, "/");

    display.init();

    
    ui_init();

    lv_obj_t *chart = objects.chart;

    lv_chart_set_range(chart, LV_CHART_AXIS_PRIMARY_Y, 0, 100);
    lv_chart_set_point_count(chart, 20);

    ser2 = lv_chart_add_series(chart, lv_palette_main(LV_PALETTE_BLUE), LV_CHART_AXIS_PRIMARY_Y);

    lv_chart_set_next_value(chart, ser2, 50);
    lv_chart_set_next_value(chart, ser2, 40);
    lv_chart_set_next_value(chart, ser2, 30);
    lv_chart_set_next_value(chart, ser2, 20);
    lv_chart_set_next_value(chart, ser2, 10);

    lv_obj_t *panel = objects.folder;

    File root = FFat.open("/assets/js");
    File file = root.openNextFile();

    //for (size_t i = 0; i < 12; i++)
    while (file)
    {
      lv_obj_t *btn = lv_btn_create(panel);

      lv_obj_set_size(btn, 100, 100);            
      lv_obj_set_style_bg_opa(btn, 0, 0);
      //lv_obj_set_style_border_color(btn, {0xFC, 0xC0, 0x74}, 0);
      //lv_obj_set_style_border_width(btn, 2, 0);
      lv_obj_set_style_pad_top(btn, 0, 0);

      lv_obj_t *img = lv_image_create(btn);
      if( file.isDirectory() )
        lv_image_set_src(img, &img_folder);
      else
        lv_image_set_src(img, &img_file);

      lv_obj_align(img, LV_ALIGN_TOP_MID ,0,0);

      lv_obj_t *label = lv_label_create(btn);
      lv_label_set_text_fmt(label, file.name());
      lv_obj_align(label, LV_ALIGN_BOTTOM_MID, 0, 0);

      lv_obj_add_event_cb(btn, click_cb, LV_EVENT_CLICKED, NULL);

      file = root.openNextFile();

    }
    
    
    WiFi.begin("Bussol", "11119999");

    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
        String url = "/index.html";
        
        request->redirect(url);
    });


    
    
    // server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    //     // need to cast to uint8_t*
    //     // if you do not, the const char* will be copied in a temporary String buffer
    //     const char data[] = "hello";
    //     request->send(200, "text/html", (uint8_t *)data, strlen(data));
    // });

    server.begin();
    
}

uint32_t time_till_next_ms = 0;
int counter =0;
void loop()
{
    lv_timer_handler();    
    lv_tick_inc(1);
    ui_tick();
    counter++;
    // if(counter >5000){
    //     counter =0;
    //     Serial.printf("Update: %d, %d", 'А','Я');
    // }
    

    //delay(1);
}