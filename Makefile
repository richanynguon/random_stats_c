#------------------------------------------------------------------------------
# Generate Map and Executable with Make
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------
include sources.mk

TARGET=statsmachine
LINKER_FILE=msp432p401r.lds

LDFLAGS=-Wl, -Map=$(TARGET).map
CFLAGS=-Wall -Werror -g -O0 -std=c99 $(INCLUDES)

ifeq ($(PLATFORM), MSP432)
CPU=cortex-m4
ARCH=thump
SPECS=nosys.SPECS

CPP=-mcpu=$(CPU) -m$(ARCH) --specs=$(SPECS) -march=armv7e-m -DMSP432 -mfloat-abi=hard -mfpu=fpv4-sp-d16
LDFLAGS+=-T $(LINKER_FILE)

CC=arm-none-eabi-gcc
LD=arm-none-eabi-ld

else
CC=gcc
CPP=-DHOST

endif

CFLAGS+=$(CPP) $(SOURCES)

OBJS:=$(SRC:.c=.o)

.PHONY: build
build: $(TARGET).out
 
.PHONY: clean
clean:
	rm -f $(OBjS) $(TARGET).out $(TARGET).map

%.o: %.c
	$(CC) -c $< $(CFLAGS) -o $@ 

$(TARGET).out: $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(TARGET).out $(OBJS)