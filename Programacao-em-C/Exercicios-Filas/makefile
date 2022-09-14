TARGET = fila1

all:
	make compilar
	make run
	make clean

compilar: main.c fila.c fila.h
	gcc -o $(TARGET) main.c fila.c fila.h

run:
	./$(TARGET)

clean:
	$(RM) $(TARGET)