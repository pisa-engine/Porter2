// Copyright 2023 PISA developers
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

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
