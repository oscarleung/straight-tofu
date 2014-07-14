CXX = g++
CXXFLAGS = -Wall -std=c++0x -MMD -O -g `pkg-config gtkmm-2.4 --cflags --libs`
OBJECTS = Card.o Command.o launcher.o model.o view.o controller.o subject.o Game.o Deck.o Player.o HumanPlayer.o CompPlayer.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = straights

${EXEC} : ${OBJECTS}
	${CXX} ${OBJECTS} ${CXXFLAGS} -o ${EXEC}

clean :
	rm -rf ${DEPENDS} ${OBJECTS} ${EXEC}

-include ${DEPENDS}	# reads the .d files and reruns dependencies

