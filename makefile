Digital_Mealplan.exe: ./source/Digital_Mealplan.c
	gcc ./source/Digital_Mealplan.c -Wall -pedantic -o Digital_Mealplan

clean:
	@echo "Removing all .exe and .o files"
	rm -f *.exe
	rm -f *.o