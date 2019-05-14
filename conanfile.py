from conans import ConanFile, tools, CMake
import os


class Porter2Conan(ConanFile):
    name = "Porter2"
    version = "1.0"
    license = "Apache License 2.0"
    description = "Porter2 stemming library"
    url = "https://github.com/pisa-engine/Porter2"
    code_url = "https://github.com/pisa-engine/Porter2"
    build_policy="missing"
    generators = "cmake_paths", "ycm"
    exports_sources = ("LICENSE", "README.md", "include/*", "src/*",
                       "cmake/*", "CMakeLists.txt", "external/*", "test/*")

    def package(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()
        cmake.install()
