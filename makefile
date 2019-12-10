FLAGS=-Wall -pedantic

Digital_Mealplan.exe: ./source/Digital_Mealplan.c compiled/FileHandler.o compiled/Recipe.o compiled/Ingredient.o compiled/Mealplan.o
	gcc compiled/FileHandler.o compiled/Recipe.o compiled/Ingredient.o compiled/Mealplan.o source/Digital_Mealplan.c $(FLAGS) -o Digital_Mealplan.exe
compiled/FileHandler.o: source/FileHandler.c
	gcc -c source/FileHandler.c $(FLAGS) -o compiled/FileHandler.o
compiled/Recipe.o: source/Recipe.c
	gcc -c source/Recipe.c $(FLAGS) -o compiled/Recipe.o
compiled/Ingredient.o: source/Ingredient.c
	gcc -c source/Ingredient.c $(FLAGS) -o compiled/Ingredient.o
compiled/Mealplan.o: source/Mealplan.c
	gcc -c source/Mealplan.c -o compiled/Mealplan.o
clean:
	@echo "Removing all .exe, .txt & .o files"
	rm -f *.exe
	rm -f ./compiled/*.o
	rm -f ./files/shoppinglist.txt
	rm -f ./files/mealplan.txt
