
Digital_Mealplan.exe: Digital_Mealplan.c
		gcc Digital_Mealplan.c -Wall -pedantic

clean:
	@echo "Removing all .exe and .o files"
    rm *.exe
    rm *.o