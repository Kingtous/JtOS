#
# Makefile for Menu Program
#

CC_PTHREAD_FLAGS			 = -lpthread
CC_FLAGS                     = -c 
CC_OUTPUT_FLAGS				 = -o
CC                           = g++
RM                           = rm
RM_FLAGS                     = -f

FILES   =   linktable.cpp menu.cpp file_system.cpp fs.cpp jtime.cpp jsystem.cpp
TARGET  =   JtOS
OBJS    =   linktable.o  menu.o main.o fs.o jtime.o jsystem.o


all:	$(OBJS)
	$(CC) $(CC_OUTPUT_FLAGS) $(TARGET) $(OBJS) 
sys:
	if [ ! -d rootfs ]; then mkdir rootfs; fi
	g++ -o ./rootfs/init $(FILES) -m32 -static -lpthread
	make -C rootfs
.c.o:
	$(CC) $(CC_FLAGS) $<

clean:
	$(RM) $(RM_FLAGS)  $(OBJS) $(TARGET) *.bak
