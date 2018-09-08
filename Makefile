CXX=g++-5
CXXFLAGS=-std=c++14 -Wall -MMD
OBJECTS=main.o player.o card.o minion.o singles.o board.o ascii_graphics.o gameover.o spell.o ssingles.o ritual.o rsingles.o absminion.o triggerminion.o enchantment.o decorator.o adenchant.o esingles.o activeminion.o normalenchant.o
DEPENDS=${OBJECTS:.o=.d}
EXEC=sorcery
${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} 
-include ${DEPENDS}
clean: rm *.o sorcery
.PHONY: clean

