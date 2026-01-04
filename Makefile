CC      := gcc
CXX     := g++
AR      := ar
CFLAGS  := -std=gnu99 -O2 -Wall -Wextra
CXXFLAGS:= -std=c++11 -O2 -Wall -Wextra

SRC := src
BLD := build
OBJ := $(BLD)/obj
BIN := $(BLD)/bin

$(shell mkdir -p $(OBJ) $(BIN))

.PHONY: all clean
all: $(BIN)/8cc $(BIN)/eli $(BIN)/elc

IR_SRCS := $(SRC)/ir/ir.c $(SRC)/ir/table.c
IR_OBJS := $(IR_SRCS:$(SRC)/%.c=$(OBJ)/%.o)
IR_LIB  := $(BIN)/libir.a

$(IR_LIB): $(IR_OBJS)
	$(AR) rcs $@ $^

$(OBJ)/%.o: $(SRC)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(SRC) -c $< -o $@

8CC_SRCS := $(filter-out $(SRC)/8cc/utiltest.c, $(wildcard $(SRC)/8cc/*.c))
8CC_OBJS := $(8CC_SRCS:$(SRC)/%.c=$(OBJ)/%.o)
8CC_BIN  := $(BIN)/8cc

$(8CC_BIN): $(8CC_OBJS)
	$(CC) $^ -o $@

ELI_SRC := $(SRC)/ir/eli.c
ELI_BIN := $(BIN)/eli

$(ELI_BIN): $(IR_LIB) $(ELI_SRC)
	$(CC) $(CFLAGS) -I$(SRC) $(ELI_SRC) $(IR_LIB) -o $@

ELC_SRCS := $(wildcard $(SRC)/target/*.c)
ELC_OBJS := $(ELC_SRCS:$(SRC)/%.c=$(OBJ)/%.o)
ELC_BIN  := $(BIN)/elc

$(ELC_BIN): $(IR_LIB) $(ELC_OBJS)
	$(CC) $(CFLAGS) $(ELC_OBJS) $(IR_LIB) -o $@

clean:
	rm -rf build
