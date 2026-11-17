#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define RED_LIGHT_PIN GPIO_NUM_0
#define YELLOW_LIGHT_PIN GPIO_NUM_1
#define GREEN_LIGHT_PIN GPIO_NUM_2

static const char *TAG = "trafficlight";

void app_main(void){
    gpio_reset_pin(RED_LIGHT_PIN);
    gpio_reset_pin(YELLOW_LIGHT_PIN);
    gpio_reset_pin(GREEN_LIGHT_PIN);
    gpio_set_direction(RED_LIGHT_PIN, GPIO_MODE_OUTPUT);
    gpio_set_direction(YELLOW_LIGHT_PIN, GPIO_MODE_OUTPUT);
    gpio_set_direction(GREEN_LIGHT_PIN, GPIO_MODE_OUTPUT);

    while (1){
        vTaskDelay(pdMS_TO_TICKS(1000));
    gpio_set_level(RED_LIGHT_PIN, 1);
    vTaskDelay(pdMS_TO_TICKS(1000));

    gpio_set_level(RED_LIGHT_PIN, 0);
    gpio_set_level(YELLOW_LIGHT_PIN, 1);
    vTaskDelay(pdMS_TO_TICKS(1000));

    gpio_set_level(YELLOW_LIGHT_PIN, 0);
    gpio_set_level(GREEN_LIGHT_PIN, 1);
    vTaskDelay(pdMS_TO_TICKS(1000));

    gpio_set_level(GREEN_LIGHT_PIN, 0);}
    gpio_set_level(RED_LIGHT_PIN, 0);
    gpio_set_level(YELLOW_LIGHT_PIN, 0);
    gpio_set_level(GREEN_LIGHT_PIN, 0);

    
}