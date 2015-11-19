CC = g++
OBJ = sort_comparison.o AllSort.o
CFLAG = -std=gnu++11 -I .

sort_comparison: $(OBJ)
	${CC} -o $@ $^

%.o: %.cxx
	$(CC)  -c -o $@ $^ $(CFLAG)

clean:
	rm *.o sort_comparison
