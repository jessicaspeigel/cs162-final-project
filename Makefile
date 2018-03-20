
output: main.o Menu.o InputValidation.o AdvisorsOffice.o AsciiArt.o Bar.o Cafe.o Classroom.o ComputerLab.o Game.o Gym.o Inventory.o InventoryItem.o Library.o Player.o Quad.o Space.o TAOffice.o
	g++ -std=c++0x -g -Wall -pedantic-errors main.o Menu.o InputValidation.o AdvisorsOffice.o AsciiArt.o Bar.o Cafe.o Classroom.o ComputerLab.o Game.o Gym.o Inventory.o InventoryItem.o Library.o Player.o Quad.o Space.o TAOffice.o -o finalProject

main.o: main.cpp
	g++ -std=c++0x -g -Wall -pedantic-errors -c main.cpp

Menu.o: Menu.cpp
	g++ -std=c++0x -g -Wall -pedantic-errors -c Menu.cpp

InputValidation.o: InputValidation.cpp
	g++ -std=c++0x -g -Wall -pedantic-errors -c InputValidation.cpp

Game.o: Game.cpp
	g++ -std=c++0x -g -Wall -pedantic-errors -c Game.cpp

AdvisorsOffice.o: AdvisorsOffice.cpp
	g++ -std=c++0x -g -Wall -pedantic-errors -c AdvisorsOffice.cpp

AsciiArt.o: AsciiArt.cpp
	g++ -std=c++0x -g -Wall -pedantic-errors -c AsciiArt.cpp

Bar.o: Bar.cpp
	g++ -std=c++0x -g -Wall -pedantic-errors -c Bar.cpp

Cafe.o: Cafe.cpp
	g++ -std=c++0x -g -Wall -pedantic-errors -c Cafe.cpp

Classroom.o: Classroom.cpp
	g++ -std=c++0x -g -Wall -pedantic-errors -c Classroom.cpp

ComputerLab.o: ComputerLab.cpp
	g++ -std=c++0x -g -Wall -pedantic-errors -c ComputerLab.cpp

Gym.o: Gym.cpp
	g++ -std=c++0x -g -Wall -pedantic-errors -c Gym.cpp

Inventory.o: Inventory.cpp
	g++ -std=c++0x -g -Wall -pedantic-errors -c Inventory.cpp

InventoryItem.o: InventoryItem.cpp
	g++ -std=c++0x -g -Wall -pedantic-errors -c InventoryItem.cpp

Library.o: Library.cpp
	g++ -std=c++0x -g -Wall -pedantic-errors -c Library.cpp

Player.o: Player.cpp
	g++ -std=c++0x -g -Wall -pedantic-errors -c Player.cpp

Quad.o: Quad.cpp
	g++ -std=c++0x -g -Wall -pedantic-errors -c Quad.cpp

Space.o: Space.cpp
	g++ -std=c++0x -g -Wall -pedantic-errors -c Space.cpp

TAOffice.o: TAOffice.cpp
	g++ -std=c++0x -g -Wall -pedantic-errors -c TAOffice.cpp

clean:
	rm *.o finalProject