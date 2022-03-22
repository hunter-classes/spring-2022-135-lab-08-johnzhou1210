main: main.o funcs.o imageio.o
	g++ -o main main.o funcs.o imageio.o

sample: sample.o imageio.o
	g++ -o sample sample.o imageio.o

sample.o: sample.cpp imageio.h

imageio.o: imageio.cpp imageio.h

main.o: main.cpp imageio.h

funcs.o: funcs.cpp imageio.h

clean:
	rm -f sample.o imageio.o main.o funcs.o
