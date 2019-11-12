Digital_Mealplan.exe: ./source/Digital_Mealplan.c
	gcc ./source/Digital_Mealplan.c -Wall -pedantic

clean:
	@echo "Removing all .exe and .o files"
	rm -f *.exe
	rm -f *.o