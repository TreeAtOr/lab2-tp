make all:
	rm -r dist
	mkdir dist
	cd dist

	g++ queue.cpp -o dist/queue.o -c -g
	g++ cyclicqueue.cpp -o dist/cyclicqueue.o -c -g
	g++ main.cpp -o dist/main.o -c -g
	
	g++ -o dist/target dist/main.o dist/cyclicqueue.o dist/queue.o -g
