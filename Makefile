
output: main.o Menu.o InputValidation.o Queue.o QueueNode.o Game.o Die.o Character.o Vampire.o Barbarian.o BlueMen.o Medusa.o HarryPotter.o
	g++ -std=c++0x -g -Wall -pedantic-errors main.o Menu.o InputValidation.o Queue.o QueueNode.o Game.o Die.o Character.o Vampire.o Barbarian.o BlueMen.o Medusa.o HarryPotter.o -o project4

main.o: main.cpp
	g++ -std=c++0x -g -Wall -pedantic-errors -c main.cpp

Menu.o: Menu.cpp
	g++ -std=c++0x -g -Wall -pedantic-errors -c Menu.cpp

Queue.o: Queue.cpp
	g++ -std=c++0x -g -Wall -pedantic-errors -c Queue.cpp

QueueNode.o: QueueNode.cpp
	g++ -std=c++0x -g -Wall -pedantic-errors -c QueueNode.cpp

InputValidation.o: InputValidation.cpp
	g++ -std=c++0x -g -Wall -pedantic-errors -c InputValidation.cpp

Game.o: Game.cpp
	g++ -std=c++0x -g -Wall -pedantic-errors -c Game.cpp

Die.o: Die.cpp
	g++ -std=c++0x -g -Wall -pedantic-errors -c Die.cpp

Character.o: Character.cpp
	g++ -std=c++0x -g -Wall -pedantic-errors -c Character.cpp

Vampire.o: Vampire.cpp
	g++ -std=c++0x -g -Wall -pedantic-errors -c Vampire.cpp

Barbarian.o: Barbarian.cpp
	g++ -std=c++0x -g -Wall -pedantic-errors -c Barbarian.cpp

BlueMen.o: BlueMen.cpp
	g++ -std=c++0x -g -Wall -pedantic-errors -c BlueMen.cpp

Medusa.o: Medusa.cpp
	g++ -std=c++0x -g -Wall -pedantic-errors -c Medusa.cpp

HarryPotter.o: HarryPotter.cpp
	g++ -std=c++0x -g -Wall -pedantic-errors -c HarryPotter.cpp

clean:
	rm *.o project4