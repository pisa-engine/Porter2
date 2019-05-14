#include <memory>
#include <string>

#include "snowball.cpp"
#include "Porter2.hpp"

namespace porter2 {

void snowball_porter2_deleter(snowball::SN_env *env) { snowball::close_env(env); }

Stemmer::Stemmer() : env_(snowball::create_env(), snowball_porter2_deleter) {}
Stemmer::Stemmer(Stemmer const &) : env_(snowball::create_env(), snowball_porter2_deleter) {}
Stemmer &Stemmer::operator=(Stemmer const &) { return *this; }

std::string Stemmer::stem(std::string const &word) const
{
    SN_set_current(env_.get(), word.size(), reinterpret_cast<const unsigned char *>(word.c_str()));
    snowball::stem(env_.get());
    auto length = env_->l;
    return std::string(env_->p, std::next(env_->p, length));
}

std::string Stemmer::operator()(std::string const &word) const { return stem(word); }

} // namespace porter2
