bin/testListArray: praF_Array.cpp ListArray.h List.h
	mkdir -p bin
	g++ -o bin/testListArray praF_Linked.cpp ListArray.h

clean:
	rm -r *.o *.gch bin

bin/testNode: testNode.cpp Node.h
	mkdir -p bin
	g++ -o bin/testNode testNode.cpp Node.h

bin/testListLinked: praF_Linked.cpp ListLinked.h List.h
	mkdir -p bin
	g++ -o bin/testListLinked praF_Linked.cpp ListLinked.h
