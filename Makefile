build:
	gcc predict_words.c -o predict -lm
	gcc tema2.c Task1.c Task2.c Task3.c -o tema2 -lm -g

clean:
	rm -f tema2
	rm -f predict