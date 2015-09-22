# Make hw_04.exe

hw_04.exe: f_01.cc f_00.cc
	gcc -O2 f_01.cc f_00.cc -o hw_04.exe -lm

f_01.o: f_01.cc
	gcc -c f_01.cc

f_00.o: f_00.cc
	gcc -c f_00.cc 
	
clean:
	rm -f f_00.o
	rm -f f_01.o

#
# end of file
