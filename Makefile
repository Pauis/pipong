.SUFFIXES : .cpp .o

SOURCES = $(wildcard *.cpp)
ifneq ($(CXX), g++)
ifneq ($(CXX), clang++)
CXX            = g++
endif
endif
ifeq ($(RPIGPIO), 1)
MODENAME       = linux_rpigpio
SDEFINEFLAG    = -DLINUX_RPIGPIO
SLINKFLAG      = -lwiringPi
else
MODENAME       = posix
SDEFINEFLAG    = -DPOSIX
SLINKFLAG      =
endif

OBJDIR         = $(MODENAME)_out
OBJECTS        = $(SOURCES:%.cpp=$(OBJDIR)/%.o)
MAINFLAG       = -o
TARGETNAME     = pipong
TARGET         = $(OBJDIR)/$(TARGETNAME)
DEPFLAG        = -MM -MT
DEPENDFILE     = $(OBJDIR)/dependfile.tlist



$(TARGET)     : $(OBJECTS)
	@`[ -d $(OBJDIR) ] || mkdir $(OBJDIR)`
	$(CXX) $(MAINFLAG) $(TARGET) $(OBJECTS) $(SDEFINEFLAG) $(SLINKFLAG)

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
	$(CXX) -c $(MAINFLAG) $@ $< $(SDEFINEFLAG)

-include $(DEPENDFILE)
