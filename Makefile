.SUFFIXES:
.SUFFIXES: .o .cpp
#============================================================
TARGET	=  storage

C_SOURCES =  dict.cpp pad.cpp sha256.cpp op.cpp split_merge_func.cpp storage.cpp
C_OBJS     = dict.o pad.o sha256.o op.o split_merge_func.o storage.o
MY_INCLUDES = dict.h pad.h sha256.h split_merge_func.h uthash.h
# merg.h


CCX = g++
CXXFLAGS = -g -std=c++14
# -Wall

#============================================================
all: $(TARGET)

.o:.cpp	$(MY_INCLUDES)
	$(CCX)  -c  $(CXXFLAGS) $<  

$(TARGET) :   $(C_OBJS)
	$(CCX) $(CXXFLAGS)  $^ $(LIBDIRS)  -o $@

# Implicit rules: $@ = target name, $< = first prerequisite name, $^ = name of all prerequisites
#============================================================

ALL_SOURCES = Makefile $(C_SOURCES) $(MY_INCLUDES)

NOTES =
%= otherstuff.np 

clean:
	rm -f $(TARGET) $(C_OBJS) core 

tar: $(ALL_SOURCES) $(NOTES)
	tar cvf $(TARGET).tar $(ALL_SOURCES)  $(NOTES)

$(TARGET).ps: $(ALL SOURCES)
	enscript -pcode.ps $(ALL_SOURCES)


