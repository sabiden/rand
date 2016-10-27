rand: rand.c
	gcc rand.c -o rand

clean:
	rm *~

run: rand
	./rand
