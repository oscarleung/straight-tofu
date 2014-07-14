CXX = g++
CXXFLAGS = -Wall -std=c++0x -MMD `pkg-config gtkmm-2.4 --cflags`
LDFLAGS='pkg-config gtkmm-2.4 --libs`
OBJECTS = Card.o Command.o launcher.o view.o model.o controller.o subject.o DeckGUI.o Game.o Deck.o Player.o HumanPlayer.o CompPlayer.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = straights

${EXEC} : ${OBJECTS}
	${CXX} ${CXXFLAGS} ${LDFLAGS} ${OBJECTS} -o ${EXEC}

clean :
	rm -rf ${DEPENDS} ${OBJECTS} ${EXEC}

-include ${DEPENDS}	# reads the .d files and reruns dependencies

