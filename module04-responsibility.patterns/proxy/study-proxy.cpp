#include <iostream>
#include <memory>

struct image { // isp
    virtual void paint() = 0;
};

struct jpeg : public image {
    jpeg(const std::string &fileName) : file_name(fileName) {
        std::cout << "Loading image " << file_name << std::endl;
    }

    void paint() override {
        std::cout << "Painting image " << file_name << std::endl;
    }

private:
    const std::string &file_name;
};

// separation of concern
struct lazy_image : public image { // proxy
    lazy_image(const std::string &fileName) : file_name(fileName) {}

    void paint() override {
        // lazy loading logic
       if (jpeg_image.get() == nullptr)
           jpeg_image = std::make_shared<jpeg>(jpeg(file_name));

       // delegates paint to real-subject : business unaware
       jpeg_image->paint();
    }

private:
    const std::string &file_name;
    std::shared_ptr<jpeg> jpeg_image; // composition to real subject
};

int main(){
    jpeg img1(std::string("photo1.jpg")); // eager -> real object
    lazy_image img2(std::string("photo2.jpg")); // lazy -> proxy
    img2.paint();
    img2.paint();
    img2.paint();
    img2.paint();
}
