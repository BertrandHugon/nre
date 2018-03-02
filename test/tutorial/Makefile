
SOURCES := Droite.cpp DemiPlan.cpp Flago.cpp

# OBJETS := $(SOURCES:%.cpp,%.o)

OBJETS := Droite.o DemiPlan.o Flago.o

INCDIRS := -I/usr/include/opencv2/

BINAIRES := Flago

all: $(BINAIRES)

$(BINAIRES) : $(OBJETS)
	g++ $(OBJETS) -o $@

%.o : %.cpp
	g++ -c $^ $(INCDIRS) -o $@

clean :
	rm --force $(OBJETS) $(BINAIRES)

.PHONY : clean

