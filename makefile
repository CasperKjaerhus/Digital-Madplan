FLAGS=-Wall -pedantic

Digital_Mealplan.exe: ./source/Digital_Mealplan.c compiled/FileHandler.o compiled/Recipe.o compiled/Ingredient.o compiled/LinkedList.o
	gcc compiled/LinkedList.o compiled/FileHandler.o compiled/Recipe.o compiled/Ingredient.o source/Digital_Mealplan.c $(FLAGS) -o Digital_Mealplan.exe
compiled/FileHandler.o: source/FileHandler.c
	gcc -c source/FileHandler.c $(FLAGS) -o compiled/FileHandler.o
compiled/Recipe.o: source/Recipe.c
	gcc -c source/Recipe.c $(FLAGS) -o compiled/Recipe.o
compiled/Ingredient.o: source/Ingredient.c
	gcc -c source/Ingredient.c $(FLAGS) -o compiled/Ingredient.o
compiled/LinkedList.o: source/LinkedList.c
	gcc -c source/LinkedList.c $(FLAGS) -o compiled/LinkedList.o
clean:
	@echo "Removing all .exe, .txt & .o files"
	rm -f *.exe
	rm -f ./compiled/*.o
	rm -f ./files/shoppinglist.txt
	rm -f ./files/mealplan.txt