.SUFFIXES : .cpp .o

SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)

CC             = g++
MAINFLAG       = -o
ADDITIONALFLAG = -lwiringPi
TARGET         = pipong
DEPFLAG        = -MM
DEPENDFILE     = dependfile.tlist

$(TARGET) : $(OBJECTS)
	$(CC) $(MAINFLAG) $(TARGET) $(OBJECTS) $(ADDITIONALFLAG)
dep       :
	$(CC) $(DEPFLAG) $(SOURCES) > $(DEPENDFILE)
clean     :
ifneq ($(wildcard $(TARGET)),)
	rm $(TARGET)
endif
ifneq ($(wildcard *.o),)
	rm $(wildcard *.o)
endif
ifneq ($(wildcard $(DEPENDFILE)),)
	rm $(DEPENDFILE)
endif

-include $(DEPENDFILE)
