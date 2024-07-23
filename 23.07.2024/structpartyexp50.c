#include <stdio.h>
struct Item {
    char name[20];
    float price;
    int quantity;
};
int main()
{
    int i, ni;
    float total = 0;
    struct Item item[50];
    printf("Enter the number of items: ");
    scanf("%d", &ni);
    for (i = 0; i < ni; i++) {
        printf("\nEnter the name of item %d: ", i+1);
        scanf("%s", item[i].name);
        printf("\nEnter the price of item %d: ", i+1);
        scanf("%f", &item[i].price);
        printf("\nEnter the quantity of item %d: ", i+1);
        scanf("%d", &item[i].quantity);
    }
    for (i = 0; i < ni; i++) {
        total+= item[i].price * item[i].quantity;
    }
    printf("\nThe total cost of the party is %.2f.", total);
    return 0;
}
