SRC := src
OBJ := obj
BIN := bin

CC := g++
CFLAGS := -std=c++0x -Wall -O3

headers := $(wildcard inc/*.h)
sources := $(wildcard src/*.cpp)
#objects := $(patsubst %.cpp, %.o, $(notdir $(sources)))
objects := $(addprefix $(OBJ)/, $(patsubst %.cpp,%.o,$(notdir $(sources))))

TARGET := $(BIN)/Scheck

all: $(TARGET)

$(TARGET): $(objects)
	$(CC) -I inc $(objects) -o $@

$(OBJ)/%.o: $(SRC)/%.cpp | dirs
	$(CC) -I inc $(CFLAGS) -c $< -o $@

dirs:
	-@mkdir -p $(OBJ) $(BIN)

clean:
	-rm $(OBJ)/*.o $(TARGET)

run: $(TARGET)
	./$(TARGET)