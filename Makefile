OBJS := Hero.o JSON.o Monster.o main.o Map.o Game.o
CPPOBJS := Hero.cpp JSON.cpp Monster.cpp main.cpp Map.cpp Game.cpp
CC := g++-9
CFLAGS := -std=c++17 -Wall -Wextra -g -lstdc++fs
CH := cppcheck
CHFLAGS := --enable=warning --error-exitcode=2
CHAFLAGS := --enable=performance,style --output-file=artifact_cppcheck.txt
VFLAGS := --leak-check=full --error-exitcode=3
VJSONS := Units/scenario1.json
SUBDIR := test
CMAKEO := CMakeLists.txt

all_tests: linking  memory_leak_check

linking: $(OBJS)
	$(CC) $(CFLAGS) -o game $(OBJS)

Hero.o: Hero.cpp Hero.h JSON.h Monster.h
	$(CC) $(CFLAGS) -c Hero.cpp

Monster.o: Monster.cpp Monster.h JSON.h Damage.h 
	$(CC) $(CFLAGS) -c Monster.cpp

JSON.o: JSON.cpp JSON.h
	$(CC) $(CFLAGS) -c JSON.cpp

main.o: main.cpp  JSON.h Monster.h Game.h
	$(CC) $(CFLAGS) -c main.cpp

Map.o: Map.cpp Map.h	
	$(CC) $(CFLAGS) -c Map.cpp

Game.o: Game.cpp Game.h
	$(CC) $(CFLAGS) -c Game.cpp	
	
static_code_analysis:
	$(CH) $(CPPOBJS) $(CHFLAGS)
	$(CH) $(CPPOBJS) $(CHAFLAGS)

memory_leak_check: linking
	valgrind $(VFLAGS) ./game 

io_diff_check:
	python3 testrun.py

buildunittest:
	cmake $(SUBDIR)/$(CMAKEO) /
	$(MAKE) -C $(SUBDIR)
unittest: buildunittest
	$(SUBDIR)/runTests

documentation:
	doxygen doxconf