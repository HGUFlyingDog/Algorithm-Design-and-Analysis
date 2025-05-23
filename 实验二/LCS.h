#pragma once
#include <string>
#include <vector>

namespace LCS {
    struct Result {
        int length;
        std::vector<std::string> sequences;
    };
    Result solve(const std::string& A, const std::string& B);
}
