#include <stdio.h>
#include <string.h>

struct Product {
    int id;
    char name[50];
    float price;
    int quantity;
};

struct Product shop[100];
int count = 0;
float totalSale = 0;

// Function declarations
void addProduct();
void displayProducts();
void sellProduct();
void searchProduct();
void updateProduct();

int main() {
    int choice;

    do {
        printf("\n====== SHOP MANAGEMENT SYSTEM ======\n");
        printf("1. Add Product\n");
        printf("2. Display Products\n");
        printf("3. Sell Product\n");
        printf("4. Search Product\n");
        printf("5. Update Product Stock\n");
        printf("6. Total Sales\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addProduct(); break;
            case 2: displayProducts(); break;
            case 3: sellProduct(); break;
            case 4: searchProduct(); break;
            case 5: updateProduct(); break;
            case 6: printf("Total Sale Amount: %.2f\n", totalSale); break;
            case 0: printf("Exiting Program...\n"); break;
            default: printf("Invalid Choice!\n");
        }

    } while (choice != 0);

    return 0;
}

// Add Product
void addProduct() {
    int id, i;
    printf("Enter Product ID: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++) {
        if (shop[i].id == id) {
            printf("Product ID already exists!\n");
            return;
        }
    }

    shop[count].id = id;
    printf("Enter Product Name: ");
    scanf(" %[^\n]", shop[count].name);
    printf("Enter Price: ");
    scanf("%f", &shop[count].price);
    printf("Enter Quantity: ");
    scanf("%d", &shop[count].quantity);

    count++;
    printf("Product Added Successfully!\n");
}

// Display Products
void displayProducts() {
    int i;
    if (count == 0) {
        printf("No products available.\n");
        return;
    }

    printf("\nID\tName\t\tPrice\tQuantity\n");
    for (i = 0; i < count; i++) {
        printf("%d\t%s\t\t%.2f\t%d\n",
               shop[i].id, shop[i].name,
               shop[i].price, shop[i].quantity);
    }
}

// Sell Product
void sellProduct() {
    int id, qty, i;
    printf("Enter Product ID: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++) {
        if (shop[i].id == id) {
            printf("Enter Quantity to Sell: ");
            scanf("%d", &qty);

            if (shop[i].quantity >= qty) {
                shop[i].quantity -= qty;
                totalSale += shop[i].price * qty;
                printf("Sale Successful! Bill Amount: %.2f\n",
                       shop[i].price * qty);
            } else {
                printf("Insufficient Stock!\n");
            }
            return;
        }
    }
    printf("Product Not Found!\n");
}

// Search Product
void searchProduct() {
    int id, i;
    printf("Enter Product ID to Search: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++) {
        if (shop[i].id == id) {
            printf("Product Found:\n");
            printf("Name: %s\n", shop[i].name);
            printf("Price: %.2f\n", shop[i].price);
            printf("Quantity: %d\n", shop[i].quantity);
            printf("Total Sale Amount: %.2f\n", totalSale);
    
            return;
        }
    }
    printf("Product Not Found!\n");
}

// Update Product Stock
void updateProduct() {
    int id, qty, i;
    printf("Enter Product ID: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++) {
        if (shop[i].id == id) {
            printf("Enter Quantity to Add: ");
            scanf("%d", &qty);
            shop[i].quantity += qty;
            printf("Stock Updated Successfully!\n");
            return;
        }
    }
    printf("Product Not Found!\n");
}