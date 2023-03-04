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
