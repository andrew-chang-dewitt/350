CC      = clang
CFLAGS  = -g -Wall -O2
OUT_DIR = target


2_2_calories-cmp: src/2_2_calories.o
	$(CC) $(CFLAGS) -o $(OUT_DIR)/2_2_calories src/2_2_calories.o

2_2_calories: 2_2_calories-cmp
	echo "1 2 3 4" | ./$(OUT_DIR)/2_2_calories

clean:
	rm -f $(OUT_DIR)
	mkdir $(OUT_DIR)
