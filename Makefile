# # Compiler
# CXX = clang++

# # Compiler flags
# CXXFLAGS = -std=c++2a -gdwarf-4 -Wall -MMD -MP

# VALGRIND_FLAGS = --tool=memcheck -v --leak-check=full --show-leak-kinds=all --error-exitcode=99

# # List of source files
# SRCS = $(wildcard *.cpp)

# # List of object files
# OBJS = $(SRCS:.cpp=.o)

# # Executable name
# EXEC = main

# # Default target
# all: $(EXEC)

# # Rule to link the executable
# $(EXEC): $(OBJS)
# 	$(CXX) $(CXXFLAGS) -o $@ $^

# # Rule to compile source files into object files
# %.o: %.cpp %.hpp
# 	$(CXX) $(CXXFLAGS) -c $< -o $@

# # Clean up object files and executable
# clean:
# 	rm -f $(OBJS) $(EXEC)

# #valgrind check
# valgrind: $(EXEC)
# 	valgrind $(VALGRIND_FLAGS) ./$(EXEC) 2>&1

# # Phony targets
# .PHONY: all clean

# Compiler
CXX = clang++

# Compiler flags
CXXFLAGS = -std=c++2a -gdwarf-4 -Wall -MMD -MP

VALGRIND_FLAGS = --tool=memcheck -v --leak-check=full --show-leak-kinds=all --error-exitcode=99

# List of source files
SRCS = $(wildcard *.cpp)

# List of object files
OBJS = $(SRCS:.cpp=.o)

# List of dependency files
DEPS = $(SRCS:.cpp=.d)

# Executable name
EXEC = main

# Default target
all: $(EXEC)

# Rule to link the executable
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule to compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Include dependency files
-include $(DEPS)

# Clean up object files, dependency files, and executable
clean:
	rm -f $(OBJS) $(DEPS) $(EXEC)

# Valgrind check
valgrind: $(EXEC)
	valgrind $(VALGRIND_FLAGS) ./$(EXEC) 2>&1

# Phony targets
.PHONY: all clean valgrind