.SUFFIXES : .cpp .o

SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)

CXX            = g++
MAINFLAG       = -o
GPIOFLAG       = -lwiringPi
TARGET         = pipong
DEPFLAG        = -MM
DEPENDFILE     = dependfile.tlist

build : $(OBJECTS)
	$(CXX) $(MAINFLAG) $(TARGET) $(OBJECTS)
dep       :
	$(CXX) $(DEPFLAG) $(SOURCES) > $(DEPENDFILE)
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
