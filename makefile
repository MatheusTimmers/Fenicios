main:
	@echo Compilando
<<<<<<< HEAD
	@g++ main.cpp File/File.cpp Utils/Utils.cpp Map/Map.cpp  Graph/Graph.cpp -o run.exe
	run

debug:
	@echo Compilando
	@g++ -g -std=c++0x main.cpp File/File.cpp Utils/Utils.cpp Map/Map.cpp  -o run.exe -o run.exe
=======
	@g++ main.cpp File/File.cpp Utils/Utils.cpp Map/Map.cpp Boat/Boat.cpp Graph/Graph.cpp -o run.exe

debug:
	@echo Compilando
	@g++ -g -std=c++0x main.cpp File/File.cpp Utils/Utils.cpp Map/Map.cpp Boat/Boat.cpp Graph/Graph.cpp -o run.exe
>>>>>>> ef73a9b308479d5a6fff47491273317303faca3b
	run


run:
	@echo rodando
	.\run.exe;

run2:
	@echo Compilando
	@g++ -g -std=c++0x  main.cpp File/File.cpp Utils/Utils.cpp Map/Map.cpp Graph/Graph.cpp -o run.exe
	./run.exe

