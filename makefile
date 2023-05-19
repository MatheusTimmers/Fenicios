main:
	@echo Compilando
	@g++ main.cpp File/File.cpp Utils/Utils.cpp Controller/Controller.cpp Monkey/Monkey.cpp UseCase/DistributeCocoNutsUseCase.cpp -o run.exe
	run

debug:
	@echo Compilando
	@g++ -g -std=c++0x main.cpp File/File.cpp Utils/Utils.cpp Controller/Controller.cpp Monkey/Monkey.cpp UseCase/DistributeCocoNutsUseCase.cpp -o run.exe
	run


run:
	@echo rodando
	./run.exe;
