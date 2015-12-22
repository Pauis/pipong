.SUFFIXES : .cpp .o

SOURCES = $(wildcard *.cpp)
ifeq ($(CXX),)
CXX            = g++
endif
MODENAME       = posix
SDEFINEFLAG    = -DTARGET_IS_POSIX
SLINKFLAG      =

OBJDIRNAME     = $(MODENAME)_out
OBJECTS        = $(SOURCES:%.cpp=$(OBJDIRNAME)/%.o)
MAINFLAG       = -o
TARGETNAME     = pipong
TARGET         = $(OBJDIRNAME)/$(TARGETNAME)
DEPFLAG        = -MM -MT
DEPENDFILE     = $(OBJDIRNAME)/dependfile.tlist



$(TARGET)     : $(OBJECTS)
	@`[ -d $(OBJDIRNAME) ] || mkdir $(OBJDIRNAME)`
	$(CXX) $(MAINFLAG) $(TARGET) $(OBJECTS) $(SDEFINEFLAG) $(SLINKFLAG)

dep           :
ifeq ($(wildcard $(OBJDIRNAME)),)
	mkdir $(OBJDIRNAME)
endif
ifneq ($(wildcard $(DEPENDFILE)),)
	rm $(DEPENDFILE)
endif
	for FILE in $(SOURCES:%.cpp=%); do \
		$(CXX) $(DEPFLAG) $(OBJDIRNAME)/$$FILE.o $$FILE.cpp >> $(DEPENDFILE); \
	done

clean         :
ifneq ($(wildcard $(OBJDIRNAME)),)
	rm -r $(OBJDIRNAME)
endif

$(OBJDIRNAME)/%.o : %.cpp
	@`[ -d $(OBJDIRNAME) ] || mkdir $(OBJDIRNAME)`
	$(CXX) -c $(MAINFLAG) $@ $< $(SDEFINEFLAG)

-include $(DEPENDFILE)
