#include <stdio.h>
#include <string.h>

struct product
{
    char name[50];
    int id;
    float price;
    int quantity;
};

struct order
{
    int product_id;
    int quantity;
};

// Admin password for restricted actions
#define ADMIN_PASSWORD "admin123"

// Function to prompt for admin password and check its validity
int check_admin_password()
{
    char password[50];
    printf("Enter Admin Password: ");
    scanf("%s", password);

    if (strcmp(password, ADMIN_PASSWORD) == 0)
    {
        return 1; // Password is correct!
    }
    else
    {
        printf("Incorrect password.\n");
        return 0; // Password is incorrect!
    }
}

void display_catalog(struct product *products, int num_products)
{
    printf("\nProduct Catalog:\n");
    printf("----------------\n");
    for (int i = 0; i < num_products; i++)
    {
        printf("Product ID: %d\n", products[i].id);
        printf("Product Name: %s\n", products[i].name);
        printf("Price: %.2f\n", products[i].price);
        printf("Quantity: %d\n", products[i].quantity);
        printf("----------------\n");
    }
}

void add_to_cart(struct product *products, int num_products, struct order *cart, int *cart_size)
{
    int product_id, quantity;
    printf("\nEnter Product ID: ");
    scanf("%d", &product_id);

    // checking if the product ID is in the range of the products
    if (product_id < 1 || product_id > num_products)
    {
        printf("Invalid Product ID.\n");
        return;
    }

    printf("Enter Quantity: ");
    scanf("%d", &quantity);

    // Checking if required quantity is available
    if (quantity > products[product_id - 1].quantity)
    {
        printf("Insufficient stock.\n");
        return;
    }

    // Checking if cart size is within limits (100 items max.)
    if (*cart_size >= 100)
    {
        printf("Cart is full. Cannot add more products.\n");
        return;
    }

    // Add product to cart
    cart[*cart_size].product_id = product_id;
    cart[*cart_size].quantity = quantity;
    (*cart_size)++;

    // Updating product quantity in the store
    products[product_id - 1].quantity -= quantity;

    printf("Added %d of product ID %d to the cart. Remaining stock: %d\n", quantity, product_id, products[product_id - 1].quantity);
}

float calculate_total(struct product *products, struct order *cart, int cart_size)
{
    float total = 0.0;
    for (int i = 0; i < cart_size; i++)
    {
        total += products[cart[i].product_id - 1].price * cart[i].quantity;
    }

    // Applying 15% discount if total bill amount goes above 10000
    if (total > 10000)
    {
        total -= (total * 0.15);
    }

    return total;
}

void delete_product(struct product *products, int *num_products, int product_id)
{
    if (product_id < 1 || product_id > *num_products)
    {
        printf("Invalid Product ID.\n");
        return;
    }

    int i;
    for (i = product_id - 1; i < *num_products - 1; i++)
    {
        products[i] = products[i + 1];
    }
    (*num_products)--;
    printf("Product with ID %d deleted.\n", product_id);
}

void edit_product_quantity(struct product *products, int num_products, int product_id)
{
    if (product_id < 1 || product_id > num_products)
    {
        printf("Invalid Product ID.\n");
        return;
    }

    int new_quantity;
    printf("Enter new quantity for Product ID %d: ", product_id);
    scanf("%d", &new_quantity);
    if (new_quantity >= 0)
    {
        products[product_id - 1].quantity = new_quantity;
        printf("Quantity updated successfully.\n");
    }
    else
    {
        printf("Invalid quantity.\n");
    }
}

void view_cart(struct product *products, struct order *cart, int cart_size)
{
    if (cart_size == 0)
    {
        printf("Cart is empty.\n");
    }
    else
    {
        printf("\nCart Contents:\n");
        printf("----------------\n");
        for (int i = 0; i < cart_size; i++)
        {
            printf("Product ID: %d\n", cart[i].product_id);
            printf("Product Name: %s\n", products[cart[i].product_id - 1].name);
            printf("Quantity: %d\n", cart[i].quantity);
            printf("----------------\n");
        }
    }
}

void delete_from_cart(struct order *cart, int *cart_size, int product_id, struct product *products)
{
    if (*cart_size == 0)
    {
        printf("Your cart is empty.\n");
        return;
    }

    int i, j;
    for (i = 0; i < *cart_size; i++)
    {
        if (cart[i].product_id == product_id)
        {
            // Update the store stock by adding the quantity back
            products[product_id - 1].quantity += cart[i].quantity;

            // Shift the elements in the cart to delete the product
            for (j = i; j < *cart_size - 1; j++)
            {
                cart[j] = cart[j + 1];
            }
            (*cart_size)--; // Ensure cart size is updated properly
            printf("Product with ID %d removed from cart. Product quantity in store updated. Remaining stock: %d\n",
                   product_id, products[product_id - 1].quantity);
            return;
        }
    }
    printf("Product not found in cart.\n");
}

void place_order(struct product *products, struct order *cart, int cart_size)
{
    if (cart_size == 0)
    {
        printf("Your cart is empty! Cannot place order.\n");
        return;
    }

    float total = calculate_total(products, cart, cart_size);
    printf("\nTotal Bill: %.2f\n", total);

    printf("Thank you for shopping with us! Your order has been placed successfully!\n");

    // Clearing the cart after placing the order
    cart_size = 0; // Reset cart size
    printf("Your cart is now empty.\n");
}

void add_new_product(struct product *products, int *num_products)
{
    if (!check_admin_password())
    {
        return;
    }

    printf("Enter new product details:\n");

    struct product new_product;
    new_product.id = *num_products + 1; // Assign the next available ID

    printf("Name: ");
    scanf("%s", new_product.name);

    printf("Price: ");
    scanf("%f", &new_product.price);

    printf("Quantity: ");
    scanf("%d", &new_product.quantity);

    products[*num_products] = new_product;
    (*num_products)++;

    printf("Product added successfully!\n");
}

int main()
{
    struct product products[100] = {
        {"Laptop", 1, 800.00, 10},
        {"Smartphone", 2, 500.00, 20},
        {"Headphones", 3, 100.00, 50},
    };
    int num_products = 3;
    struct order cart[100];
    int cart_size = 0;

    int choice, product_id;
    do
    {
        printf("\nWelcome to our Store!\n");
        printf("1. Display Products\n");
        printf("2. Add to Cart\n");
        printf("3. View Cart\n");
        printf("4. Calculate Total\n");
        printf("5. Place Order\n");
        printf("6. Delete Product (Admin Only)\n");
        printf("7. Edit Product Quantity (Admin Only)\n");
        printf("8. Add New Product (Admin Only)\n");
        printf("9. Delete from Cart\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            display_catalog(products, num_products);
            break;
        case 2:
            add_to_cart(products, num_products, cart, &cart_size);
            break;
        case 3:
            view_cart(products, cart, cart_size);
            break;
        case 4:
            printf("Total Price: %.2f\n", calculate_total(products, cart, cart_size));
            break;
        case 5:
            place_order(products, cart, cart_size);
            break;
        case 6:
            // Admin access is required to delete product
            if (check_admin_password())
            {
                printf("Enter Product ID to delete: ");
                scanf("%d", &product_id);
                delete_product(products, &num_products, product_id);
            }
            break;
        case 7:
            // Admin access is required to edit product quantity
            if (check_admin_password())
            {
                printf("Enter Product ID to edit: ");
                scanf("%d", &product_id);
                edit_product_quantity(products, num_products, product_id);
            }
            break;
        case 8:
            add_new_product(products, &num_products);
            break;
        case 9:
            printf("Enter Product ID to delete from cart: ");
            scanf("%d", &product_id);
            delete_from_cart(cart, &cart_size, product_id, products);
            break;
        case 10:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice != 10);

    return 0;
}
