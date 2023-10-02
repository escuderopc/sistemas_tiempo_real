#include "pico/stdlib.h"
#include "pico/stdio_uart.h"
#include "FreeRTOS.h"
#include "task.h"
#include "hardware/gpio.h"
#include "hardaware/adc.h"

#define RED_LED_PIN
#define BLUE_LED_PIN
#define YELLOW_LED_PIN

unit16_t result;
void vBlinkTask(){
    for(;;){
        gpio_put(RED_LED_PIN, 1);

        vTaskDelay(result);

        gpio_put(RED_LED_PIN,0);

        vTaskDelay(result);
        //printf("Tarea1");
    }
}
//Prender y apaga un LED  de manera independiente
// del potenciomentro con un tiempo de espera de 1 ms

void TaskBlink2(){ 
        for(;;){
        gpio_put(BLUE_LED_PIN,1);

        vTaskDelay(1000);

        gpio_put(BLUE_LED_PIN, 0);

        vTaskDelay(1000);
        //print("Tarea2")
    }
}



void TaskAnalogRead(){
    for(;;){
        const float conversion_factor = 3.3f / (1 << 12);
            result = adc_read(); //Lectura del potenciometro
        if(result*conversion_factor>2)
        {
            gpio_put(YELLOW_LED_PIN, 1);
            vTaskDelay(500);
        }
        else{
            gpio_put(YELLOW_LED_PIN, 0);
            vTaskDelay(500);
        }
        vTaskDelay(500);
    }
}


void main(){
    stdio_initall();
    //*****Entradas digitales*******
    gpio_init(RED_LED_PIN);
    gpio_set_dir(RED_LED_PIN, GPIO_OUT);

    gpio_init(BLUE_LED_PIN);
    gpio_set_dir(BLUE_LED_PIN, GPIO_OUT);

    gpio_init(YELLOW_LED_PIN);
    gpio_set_dir(YELLOW_LED_PIN, GPIO_OUT);

       //*****Entradas analogicas*******

    adc_init();
    adc_gpio_init(26);
    adc_select_input(0);

    //***************
    xTaskCreate(vBlinkTask, "Blink Task", 128,NULL,1,NULL);
    xTaskCreate(TaskBlink2, "Blink Task2", 128,NULL,1,NULL);
    xTaskCreate(TaskAnalogegRead, "AnalogRead1", 128,NULL,1,NULL);

    vTaskStartScheduler(); //Planificador de tareas priroridad 0 min - 3 maxima
}