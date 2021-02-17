#include <iostream>

struct man // creation of a class 'man'
{
    private: // not available for all

        std::string name;
        std::string surname;
        std::string nationality;
        int age;
        int height;
        int mass;

    public: // available for all

        // constructor (INITAILIZATION)
        man(std::string name_init, std::string surname_init, std::string nationality_init, int age_init, int height_init, int mass_init)
        {
            // don't need to addres like this: man.name = ...
            name = name_init;
            surname = surname_init;
            nationality = nationality_init;
            age = age_init;
            height = height_init;
            mass = mass_init;

            std::cout << name << " was added" << "\a" << "\n";
        }

        // destructor (REMOVAL)
        ~man()
        {
            std::cout << name << " was deleted" << "\a" << "\n";
        }

        // method (function of an object of a class)
        void print()
        {
            std::cout << name << " " << surname << " (nat: " << nationality << ", " << "age: " << age << ", " << "hei: " << height << ", mas: " << mass << ")\n";
        }
};

int main()
{
    std::string name;
    std::string surname;
    std::string nationality;
    int age;
    int height;
    int mass;

    std::cin >> name >> surname >> nationality >> age >> height >> mass;

    man man(name, surname, nationality, age, height, mass); // creating an object of a class man with name "man" with non-standart constructor
    man.print(); // using method of class man to object "man"

    return 0;
}