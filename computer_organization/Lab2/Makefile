# Declaration of the makefile variables. These variables are used in place of
# common keywords that the makefile will use like compile (gcc)
CC=gcc
CFLAGS=-Wall -g
LFLAGS=-lm
TARGET=out

# A wildcard is used to hold a place for the file that will take its place.
# The makefile searches for .c files to pickup, files outside of the src subdirectory
# and files inside. C_SRCS for C source code.
C_SRCS := \
	$(wildcard *.c) \
	$(wildcard src/*.c) \
	$(wildcard src/**/*.c)

# A wildcard is used to hold a place for the file that will take its place.
# The makefile searches for .h files to pickup, files outside of the src subdirectory
# and files inside. HDRS for header files.
HDRS := \
	$(wildcard *.h) \
	$(wildcard src/*.h) \
	$(wildcard src/**/*.h) \

# patsubst operation here takes .c files found in the parent subdirectory
# and turns them into .o files. .o files are the last files created in the
# preprocesing phase right before the executable is created.
OBJS := $(patsubst %.c, bin/%.o, $(wildcard *.c))
OBJS += $(filter %.o, $(patsubst src/%.c, bin/%.o, $(C_SRCS)))

# This target executes at the end of make after all other targets have been
# successfully gone through, and indicates the user that it is ready to run.
all: build
	@echo "All Done!"

# This target compiles the program using multiple variables created
# previously. This action generates the executable needed to run the program
build: $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(LFLAGS)

# These are special build rules that place the .o files into a /bin directory
# keeping track of all of them. This step generates a list of strings to change
# the tail of the file from .c to .o.
# This compile step is for the driver since it is not inside the src/ directory.
bin/%.o: %.c $(HDRS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# This build rule is similar to the last one just applied to the .c files inside
# of the src/ file.
bin/%.o: src/%.c $(HDRS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# This target removes the executable file and the .o files from the /bin directory.
# Called clean because each time the program runs another version of this
# file will be created.
clean:
	rm -f $(TARGET)
	rm -rf bin

# This target runs the executable file. Thus beginning the program. These
# previous build target compiles creating the TARGET executable file and
# run executes it.
run: build
	./$(TARGET)

# This target finds the necessary files in their directories and displays them
# so that the user can see what files are being compiled.
which:
	@echo "FOUND SOURCES: ${C_SRCS}"
	@echo "FOUND HEADERS: ${HDRS}"
	@echo "FOUND OBJS: ${OBJS}"
