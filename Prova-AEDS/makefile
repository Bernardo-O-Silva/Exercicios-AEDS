TARGET = listas

all:
	make compilar
	make run
	make clean

compilar: main.c pilhas.c pilhas.h
	gcc -o $(TARGET) main.c pilhas.c pilhas.h

run:
	./$(TARGET)

clean:
	$(RM) $(TARGET)