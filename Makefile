CC = g++

INC_DIRS = ./include
INC_FLAGS = $(addprefix -I,$(INC_DIRS))
CPPFLAGS = $(INC_FLAGS)

CPPFILES = $(wildcard src/*.cpp)
OBJFILES = $(CPPFILES:.cpp=.o)
OUT = libbcryptcpp.a

CPPFILES_TEST = $(wildcard test/*.cpp)
OUT_TEST = test/test

.PHONY: build clean test

$(OUT): $(OBJFILES)
	ar rcs $@ $^

%.o: %.cpp
	$(CC) $(CPPFLAGS) -c -o $@ $^

build: $(OUT)

test: build
	$(CC) $(CPPFLAGS) -L. -o $(OUT_TEST) $(CPPFILES_TEST) -lbcryptcpp -lstdc++
	$(OUT_TEST)

clean:
	rm -f $(OBJFILES) $(OUT) $(OUT_TEST)

