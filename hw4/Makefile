# Make hw_04.exe

hw_04.exe: ece_3822_add_sin.o f_00.o
	gcc -O2 ece_3822_add_sin.o f_00.o -o hw_04.exe -lm

ece_3822_add_sin.o: ece_3822_add_sin.cc
	gcc -c ece_3822_add_sin.cc

f_00.o: f_00.cc
	gcc -c f_00.cc 
	
clean:
	rm -f f_00.o
	rm -f ece_3822_add_sin.o

#
# end of file
