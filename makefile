CXX = clang++
CXXFLAGS = -Wall -Wextra -std=c++23 -I./include -MMD -MP
TARGET = db

# Разделяем исходники и объекты
SRC_DIR = src
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(SOURCES:.cpp=.o)
DEPFILES = $(SOURCES:.cpp=.d)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@echo "Linking..."
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	@echo "Compiling $< ..."
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Умное включение зависимостей
-include $(DEPFILES)

clean:
	@rm -f $(TARGET) $(OBJECTS) $(DEPFILES)

debug: CXXFLAGS += -g -O0 -DDEBUG
debug: all

release: CXXFLAGS += -O3 -DNDEBUG
release: all

.PHONY: all clean debug release
