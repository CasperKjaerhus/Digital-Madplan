enum category{meat, vegetables, fruit, carbohydrates, spices};

typedef struct Ingredient{
    char *name;
    int amount;
    enum category;
    
} Ingredient;