CC      := clang
CFLAGS  := -g -Wall -O2
TFLAGS  := $(CFLAGS) -DCMP_TST
OUT_DIR := ./target
BIN_DIR := $(OUT_DIR)/bin
OBJ_DIR := $(OUT_DIR)/obj
SRC_DIR := ./src
#DEPS    := $(SRC_DIR)/llist.h $(SRC_DIR)/result.h
DEPS    := $(SRC_DIR)/llist.c $(SRC_DIR)/result.c
SRCS    := $(wildcard $(SRC_DIR)/*.c)
OBJS    := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
RUN     := $(patsubst $(SRC_DIR)/%.c,%,$(SRCS))
#TDEPS   := $(DEPS) $(SRC_DIR)/test.h
TDEPS   := $(DEPS) $(SRC_DIR)/test.c
TOBJS   := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/test_%.o,$(SRCS))
TRUN    := $(patsubst %,test_%,$(RUN))

$(RUN): %: $(OBJ_DIR)/%.o
	$(CC) $(CFLAGS) $^ -o $(BIN_DIR)/$@
	$(BIN_DIR)/$@

$(OBJS): $(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

$(TRUN): %: $(OBJ_DIR)/%.o $(TDOBJS)
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^ && $(BIN_DIR)/$@

$(TOBJS): $(OBJ_DIR)/test_%.o:  $(SRC_DIR)/%.c
	$(CC) $(TFLAGS) -c $< -o $@

clean:
	rm -rf $(OUT_DIR)
	mkdir -p $(BIN_DIR)
	mkdir -p $(OBJ_DIR)

list_srcs:
	echo "$(SRCS)"

list_objs:
	echo "$(OBJS)"

list_tgts:
	echo "$(RUN)"
