#------------------------------------------------------------------------------
# Generate Map and Executable with Make
#
# Use: make [TARGET] PLATFORM=[PLATFORM-OVERRIDES]
#
# Build Targets:
#      stats.c - Statistics tool to print basic information from a data set
#
# Platform Overrides:
#		DEFAULT - DHOST Current platform
#		MSP432
#
#------------------------------------------------------------------------------
include sources.mk

# Name of output executable
TARGET=statsmachine
LINKER_FILE=msp432p401r.lds

# Initial Creations of Linker Flags and Compiler Flags
LDFLAGS=-Wl, -Map=$(TARGET).map
CFLAGS=-Wall -Werror -g -O0 -std=c99 $(INCLUDES)

# Platform Override
# ifeq = if equipped
ifeq ($(PLATFORM), MSP432)

# Platform Override Specs
CPU=cortex-m4
ARCH=thump
SPECS=nosys.specs

# Platform Override Specific Specs Flags
CPP=-mcpu=$(CPU) -m$(ARCH) --specs=$(SPECS) -march=armv7e-m -DMSP432 -mfloat-abi=hard -mfpu=fpv4-sp-d16
LDFLAGS+=-T $(LINKER_FILE)

# Platform Override Compiler and Linker
CC=arm-none-eabi-gcc
LD=arm-none-eabi-ld

else
# Default Compiler
CC=gcc
# Default Specs Flag
CPP=-DHOST

endif

# Depending on conditional equipment will add on appropriate flags
CFLAGS+=$(CPP) $(SOURCES)

# Generates list of object variables based of .c files
OBJS:=$(SRC:.c=.o)

# .PHONY explicitly tell Make they're not associated with files but
# would like to execute this specific command
.PHONY: build
build: $(TARGET).out
 
.PHONY: clean
clean:
	rm -f $(OBjS) $(TARGET).out $(TARGET).map

# % Pattern Matcher >> ThisFile.o: ThisFile.c
# C to ASM Files
%.o: %.c
	$(CC) -c $< $(CFLAGS) -o $@ 

# ASM to executable also generating a map
$(TARGET).out: $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(TARGET).out $(OBJS)