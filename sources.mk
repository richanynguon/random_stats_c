SOURCES=	\
	src/course1.c \
	src/main.c	\
	src/memory.c \
	src/stats.c	\
	src/data.c \
	src/interrupts_msp432p401r_gcc.c \
	src/startup_msp432p401r_gcc.c \
	src/system_msp432p401r.c 

INCLUDES=	\
	-Iinclude/common	\
	-Iinclude/msp432	\
	-Iinclude/CMSIS	