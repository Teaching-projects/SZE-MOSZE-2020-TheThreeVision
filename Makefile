OBJS := Hero.o JSON.o Monster.o main.o Map.o Game.o SVGRenderer.o TextRenderer.o
CPPOBJS := Hero.cpp JSON.cpp Monster.cpp main.cpp Map.cpp Game.cpp SVGRenderer.cpp TextRenderer.cpp
CC := g++-9
CFLAGS := -std=c++17 -Wall -Wextra -g -lstdc++fs
CH := cppcheck --enable=all --suppress=missingIncludeSystem
CHFLAGS := --enable=warning --error-exitcode=2
CHAFLAGS := --enable=performance,style --output-file=artifact_cppcheck.txt
VFLAGS := --leak-check=full --error-exitcode=3
VJSONS := Units/scenario1.json
SUBDIR := test
CMAKEO := CMakeLists.txt
SUBDIR2 := Units
CONF := --check-config

all_tests: linking static_code_analysis memory_leak_check io_diff_check

linking: $(OBJS)
	$(CC) $(CFLAGS) -o main $(OBJS)

Hero.o: Hero.cpp Hero.h JSON.h Monster.h Damage.h
	$(CC) $(CFLAGS) -c Hero.cpp

Monster.o: Monster.cpp Monster.h JSON.h Damage.h 
	$(CC) $(CFLAGS) -c Monster.cpp

JSON.o: JSON.cpp JSON.h
	$(CC) $(CFLAGS) -c JSON.cpp

main.o: main.cpp  JSON.h Monster.h Game.h SVGRenderer.h TextRenderer.h
	$(CC) $(CFLAGS) -c main.cpp

Map.o: Map.cpp Map.h	
	$(CC) $(CFLAGS) -c Map.cpp

Game.o: Game.cpp Game.h Renderer.h
	$(CC) $(CFLAGS) -c Game.cpp	

SVGRenderer.o: SVGRenderer.cpp SVGRenderer.h Renderer.h Game.h
	$(CC) $(CFLAGS) -c SVGRenderer.cpp	

TextRenderer.o: TextRenderer.cpp TextRenderer.h Renderer.h Game.h
	$(CC) $(CFLAGS) -c TextRenderer.cpp	

static_code_analysis:
	$(CH) $(CPPOBJS) $(CHFLAGS) $(CONF)
	$(CH) $(CPPOBJS) $(CHAFLAGS)

memory_leak_check: linking
	valgrind $(VFLAGS) cat inputdata.txt | ./main Units/preparedgame.txt >> output2.txt

io_diff_check:
	$ cmp output1.txt output2.txt

buildunittest:
	cmake $(SUBDIR)/$(CMAKEO) /
	$(MAKE) -C $(SUBDIR)
unittest: buildunittest
	$(SUBDIR)/runTests

documentation:
	doxygen doxconf