

# Compiler
CXX = clang++

# Compiler flags
CXXFLAGS = -std=c++2a -gdwarf-4 -Wall -MMD -MP -Werror
VALGRIND_FLAGS = --tool=memcheck -v --leak-check=full --show-leak-kinds=all --error-exitcode=99

# List of source files

MAIN_SRCS = $(filter-out Test.cpp, $(wildcard *.cpp))
TEST_SRCS = $(filter-out main.cpp, $(wildcard *.cpp))

# List of object files
MAIN_OBJS = $(MAIN_SRCS:.cpp=.o)
TEST_OBJS = $(TEST_SRCS:.cpp=.o)

# List of dependency files
MAIN_DEPS = $(MAIN_SRCS:.cpp=.d)
TEST_DEPS = $(TEST_SRCS:.cpp=.d)

# Executable names
EXEC = main
TEST_EXEC = test_catan

# Default target
catan: $(EXEC)
	./$(EXEC)


# Rule to link the main executable
$(EXEC): $(MAIN_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule to link the test executable
$(TEST_EXEC): $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

test: $(TEST_EXEC)
	./$(TEST_EXEC)

# Rule to compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Include dependency files
-include $(MAIN_DEPS) $(TEST_DEPS)

# Clean up object files, dependency files, and executables
clean:
	rm -f *.o $(MAIN_DEPS) $(TEST_DEPS) $(EXEC) $(TEST_EXEC)

# Valgrind check for both executables
valgrind: $(EXEC) $(TEST_EXEC)
	valgrind $(VALGRIND_FLAGS) ./$(EXEC) 2>&1
	valgrind $(VALGRIND_FLAGS) ./$(TEST_EXEC) 2>&1

# Phony targets
.PHONY: catan test_catan clean valgrind