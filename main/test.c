#include <string.h>

#include "board_gpio.h"
#include "board_mfrc522.h"
#include "board_spi.h"
#include "esp_err.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "nvs_flash.h"

static const char *TAG = "rc522";

static void
monitor_task(void *arg)
{
    
    while (1) // 任务都是一个无限循环，不能返回
    {
        uint8_t card[4];
        MFRC522_ReadCardSerialNo(card);
        ESP_LOGI(TAG, "card: %02x%02x%02x%02x", card[0], card[1], card[2],
                 card[3]);
        vTaskDelay(500 / portTICK_PERIOD_MS); // 100ms
    }
}

/**@brief Application main function.
 */
void app_main(void)
{
    ESP_ERROR_CHECK(nvs_flash_init());

    NFC_GPIO_Init();
    NFC_SPI_Init();
    MFRC522_Init();

    /*-------------------------- 创建线程 ---------------------------*/
    xTaskCreate(monitor_task, "monitor_task", 2048, NULL, 4, NULL);
}

// ESP_LOGI(TAG, "reg: %02x" ,readRawRc(Status1Reg));
// ESP_LOGI(TAG, "reg: %02x" ,readRawRc(Status2Reg));
// ESP_LOGI(TAG, "reg: %02x" ,readRawRc(WaterLevelReg));
