.SUFFIXES : .cpp .o

SOURCES = $(wildcard *.cpp)
ifneq ($(CXX), g++)
ifneq ($(CXX), clang++)
CXX            = g++
endif
endif
ifeq ($(RPIGPIO), 1)
OBJDIR         = rpigpio
RPIGPIODFLAG   = -DUSINGRPIGPIO
RPIGPIOLFLAG   = -lwiringPi
else
OBJDIR         = standard
RPIGPIODFLAG   =
RPIGPIOLFLAG   =
endif
OBJECTS = $(SOURCES:%.cpp=$(OBJDIR)/%.o)
MAINFLAG       = -o
TARGET         = $(OBJDIR)/pipong
DEPFLAG        = -MM -MT
DEPENDFILE     = $(OBJDIR)/dependfile.tlist

$(TARGET)     : $(OBJECTS)
	@`[ -d $(OBJDIR) ] || mkdir $(OBJDIR)`
	$(CXX) $(MAINFLAG) $(TARGET) $(OBJECTS) $(RPIGPIODFLAG) $(RPIGPIOLFLAG)
dep           :
ifeq ($(wildcard $(OBJDIR)),)
	mkdir $(OBJDIR)
endif
ifneq ($(wildcard $(DEPENDFILE)),)
	rm $(DEPENDFILE)
endif
	for FILE in $(SOURCES:%.cpp=%); do \
		$(CXX) $(DEPFLAG) $(OBJDIR)/$$FILE.o $$FILE.cpp >> $(DEPENDFILE); \
	done
clean         :
ifneq ($(wildcard $(OBJDIR)),)
	rm -r $(OBJDIR)
endif
$(OBJDIR)/%.o : %.cpp
	@`[ -d $(OBJDIR) ] || mkdir $(OBJDIR)`
	$(CXX) $(CFLAGS) $(RPIGPIODFLAG) -c $< -o $@

-include $(DEPENDFILE)
