all: prep dist

prep:
	if [ -d bin ]; then echo '' > /dev/null; else mkdir bin; fi
	if [ -d tmp ]; then echo '' > /dev/null; else mkdir tmp; fi

dist: prep hamming levenshtein
	gcc -g tmp/*.o src/dist.c -o bin/dist

hamming:
	gcc -c -g src/hamming.c -o tmp/hamming.o

levenshtein:
	gcc -c -g src/levenshtein.c -o tmp/levenshtein.o

clean:
	rm bin/* tmp/*.o

tests: prep hamming levenshtein
	gcc tmp/*.o test/levenshtein_test.c -o bin/test && bin/test
