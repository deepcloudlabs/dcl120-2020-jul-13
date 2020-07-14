#pragma once

#include <string>

// DSL (Domain Specific Language) -> Fluent API
class PersonAddressBuilder : public PersonBuilderBase {
    typedef PersonAddressBuilder Self;
public:
    explicit PersonAddressBuilder(Person &person) : PersonBuilderBase{person} {
    }

    Self &at(std::string street_address) {
        person.street_address = street_address;
        return *this;
    }

    Self &with_postcode(std::string post_code) {
        person.post_code = post_code;
        return *this;
    }

    Self &in(std::string city) {
        person.city = city;
        return *this;
    }

    Self &on(std::string country) {
        person.country = country;
        return *this;
    }

    Self & validate(){
        //TODO: validate address
        return *this;
    }
    Self & cache(){
        //TODO: cache address
        return *this;
    }
};

Person::Person(const std::string &streetAddress, const std::string &postCode, const std::string &city,
               const std::string &companyName, const std::string &position, int annualIncome) : street_address(
        streetAddress), post_code(postCode), city(city), company_name(companyName), position(position), annual_income(
        annualIncome) {}

Person::Person(const std::string &streetAddress, const std::string &postCode, const std::string &city,
               const std::string &country, const std::string &companyName, const std::string &position,
               int annualIncome) : street_address(streetAddress), post_code(postCode), city(city), country(country),
                                   company_name(companyName), position(position), annual_income(annualIncome) {}

