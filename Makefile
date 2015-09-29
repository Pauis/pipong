].SUFFIXES : .cpp .o

SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)

ifneq ($(CXX), g++)
ifneq ($(CXX), clang++)
CXX            = g++
endif
endif
ifeq ($(RPIGPIO), 1)
RPIGPIOFLAG    = -DUSINGRPIGPIO -lwiringPi
else
RPIGPIOFLAG    =
endif
MAINFLAG       = -o
TARGET         = pipong
DEPFLAG        = -MM
DEPENDFILE     = dependfile.tlist

$(TARGET) : $(OBJECTS)
	$(CXX) $(MAINFLAG) $(TARGET) $(OBJECTS) $(RPIGPIOFLAG)
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
