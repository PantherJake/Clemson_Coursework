# Config, just variables
CC=g++
CFLAGS=-Wall -g -fopenmp
LFLAGS=-lm -fopenmp
TARGET=out
file1 =
file2 = 
# Generate source and object lists, and string vars
C_SRCS := \
 $(wildcard *.cpp) \
 $(wildcard src/*.cpp) \
 $(wildcard src/**/*.cpp)\
 $(wildcard src/***/**/*.cpp)
HDRS := \
 $(wildcard *.h) \
 $(wildcard src/*.h) \
 $(wildcard src/**/*.h)\
 $(wildcard src/***/**/*.h)

OBJS := $(patsubst %.cpp, bin/%.o, $(wildcard *.cpp))

OBJS += $(filter %.o, $(patsubst src/%.cpp, bin/%.o, $(C_SRCS)))
# default target
all: build
	@echo "Found" $(HDRS)
	@echo "Found" $(C_SRCS)
	@echo "All Done!"
# Link all built objects
build: $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(LFLAGS)
# special build rule
%.o: %.c $(HDRS)
	$(CC) $(CFLAGS) -c $< -o $@

# Catch root directory src files
bin/%.o: %.cpp $(HDRS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@
# Catch all nested directory files
bin/%.o: src/%.cpp $(HDRS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET)
	rm -rf bin

run: build
	./$(TARGET) $(file1) $(file2) 
which:
	@echo "Input 1: $(file1)"
	@echo "Input 2: $(file2)" 

