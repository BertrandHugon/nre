
SOURCES := Droite.cpp DemiPlan.cpp Flago.cpp

# OBJETS := $(SOURCES:%.cpp,%.o)

OBJETS := Droite.o DemiPlan.o Flago.o

INCDIRS := -I/usr/include/opencv2/

BINAIRES := Flago

LIBRAIRIES := -lopencv_imgproc -lopencv_core -lc

LD_FLAGS := -static-libgcc -static-libstdc++

all: $(BINAIRES)

$(BINAIRES) : $(OBJETS)
	g++ $(OBJETS) $(LIBRAIRIES) $(LD_FLAGS) -o $@

%.o : %.cpp
	g++ -c $^ $(INCDIRS) -o $@

clean :
	rm --force $(OBJETS) $(BINAIRES)

.PHONY : clean

