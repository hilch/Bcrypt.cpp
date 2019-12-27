CC = g++

INC_DIRS = ./include
INC_FLAGS = $(addprefix -I,$(INC_DIRS))
CPPFLAGS = $(INC_FLAGS)

CFILES = $(wildcard src/*.c)
CPPFILES = $(wildcard src/*.cpp)
OBJFILES = $(CFILES:.c=.h) $(CPPFILES:.cpp=.o)
OUT = libbcrypt.a

CFILES_TEST = $(wildcard test/*.c)
CPPFILES_TEST = $(wildcard test/*.cpp)
OUT_TEST = test/test

.PHONY: build clean test

$(OUT): $(OBJFILES)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CPPFLAGS) -c -o $@ $^

build: $(OUT)

test: build
	$(CC) $(CPPFLAGS) -L. -lbcrypt -o $(OUT_TEST) $(CFILES_TEST) $(CPPFILES_TEST)
	$(OUT_TEST)

clean:
	rm -f $(OBJFILES) $(OUT) $(OUT_TEST)

