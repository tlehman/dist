all: prep dist

prep:
	if [ -d bin ]; then echo '' > /dev/null; else mkdir bin; fi

dist: prep
	cc src/dist.c -o bin/dist

