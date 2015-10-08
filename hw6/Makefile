# Make hw_04.exe

hw_05.exe: print_signals.o devsig.o
	gcc devsig.o print_signals.o -o print_signals.exe -lm

devsig.o: devsig.cc
	gcc -c devsig.cc -o devsig.o -lm

print_signals.o: print_signals.cc
	gcc -c print_signals.cc -o print_signals.o -lm

clean:
	rm -f devsig.o print_signals.o

#
# end of file
