bst: *.cpp *.h tokenizer/*.cpp tokenizer/*.h
	g++ *.cpp tokenizer/*.cpp -o bst

clean:
	rm -f bst