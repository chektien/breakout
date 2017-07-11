SOURCES = main.cpp Game.cpp
FLAGS = -std=c++14
LDIRS = /usr/local/Cellar/sfml/2.4.2/lib 
IDIRS = /usr/local/Cellar/sfml/2.4.2/include 
LIBS = -lsfml-system -lsfml-graphics -lsfml-window -lsfml-audio

clean:
	rm *-app *.o *.obj

all:
	g++ -o breakout-app $(SOURCES) $(FLAGS) -L$(LDIRS) -I$(IDIRS) $(LIBS)
