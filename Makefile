OBJS := player.o parser.o main.o
CPPOBJS := player.cpp parser.cpp main.cpp
CC := g++
CFLAGS := -std=c++17 -Wall -Wextra -g
CH := cppcheck
CHFLAGS := --enable=warning --error-exitcode=2
CHAFLAGS := --enable=performance,style --output-file=artifact_cppcheck.txt
VFLAGS := --leak-check=full --error-exitcode=3
VJSONS := Units/Kakarott.json Units/Maple.json


all_tests: linking static_code_analysis cppcheck_style_and_performance memory_leak_check correct_io_diff_check

linking: $(OBJS)
	$(CC) $(CFLAGS) -o game $(OBJS)

player.o: player.cpp player.h parser.h
	$(CC) $(CFLAGS) -c player.cpp

parser.o: parser.cpp parser.h BadJsonException.h
	$(CC) $(CFLAGS) -c parser.cpp

main.o: main.cpp player.h
	$(CC) $(CFLAGS) -c main.cpp

static_code_analysis:
	$(CH) $(CPPOBJS) $(CHFLAGS)
	$(CH) $(CPPOBJS) $(CHAFLAGS)

memory_leak_check: linking
	valgrind $(VFLAGS) ./game $(VJSONS)

io_diff_check:
	python3 testrun.py

unittest:
	cd test && ./runTests

documentation:
	doxygen doxconf