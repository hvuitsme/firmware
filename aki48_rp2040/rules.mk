BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no       # Enable keyboard RGB underglow
RGB_MATRIX_ENABLE = yes
WS2812_DRIVER = vendor
#Encoder
ENCODER_ENABLE = yes
ENCODER_MAP_ENABLE = yes
#OLED
OLED_DRIVER_ENABLE = yes
#Matrix
CUSTOM_MATRIX = lite
SRC += matrix.c
