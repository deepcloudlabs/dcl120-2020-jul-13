#include <iostream>
#include "PersonBuilder.h"
#include "PersonJobBuilder.h"
#include "PersonAddressBuilder.h"
#include "Person.h"

int main() {
    Person p1 {
            "123 London Road",
            "SW1 1GB",
            "London",
            "UK",
            "PragmaSoft",
            "Consultant",
            100000
    };
    Person p2 = Person::create()
            .lives().at("123 London Road")
                    .with_postcode("SW1 1GB")
                    .in("London")
                    .on("UK")
                    .validate()
                    .cache()
            .works().at("PragmaSoft")
                    .as_a("Consultant")
                    .earning(10e6);
    std::cout << p1 << std::endl ;
    std::cout << p2 << std::endl ;
    return 0;
}
