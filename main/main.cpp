#include "vars.h"
#include "actions.h"


#include <Arduino.h>
#include "Display.h"

#include "esp_console.h"

#include "ui/ui.h"

#include "FFat.h"
#include <WiFi.h>
#include <ESPAsyncWebServer.h>


static const char *TAG = "example";

void action_inc_counter(lv_event_t *e) {
    
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
      //Serial.print("  FILE: ");
      //Serial.print(file.path());
      //Serial.print("\tSIZE: ");
      //Serial.println(file.size());
      server.serveStatic(file.path(), FFat, file.path());
    }
    file = root.openNextFile();
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