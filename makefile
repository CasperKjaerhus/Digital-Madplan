Digital_Mealplan.exe: ./source/Digital_Mealplan.c compiled/FileHandler.o compiled/Ingredient.o
	gcc ./compiled/FileHandler.o ./compiled/Ingredient.o ./source/Digital_Mealplan.c -Wall -pedantic -o Digital_Mealplan
compiled/FileHandler.o: ./source/FileHandler.c
	gcc -c ./source/FileHandler.c -Wall -pedantic -o compiled/FileHandler.o
compiled/Recipe.o: ./source/Recipe.c ./compiled/Ingredient.o
	gcc -c ./compiled/Ingredient.o ./source/Ingredient.c -Wall -pedantic -o compiled/Recipe.o
compiled/Ingredient.o: ./source/Ingredient.c
	gcc -c ./source/Ingredient.c -Wall -pedantic -o compiled/Ingredient.o
clean:
	@echo "Removing all .exe, .txt & .o files"
	rm -f *.exe
	rm -f ./compiled/*.o
	rm -f ./files/*.txt