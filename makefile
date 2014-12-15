.PHONY: all run

CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS = Image.o main.o

LIBS =

INC = inc

TARGET = main

all: $(TARGET)

$(TARGET): dirs $(OBJS)
	$(CXX) $(addprefix obj/,$(OBJS)) $(LIBS) -o bin/$(TARGET)

%.o: src/%.cpp
	$(CXX) -I $(INC) -c $< -o obj/$@
	
run: $(TARGET)
	./bin/$(TARGET)

dirs:
	mkdir -p bin
	mkdir -p obj

clean:
	rm -rf obj bin
