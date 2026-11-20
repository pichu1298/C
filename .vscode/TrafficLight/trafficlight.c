#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"

#define RED_LIGHT_PIN GPIO_NUM_18
#define YELLOW_LIGHT_PIN GPIO_NUM_19
#define GREEN_LIGHT_PIN GPIO_NUM_21

static const char *TAG = "trafficlight";

void app_main(void){
    gpio_reset_pin(RED_LIGHT_PIN);
    gpio_reset_pin(YELLOW_LIGHT_PIN);
    gpio_reset_pin(GREEN_LIGHT_PIN);
    gpio_set_direction(RED_LIGHT_PIN, GPIO_MODE_OUTPUT);
    gpio_set_direction(YELLOW_LIGHT_PIN, GPIO_MODE_OUTPUT);
    gpio_set_direction(GREEN_LIGHT_PIN, GPIO_MODE_OUTPUT);


    gpio_set_level(RED_LIGHT_PIN, 0);
    gpio_set_level(YELLOW_LIGHT_PIN, 0);
    gpio_set_level(GREEN_LIGHT_PIN, 0);

    while (1){
        //turn on green light for 5 seconds and turn off red light
        ESP_LOGI(TAG, "Turning on green lightfor 5 seconds");
        gpio_set_level(RED_LIGHT_PIN, 0);
        gpio_set_level(GREEN_LIGHT_PIN, 1);
        vTaskDelay(pdMS_TO_TICKS(5000));

        //turn off green light and turn on yellow light for 2 seconds
        ESP_LOGI(TAG, "Turning on yellow light for 2 seconds");
        gpio_set_level(GREEN_LIGHT_PIN, 0);
        gpio_set_level(YELLOW_LIGHT_PIN, 1);
        vTaskDelay(pdMS_TO_TICKS(2000));

        //turn off yellow light and turn on red light for 5 seconds
        ESP_LOGI(TAG, "Turning on red light for 5 seconds");
        gpio_set_level(YELLOW_LIGHT_PIN, 0);
        gpio_set_level(RED_LIGHT_PIN, 1);
        vTaskDelay(pdMS_TO_TICKS(5000));

    }
    
}