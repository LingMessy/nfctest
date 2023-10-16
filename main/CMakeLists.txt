# idf_component_register(SRCS "main.c" "rc522.c" "*.c"
#                     INCLUDE_DIRS ".")

idf_component_register(SRCS "test.c" "board_gpio.c" "board_mfrc522.c" "board_spi.c"
                    INCLUDE_DIRS ".")
