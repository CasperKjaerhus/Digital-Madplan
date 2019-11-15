Digital_Mealplan.exe: ./source/Digital_Mealplan.c FileHandler.o
	gcc ./compiled/FileHandler.o ./source/Digital_Mealplan.c -Wall -pedantic -o Digital_Mealplan
compiled/FileHandler.o: ./source/FileHandler.c
	gcc -c ./source/FileHandler.o -Wall -pedantic -o compiled/FileHandler.o
clean:
	@echo "Removing all .exe and .o files"
	rm -f *.exe
	rm -f ./compiled/*.o