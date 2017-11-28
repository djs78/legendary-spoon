
all:

	echo "###################################################"
	g++ -Wall -c *.cpp
	g++ -Wall -o group *.o
	rm -rf *.o
	./group

