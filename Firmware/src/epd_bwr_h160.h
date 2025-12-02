#pragma once

uint8_t EPD_BWR_h160_detect(void);
uint8_t EPD_BWR_h160_read_temp(void);
uint8_t EPD_BWR_h160_Display(unsigned char *image, int size, uint8_t full_or_partial);
uint8_t EPD_BWR_h160_Display_BWR(unsigned char *image, unsigned char *red_image, int size, uint8_t full_or_partial);
void EPD_BWR_h160_set_sleep(void);