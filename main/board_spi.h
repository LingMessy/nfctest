#ifndef _BOARD_SPI_H_
#define _BOARD_SPI_H_

/*********************************************************************
 * INCLUDES
 */
#include "driver/gpio.h"

/*********************************************************************
 * DEFINITIONS
 */
#define NFC_SPI_MISO_PIN        GPIO_NUM_19
#define NFC_SPI_MOSI_PIN        GPIO_NUM_23
#define NFC_SPI_SCLK_PIN        GPIO_NUM_18
#define NFC_SPI_CS_PIN          GPIO_NUM_5

#define DMA_CHAN                2

#define SPI_CS_LOW              gpio_set_level(NFC_SPI_CS_PIN, 0)
#define SPI_CS_HIGH             gpio_set_level(NFC_SPI_CS_PIN, 1)

/*********************************************************************
 * API FUNCTIONS
 */
void NFC_SPI_Init(void);
void NFC_SPI_Write(uint8_t *pData, uint32_t dataLen);
void NFC_SPI_Read(uint8_t *pData, uint32_t dataLen);

#endif /* _BOARD_SPI_H_ */

