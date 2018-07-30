#include <memory>
#include <string>

#include "snowball/porter2.hpp"
namespace stem {

class Porter2 {
public:
    Porter2() = default;
    ~Porter2() { snowball::close_env(env_); }

    std::string stem(const std::string& word) const
    {
        snowball::SN_set_current(env_,
            word.size(),
            reinterpret_cast<const unsigned char*>(word.c_str()));
        snowball::stem(env_);
        auto length = env_->l;  // NOLINT
        return std::string(env_->p, std::next(env_->p, length));
    }

private:
    snowball::SN_env* env_ = snowball::create_env();
};

} // stem