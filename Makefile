all: prep dist

prep:
	if [ -d bin ]; then echo '' > /dev/null; else mkdir bin; fi
	if [ -d tmp ]; then echo '' > /dev/null; else mkdir tmp; fi

dist: prep hamming levenshtein
	cc tmp/*.o src/dist.c -o bin/dist

hamming:
	cc -c src/hamming.c -o tmp/hamming.o

levenshtein:
	cc -c src/levenshtein.c -o tmp/levenshtein.o

clean:
	rm bin/* tmp/*.o

tests: prep hamming levenshtein
	cc tmp/*.o test/levenshtein_test.c -o bin/test && bin/test
