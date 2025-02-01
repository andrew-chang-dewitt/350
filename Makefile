CC      := clang
CFLAGS  := -g -Wall -O2
TFLAGS  := $(CFLAGS) -DCMP_TST
OUT_DIR := ./target
BIN_DIR := $(OUT_DIR)/bin
OBJ_DIR := $(OUT_DIR)/obj
SRC_DIR := ./src
SRCS    := $(wildcard $(SRC_DIR)/*.c)
OBJS    := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
RUN     := $(patsubst $(SRC_DIR)/%.c,%,$(SRCS))
TOBJS   := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/test_%.o,$(SRCS))
TRUN   := $(patsubst %,test_%,$(RUN))
TDEPS   := $(SRC_DIR)/test.h

$(RUN): %: $(OBJ_DIR)/%.o
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^ && $(BIN_DIR)/$@

$(OBJS): $(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# $(TSRCS): test_%: $(OBJ_DIR)/test_%.o
# 	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $(filter-out %.h,$^) && $(BIN_DIR)/$@
$(TRUN): %: $(OBJ_DIR)/%.o
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^ && $(BIN_DIR)/$@

$(TOBJS): $(OBJ_DIR)/test_%.o:  $(SRC_DIR)/%.c $(TDEPS)
	$(CC) $(TFLAGS) -c $< -o $@

clean:
	rm -rf $(OUT_DIR)
	mkdir -p $(BIN_DIR)
	mkdir -p $(OBJ_DIR)

list_srcs:
	echo "$(SRCS)"

list_tgts:
	echo "$(TGTS)"

list_objs:
	echo "$(OBJS)"

list_test:
	echo "$(TSRCS)"
