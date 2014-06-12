CXX = g++
CXXFLAGS = -Wall -std=c++0x -MMD
OBJECTS = Card.o Command.o shuffle.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = Passwords

${EXEC} : ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

clean :
	rm -rf ${DEPENDS} ${OBJECTS} ${EXEC}

-include ${DEPENDS}	# reads the .d files and reruns dependencies

