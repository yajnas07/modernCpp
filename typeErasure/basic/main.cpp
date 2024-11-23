#include<iostream>
#include<memory>
#include<functional>


using namespace std;

class genericPrinter {
public:
    template<typename GP>
    genericPrinter(GP value): self_(std::make_shared<Model<GP>>(std::move(value))) {

    }

    void print() const {
        self_->print();
    }

private:
    struct Concept {
        virtual ~Concept() = default;
        virtual void print() const = 0;
    };

    template <typename T>
    struct Model : Concept{
        Model(T value): value_(std::move(value)) {
        }
        void print() const override {
            value_.print();
        }
        T value_;
    };


    std::shared_ptr<const Concept> self_;

};

class circle {
    public: circle(){
        cout << " Constructing a circle" << endl;
    }
    void print() const {
        cout << "Printing a clrcle" << endl;
    }
};

class rectangle {
    public: rectangle(){
        cout << " Constructing a rectangle" << endl;
    }
    void print() const {
        cout << "Printing a rectangle" << endl;
    }
};

int main()
{

    circle c;
    rectangle r;
    genericPrinter p1(c);
    genericPrinter p2(r);

     p1.print();
     p2.print();
    return 0;
}
