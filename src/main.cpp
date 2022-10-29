#include <Arduino.h>
#include <STM32FreeRTOS.h>

static portTASK_FUNCTION_PROTO(vBlinky1, pvParameters);
static portTASK_FUNCTION_PROTO(vBlinky2, pvParameters);
void vvBlinky1TaskCreate()
{
  pinMode(PA12,OUTPUT);
  xTaskCreate(vBlinky1,
              "TestTask",
              configMINIMAL_STACK_SIZE,
              NULL,
              tskIDLE_PRIORITY,
              NULL);
}

void vvBlinky2TaskCreate()
{
  pinMode(PC7,OUTPUT);
  xTaskCreate(vBlinky2,
              "TestTask",
              configMINIMAL_STACK_SIZE,
              NULL,
              tskIDLE_PRIORITY,
              NULL);
}

void setup() {
  // put your setup code here, to run once:
  vvBlinky1TaskCreate();
  vvBlinky2TaskCreate();
  vTaskStartScheduler();
}

void loop() {
  // put your main code here, to run repeatedly:
}

static portTASK_FUNCTION(vBlinky1, pvParameters)
{
  for (;;)
  {
    digitalWrite(PA12,LOW);
    delay(250);
    digitalWrite(PA12,HIGH);
    delay(250);
  }
}

static portTASK_FUNCTION(vBlinky2, pvParameters)
{
  /* Block for 500ms. */
  const TickType_t xDelay = 500 / portTICK_PERIOD_MS;
  for (;;)
  {
    digitalWrite(PC7,LOW);
    vTaskDelay( xDelay );
    digitalWrite(PC7,HIGH);
    vTaskDelay( xDelay );
  }
}