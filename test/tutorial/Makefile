
SOURCES := Droite.cpp DemiPlan.cpp Flago.cpp

# OBJETS := $(SOURCES:%.cpp,%.o)

OBJETS := Droite.o DemiPlan.o Flago.o

INCDIRS := -I/usr/include/

BINAIRES := Flago

LIBRAIRIES := -lopencv_imgproc -lopencv_core -lopencv_highgui -lc

LD_FLAGS := -static-libgcc -static-libstdc++

all: $(BINAIRES)

test: $(BINAIRES)
	./$^

$(BINAIRES) : $(OBJETS)
	g++ $(OBJETS) $(LIBRAIRIES) $(LD_FLAGS) -o $@

%.o : %.cpp
	g++ -c $^ $(INCDIRS) -o $@

clean :
	rm --force $(OBJETS) $(BINAIRES)

.PHONY : clean

