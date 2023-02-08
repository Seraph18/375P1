# Specifiy the target
all:	main

# Specify the object files that the target depends on
# Also specify the object files needed to create the executable
main:	main.o  
	g++ main.o -o main.exe

# Specify how the object files should be created from source files

main.o:	main.cpp
	g++ -c main.cpp -o main.o

run:
	./main.exe

# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -rf *.o *.exe
