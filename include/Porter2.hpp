#pragma once

#include <cstdint>
#include <functional>
#include <memory>
#include <string>

namespace snowball {
struct SN_env;
}

namespace porter2 {

/// Custom deleter of Snowball's environment for use in `std::unique_ptr`.
void snowball_porter2_deleter(snowball::SN_env *env);

class Stemmer {
   public:
    Stemmer();
    Stemmer(Stemmer const &);
    Stemmer(Stemmer &&) = default;
    Stemmer &operator=(Stemmer const &);
    Stemmer &operator=(Stemmer &&) = default;
    ~Stemmer() = default;
    std::string stem(std::string const &word) const;
    std::string operator()(std::string const &word) const;

   private:
    std::unique_ptr<snowball::SN_env, std::function<void(snowball::SN_env *)>> env_;
};

} // namespace stem
