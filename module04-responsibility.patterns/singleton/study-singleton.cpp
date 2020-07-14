#include <iostream>
#include <map>

struct cacheable{
    virtual std::size_t hash_code() = 0 ;
};
// immutable -> object pool
struct point : public cacheable {
    const int x,y;

    point(const int x, const int y) : x(x), y(y) {}

    size_t hash_code() override {
        return 17 * x + y;
    }
};

struct object_caching {
    static std::map<size_t,cacheable*> cache;
protected:
    object_caching(){
       static int instance_count{0};
       instance_count++;
       if (instance_count>1){
           throw "Cannot create multiple instance!";
       }
    }
public:
    object_caching(object_caching const &) = delete;
    object_caching(object_caching &&) = delete;
    object_caching& operator=(object_caching const &) = delete;

    static object_caching& get_cache(){ // c++11 -> thread-safe
        static object_caching instance; // singleton
        return instance;
    }

    cacheable* put(cacheable *o){
        auto code = o->hash_code();
        auto found = cache.find(code);
        if (found == cache.end()){ // not present
            cache[code] = o;
            return o;
        }
        delete o;
        return found->second;
    }
};

std::map<size_t,cacheable*> object_caching::cache ;

int main() {
    auto &cache1 = object_caching::get_cache();
    auto &cache2 = object_caching::get_cache();
    auto *p1 = new point {1,2};
    auto *p3 = new point {1,2};
    std::cout << "Before putting into cache:" << std::endl;
    std::cout << "p1: " << std::hex << p1 << std::endl;
    std::cout << "p3: " << std::hex << p3 << std::endl;
    p1 = dynamic_cast<point *>(cache1.put(p1));
    p3 = dynamic_cast<point *>(cache2.put(p3));
    std::cout << "After putting into cache:" << std::endl;
    std::cout << "p1: " << std::hex << p1 << std::endl;
    std::cout << "p3: " << std::hex << p3 << std::endl;
    return 0;
}
