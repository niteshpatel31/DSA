file = vector

run:
	$(main)	./$(file)

main.o:
	g++ -c $(file).cpp -std=c++26 -Wall  -o $(file).o

main:
	g++ $(file).cpp -std=c++26 -Wall -o && $(file)

clean:
	 rm -rf $(file).o $(file) 

.PHONY:
	clean
