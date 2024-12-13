#include <iostream>
#include <vector>
#include <algorithm>

class Product {
private:
    std::string name;
    std::string category;
    double price;

public:
    Product(std::string n, std::string c, double p) : name(n), category(c), price(p) {}

    std::string getName() const { return name; }
    std::string getCategory() const { return category; }
    double getPrice() const { return price; }

    void setName(const std::string& n) { name = n; }
    void setCategory(const std::string& c) { category = c; }
    void setPrice(double p) { price = p; }
};

class ProductManager {
private:
    std::vector<Product> products;

public:
    void addProduct(const Product& product) {
        products.push_back(product);
    }

    void displayProducts() const {
        for (const auto& product : products) {
            std::cout << "Name: " << product.getName() 
                      << ", Category: " << product.getCategory() 
                      << ", Price: $" << product.getPrice() << std::endl;
        }
    }

    void filterByCategory(const std::string& category) const {
        for (const auto& product : products) {
            if (product.getCategory() == category) {
                std::cout << "Name: " << product.getName() 
                          << ", Price: $" << product.getPrice() << std::endl;
            }
        }
    }

    void sortByPrice() {
        std::sort(products.begin(), products.end(), [](const Product& a, const Product& b) {
            return a.getPrice() < b.getPrice();
        });
    }
};

int main() {
    ProductManager manager;

    manager.addProduct(Product("Laptop", "Electronics", 999.99));
    manager.addProduct(Product("Phone", "Electronics", 599.99));
    manager.addProduct(Product("Shirt", "Clothing", 29.99));
    manager.addProduct(Product("Shoes", "Clothing", 49.99));

    std::cout << "All Products:" << std::endl;
    manager.displayProducts();

    std::cout << "\nFilter by Category 'Electronics':" << std::endl;
    manager.filterByCategory("Electronics");

    std::cout << "\nProducts sorted by Price:" << std::endl;
    manager.sortByPrice();
    manager.displayProducts();

    return 0;
}
