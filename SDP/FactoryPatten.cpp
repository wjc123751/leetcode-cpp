#include <iostream>
using namespace std;

// 工厂定义创建对象的接口，让子工厂决定实例化哪一个类，将产品的创建与使用分离。

// 1. 抽象产品（所有产品的父类）
class Product {
public:
    virtual void show() = 0; // 纯虚函数
    virtual ~Product() {}
};

// 2. 具体产品 A
class ProductA : public Product {
public:
    void show() override {
        cout << "我是产品 A" << endl;
    }
};

// 3. 具体产品 B
class ProductB : public Product {
public:
    void show() override {
        cout << "我是产品 B" << endl;
    }
};

// 4. 抽象工厂
class Factory {
public:
    virtual Product* createProduct() = 0;
    virtual ~Factory() {}
};

// 5. 生产 A 的工厂
class FactoryA : public Factory {
public:
    Product* createProduct() override {
        return new ProductA();
    }
};

// 6. 生产 B 的工厂
class FactoryB : public Factory {
public:
    Product* createProduct() override {
        return new ProductB();
    }
};

// 测试
int main() {
    Factory* factory = new FactoryA();
    Product* p = factory->createProduct();
    p->show(); // 输出：我是产品 A

    delete p;
    delete factory;

    factory = new FactoryB();
    p = factory->createProduct();
    p->show(); // 输出：我是产品 B

    delete p;
    delete factory;
    return 0;
}