#include <bits/stdc++.h>
using namespace std;

class Product {
    string name;
    int price, quantity;

    public:
    Product(string name, int pr, int qu) {
        this->name = name;
        this->price = pr;
        this->quantity = qu;
    }

    int getPrice() {
        return this->price;
    }

    int getQuantity() {
        return this->quantity;
    }

    string getName() {
        return this->name;
    }

    void productInfo() {
        cout << "Product Detail: " << endl;
        cout << "Name: " << this->name << " Price: " << this->price << " Quantity: " << this->quantity << endl;
    }
};

class ShoppingCart {
    vector<Product> products;

    public:
    void addProduct(Product p) {
        products.push_back(p);
    }

    vector<Product> getProducts() {
        return this->products;
    }

    int calculatePrice() {
        int total = 0;
        for(Product p: products) {
            total += p.getPrice() * p.getQuantity();
        }
        return total;
    }
};

class InvoicePrinter {
    ShoppingCart* cart;

    public:
    InvoicePrinter(ShoppingCart c) {
        cart = new ShoppingCart(c);
    }

    void printInvoice() {
        for(Product p: cart->getProducts()) {
            cout << "Name: " << p.getName() << " Price: " << p.getPrice() << " Quantity: " << p.getQuantity() << endl;
        }
        cout << "Total: " << cart->calculatePrice() << endl;
    }
};

class Database {
    ShoppingCart *cart;

    public:
    Database(ShoppingCart c) {
        cart = new ShoppingCart(c);
    }

    void saveToDB() {
        cout << "Saving Products to DB...." << endl;
    }

};


int main() {

    Product p1("Laptop", 4000, 1), p2("IPhone", 2000, 1);

    ShoppingCart *cart = new ShoppingCart();
    cart->addProduct(p1);
    cart->addProduct(p2);

    InvoicePrinter *inv = new InvoicePrinter(*cart);

    inv->printInvoice();

    Database *db = new Database(*cart);

    db->saveToDB();

    return 0;
}