
SOURCES := Droite.cpp DemiPlan.cpp

# OBJETS := $(SOURCES:%.cpp,%.o)

OBJETS := Droite.o DemiPlan.o

%.o : %.cpp
	g++ -c $^ -o $@

clean : $(OBJETS)
	rm --force $^

.PHONY : clean

