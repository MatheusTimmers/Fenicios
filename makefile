main:
	@echo Compilando
	@g++ main.cpp File/File.cpp Utils/Utils.cpp Map/Map.cpp Boat/Boat.cpp -o run.exe
	run

debug:
	@echo Compilando
	@g++ -g -std=c++0x main.cpp File/File.cpp Utils/Utils.cpp Map/Map.cpp Boat/Boat.cpp -o run.exe -o run.exe
	run


run:
	@echo rodando
	./run.exe;

mainLinux:
	@echo Compilando
	@g++ main.cpp File/File.cpp Utils/Utils.cpp Map/Map.cpp Boat/Boat.cpp Graph/Graph.cpp -o run.exe
	./run.exe

