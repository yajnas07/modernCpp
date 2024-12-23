#include<iostream>
#include<memory>
#include<functional>
#include<vector>


using namespace std;

class Animal {
public:
    template<typename AnimalType>
    Animal(AnimalType animal): self_(std::make_shared<Model<AnimalType>>(std::move(animal))) {

    }

    void speak() const {
        self_->speak();
    }
    void favoriteFood() const  {
            self_->favoriteFood();
    }

private:
    struct Concept {
        virtual ~Concept() = default;
        virtual void speak() const = 0;
        virtual void favoriteFood() const = 0;
    };

    template <typename T>
    struct Model : Concept{
        Model(T animal): realAnimal_(std::move(animal)) {
        }
        void speak() const override {
            realAnimal_.speak();
        }
        void favoriteFood() const override {
            realAnimal_.favoriteFood();
        }
        T realAnimal_;
    };


    std::shared_ptr<const Concept> self_;

};

template <typename FoodType>
class dog {
    public: dog(string name, FoodType food): name_(name), food_(food) {
        cout << " Constructing a dog named " << name_ << endl;
    }
    void speak() const {
        cout << name_ << " says Woof woof" << endl;
    }
    void favoriteFood() const {
        cout << name_ << "'s favourite food :" << food_ << endl;
    }
    string name_;
    FoodType food_;
};


template <typename FoodType>
class cat {
    public: cat(string name, FoodType food): name_(name), food_(food) {
        cout << " Constructing a cat named " << name_ << endl;
    }
    void speak() const {
        cout << name_ << " says Mewo Meow" << endl;
    }
    void favoriteFood() const {
        cout << name_ << "'s favourite food is :" << food_ << endl;
    }
    string name_;
    FoodType food_;
};

int main()
{

    vector<Animal> animals;

    cat<string>  c1("Oscar", "Chicken and milk" );
    animals.emplace_back(c1);
    
    cat<string>  c2("Cherry", "Fish and rice");
    animals.emplace_back(c2);


    dog<string>  d1("Nancy", "Chicken and rice" );
    animals.emplace_back(d1);

    dog<string>  d2("Polo", "Chicken and eggs");
    animals.emplace_back(d2);


    for(auto a: animals){
        a.speak();
        a.favoriteFood();
    }

    return 0;
}
