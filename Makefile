
NAME = dht-test
BOARD = nodemcu
SERIAL_PORT = /dev/ttyUSB0
BAUDRATE = 76800

CDEFS += \
  CONFIG_MINIMAL_SYSTEM=1 \
  CONFIG_PIN=1 \
  CONFIG_DHT=1

MAIN_C = src/main.c

include $(SIMBA_ROOT)/make/app.mk
